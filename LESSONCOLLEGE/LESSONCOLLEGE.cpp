/*Пользователь вводит две стороны прямоугольника (целые числа).
Определить его перимиметр, площадь, диагональ и радиус
описанной окружности (вещественные числа).*/
#include <iostream>
using namespace std;
int main()
{
	int a;
	int d;
	cout << "Print sides\n";
	cout << "a=";
	cin >> a;
	cout << "d= ";
	cin >> d;
	int P = 2 * (a + d);
	int S = a * d;
	int D = a * a + d * d;
	int R = D / 2;
	cout << P << " " << S << " " << D << " " << R;
}