#include <sstream>
#include "Point.h"

Point::Point(int x, int y)
{
    if (x < 0 || y < 0) {
        throw std::invalid_argument("Incorrect coordinates!\n");
    }
    this->m_x = x;
    this->m_y = y;
}

int Point::getX() const {
    return m_x;
}

int Point::getY() const {
    return m_y;
}

std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << "(" << point.m_x << ", " << point.m_y << ")";
    return os;
}

std::string Point::ToString() const
{
    std::stringstream buffer{};
    buffer << "(" + std::to_string(m_x) + ", " + std::to_string(m_y) + ")";
    return buffer.str();
}

bool Point::operator==(const Point& other) const
{
    return m_x == other.m_x && m_y == other.m_y;
}