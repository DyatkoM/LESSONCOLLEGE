/*Индивидуальное задание:
Реализовать следующие функции для работы с однонаправленным списком: 
- 1 добавление элемента в конец списка;
- 2 нахождение максимального элемента списка;
- 3 добавление элемента после каждого отрицательного;
- 4 вывод на экран каждого второго элемента списка; 
- 5 вывод элемента, стоящего после первого положительного элемента списка.
Работу программы реализовать с помощью меню.
*/
#include <iostream>
using namespace std;

struct list
{
	int data;
	struct list* next;
};

void add_last(list** head, int add_data) {
	//-добавление элемента в конец списка;
	list* add = new list;
	add->data = add_data;
	add->next = NULL;

	if (*head != NULL)
	{
		list* ptr;
		ptr = *head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = add;
	}
	else
	{
		*head = add;
	}
}
void print_list(list** head) {
	list* ptr = *head;
	cout << "Список:\n";
	if (ptr == NULL) cout << " пуст";
	else {
		while (ptr != NULL) {
			cout << ptr->data << "  ";
			ptr = ptr->next;
		}
		cout << endl;
	}
}
//int largestElement(list** head)
//{
//  нахождение максимального элемента списка;
//	list* ptr = *head;
//	int max = INT_MIN;
//	while (head != NULL) {
//		if (max < ptr->data)
//			max = ptr->data;
//		ptr = ptr->next;
//	}
//	return max;
//}
void print_list_2(list** head) {
	list* ptr = *head;
	cout << "Список:\n";
	if (ptr == NULL) cout << " пуст";
	else {
		int count = 0;
		
		while (ptr != NULL) {
			if (count == 0) {
				ptr = ptr->next;
				count++;
			}
			cout << ptr->data << "  ";
			ptr = ptr->next;
			count--;
		}
		cout << endl;
		
	}
}
void add_after_(list** head, int add_inf)
{
	//добавление элемента после каждого отрицательного
	if (*head != NULL)
	{
		list* ptr;
		ptr = *head;
		while (ptr != NULL)
		{
			if (ptr->data< 0)
			{
				list* add = new list;
				add->data = add_inf;
				add->next = ptr->next;
				ptr->next = add;
				ptr = ptr->next;
			}
			ptr = ptr->next;
		}
	}
}
void after_first_p(list** head)
{
	//вывод элемента, стоящего после первого положительного элемента списка.
	list* ptr;
	ptr = *head;
	cout << "Список: " << endl;
	if (ptr == NULL)
	{
		cout << "Cписок пуст";
	}
	else
	{
		while (ptr != NULL)
		{
			if (ptr->data >0)
				cout << ptr->next->data << " ";
			ptr = ptr->next;
			break;
		}
		cout << endl;
	}
}

int main()
{
	setlocale(0, "");
	list** head = new list*;//создали список
	*head = NULL;//начало списка
	while (true)
	{
		cout << "\t\tMENU\n";
		cout << "1. Добавление элемента в конец списка\n";
		cout << "2. Нахождение максимального элемента списка;\n";
		cout << "3. Добавление элемента после каждого отрицательного\n";
		cout << "4. вывод на экран каждого второго элемента списка\n";
		cout << "5. Вывод элемента, стоящего после первого положительного элемента списка\n";
		cout << "6. Выход\n";
		int menu;
		cin >> menu;
		cout << endl;
		switch (menu)
		{
		case 1: {
			int a;
			cout << "Введите добавляемое значение\n";
			cin >> a;
			add_last(head, a);
			print_list(head);
			break;
		}
		case 2:
		{
			cout << "Нахождение максимального элемента списка:" << endl;
			//cout << "наибольший эл:" << largestElement(head) << endl;
		}
		case 3:
		{
			int add_inf;
			cout << "Введите добавляемое значение" << endl;
			cin >> add_inf;
			add_after_(head, add_inf);
			print_list(head);
			break;
		}
		case 4:
		{
			
			print_list_2(head);
			break;
		}
		case 5:
		{
			cout << "элемент, стоящий после первого положительного " << endl;
			after_first_p(head);
			print_list(head);
			break;
		}
		}
	}
}
