/* Пользователь вводит размеры прямоугольного бассейна и его
высоту (в метрах, действительные числа). Определить объем
бассейна. Каким должна была бы быть глубина бассейна такого
же объема, будь он круглым (описанным около прямоугольника
исходного бассейна). Объем цилиндра πr 2 h. Вычислите остаток
от деления введенной глубины на вычисленную.*/

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	system("chcp 1251");
	int a, d, H;
	cout << "a=";
	cin >> a;
	cout << "d=";
	cin >> d;
	cout << "H=";
	cin >> H;
	int VS = a * H * d;
	cout << VS << " объем боссейна \n";
	float hypotenuse = sqrt(a * a + d * d);
	int haifHypotenuseRadius = hypotenuse / 2;
	int HC = VS/(3.14 *haifHypotenuseRadius*2 ) ;
	cout << HC << "высота бассейна если бы он был бы круглым \n";
	float remains = H % HC;
	cout << remains<< " отаток от деления одной высоты на другую \n" ;

}

