#include "CircularLinkedList.h"

CircularLinkedList::CircularLinkedList() : head(nullptr), tail(nullptr) {}


CircularLinkedList::CircularLinkedList(const CircularLinkedList& other)
{
    head = tail = nullptr;
    Node* current = other.head;
    if (current) {
        do {
            add(current->data);
            current = current->next;
        } while (current != other.head);
    }
}

CircularLinkedList::CircularLinkedList(std::initializer_list<int> init) : tail(nullptr)
{
    for (int value : init)
    {
        add(value);
    }
}

CircularLinkedList::~CircularLinkedList()
{
    if (tail == nullptr) {
        return;
    }

    Node* current = tail->next;
    Node* nextNode;

    do {
        nextNode = current->next;
        current = nextNode;
    } while (current != tail->next);

    tail = nullptr;
}

void CircularLinkedList::add(int value)
{
    Node* newNode = new Node(value);
    if (tail != nullptr)
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
    std::stringstream buffer;

    if (tail == nullptr) {
        return "[]";
    }

    buffer << "[";
    Node* current = tail->next;

    do {
        buffer << current->data;
        current = current->next;

        if (current != tail->next) {
            buffer << " ";
        }
    } while (current != tail->next);

    buffer << "]";
    return buffer.str();
}

CircularLinkedList& CircularLinkedList::operator=(const CircularLinkedList& other)
{
    if (this == &other)
    {
        return *this;
    }

    return *this;
}

CircularLinkedList& CircularLinkedList::operator<<(int value)
{
    add(value);
    return *this;
}

CircularLinkedList& CircularLinkedList::operator>>(int& value)

{
    if (head)
    {
        value = head->data;
    }
    return *this;
}


CircularLinkedList::CircularLinkedList(CircularLinkedList&& other) noexcept : head(other.head), tail(other.tail)
{
    other.head = other.tail = nullptr;
}


CircularLinkedList& CircularLinkedList::operator=(CircularLinkedList&& other) noexcept
{
    if (this == &other)
    {
        return *this;
    }
    head = other.head;
    tail = other.tail;
    other.head = other.tail = nullptr;

    return *this;
}