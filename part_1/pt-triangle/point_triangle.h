#pragma once

#include <stdexcept>

struct Point {
    int64_t x, y;
    bool operator==(const Point& t) const {
        return (this->x == t.x) && (this->y == t.y);
    }
};

struct Triangle {
    Point a, b, c;
};

double Sign(Point a, Point b, Point c) {
    return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}

bool IsPointInTriangle(const Triangle& t, const Point& pt) {
    if (pt == t.a || pt == t.b || pt == t.c) {
        return true;
    }
    bool b1, b2, b3;
    b1 = Sign(pt, t.a, t.b) <= 0.0;
    b2 = Sign(pt, t.b, t.c) <= 0.0;
    b3 = Sign(pt, t.c, t.a) <= 0.0;
    return ((b1 == b2) && (b2 == b3));
}
