/*Пользователь вводит две стороны треугольника (вещественные
числа) и угол между ними (в градусах). Определить площадь
треугольника (вещественное число).
*/

#include <iostream>
using namespace std;
int main()
{
    int a;
    int d;
    int corner;
    float const degree = 0.01745;
    cout << "Print sides ";
    cout << "a=";
    cin >> a;
    cout << "d=";
    cin >> d;
    cout << "Print degree angle";
    cin >> corner;
    float S = 1 / 2 * a * d * degree * corner;
    cout << "S triangle =" << S;
}