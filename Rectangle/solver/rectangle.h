#include "Point.h"
#include "Color.h"
#include "Shape.h"
#include <string>

/**
 * @brief Класс, представляющий прямоугольник.
 * Наследуется от класса Shape.
 */
class Rectangle final : public Shape
{
    /**
     * @brief Точка верхнего левого угла прямоугольника.
     */
    Point m_topLeft;

    /**
     * @brief Ширина прямоугольника.
     * @brief Высота прямоугольника.
     */
    unsigned int m_width, m_height;

    /**
    * @brief Цвет прямоугольника.
    */
    Color m_color;


public:

    /**
    * @brief Возвращает ширину прямоугольника.
    * @return Ширина прямоугольника.
    */
    unsigned int GetWidth() const { return m_width; };

    /**
     * @brief Возвращает высоту прямоугольника.
     * @return Высота прямоугольника.
     */
    unsigned int GetHeight() const { return m_height; };

    /**
    * @brief Конструктор класса Rectangle.
    * Создает объект Rectangle с заданными параметрами.
    * @param tl Точка верхнего левого угла прямоугольника.
    * @param w Ширина прямоугольника.
    * @param h Высота прямоугольника.
    * @param c Цвет прямоугольника.
    */
    Rectangle(Point tl, int w, int h, Color c);

    ~Rectangle() = default;

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