#include <iostream>

/**
 * @brief  класс, представл¤ющий цвет в формате RGB.
 * хранит значени¤ красного, зеленого и синего каналов в диапазоне от 0 до 255.
 */
class Color final
{
    /**
     * @brief значение красного канала (от 0 до 255).
     * @brief значение зеленого канала (от 0 до 255).
     * @brief значение синего канала (от 0 до 255).
     */
    unsigned int red, green, blue;

    const int min = 0;
    const int max = 255;

public:

    /**
     * @brief  конструктор класса Color.
     * создает объект Color с заданными значени¤ми дл¤ красного, зеленого и синего каналов.
     * @param r значение красного канала (от 0 до 255).
     * @param g значение зеленого канала (от 0 до 255).
     * @param b значение синего канала (от 0 до 255).
     */
    Color(int r, int g, int b);

    /**
     * @brief возвращает строковое представление объекта Color.
     * @return строка, представл¤юща¤ цвет в формате "RGB(r, g, b)".
     */
    std::string ToString() const;
};