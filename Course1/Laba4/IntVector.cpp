#include "IntVector.h"
#include <iostream>
#include <stdexcept>

// Конструктор по умолчанию
IntVector::IntVector() : size(0), capacity(10) {
    data = new int[capacity];
}

// Конструктор размера
IntVector::IntVector(int n) : size(n), capacity(n > 0 ? n : 1) {
    if (n < 0) {
        throw std::invalid_argument("Размер не может быть отрицательным");
    }

    data = new int[capacity];

    for (int i = 0; i < size; ++i) {
        data[i] = 0;
    }
}

// Конструктор копирования
IntVector::IntVector(const IntVector& other)
    : size(other.size), capacity(other.capacity) {

    data = new int[capacity];

    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

// Деструктор
IntVector::~IntVector() {
    delete[] data;
}

// Оператор присваивания
IntVector& IntVector::operator=(const IntVector& other) {
    if (this != &other) {
        int* newData = new int[other.capacity];

        for (int i = 0; i < other.size; ++i) {
            newData[i] = other.data[i];
        }

        delete[] data;

        data = newData;
        size = other.size;
        capacity = other.capacity;
    }

    return *this;
}

// Получение размера
int IntVector::getSize() const {
    return size;
}

// Проверка на пустоту
bool IntVector::isEmpty() const {
    return size == 0;
}

// Добавление элемента
void IntVector::pushBack(int value) {
    if (size >= capacity) {
        int newCapacity = capacity * 2;

        int* newData = new int[newCapacity];

        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }

        delete[] data;

        data = newData;
        capacity = newCapacity;
    }

    data[size] = value;
    size++;
}

// Поиск минимального элемента
int IntVector::Min() const {
    if (isEmpty()) {
        throw std::underflow_error("Вектор пуст");
    }

    int minimum = data[0];

    for (int i = 1; i < size; ++i) {
        if (data[i] < minimum) {
            minimum = data[i];
        }
    }

    return minimum;
}

// Поиск максимального элемента
int IntVector::Max() const {
    if (isEmpty()) {
        throw std::underflow_error("Вектор пуст");
    }

    int maximum = data[0];

    for (int i = 1; i < size; ++i) {
        if (data[i] > maximum) {
            maximum = data[i];
        }
    }

    return maximum;
}

// Вывод массива
void IntVector::print() const {
    std::cout << "[";

    for (int i = 0; i < size; ++i) {
        std::cout << data[i];

        if (i < size - 1) {
            std::cout << ", ";
        }
    }

    std::cout << "]\n";
}