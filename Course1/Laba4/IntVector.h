#pragma once

class IntVector {
private:
    int* data;
    int size;
    int capacity;

public:
    // Конструкторы
    IntVector();
    IntVector(int n);
    IntVector(const IntVector& other);

    // Деструктор
    ~IntVector();

    // Оператор присваивания
    IntVector& operator=(const IntVector& other);

    // Методы доступа
    int getSize() const;
    bool isEmpty() const;

    // Методы изменения
    void pushBack(int value);

    // Поиск
    int Min() const;
    int Max() const;

    // Вывод
    void print() const;
};