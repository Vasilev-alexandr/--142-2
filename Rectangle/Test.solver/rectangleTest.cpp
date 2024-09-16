#include "pch.h"
#include "CppUnitTest.h"
#include "..//solver/rectangle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace rectangleTests
{
    TEST_CLASS(rectangleTests)
    {
    public:

        /**
         * @brief Тест конструктора Rectangle с валидными значениями
         * Проверяет, что конструктор Rectangle(Point tl, int w, int h, Color c) правильно инициализирует объект Rectangle с заданными значениями для точки верхнего левого угла, ширины, высоты и цвета.
         */
        TEST_METHOD(TestConstructValidRectangle)
        {
            Point topLeft(0, 0);
            Color color(255, 0, 0);
            Rectangle rect(topLeft, 10, 5, color);
            Assert::AreEqual(10, rect.GetWidth());
            Assert::AreEqual(5, rect.GetHeight());
            Assert::AreEqual(topLeft.ToString(), rect.GetTopLeft().ToString());
            std::string expectedColorStr = color.ToString();
            Assert::IsTrue(expectedColorStr == rect.GetColor().ToString());
        }

        /**
         * @brief Тест конструктора Rectangle с невалидными значениями
         * Проверяет, что конструктор Rectangle(Point tl, int w, int h, Color c) бросает исключение std::invalid_argument, если значения ширины или высоты отрицательны.
         */
        TEST_METHOD(TestConstructInvalidRectangle)
        {
            Point topLeft(0, 0);
            Color color(255, 0, 0);
            Assert::ExpectException<std::invalid_argument>([&]()
                {
                    Rectangle rect(topLeft, -1, 5, color);
                });
            Assert::ExpectException<std::invalid_argument>([&]()
                {
                    Rectangle rect(topLeft, 10, -1, color);
                });
        }

        /**
         * @brief Тест метода ToString() для объекта Rectangle
         * Проверяет, что метод ToString() правильно возвращает строковое представление прямоугольника в формате "Rectangle: w x h at (x, y) with (r, g, b)".
         */
        TEST_METHOD(TestToString)
        {
            Point topLeft(0, 0);
            Color color(255, 0, 0);
            Rectangle rect(topLeft, 10, 5, color);
            std::string expected = "Rectangle: 10x5 at " + topLeft.ToString() + " with " + color.ToString();
            Assert::AreEqual(expected, rect.ToString());
        }

        /**
         * @brief Тест перегруженного оператора вывода (<<) для объекта Rectangle.
         * Проверяет, что оператор << корректно выводит прямоугольник в поток вывода в формате "Rectangle: w x h at (x, y) with (r, g, b)".
         */
        TEST_METHOD(TestOutputOperator)
        {
            Point topLeft(0, 0);
            Color color(255, 0, 0);
            Rectangle rect(topLeft, 10, 5, color);
            std::ostringstream oss;
            oss << rect;
            std::string expected = "Rectangle: 10x5 at " + topLeft.ToString() + " with " + color.ToString();
            Assert::AreEqual(expected, oss.str());
        }

        /**
         * @brief Тест статического метода Read() для объекта Rectangle.
         * Проверяет, что метод Read() правильно читает прямоугольник из стандартного потока ввода и возвращает объект Rectangle с соответствующими параметрами.
         */
        TEST_METHOD(TestReadMethod)
        {
            Rectangle rect = Rectangle::Read();
            Assert::AreEqual(10, rect.GetWidth());
            Assert::AreEqual(5, rect.GetHeight());
            Assert::AreEqual(Point(0, 0).ToString(), rect.GetTopLeft().ToString());
            Assert::AreEqual(Color(255, 0, 0).ToString(), rect.GetColor().ToString());
        }
    };
}