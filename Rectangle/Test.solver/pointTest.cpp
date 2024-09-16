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
        * @brief ���� ������������ � ��������� ������������.
        * ���������, ��� ����������� Point(int x, int y) ��������� �������������� ������ Point � ��������� ���������� ��������� x � y.
        */
        TEST_METHOD(TestConstructor_ValidCoordinates)
        {
            Point p(3, 4);
            Assert::AreEqual(3, p.getX());
            Assert::AreEqual(4, p.getY());
        }

        /**
        * @brief ���� ������������ � ���������� ��������� ���������� x.
        * ���������, ��� ����������� Point(int x, int y) ������� ���������� std::invalid_argument,���� �������� ���������� x �������������.
        */
        TEST_METHOD(TestConstructor_InvalidX)
        {
            Assert::ExpectException<std::invalid_argument>([] { Point p(-1, 2); });
        }

        /**
        * @brief ���� ������������ � ���������� ��������� ���������� y.
        * ���������, ��� ����������� Point(int x, int y) ������� ���������� std::invalid_argument,���� �������� ���������� y �������������.
        */
        TEST_METHOD(TestConstructor_InvalidY)
        {
            Assert::ExpectException<std::invalid_argument>([] { Point p(1, -2); });
        }

        /**
        * @brief ���� ��������� ��������� (==) ��� �������� Point.
        * ���������, ��� �������� == ��������� ���������� ��� ����� �� ���������. ��� ����� ��������� �������, ���� �� ���������� x � y ���������.
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
        * @brief ���� ������ ToString() ��� ������� Point.
        * ���������, ��� ����� ToString() ��������� ���������� ��������� ������������� ����� � ������� "(x, y)".
        */
        TEST_METHOD(TestToString)
        {
            Point p(3, 4);
            Assert::AreEqual(std::string("(3, 4)"), p.ToString());
        }

        /**
        * @brief ���� �������������� ��������� ������ (<<) ��� ������� Point.
        * ���������, ��� �������� << ��������� ������� ����� � ����� ������ � ������� "(x, y)".
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