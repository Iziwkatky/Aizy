//объявление библиотек:
#include "stdafx.h"
#include <math.h>
#include <cmath>
#include <iostream>
#include <iomanip>      // std::setprecision
#include <limits>


float y(float x) //объявляем переменные
{
	return  13.9 * cos(2 * x) - 16.3 * x + log(sqrt(x + 1) - 1);//возвращает значение y при подстановке x
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n; //объявляем переменные
	double x0, p;
	double step;

	std::cout << "Write number of lines ";//потоковый вывод на экран
	std::cin >> n;//потоковый ввод переменной n
	while (n <= 0) {
		std::cout << "Where is no solution,try again";
		std::cin >> n;
	} //пока n<0,повторно просит ввести значение n
	std::cout << "x0 = ";//потоковый вывод на экран
	std::cin >> x0; //потоковый ввод переменной x

	std::cout << "step = "; ";//потоковый вывод на экран
		std::cin >> step;//потоковый ввод переменной step

	std::cout << "n\tx\ty(x)\n";//потоковый вывод на экран “шапки” таблицы

	double x = x0;//присваиваем значение переменной x начальное значение x0
	std::cout << std::fixed;

	double min = DBL_MAX;   //std::numeric_limits<double>::max(); //объявление переменной ,которая будет хранит минимальное значение

	bool flag = false;

	for (int i = 1; i <= n; i++)
	{
		std::cout << i << '\t' << std::setprecision(4) << x
			<< '\t' << std::setprecision(4) << y(x) << std::endl;//вывод значений с  4 знаками после запятой
		{
			flag = true;
			if (abs(modf(y(x), &p) < 0.6 && y(x) < min))
			{
				min = y(x);
			}//если истина ,то возвращает дробное значение и оно равняется min
		}
		x += step;//увеличим значение переменной x на step
	}
	if (flag)//если истина то
		std::cout << "get a fractional part less than 0.6:  "
		<< min << std::endl;//выводит минимальное значение среди значений функции,  имеющих дробную часть,  меньшую 0.6.

	else //если ложь
		std::cout << "There is no results less than 0.6" << std::endl;//выводит ,что такого числа нет
	system("pause");//вызов команды для задержки консоли
	return 0;//выход из функции main
}
