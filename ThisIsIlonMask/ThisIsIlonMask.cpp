/*1. Реализовать возможность ввода размерности массива и его элементов из
текстового файла.
2. Вычислить количество минимальных элементов массива и вывести его на экран.
3. Найти в каждом столбце произведение нечетных элементов и вывести найденные
значения в текстовый в новый текстовый файл в столбик.

4. Найти первый нечетный элемент массива и вывести его на экран. Если нечетных
элементов нет, то выведите соответствующее сообщение.

5. Заменить в предпоследней строке все двузначные элементы на первый нечетный
элемент.

6. Вывести измененный массив в текстовый файл в виде матрицы.
7. Проверить, в каждой ли строке все элементы четные. Ответ вывести на экран.*/

#include <iostream>
#include <fstream>
using namespace std;
/*1. Реализовать возможность ввода размерности массива и его элементов из
текстового файла.*/
void print(int array[100][100], int& n, int& m)
{
	fstream f;
	f.open("text.txt", ios::in);
	f >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			f >> array[i][j];
		}
	}
	f.close();
}
void vivod(int array[100][100], int& n, int& m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}
/*2.Вычислить количество минимальных элементов массива и вывести его на экран.*/
int minEl(int array[100][100], int n, int m)
{
	int minel = array[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (minel > array[i][j]) {
				minel = array[i][j];
			}
		}
	}
	return minel;
}
/* подсчет количество минимального элемента в массиве */
void count(int array[100][100], int& n, int& m)
{
	int col = 0;
	int min = minEl(array, n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (array[i][j] == min)
				col++;
		}
	}
	cout << col;
}
/*3.Найти в каждом столбце произведение нечетных элементов и вывести найденные
значения в текстовый в новый текстовый файл в столбик.*/
void prois(int array[100][100], int n, int m)
{
	int h;
	ofstream s("text2.txt", ios::out);
	for (int i = 0; i < m; i++)
	{
		int h = 1;
		for (int j = 0; j < n; j++)
		{
			if (array[j][i] % 2 != 0)
				h *= array[j][i];
			else
				h *= 1;

		}

		s << "в каждом столбце произведение нечетных элементов" << "=" << h << endl;
	}
	s.close();
}
/*4. Найти первый нечетный элемент массива и вывести его на экран. Если нечетных
элементов нет, то выведите соответствующее сообщение.*/
int ferst(int array[100][100], int n, int m) {
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			if (array[i][j] % 2 != 0)
			{
				t = array[i][j];
				break;
			}

			if (t != 0)
			{
				break;
			}
		}
	}
	return t;
}
int main()
{

	int array[100][100], n, m;
	system("chcp 1251");
	print(array, n, m);
	vivod(array, n, m);
	cout << endl;
	int minel=minEl(array, n, m);
	cout << " минимальный элемент массива:" << minel<<"число повторений в массиве:";
	count(array, n, m);
	cout << endl;
	prois(array, n, m);
	int fer=ferst(array, n, m);
	cout << "первыый элемент массива нечетный равен:" << fer << endl;
	/*5. Заменить в предпоследней строке все двузначные элементы на первый нечетный
элемент.*/ 
	for (int j = 0; j < m; j++) {
		if ((array[3][j] >= -99 && array[3][j] <= -10) && (array[3][j] >= 99 && array[3][j] <= 10)) {
			array[3][j] = 1;
		}
	}
}