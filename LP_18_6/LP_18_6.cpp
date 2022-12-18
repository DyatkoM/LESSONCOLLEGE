/*
11. Пользователь вводит размерность и элементы динамического массива из
целых чисел. Определить минимальный нечетный элемент массива и вывести
его на экран, если в массиве нет нечетных элементов, то вывести
соответствующее сообщение. Создать новый динамический массив, i-й
элемент которого является произведением первых i элементов исходного
массива, и вывести новый массив на экран. Отсортировать оба массива
сортировкой обменом по возрастанию. Все алгоритмы оформить в виде
подпрограмм с параметрами.
*/

#include <iostream>
using namespace std;
void EnterArr(int n, int array[])
{
	cout << "Введите элементы массива: ";
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
}
void search(int n, int array[])
{
	int min = 999;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if ((array[i] %2!=0) && (array[i] < min)) {
			min = array[i];
			count++;
		}

	}

	if (count == 0) {
		cout << "в массиве нет кратных трем элементов" << endl;
	}
	else {
		cout << "min" << " " << min << endl;
	}
}
int main()
{
	setlocale(LC_ALL, "RUS");
	int n, quantity = 0;
	cout << "Введите кол-во элементов: ";
	cin >> n;
	int* array = new int[n];
	EnterArr(n, array);
	cout << "Введенный массив: ";
	for (size_t i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	search(n, array);
}

