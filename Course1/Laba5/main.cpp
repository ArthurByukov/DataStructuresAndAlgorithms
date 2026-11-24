
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <Windows.h>

class Vector3D {
private:
    double x, y, z;

public:
    // Конструктор
    Vector3D(double x = 0, double y = 0, double z = 0)
        : x(x), y(y), z(z) {
    }

    // Сложение векторов
    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    // Вычитание векторов
    Vector3D operator-(const Vector3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    // Умножение вектора на число
    Vector3D operator*(double number) const {
        return Vector3D(x * number, y * number, z * number);
    }

    // Деление вектора на число
    Vector3D operator/(double number) const {
        if (number == 0) {
            throw std::runtime_error("Деление на ноль!");
        }

        return Vector3D(x / number, y / number, z / number);
    }

    // Составное присваивание
    Vector3D& operator+=(const Vector3D& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Vector3D& operator-=(const Vector3D& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    Vector3D& operator*=(double number) {
        x *= number;
        y *= number;
        z *= number;
        return *this;
    }

    Vector3D& operator/=(double number) {
        if (number == 0) {
            throw std::runtime_error("Деление на ноль!");
        }

        x /= number;
        y /= number;
        z /= number;
        return *this;
    }

    // Вычисление длины вектора
    double length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    // Операторы сравнения по длине
    bool operator<(const Vector3D& other) const {
        return length() < other.length();
    }

    bool operator>(const Vector3D& other) const {
        return length() > other.length();
    }

    bool operator<=(const Vector3D& other) const {
        return length() <= other.length();
    }

    bool operator>=(const Vector3D& other) const {
        return length() >= other.length();
    }

    // Префиксный инкремент
    Vector3D& operator++() {
        ++x;
        ++y;
        ++z;
        return *this;
    }

    // Постфиксный инкремент
    Vector3D operator++(int) {
        Vector3D temp = *this;
        ++(*this);
        return temp;
    }

    // Префиксный декремент
    Vector3D& operator--() {
        --x;
        --y;
        --z;
        return *this;
    }

    // Постфиксный декремент
    Vector3D operator--(int) {
        Vector3D temp = *this;
        --(*this);
        return temp;
    }

    // Оператор вызова функции
    double operator()() const {
        return length();
    }

    // Скалярное произведение
    double scalarProduct(const Vector3D& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // Векторное произведение
    Vector3D vectorProduct(const Vector3D& other) const {
        return Vector3D(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    // Вывод вектора
    friend std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }
};

// Умножение числа на вектор
Vector3D operator*(double number, const Vector3D& v) {
    return v * number;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Vector3D a(2, 3, 4);
    Vector3D b(1, 2, 3);

    std::cout << "Вектор A: " << a << std::endl;
    std::cout << "Вектор B: " << b << std::endl;

    // Арифметические операторы
    std::cout << "\nАрифметические операторы:\n";
    std::cout << "A + B = " << a + b << std::endl;
    std::cout << "A - B = " << a - b << std::endl;
    std::cout << "A * 2 = " << a * 2 << std::endl;
    std::cout << "A / 2 = " << a / 2 << std::endl;

    // Составное присваивание
    std::cout << "\nСоставное присваивание:\n";
    Vector3D c = a;
    c += b;
    std::cout << "A += B: " << c << std::endl;

    c = a;
    c -= b;
    std::cout << "A -= B: " << c << std::endl;

    c = a;
    c *= 2;
    std::cout << "A *= 2: " << c << std::endl;

    c = a;
    c /= 2;
    std::cout << "A /= 2: " << c << std::endl;

    // Сравнение
    std::cout << "\nСравнение векторов:\n";
    std::cout << "A < B: " << (a < b) << std::endl;
    std::cout << "A > B: " << (a > b) << std::endl;
    std::cout << "A <= B: " << (a <= b) << std::endl;
    std::cout << "A >= B: " << (a >= b) << std::endl;

    // Инкремент и декремент
    std::cout << "\nИнкремент и декремент:\n";
    c = a;
    std::cout << "++A: " << ++c << std::endl;

    c = a;
    std::cout << "A++: " << c++ << std::endl;
    std::cout << "После A++: " << c << std::endl;

    c = a;
    std::cout << "--A: " << --c << std::endl;

    c = a;
    std::cout << "A--: " << c-- << std::endl;
    std::cout << "После A--: " << c << std::endl;

    // Функтор
    std::cout << "\nДлина вектора через оператор ():\n";
    std::cout << "A() = " << a() << std::endl;

    // Скалярное и векторное произведения
    std::cout << "\nДополнительные методы:\n";
    std::cout << "Скалярное произведение A и B: "
        << a.scalarProduct(b) << std::endl;

    std::cout << "Векторное произведение A и B: "
        << a.vectorProduct(b) << std::endl;

    return 0;
}
