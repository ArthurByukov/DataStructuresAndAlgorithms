#include <iostream>
#include <Windows.h>
#include "IntVector.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    IntVector v1;

    // Заполняем массив
    v1.pushBack(15);
    v1.pushBack(4);
    v1.pushBack(28);
    v1.pushBack(-3);
    v1.pushBack(10);

    std::cout << "Динамический массив: ";
    v1.print();

    std::cout << "Размер массива: " << v1.getSize() << std::endl;

    std::cout << "Минимальный элемент: " << v1.Min() << std::endl;
    std::cout << "Максимальный элемент: " << v1.Max() << std::endl;

    return 0;
}