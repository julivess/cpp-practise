#include "long_sum.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Your test") {
    CHECK(LongSum("2", "2") == "4");
    CHECK(LongSum("105", "10") == "115");
    CHECK(LongSum("10", "2") == "12");
    CHECK(LongSum("40", "59") == "99");
    CHECK(LongSum("21", "9") == "30");
    CHECK(LongSum("", "") == "");
    CHECK(LongSum("9999", "1") == "10000");
    
}

TEST_CASE("Big") {
    CHECK(LongSum("9999999", "9999999") == "19999998");
    CHECK(LongSum("1000000", "9999999") == "10999999");
    CHECK(LongSum("1000000", "1000000") == "2000000");
    CHECK(LongSum("1245897348", "1245597823") == "2491495171");
    CHECK(LongSum("10000000", "9") == "10000009");
    CHECK(LongSum("4217219467", "4841") == "4217224308");
}