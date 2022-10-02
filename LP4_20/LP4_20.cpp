/*Пользователь вводит натуральное число а. Найти k простых чисел
больших а и, если возможно, k простых чисел меньших а. a и k вводит
пользователь. Если это невозможно вывести соответствующее
сообщение.*/

#include <iostream>
using namespace std;
int isprime(int num)
{

	if ((num * num) % 24 == 1)
	{
		return true;
	}

	return false;

}
int main()
{
	int a;
	int k;
	cout << "a:";
	cin >> a;
	cout << "k:";
	cin >> k;
	int s = a;
	int d = k;
	while (k != 0) {
		if (isprime(a)) {
			cout << a << "+";
			k--;
			a++;
		}
		else
			a++;
	}
	cout << endl;
	while (d != 0) {
		if (isprime(s)) {
			if (s <1) {
				cout << "Error";
				break;
			}
			cout << s<<"-";
			d--;
			s--;
		}
		else
			s--;

	}
}


