#include "CppUnitTest.h"
#include "..//Solver/CircularLinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CircularLinkedListTests
{
    TEST_CLASS(UnitTests)
    {
    public:
        /**
         * @brief ���� ������ add().
         * ���������, ��� ����� add() ��������� ��������� �������� � ����������� ������.
         */
        TEST_METHOD(TestAdd)
        {
            CircularLinkedList list;
            list.add(10);
            Assert::AreEqual(std::string("[10 ]"), list.toString());
            list.add(20);
            Assert::AreEqual(std::string("[10 20 ]"), list.toString());
            list.add(30);
            Assert::AreEqual(std::string("[10 20 30 ]"), list.toString());
        }
        /**
         * @brief ���� ������ isEmpty().
         * ���������, ��� ����� isEmpty() ��������� ����������, ���� �� ������.
         */
        TEST_METHOD(TestIsEmpty)
        {
            CircularLinkedList list;
            Assert::IsTrue(list.isEmpty());
            list.add(10);
            Assert::IsFalse(list.isEmpty());
        }
        /**
         * @brief ���� ������������ �������������.
         * ���������, ��� ����������� ������������� ��������� ������� ����������� ������ � ��������� ����������.
         */
        TEST_METHOD(TestInitList)
        {
            CircularLinkedList list = { 10, 20, 30 };
            Assert::AreEqual(std::string("[10 20 30 ]"), list.toString());
        }
        /**
         * @brief ���� ��������� ������������.
         * ���������, ��� �������� ������������ (=) ��������� �������� �������� �� ������ ������ � ������.
         */
        TEST_METHOD(TestAssignmentOperator)
        {
            CircularLinkedList list1;
            list1.add(5);
            CircularLinkedList list2;
            list2 = list1;
            Assert::AreEqual(std::string("[]"), list2.toString());
        }
        /**
         * @brief ���� ��������� �������.
         * ���������, ��� �������� ������� (<<) ��������� ��������� �������� � ������.
         */
        TEST_METHOD(TestInsertionOperator)
        {
            CircularLinkedList list;
            list << 10 << 20 << 30;
            Assert::AreEqual(std::string("[10 20 30 ]"), list.toString());
        }
        /**
         * @brief ���� ������ toString() ��� ������� ������.
         * ���������, ��� ����� toString() ��������� ���������� ��������� ������������� ������� ������.
         */
        TEST_METHOD(TestEdgeCaseEmptyToString)
        {
            CircularLinkedList list;
            Assert::AreEqual(std::string("[]"), list.toString());
        }
    };
}