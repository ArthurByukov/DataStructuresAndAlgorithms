#pragma once
#include <string>
#include <iostream>

class Time {
private:
	int hour;
	int min;
	int sec;

public:
	//Конструкторы
	Time();
	Time(int newHour, int newMin, int newSec);
	Time(const Time& other);

	//Деструкторs
	~Time();

	//Геттеры
	int getHour() const;
	int getMin() const;
	int getSec() const;
	
	//Сеттеры
	void setTime(int newHour, int newMin, int newSec );
	
	//Методы
	int howManySecond() const;
	void add5seconds();

};