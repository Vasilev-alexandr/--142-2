#include "Point.h"
#include "Color.h"
#include "Shape.h"
#include <string>

/**
 * @brief Класс, представляющий прямоугольник.
 * Наследуется от класса Shape.
 */
class Rectangle : public Shape
{
    /**
     * @brief Точка верхнего левого угла прямоугольника.
     */
    Point m_topLeft;

    /**
     * @brief Ширина прямоугольника.
     * @brief Высота прямоугольника.
     */
    int m_width, m_height;

    /**
    * @brief Цвет прямоугольника.
    */
    Color m_color;

public:

    /**
    * @brief Возвращает ширину прямоугольника.
    * @return Ширина прямоугольника.
    */
    int GetWidth() const { return m_width; };

    /**
     * @brief Возвращает высоту прямоугольника.
     * @return Высота прямоугольника.
     */
    int GetHeight() const { return m_height; };

    /**
     * @brief Возвращает точку верхнего левого угла прямоугольника.
     * @return Точка верхнего левого угла прямоугольника.
     */
    Point GetTopLeft() const { return m_topLeft; };

    /**
     * @brief Возвращает цвет прямоугольника.
     * @return Цвет прямоугольника.
     */
    Color GetColor() const { return m_color; };

    /**
    * @brief Конструктор класса Rectangle.
    * Создает объект Rectangle с заданными параметрами.
    * @param tl Точка верхнего левого угла прямоугольника.
    * @param w Ширина прямоугольника.
    * @param h Высота прямоугольника.
    * @param c Цвет прямоугольника.
    */
    Rectangle(Point tl, int w, int h, Color c);

    /**
     * @brief Возвращает строковое представление прямоугольника.
     * Переопределяет метод ToString() из базового класса Shape.
     * @return Строковое представление прямоугольника.
     */
    std::string ToString() const override;

    /**
     * @brief Статический метод, читающий прямоугольник из стандартного потока ввода.
     * @return Объект Rectangle, прочитанный из стандартного потока ввода.
     */
    static Rectangle Read();

    /**
     * @brief Перегруженный оператор вывода для объекта Rectangle.
     * Позволяет выводить объект Rectangle в поток вывода (например, в консоль).
     * @param os Поток вывода.
     * @param rect Объект Rectangle.
     * @return Поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect);
};