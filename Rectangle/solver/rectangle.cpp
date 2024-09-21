#include "Rectangle.h"
#include <sstream>

Rectangle::Rectangle(Point tl, int w, int h, Color c) : m_topLeft(tl), m_width(w), m_height(h), m_color(c)
{
    if (w < 0 || h < 0) throw std::invalid_argument("Width and height must be non-negative");
}

std::string Rectangle::ToString() const
{
    std::stringstream buffer{};
    buffer << "Rectangle: " << GetWidth() << "x" << GetHeight()
        << " at " << m_topLeft << " with " << m_color.ToString();
    return buffer.str();
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