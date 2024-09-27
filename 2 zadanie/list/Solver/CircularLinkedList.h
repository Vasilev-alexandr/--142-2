#include <iostream>
#include <string>
#include "Node.h"
#include <sstream>

/**
 * @brief Класс, представляющий циклический связный список.
 * Этот класс реализует циклический связный список, где последний элемент списка связан с первым.
 * Он предоставляет методы для добавления элементов, проверки пустоты списка, преобразования списка в строку и перегрузки операторов
 * присваивания, вставки и извлечения элементов.
 */
class CircularLinkedList final
{
private:

    /**
     * @brief Указатель на последний элемент списка.
     * Используется для облегчения операций вставки.
     */
    Node* tail;

    /**
     * @brief Указатель на первый элемент списка.
     */
    Node* head;

public:

    /**
     * @brief Конструктор по умолчанию.
     * Инициализирует пустой циклический список.
     */
    CircularLinkedList();

    /**
     * @brief Конструктор копирования.
     * Инициализирует новый список как копию другого списка.
     * @param other Другой список для копирования.
     */
    CircularLinkedList(const CircularLinkedList& other);

    /**
     * @brief Перегруженный оператор присваивания.
     * Копирует значения из другого списка в текущий.
     * @param other Другой список для копирования.
     * @return Ссылка на текущий список.
     */
    CircularLinkedList& operator=(const CircularLinkedList& other);

    /**
     * @brief Конструктор инициализации.
     * Инициализирует циклический список с помощью списка инициализации.
     * @param init Список значений для элементов списка.
     */
    CircularLinkedList(std::initializer_list<int> init);

    /**
     * @brief Деструктор.
     * Освобождает память, занимаемую узлами списка.
     */
    ~CircularLinkedList();

    /**
     * @brief Добавляет новый элемент в конец списка.
     * @param value Значение нового элемента.
     */
    void add(int value);

    /**
     * @brief Проверяет, является ли список пустым.
     * @return true, если список пуст, иначе false.
     */
    bool isEmpty() const;

    /**
     * @brief Преобразует список в строку.
     * Преобразует элементы списка в строку с их значениями, разделёнными пробелами.
     * @return Строковое представление списка.
     */
    std::string toString() const;

    /**
     * @brief Перегруженный оператор вставки.
     * Добавляет новое значение в конец списка.
     * @param value Значение для вставки.
     * @return Ссылка на текущий список.
     */
    friend std::ostream& operator<<(std::ostream& os, CircularLinkedList& list);

    /**
     * @brief Перегруженный оператор извлечения.
     * Извлекает значение из начала списка.
     * @param is Входной поток.
     * @param list Список, в который добавляются элементы.
     * @return Входной поток.
     */
    friend std::istream& operator>>(std::istream& is, CircularLinkedList& list);

    /**
     * @brief Конструктор перемещения.
     * Перемещает данные из другого списка в текущий.
     * @param other Список для перемещения.
     */
    CircularLinkedList(CircularLinkedList&& other) noexcept;

    /**
     * @brief Оператор перемещения.
     * Перемещает данные из другого списка в текущий.
     * @param other Список для перемещения.
     * @return Ссылка на текущий список.
     */
    CircularLinkedList& operator=(CircularLinkedList&& other) noexcept;
};
