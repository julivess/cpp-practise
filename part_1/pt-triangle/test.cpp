#include "point_triangle.h"

#include <catch2/catch_test_macros.hpp>

Triangle T;

Point a, b, c, d;


TEST_CASE("Your test") {
    a.x = -1; a.y = -1;
    b.x = -5; b.y = -3;
    c.x = -2; c.y = -4;
    d.x = -5; d.y = -3;
    T.a = a;
    T.b = b;
    T.c = c;
    Triangle& Tr = T;
    Point& pt = d;
    CHECK(IsPointInTriangle(Tr, pt) == true);
}
