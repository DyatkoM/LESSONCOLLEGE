/*Пользователь вводит два целых числа. Выведите все числа,
оканчивающиеся на цифру 3, лежащие между ними. Выводить не
более 5 чисел в строке, затем переходить на следующую строку. Для
последнего из выведенных чисел определите факториал последней
цифры и выведите его на экран. Если таких чисел нет, то выведите
соответствующее сообщение. Не использовать библиотеку cmath.*/

#include <iostream>
using namespace std;
int main()
{
	int a, d;
	cout << "print the ferst number";
	cin >> a;
	cout << "print the second number";
	cin >> d;
	int counter = 0;
	int memory = 0;
	while (true)
	{
		if (a < d) {
			for (int i = a; i <= d; i++) {
				if (i % 10 == 3) {
					cout << i << " ";
					counter++;
					memory = i;
					if (counter == 5) {
						counter = 0;
						cout << endl;
					}
				}
			}
			int fact = 1;
			for (int j = memory; j >= 1; j--) {
				fact *= j;
			}
			cout << "\n" << fact;
		}
		else
		{
			for (int i = d; i <= a; i++) {
				if (i % 10 == 3) {
					cout << i << " ";
					counter++;
					memory = i;
					if (counter == 5) {
						counter = 0;
						cout << endl;
					}
				}
			}
			int fact = 1;
			for (int j = memory; j >= 1; j--) {
				fact *= j;
			}
			cout << "\n" << fact;
		}

	}
