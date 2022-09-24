/*Пользователь вводит натуральное число. Определите, все ли цифры
во введенном числе четные. Получите наибольшее целое k, при
котором 3^k меньше введенного числа.*/

#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	int number;
	int k = 0;
	int i = 3;
	cout << "num: ";
	cin >> number;
	
	while (i < number) {
		
		i = pow(i, k);
		k++;
	}
	cout << k-1 << endl;
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

