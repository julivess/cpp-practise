#pragma once

#include <sstream>
#include <memory>
#include <variant>
#include <cassert>
#include <iostream>

class Tokenizer {
public:
    explicit Tokenizer(std::istream* in) : in_{in} {
        Consume();
    }

    enum TokenType { kStart, kNumber, kSymbol, kEnd };

    void Consume() {
        while (in_->peek() != EOF && in_->peek() == ' ') {
            in_->get();
        }
        if (in_->peek() == EOF) {
            type_ = TokenType::kEnd;
            return;
        }
        if (isdigit(in_->peek())) {
            std::string number;
            while (isdigit(in_->peek())) {
                number += in_->get();
            }
            number_ = stoll(number);
            type_ = TokenType::kNumber;
            return;
        }
        char s = in_->get();
        if (s == '(' || s == ')' || s == '+' || s == '-' || s == '*' || s == '/') {
            type_ = TokenType::kSymbol;
            symbol_ = s;
            return;
        }
    }

    TokenType GetType() const {
        return type_;
    }

    int64_t GetNumber() const {
        return number_;
    }

    char GetSymbol() const {
        return symbol_;
    }

private:
    std::istream* in_;
    TokenType type_;
    char symbol_;
    int64_t number_;
};

class Expression {
public:
    virtual ~Expression() = default;
    virtual int64_t Evaluate() const = 0;
};

using ExPtr = std::unique_ptr<Expression>;

class Number : public Expression {
public:
    Number(const int64_t& number) : number_{number} {
    }
    int64_t Evaluate() const override {
        return number_;
    }

private:
    int64_t number_;
};

class Plus : public Expression {
public:
    Plus(ExPtr left, ExPtr right) : left_{std::move(left)}, right_{std::move(right)} {
    }
    int64_t Evaluate() const override {
        return left_->Evaluate() + right_->Evaluate();
    }

private:
    ExPtr left_;
    ExPtr right_;
};

class Minus : public Expression {
public:
    Minus(ExPtr left, ExPtr right) : left_{std::move(left)}, right_{std::move(right)} {
    }
    int64_t Evaluate() const override {
        return left_->Evaluate() - right_->Evaluate();
    }

private:
    ExPtr left_;
    ExPtr right_;
};

class Mult : public Expression {
public:
    Mult(ExPtr left, ExPtr right) : left_{std::move(left)}, right_{std::move(right)} {
    }

    int64_t Evaluate() const override {
        return left_->Evaluate() * right_->Evaluate();
    }

private:
    ExPtr left_;
    ExPtr right_;
};

class Div : public Expression {
public:
    Div(ExPtr left, ExPtr right) : left_{std::move(left)}, right_{std::move(right)} {
    }

    int64_t Evaluate() const override {
        return left_->Evaluate() / right_->Evaluate();
    }

private:
    ExPtr left_;
    ExPtr right_;
};

class UnarMinus : public Expression {
public:
    UnarMinus(ExPtr number) : number_{std::move(number)} {
    }
    int64_t Evaluate() const override {
        return -number_->Evaluate();
    }

private:
    ExPtr number_;
};

std::unique_ptr<Expression> ParseExpression(Tokenizer* tokenizer);
std::unique_ptr<Expression> ParseTerm(Tokenizer* tokenizer);

std::unique_ptr<Expression> ParseFactor(Tokenizer* tokenizer) {
    if (tokenizer->GetType() == Tokenizer::kNumber) {
        auto number = std::make_unique<Number>(tokenizer->GetNumber());
        tokenizer->Consume();
        return number;
    } else if (tokenizer->GetType() == Tokenizer::kSymbol && tokenizer->GetSymbol() == '-') {
        tokenizer->Consume();
        return std::make_unique<UnarMinus>(ParseTerm(tokenizer));
    } else {
        tokenizer->Consume();
        auto expr = ParseExpression(tokenizer);
        tokenizer->Consume();
        return expr;
    }
}

std::unique_ptr<Expression> ParseTerm(Tokenizer* tokenizer) {
    std::unique_ptr<Expression> result = ParseFactor(tokenizer);
    while ((tokenizer->GetType() == Tokenizer::kSymbol) &&
           (tokenizer->GetSymbol() == '*' || tokenizer->GetSymbol() == '/')) {
        if (tokenizer->GetSymbol() == '*') {
            tokenizer->Consume();
            result = std::make_unique<Mult>(std::move(result), ParseFactor(tokenizer));
        } else if (tokenizer->GetSymbol() == '/') {
            tokenizer->Consume();
            result = std::make_unique<Div>(std::move(result), ParseFactor(tokenizer));
        }
    }
    return result;
}

std::unique_ptr<Expression> ParseExpression(Tokenizer* tokenizer) {
    std::unique_ptr<Expression> result = ParseTerm(tokenizer);
    while ((tokenizer->GetType() == Tokenizer::kSymbol) &&
           (tokenizer->GetSymbol() == '+' || tokenizer->GetSymbol() == '-')) {
        if (tokenizer->GetSymbol() == '+') {
            tokenizer->Consume();
            result = std::make_unique<Plus>(std::move(result), ParseTerm(tokenizer));
        } else if (tokenizer->GetSymbol() == '-') {
            tokenizer->Consume();
            result = std::make_unique<Minus>(std::move(result), ParseTerm(tokenizer));
        }
    }
    return result;
}
