#include "pch.h"
#include "CppUnitTest.h"
#include "..//solver/color.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace colorTests
{
    TEST_CLASS(colorTest)
    {
    public:

        /**
         * @brief Тест конструктора Color с валидными значениями.
         * Проверяет, что конструктор Color(int r, int g, int b) правильно инициализирует объект Color с заданными значениями для красного, зеленого и синего каналов.
         */
        TEST_METHOD(TestColorConstructorValid)
        {
            Color color(100, 150, 200);
            Assert::AreEqual(static_cast<uint8_t>(100), color.getRed());
            Assert::AreEqual(static_cast<uint8_t>(150), color.getGreen());
            Assert::AreEqual(static_cast<uint8_t>(200), color.getBlue());
        }

        /**
         * @brief Тест конструктора Color с невалидными значениями.
         * Проверяет, что конструктор Color(int r, int g, int b) бросает исключение std::invalid_argument, если значения каналов выходят за пределы допустимого диапазона (от 0 до 255).
         */
        TEST_METHOD(TestColorConstructorInvalid)
        {
            Assert::ExpectException<std::invalid_argument>([]() { Color color(-1, 0, 0); });
            Assert::ExpectException<std::invalid_argument>([]() { Color color(0, 256, 0); });
            Assert::ExpectException<std::invalid_argument>([]() { Color color(0, 0, -1); });
            Assert::ExpectException<std::invalid_argument>([]() { Color color(256, 255, 255); });
        }

        /**
         * @brief Тест метода ToString() для объекта Color.
         * Проверяет, что метод ToString() правильно возвращает строковое представление цвета в формате "(r, g, b)".
         */
        TEST_METHOD(TestColorToString)
        {
            Color color(100, 150, 200);
            Assert::AreEqual(std::string("(100, 150, 200)"), color.ToString());
        }

        /**
         * @brief Тест перегруженного оператора вывода (<<) для объекта Color.
         * Проверяет, что оператор << корректно выводит цвет в поток вывода в формате "Color(r, g, b)".
         */
        TEST_METHOD(TestColorOutputStream)
        {
            Color color(100, 150, 200);
            std::ostringstream os;
            os << color;
            Assert::AreEqual(std::string("Color(100, 150, 200)"), os.str());
        }
    };
}