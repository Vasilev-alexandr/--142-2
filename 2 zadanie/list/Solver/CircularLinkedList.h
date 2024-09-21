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
     */
    Node* tail;

    Node* head;
public:

    /**
     * @brief Конструктор по умолчанию.
     * Инициализирует пустой циклический список.
     */
    CircularLinkedList();

    CircularLinkedList(const CircularLinkedList& other);

    /**
     * @brief Перегруженный оператор присваивания.
     * Копирует значения из другого списка в текущий.
     * @param other Другой список.
     * @return Ссылка на текущий список.
     */
    CircularLinkedList& operator=(const CircularLinkedList& other);

    /**
     * @brief Конструктор инициализации.
     * Инициализирует циклический список с помощью инициализатора списка.
     * @param init Инициализатор списка с значениями для элементов.
     */
    CircularLinkedList(std::initializer_list<int> init);
    /**
     * @brief Деструктор.
     * Освобождает память, занимаемую узлами списка.
     */
    ~CircularLinkedList();

    /**
     * @brief Добавляет новый элемент в список.
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
     * @return Строковое представление списка.
     */
    std::string toString() const;

    /**
     * @brief Перегруженный оператор вставки.
     * Добавляет новое значение в конец списка.
     * @param value Значение для вставки.
     * @return Ссылка на текущий список.
     */
    CircularLinkedList& operator<<(int value);
    /**
     * @brief Перегруженный оператор извлечения.
     * Извлекает значение из начала списка.
     * @param value Ссылка на переменную, в которую будет записано извлеченное значение.
     * @return Ссылка на текущий список.
     */
    CircularLinkedList& operator>>(int& value);

    CircularLinkedList(CircularLinkedList&& other) noexcept;

    CircularLinkedList& operator=(CircularLinkedList&& other) noexcept;  
};