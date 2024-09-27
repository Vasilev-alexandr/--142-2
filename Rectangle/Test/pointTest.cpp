#include <gtest/gtest.h>
#include "..//solver/point.h"
#include <stdexcept>

TEST(PointTest, ConstructorValidParameters) {
    Point point(3, 4);
    EXPECT_EQ(point.getX(), 3);
    EXPECT_EQ(point.getY(), 4);
}

TEST(PointTest, ConstructorInvalidParameters) {
    EXPECT_THROW(Point point(-1, 4), std::invalid_argument);
    EXPECT_THROW(Point point(3, -2), std::invalid_argument);
}

TEST(PointTest, ToStringMethod) {
    Point point(3, 4);
    EXPECT_EQ(point.ToString(), "(3, 4)");
}

TEST(PointTest, OutputOperator) {
    Point point(3, 4);
    std::stringstream output;
    output << point;
    EXPECT_EQ(output.str(), "(3, 4)");
}

TEST(PointTest, EqualityOperator) {
    Point point1(3, 4);
    Point point2(3, 4);
    Point point3(5, 6);

    EXPECT_TRUE(point1 == point2);
    EXPECT_FALSE(point1 == point3);
}
