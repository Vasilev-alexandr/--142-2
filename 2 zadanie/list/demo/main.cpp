#include "..//Solver/CircularLinkedList.h"

/**
* @brief ����� ����� � ���������
* @return 0 � ������ ������
*/
int main()
{
    CircularLinkedList list = { 1, 2, 3, 4 };
    std::cout << "Initial list: " << list.toString() << std::endl;
    std::cin >> list;
    std::cout << "After adding 5: " << list.toString() << std::endl;
    return 0;
}