#include <gtest/gtest.h>
#include "pch.h"
#include "..//solver/rectangle.h"

// Тестирование конструктора Rectangle
TEST(RectangleTest, ConstructorValid) {
    Point tl(0, 0);
    Color c(255, 0, 0);
    Rectangle rect(tl, 10, 5, c);
    EXPECT_NO_THROW(rect);
}

TEST(RectangleTest, ConstructorInvalid) {
    Point tl(0, 0);
    Color c(255, 0, 0);
    // Проверка исключения на отрицательную ширину
    EXPECT_THROW(Rectangle rect(tl, -10, 5, c), std::invalid_argument);
    // Проверка исключения на отрицательную высоту
    EXPECT_THROW(Rectangle rect(tl, 10, -5, c), std::invalid_argument);
}

// Тестирование метода ToString
TEST(RectangleTest, ToString) {
    Point tl(2, 3);
    Color c(0, 255, 0);
    Rectangle rect(tl, 8, 4, c);
    EXPECT_EQ(rect.ToString(), "Rectangle: 8x4 at (2, 3) with (0, 255, 0)");
}

// Тестирование оператора вывода
TEST(RectangleTest, OperatorOutput) {
    Point tl(1, 2);
    Color c(0, 0, 255);
    Rectangle rect(tl, 6, 4, c);
    std::ostringstream os;
    os << rect;
    EXPECT_EQ(os.str(), "Rectangle: 6x4 at (1, 2) with (0, 0, 255)");
}