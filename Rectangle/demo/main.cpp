#include "../solver/rectangle.h"

/**
* @brief ����� ����� � ���������
* @return 0 � ������ ������
*/
int main()
{
    Point p1{ 0, 0 };
    Color c1(255, 0, 0);
    Rectangle rect(p1, 10, 5, c1);

    std::cout << rect << std::endl;

    return 0;
}