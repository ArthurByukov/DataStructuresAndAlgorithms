#include "Time.h"

Time::Time() : hour(0), min(0), sec(0) {
	std::cout << "Создано время по умолчанию" << std::endl;
}

Time::Time(int newHour, int newMin, int newSec) {
	setTime(newHour, newMin, newSec);
	std::cout << "Создано время " << hour << ":" << min << ":" << sec << std::endl;
}

Time::Time(const Time& other) :hour(other.hour), min(other.min), sec(other.sec) {
	std::cout << "Создана копия времени" << std::endl;
}


Time::~Time() {
	std::cout<<"Уничтожено время "<< hour << ":" << min << ":" << sec << std::endl;
}


int Time::getHour()const{
	return hour;
}
int Time::getMin()const {
	return min;
}
int Time::getSec()const {
	return sec;
}


void Time::setTime(int h, int m, int s) {
	if ((h >= 0) && (m >= 0) && (s >= 0)) {

		if (s >= 60) {
			m += s / 60;
			sec = s % 60;
		}
		else {
			sec = s;
		}

		if (m >= 60) {
			h += m / 60;
			min = m % 60;
		}
		else {
			min = m;
		}

		hour = h;

	}
	else {
		std::cout << "Ошибка, время должно быть положительным." << std::endl;
	}
}

int Time::howManySecond() const {
	//std::cout << "Всего секунд: " << hour * 360 + min * 60 + sec << std::endl;
	return hour * 360 + min * 60 + sec;
}

void Time::add5seconds() {
	sec += 5;
	if (sec >= 60) {
		min += 1;
		sec -= 60;
	}
}
