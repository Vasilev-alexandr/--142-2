#include "Point.h"
#include "Color.h"
#include "Shape.h"
#include <string>

/**
 * @brief �����, �������������� �������������.
 * ����������� �� ������ Shape.
 */
class Rectangle : public Shape
{
    /**
     * @brief ����� �������� ������ ���� ��������������.
     */
    Point m_topLeft;

    /**
     * @brief ������ ��������������.
     * @brief ������ ��������������.
     */
    int m_width, m_height;

    /**
    * @brief ���� ��������������.
    */
    Color m_color;

public:

    /**
    * @brief ���������� ������ ��������������.
    * @return ������ ��������������.
    */
    int GetWidth() const { return m_width; };

    /**
     * @brief ���������� ������ ��������������.
     * @return ������ ��������������.
     */
    int GetHeight() const { return m_height; };

    /**
     * @brief ���������� ����� �������� ������ ���� ��������������.
     * @return ����� �������� ������ ���� ��������������.
     */
    Point GetTopLeft() const { return m_topLeft; };

    /**
     * @brief ���������� ���� ��������������.
     * @return ���� ��������������.
     */
    Color GetColor() const { return m_color; };

    /**
    * @brief ����������� ������ Rectangle.
    * ������� ������ Rectangle � ��������� �����������.
    * @param tl ����� �������� ������ ���� ��������������.
    * @param w ������ ��������������.
    * @param h ������ ��������������.
    * @param c ���� ��������������.
    */
    Rectangle(Point tl, int w, int h, Color c);

    /**
     * @brief ���������� ��������� ������������� ��������������.
     * �������������� ����� ToString() �� �������� ������ Shape.
     * @return ��������� ������������� ��������������.
     */
    std::string ToString() const override;

    /**
     * @brief ����������� �����, �������� ������������� �� ������������ ������ �����.
     * @return ������ Rectangle, ����������� �� ������������ ������ �����.
     */
    static Rectangle Read();

    /**
     * @brief ������������� �������� ������ ��� ������� Rectangle.
     * ��������� �������� ������ Rectangle � ����� ������ (��������, � �������).
     * @param os ����� ������.
     * @param rect ������ Rectangle.
     * @return ����� ������.
     */
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect);
};