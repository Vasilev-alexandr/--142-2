#include <sstream>
#include "Color.h"
#include "Shape.h"

Color::Color(int r, int g, int b)
{
    const int min = 0;
    const int max = 255;
    if (r < min || r > max || g < min || g > max || b < min || b > max)
        throw std::invalid_argument("Color values must be between 0 and 255");
    red = r; green = g; blue = b;
}

std::string Color::ToString() const
{
    std::stringstream buffer{};
    for (size_t i = 0; i < size; ++i)
    {
        buffer << "(" + std::to_string(red) + ", " + std::to_string(green) + ", " + std::to_string(blue) + ")";
    }
    return buffer.str();
}