#include <sstream>
#include "Color.h"
#include "Shape.h"

Color::Color(int r, int g, int b)
{
    if (r < min || r > max || g < min || g > max || b < min || b > max)
        throw std::invalid_argument("Color values must be between 0 and 255");
    this->red = static_cast<unsigned int>(r);
    this->green = static_cast<unsigned int>(g);
    this->blue = static_cast<unsigned int>(b);
}

std::string Color::ToString() const
{
    std::stringstream buffer{};
    buffer << "(" << red << ", " << green << ", " << blue << ")";
    return buffer.str();
}

int Color::GetRed() const { return red; }
int Color::GetGreen() const { return green; }
int Color::GetBlue() const { return blue; }
