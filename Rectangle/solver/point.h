#include <iostream>

/**
 * @brief Класс, представляющий точку на плоскости.
 * Хранит координаты точки (x, y).
 */
class Point final
{
    /**
     * @brief Координата m_x точки.
     * @brief Координата m_y точки.
     */
    int m_x, m_y;
    
    int size;

public:

    /**
     * @brief Конструктор класса Point.
     * Создает объект Point с заданными координатами.
     * @param x Координата x точки.
     * @param y Координата y точки.
     */
    Point(int x, int y);

    /**
     * @brief Возвращает координату x точки.
     * @return Координата x точки.
     */
    int getX() const;

    /**
     * @brief Возвращает координату y точки.
     * @return Координата y точки.
     */
    int getY() const;

    /**
    * @brief Перегруженный оператор вывода для объекта Point.
    * Позволяет выводить объект Point в поток вывода (например, в консоль).
    * @param os Поток вывода.
    * @param point Объект Point.
    * @return Поток вывода.
    */
    friend std::ostream& operator<<(std::ostream& os, const Point& point);

    /**
    * @brief Возвращает строковое представление объекта Point.
    * @return Строка, представляющая точку в формате "(x, y)".
    */
    std::string ToString() const;

    /**
    * @brief Перегруженный оператор сравнения для объектов Point.
    * Сравнивает две точки на равенство.
    * @param other Точка для сравнения.
    * @return true, если точки равны, иначе false.
    */
    bool operator==(const Point& other) const;
};