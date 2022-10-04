/*Дан числовой массив А, состоящий из n целых чисел.
Если все отрицательные элементы массива являются четными,
то разделите все элементы массива на минимальный элемент. 
Выведите измененный массив на экран.
Найдите минимальный четный элемент массива и выведите его на экран.*/

#include <iostream>
using namespace std;
int main()
{
	int A[100];
	int size;
	cout << "size:";
	cin >> size;
	for (int i = 0; i < size; i++) {
		cout << "Print number in array: ";
		cin >> A[i];
	}
	int min = A[0];
	for (int i = 0; i < size; i++) {
		if (A[i] < min) {
			min = A[i];
		}
	}
	cout << min << " Min" << endl;
	int negative = 0;
	for (int i = 0; i < size; i++) {
		if (A[i] < 0) {
			negative++;
			if (A[i] % 2 == 0) {
				negative--;
			}
		}
	}cout <<"negative- "<< negative << endl;
	if (negative == 0) {
		for (int i = 0; i < size; i++) {
			A[i] = A[i] / min;
		}
	}

	for (int j = 0; j < size; j++) {
		cout << A[j] << " ";
	}
	/*Пример входнях данных:
	size:4
Print number in array12
Print number in array4
Print number in array16
Print number in array20
4 Min
0
3 1 4 5*/
}

