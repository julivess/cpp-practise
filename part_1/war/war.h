#pragma once

#include <array>
#include <stdexcept>
#include <queue>

enum class Winner { kFirst, kSecond, kNone };

struct GameResult {
    Winner winner;
    int turn;
};

GameResult SimulateWarGame(const std::array<int, 6>& first_deck,
                           const std::array<int, 6>& second_deck) {

    std::queue<int> first_d, second_d;
    for (size_t i = 0; i < first_deck.size(); ++i) {
        first_d.push(first_deck[i]);
        second_d.push(second_deck[i]);
    }
    int n = 0;
    while (!first_d.empty() && !second_d.empty() && n != 1000000) {
        ++n;
        int first = first_d.front();
        first_d.pop();
        int second = second_d.front();
        second_d.pop();
        if (first == 0 && second == 11) {
            first_d.push(first);
            first_d.push(second);
        } else if (first == 11 && second == 0) {
            second_d.push(first);
            second_d.push(second);
        } else if (first > second) {
            first_d.push(first);
            first_d.push(second);
        } else if (second > first) {
            second_d.push(first);
            second_d.push(second);
        }
    }
    GameResult res;
    if (first_d.empty()) {
        res.winner = Winner::kSecond;
        res.turn = n;
    } else if (second_d.empty()) {
        res.winner = Winner::kFirst;
        res.turn = n;
    } else if (n == 1000000) {
        res.winner = Winner::kNone;
        res.turn = n;
    }
    return res;
}
