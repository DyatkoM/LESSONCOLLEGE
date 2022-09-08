/*Пользователь вводит количество деталей,которые выточил работник
и время его работы (целые числа).
Определить среднее время
выполнения детали (вещественное число)
и какой процент от 8-часового дня он отработал.*/
#include <iostream>
using namespace std;
int main()
{
	int detail;
	int time;
	int const workingDay = 8;
	cout << "Print here quantity detail ";
	cin >> detail;
	cout << "Print here time work ";
	cin >> time;
	float averageTime = time / detail;
	float percentageOutput = 100 * time / workingDay;
	cout << "average time " << averageTime << "\nyou work " << percentageOutput << "% out of 8 hours ";
}