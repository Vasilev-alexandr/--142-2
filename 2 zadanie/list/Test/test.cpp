#include "pch.h"
#include <gtest/gtest.h>
#include "..//Solver/CircularLinkedList.h"

TEST(CircularLinkedListTest, DefaultConstructor) {
    CircularLinkedList list;
    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.toString(), "[]");
}

TEST(CircularLinkedListTest, AddElements) {
    CircularLinkedList list;
    list.add(1);
    list.add(2);
    list.add(3);

    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.toString(), "[3 1 2]");
}

TEST(CircularLinkedListTest, CopyConstructor) {
    CircularLinkedList list1;
    list1.add(1);
    list1.add(2);
    list1.add(3);

    CircularLinkedList list2(list1);
    EXPECT_EQ(list2.toString(), "[3 1 2]");
}

TEST(CircularLinkedListTest, InitializerList) {
    CircularLinkedList list = { 1, 2, 3 };
    EXPECT_EQ(list.toString(), "[3 1 2]");
}

TEST(CircularLinkedListTest, AssignmentOperator) {
    CircularLinkedList list1;
    list1.add(1);
    list1.add(2);

    CircularLinkedList list2;
    list2 = list1;

    EXPECT_EQ(list2.toString(), "[2 1]");
}

TEST(CircularLinkedListTest, MoveConstructor) {
    CircularLinkedList list1;
    list1.add(1);
    list1.add(2);

    CircularLinkedList list2(std::move(list1));
    EXPECT_EQ(list2.toString(), "[2 1]");
    EXPECT_TRUE(list1.isEmpty());
}

TEST(CircularLinkedListTest, MoveAssignmentOperator) {
    CircularLinkedList list1;
    list1.add(1);
    list1.add(2);

    CircularLinkedList list2;
    list2 = std::move(list1);

    EXPECT_EQ(list2.toString(), "[2 1]");
    EXPECT_TRUE(list1.isEmpty());
}

TEST(CircularLinkedListTest, GetHeadValue) {
    CircularLinkedList list;
    list.add(1);
    list.add(2);

    int value;
    list >> value;
    EXPECT_EQ(value, 1);
}

TEST(CircularLinkedListTest, Destructor) {
    {
        CircularLinkedList list;
        list.add(1);
        list.add(2);
        list.add(3);
    }
}