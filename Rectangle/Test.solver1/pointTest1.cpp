#include <gtest/gtest.h>
#include "pch.h"
#include "..//solver/point.h"

// Тест на создание точки с корректными координатами
TEST(PointTest, CreateValidPoint) {
    Point p(3, 4);
    EXPECT_EQ(p.getX(), 3);
    EXPECT_EQ(p.getY(), 4);
}

// Тест на создание точки с некорректными координатами
TEST(PointTest, CreateInvalidPoint) {
    EXPECT_THROW(Point(-1, 5), std::invalid_argument);
    EXPECT_THROW(Point(5, -1), std::invalid_argument);
}

// Тест на оператор вывода
TEST(PointTest, OutputOperator) {
    Point p(2, 3);
    std::ostringstream oss;
    oss << p;
    EXPECT_EQ(oss.str(), "(2, 3)");
}

// Тест на метод ToString
TEST(PointTest, ToStringMethod) {
    Point p(5, 6);
    EXPECT_EQ(p.ToString(), "(5, 6)");
}

// Тест на оператор сравнения
TEST(PointTest, EqualityOperator) {
    Point p1(1, 2);
    Point p2(1, 2);
    Point p3(2, 3);
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

// Функция запуска всех тестов
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}