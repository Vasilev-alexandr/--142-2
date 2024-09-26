#include <gtest/gtest.h>
#include "..//solver/color.h"
#include <stdexcept>

TEST(ColorTest, ConstructorValidParameters) {
    Color color(100, 150, 200);

    EXPECT_EQ(color.GetRed(), 100);
    EXPECT_EQ(color.GetGreen(), 150);
    EXPECT_EQ(color.GetBlue(), 200);
}

TEST(ColorTest, ConstructorInvalidRed) {
    EXPECT_THROW(Color color(-1, 150, 200), std::invalid_argument);
    EXPECT_THROW(Color color(256, 150, 200), std::invalid_argument);
}

TEST(ColorTest, ConstructorInvalidGreen) {
    EXPECT_THROW(Color color(100, -1, 200), std::invalid_argument);
    EXPECT_THROW(Color color(100, 256, 200), std::invalid_argument);
}

TEST(ColorTest, ConstructorInvalidBlue) {
    EXPECT_THROW(Color color(100, 150, -1), std::invalid_argument);
    EXPECT_THROW(Color color(100, 150, 256), std::invalid_argument);
}

TEST(ColorTest, ToStringMethod) {
    Color color(100, 150, 200);

    std::string expected = "(100, 150, 200)";
    EXPECT_EQ(color.ToString(), expected);
}
