#include <sstream>
#include "Color.h"
#include "Shape.h"

Color::Color(int r, int g, int b)
{
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        throw std::invalid_argument("Color values must be between 0 and 255");
    red = r; green = g; blue = b;
}

bool Color::operator==(const Color& other) const
{
    return m_r == other.m_r && m_g == other.m_g && m_b == other.m_b;
}

std::string Color::ToString() const
{
    return "(" + std::to_string(red) + ", " + std::to_string(green) + ", " + std::to_string(blue) + ")";
}

std::ostream& operator<<(std::ostream& os, const Color& color)
{
    os << "Color(" << (int)color.red << ", " << (int)color.green << ", " << (int)color.blue << ")";
    return os;
}