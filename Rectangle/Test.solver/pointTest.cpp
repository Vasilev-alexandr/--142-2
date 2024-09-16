#include "pch.h"
#include "CppUnitTest.h"
#include "..//solver/point.h"
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace pointTests
{
    TEST_CLASS(pointTests)
    {
    public:

        /**
        * @brief Тест конструктора с валидными координатами.
        * Проверяет, что конструктор Point(int x, int y) правильно инициализирует объект Point с заданными значениями координат x и y.
        */
        TEST_METHOD(TestConstructor_ValidCoordinates)
        {
            Point p(3, 4);
            Assert::AreEqual(3, p.getX());
            Assert::AreEqual(4, p.getY());
        }

        /**
        * @brief Тест конструктора с невалидным значением координаты x.
        * Проверяет, что конструктор Point(int x, int y) бросает исключение std::invalid_argument,если значение координаты x отрицательное.
        */
        TEST_METHOD(TestConstructor_InvalidX)
        {
            Assert::ExpectException<std::invalid_argument>([] { Point p(-1, 2); });
        }

        /**
        * @brief Тест конструктора с невалидным значением координаты y.
        * Проверяет, что конструктор Point(int x, int y) бросает исключение std::invalid_argument,если значение координаты y отрицательное.
        */
        TEST_METHOD(TestConstructor_InvalidY)
        {
            Assert::ExpectException<std::invalid_argument>([] { Point p(1, -2); });
        }

        /**
        * @brief Тест оператора равенства (==) для объектов Point.
        * Проверяет, что оператор == корректно сравнивает две точки на равенство. Две точки считаются равными, если их координаты x и y совпадают.
        */
        TEST_METHOD(TestEqualityOperator)
        {
            Point p1(3, 4);
            Point p2(3, 4);
            Point p3(5, 6);
            Assert::IsTrue(p1 == p2);
            Assert::IsFalse(p1 == p3);
        }

        /**
        * @brief Тест метода ToString() для объекта Point.
        * Проверяет, что метод ToString() правильно возвращает строковое представление точки в формате "(x, y)".
        */
        TEST_METHOD(TestToString)
        {
            Point p(3, 4);
            Assert::AreEqual(std::string("(3, 4)"), p.ToString());
        }

        /**
        * @brief Тест перегруженного оператора вывода (<<) для объекта Point.
        * Проверяет, что оператор << корректно выводит точку в поток вывода в формате "(x, y)".
        */
        TEST_METHOD(TestOutputOperator)
        {
            Point p(5, 6);
            std::ostringstream os;
            os << p;
            Assert::AreEqual(std::string("(5, 6)"), os.str());
        }
    };
}