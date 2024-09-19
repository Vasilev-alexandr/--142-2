#include <gtest/gtest.h>
#include "pch.h"
#include "..//solver/color.h"

TEST(ColorTest, ConstructorValidValues) {
    Color color(100, 150, 200);
    EXPECT_NO_THROW(color);
}

TEST(ColorTest, ConstructorInvalidRed) {
    EXPECT_THROW(Color(-1, 100, 100), std::invalid_argument);
    EXPECT_THROW(Color(256, 100, 100), std::invalid_argument);
}

TEST(ColorTest, ConstructorInvalidGreen) {
    EXPECT_THROW(Color(100, -1, 100), std::invalid_argument);
    EXPECT_THROW(Color(100, 256, 100), std::invalid_argument);
}

TEST(ColorTest, ConstructorInvalidBlue) {
    EXPECT_THROW(Color(100, 100, -1), std::invalid_argument);
    EXPECT_THROW(Color(100, 100, 256), std::invalid_argument);
}

TEST(ColorTest, ToString) {
    Color color(100, 150, 200);
    EXPECT_EQ(color.ToString(), "(100, 150, 200)");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}