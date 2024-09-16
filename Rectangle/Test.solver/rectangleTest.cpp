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
         * @brief ���� ������������ Rectangle � ��������� ����������
         * ���������, ��� ����������� Rectangle(Point tl, int w, int h, Color c) ��������� �������������� ������ Rectangle � ��������� ���������� ��� ����� �������� ������ ����, ������, ������ � �����.
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
         * @brief ���� ������������ Rectangle � ����������� ����������
         * ���������, ��� ����������� Rectangle(Point tl, int w, int h, Color c) ������� ���������� std::invalid_argument, ���� �������� ������ ��� ������ ������������.
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
         * @brief ���� ������ ToString() ��� ������� Rectangle
         * ���������, ��� ����� ToString() ��������� ���������� ��������� ������������� �������������� � ������� "Rectangle: w x h at (x, y) with (r, g, b)".
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
         * @brief ���� �������������� ��������� ������ (<<) ��� ������� Rectangle.
         * ���������, ��� �������� << ��������� ������� ������������� � ����� ������ � ������� "Rectangle: w x h at (x, y) with (r, g, b)".
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
         * @brief ���� ������������ ������ Read() ��� ������� Rectangle.
         * ���������, ��� ����� Read() ��������� ������ ������������� �� ������������ ������ ����� � ���������� ������ Rectangle � ���������������� �����������.
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