/*10. Разработайте программу в консольном приложении для работы с целочисленным
двумерным массивом.
1. Реализовать возможность ввода размерности массива и его элементов из текстового
файла (+1.5)
2. Вычислить минимальный элемент и его позицию (номер строки и номер столбца) и
вывести их на экран. (+1)
3. Найти в каждом столбце с нечетным номером минимальный элемент и вывести
найденные значения (+1) в текстовый файл в столбик (+1).
4. Проверьте, все ли элементы массива положительны и выведите соответствующее
сообщение на экран (+1).
5. Заменить все положительные трехзначные элементы массива на количество нулей в
них (+1). Оформить алгоритм в виде функции(+1)
6. Вывести измененный массив на экран в виде матрицы (+1.5)
7. Найти минимальный нечетный элемент массива и вывести его на экран (+1).
Вывод информации должен сопровождаться соответствующими комментариями. Не
использовать библиотеку cmath.*/
#include <iostream>
#include <fstream>

using namespace std;
void print(int array[100][100], int& n, int& m)
{
	/*1. Реализовать возможность ввода размерности массива и его элементов из
текстового файла.*/
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
/*
 Вычислить минимальный элемент и его позицию (номер строки и номер столбца) и
вывести их на экран. (+1)*/
void minEl(int array[100][100], int n, int m)
{
	int minel = array[0][0];
	int nct = 0;
	int mct = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (minel > array[i][j]) {
				minel = array[i][j];
				nct = i;
				mct = j;
			}
		}
	}
	cout<<"минимальный элемент:"<<minel<<" его позиция - строка и столбец:"<<nct<<" "<<mct;
}

/*
 Найти в каждом столбце с нечетным номером минимальный элемент и вывести
найденные значения (+1) в текстовый файл в столбик (+1).*/
void minElInNM(int array[100][100], int n, int m)
{
	int h;
	ofstream s("text2.txt", ios::out);
	for (int i = 0; i < n; i++)
	{
		
		if (i % 2 == 1) {
			int minel = array[i][0];
			for (int j = 0; j < m; j++)
			{
				if (minel > array[i][j]) {
					minel = array[i][j];
				}
				
			}
			s << "столбец с нечетным номером " << i << " минимальный элемент " << " = " << minel << endl;
		}
	}
	s.close();
}
/*
Заменить все положительные трехзначные элементы массива на количество нулей в
них (+1). Оформить алгоритм в виде функции(+1)*/
void colNull(int array[100][100], int n, int m) 
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		int coll = 0;
		for (int j = 0; j < m; j++) {
			if ((array[i][j] > 99) && (array[i][j] < 1000))
			{
				int a = 0;
				t = array[i][j];
				while (t != 0) {
					a = t % 10;
					if (a == 0) {
						coll++;
					}
					t/= 10;
				}
				array[i][j] = coll;
			}
		}
	}
}
/*
Проверьте, все ли элементы массива положительны и выведите соответствующее
сообщение на экран (+1).*/
void printMes(int array[100][100], int n, int m) {
	int col = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < m; j++) {
			if (array[i][j] < 0) {
				col++;
			}
		}
	}
	if (col == 0) 
		cout << "все элементы положительны" << endl;
	
	else 
		cout << "в массиве есть отрицательные элементы" << endl;
}
/*Найти минимальный нечетный элемент массива и вывести его на экран (+1).*/
int minOdd(int array[100][100], int n, int m) {
	int t = 0;
	int minel = array[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			if ((minel > array[i][j]) && (array[i][j] % 2 != 0)) {
				minel = array[i][j];
			}
		}
	}
		t = minel;
	return t;
}
int main()
{

	int array[100][100], n, m;
	system("chcp 1251");
	print(array, n, m);
	vivod(array, n, m);
	cout << endl;
	minEl(array, n, m);
		cout<< endl;
		minElInNM(array, n, m);
		cout<< endl;
		colNull(array, n, m);
		cout<< endl;
	printMes(array, n, m);
	cout << endl;
	vivod(array, n, m);
	cout << endl;
	int reсult1 = minOdd(array, n, m);
	cout <<"минимальный нечетный элемент массива "<<reсult1;
}