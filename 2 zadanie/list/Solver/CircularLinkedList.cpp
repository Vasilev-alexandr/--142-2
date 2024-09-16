#include "CircularLinkedList.h"

CircularLinkedList::CircularLinkedList() : tail(nullptr) {}

CircularLinkedList::CircularLinkedList(std::initializer_list<int> init) : tail(nullptr)
{
    for (int value : init)
    {
        add(value);
    }
}

CircularLinkedList::~CircularLinkedList() {}

void CircularLinkedList::add(int value)
{
    Node* newNode = new Node(value);
    if (!tail)
    {
        tail = newNode;
        tail->next = tail;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

bool CircularLinkedList::isEmpty() const
{
    return tail == nullptr;
}

std::string CircularLinkedList::toString() const
{
    if (isEmpty()) return "[]";
    std::string result = "[";
    Node* current = tail->next;
    do
    {
        result += std::to_string(current->data) + " ";
        current = current->next;
    } while (current != tail->next);
    result += "]";
    return result;
}

CircularLinkedList& CircularLinkedList::operator=(const CircularLinkedList& other)
{
    return *this;
}

CircularLinkedList& CircularLinkedList::operator<<(int value)
{
    add(value);
    return *this;
}

CircularLinkedList& CircularLinkedList::operator>>(int& value)
{
    return *this;
}