#include <iostream>

/**
 * @brief �����, �������������� ����� �� ���������.
 * ������ ���������� ����� (x, y).
 */
class Point
{
    /**
     * @brief ���������� m_x �����.
     * @brief ���������� m_y �����.
     */
    int m_x, m_y;

public:

    /**
     * @brief ����������� ������ Point.
     * ������� ������ Point � ��������� ������������.
     * @param x ���������� x �����.
     * @param y ���������� y �����.
     */
    Point(int x, int y);

    /**
     * @brief ���������� ���������� x �����.
     * @return ���������� x �����.
     */
    int getX() const;

    /**
     * @brief ���������� ���������� y �����.
     * @return ���������� y �����.
     */
    int getY() const;

    /**
    * @brief ������������� �������� ������ ��� ������� Point.
    * ��������� �������� ������ Point � ����� ������ (��������, � �������).
    * @param os ����� ������.
    * @param point ������ Point.
    * @return ����� ������.
    */
    friend std::ostream& operator<<(std::ostream& os, const Point& point);

    /**
    * @brief ���������� ��������� ������������� ������� Point.
    * @return ������, �������������� ����� � ������� "(x, y)".
    */
    std::string ToString() const;

    /**
    * @brief ������������� �������� ��������� ��� �������� Point.
    * ���������� ��� ����� �� ���������.
    * @param other ����� ��� ���������.
    * @return true, ���� ����� �����, ����� false.
    */
    bool operator==(const Point& other) const;
};