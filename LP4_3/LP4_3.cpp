/*Пользователь вводит натуральное число. Определите, все ли цифры
во введенном числе четные. Получите наибольшее целое k, при
котором 3^k меньше введенного числа.*/

#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	int number;
	int k = 1;
	int i = 3;
	cout << "num: ";
	cin >> number;
		for (int j = 1; j < number; j++)
		{
			k++;
			i= i*3;
			if (i < number) {
				break;
			}
	}
	cout << k<<endl;
	while (number > 0)  {
		k = number % 10;
		if (number % 2 == 0) {
			cout << "+" << endl;
		}
		else
			cout << "-"<<endl;
		number /= 10;
	}
	
}

