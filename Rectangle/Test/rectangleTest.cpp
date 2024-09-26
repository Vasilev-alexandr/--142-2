#include "gtest/gtest.h"
#include "..//solver/rectangle.h"

TEST(RectangleTest, ConstructorAndToString) {
    Point topLeft(0, 0);
    Color color(255, 0, 0);
    Rectangle rect(topLeft, 10, 5, color);

    EXPECT_EQ(rect.GetWidth(), 10);
    EXPECT_EQ(rect.GetHeight(), 5);
    EXPECT_EQ(rect.ToString(), "Rectangle: 10x5 at (0, 0) with Color(255, 0, 0)");
}

TEST(RectangleTest, ConstructorThrowsOnNegativeWidth) {
    Point topLeft(0, 0);
    Color color(255, 0, 0);

    EXPECT_THROW(Rectangle rect(topLeft, -1, 5, color), std::invalid_argument);
}

TEST(RectangleTest, ConstructorThrowsOnNegativeHeight) {
    Point topLeft(0, 0);
    Color color(255, 0, 0);

    EXPECT_THROW(Rectangle rect(topLeft, 10, -1, color), std::invalid_argument);
}

TEST(RectangleTest, ReadMethod) {
    Rectangle rect = Rectangle::Read();
    EXPECT_EQ(rect.GetWidth(), 10);
    EXPECT_EQ(rect.GetHeight(), 5);
    EXPECT_EQ(rect.ToString(), "Rectangle: 10x5 at (0, 0) with Color(255, 0, 0)");
}

TEST(RectangleTest, OutputStreamOperator) {
    Point topLeft(1, 1);
    Color color(0, 255, 0);
    Rectangle rect(topLeft, 2, 3, color);

    std::stringstream ss;
    ss << rect;
    EXPECT_EQ(ss.str(), "Rectangle: 2x3 at (1, 1) with Color(0, 255, 0)");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}