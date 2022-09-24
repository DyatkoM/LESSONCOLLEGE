/*Пользователь вводит два натуральных числа. Выведите на экран то
из них, у которого больше четных цифр. Если количество четных
цифр одинаково, то выведите соответствующее сообщение. Найдите
наибольший общий делитель введенных чисел.*/

#include <iostream>
using namespace std;
int NOD(int  a, int d)
{
	int div;
	if (a == d)   // если числа равны, НОД найден
		return a;
	int g = a - d; // Находим разность чисел
	if (g < 0)       // если разность отрицательная,
	{
		g = -g;     // меняем знак
		div = NOD(a, g); // вызываем функцию NOD() для двух наименьших чисел
	}
	else      // если разность n1-n2 положительная
	{
		div = NOD(d, g); // вызываем функцию NOD() для двух наименьших чисел
	}
	return div;
}
int main()
{
	int a, d;
	cout << "a=";
	cin >> a;
	cout << "d=";
	cin >> d;
	int k;
	cout << NOD(a, d) << endl;
	int count = 0;
	int count1 = 0;

	while (a > 0) {
		k = a % 10;
		if (k % 2 == 0) {
			count++;
		}
		a /= 10;
	}
	cout << " " << count << " the ferst" << endl;
	while (d > 0) {
		k = d % 10;
		if (d % 2 == 0) {
			count1++;
		}
		d /= 10;
	}
	cout << " " << count1 << " the second" << endl;
	if (count > count1) {
		cout << count;
	}
	else if (count < count1) {
		cout << count1;
	}
	else {
		cout << endl << "=";
	}


}
