#include "Rectangle.h"

Rectangle::Rectangle(Point tl, int w, int h, Color c) : m_topLeft(tl), m_width(w), m_height(h), m_color(c)
{
    if (w < 0 || h < 0) throw std::invalid_argument("Width and height must be non-negative");
}

std::string Rectangle::ToString() const
{
    return "Rectangle: " + std::to_string(GetWidth()) + "x" + std::to_string(GetHeight()) + " at " + m_topLeft.ToString() + " with " + m_color.ToString();
}

Rectangle Rectangle::Read()
{
    return Rectangle(Point(0, 0), 10, 5, Color(255, 0, 0));
}


std::ostream& operator<<(std::ostream& os, const Rectangle& rect)
{
    os << rect.ToString();
    return os;
}