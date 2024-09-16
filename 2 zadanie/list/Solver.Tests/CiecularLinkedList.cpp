#include "CppUnitTest.h"
#include "..//Solver/CircularLinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CircularLinkedListTests
{
    TEST_CLASS(UnitTests)
    {
    public:
        /**
         * @brief “ест метода add().
         * ѕровер€ет, что метод add() правильно добавл€ет элементы в циклический список.
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
         * @brief “ест метода isEmpty().
         * ѕровер€ет, что метод isEmpty() правильно определ€ет, пуст ли список.
         */
        TEST_METHOD(TestIsEmpty)
        {
            CircularLinkedList list;
            Assert::IsTrue(list.isEmpty());
            list.add(10);
            Assert::IsFalse(list.isEmpty());
        }
        /**
         * @brief “ест конструктора инициализации.
         * ѕровер€ет, что конструктор инициализации правильно создает циклический список с заданными значени€ми.
         */
        TEST_METHOD(TestInitList)
        {
            CircularLinkedList list = { 10, 20, 30 };
            Assert::AreEqual(std::string("[10 20 30 ]"), list.toString());
        }
        /**
         * @brief “ест оператора присваивани€.
         * ѕровер€ет, что оператор присваивани€ (=) правильно копирует значени€ из одного списка в другой.
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
         * @brief “ест оператора вставки.
         * ѕровер€ет, что оператор вставки (<<) правильно добавл€ет элементы в список.
         */
        TEST_METHOD(TestInsertionOperator)
        {
            CircularLinkedList list;
            list << 10 << 20 << 30;
            Assert::AreEqual(std::string("[10 20 30 ]"), list.toString());
        }
        /**
         * @brief “ест метода toString() дл€ пустого списка.
         * ѕровер€ет, что метод toString() правильно возвращает строковое представление пустого списка.
         */
        TEST_METHOD(TestEdgeCaseEmptyToString)
        {
            CircularLinkedList list;
            Assert::AreEqual(std::string("[]"), list.toString());
        }
    };
}