

#include <iostream>
using namespace std;
/*сумму цифр введенного числа*/
int sum(int num) {
	int sumNum = 0;
	while (num != 0) {
		sumNum += num % 10;
		num /= 10;
	}
	return sumNum;
}
/*количество цифр 5 во введенном числе*/
int countNall(int num) {
	int couNall = 0;
	while (num != 0) {
		 num %= 10;
		 if (num == 5) {
			 couNall++;
			 
		 }
		 num /= 10;
	}
	return couNall;
}
/*Найти первое простое число*/
bool ferst(int num) {
	int count = 0;
	for (int i = 1; i <= num; i++)//задаем счетчик 
	{
		if (num % i == 0)//ищем делители числе 
			count++;


	}
	if (count == 2)
	{
		return true;
	}
	else
		return false;
}
/*меньшее введенного*/
int cekond(int num) {
	while (num != 0) {
		if (ferst(num) == true) {
			int A = num;
			return A;
			break;
		}num--;
	}
}
int main()
{
	int num;
	cout << "num:";
	cin >> num;
	int k=cekond(num);
	cout << k;
	int f = countNall(num);
	cout << endl << f;
	int sum1 = sum(num);
	cout << endl << sum1;

}

