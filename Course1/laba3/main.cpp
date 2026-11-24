#include <iostream>
#include <string>
#include "Time.h"
#include <Windows.h>

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	
	Time Time1;//композиция по умолчанию
	Time Time2(6, 59, 63);//параметризированная композиция
	Time Time3(Time2);//композиция копирования

	Time3.~Time();//деструктор
	
	//сеттер потом геттеры
	Time1.setTime(666, 666, 666);
	std::cout << "Время 2-" << Time2.getHour() << ":" << Time2.getMin() << ":" << Time2.getSec()<<std::endl;

	//методы 
	Time1.add5seconds();
	std::cout << "Всего секунд в времени 1: " << Time1.howManySecond() << std::endl;


}