#include <iostream>
using namespace std;
struct list
{
	int inf; // поле данных
	struct list* next; // указатель на следующий элемент
};
void add_last(list** head, int add_inf) {
	list* add = new list;
	add->inf = add_inf;
	add->next = NULL;
	if (*head != NULL) {
		list* ptr;
		ptr = *head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = add;
	}
	else *head = add;
}
void del_after(list** head, int a) {
	//- добавление элемента в конец списка;
	if (*head != NULL) {
		list* ptr;
		ptr = *head;
		while (ptr != NULL) {
			if (ptr->inf == a) {
				if (ptr->next != NULL) {
					list* del;
					del = ptr->next;
					ptr->next = del->next;
					delete del;
				}
			}
			ptr = ptr->next;
		}
	}
}

void add_after(list** head, int add_inf, int a) {
	if (*head != NULL) {
		list* ptr;
		ptr = *head;
		while (ptr != NULL) {
			if (ptr->inf == a) {
				list* add = new list;
				add->inf = add_inf;
				add->next = ptr->next;
				ptr->next = add;
				ptr = ptr->next;
			}
			ptr = ptr->next;
		}
	}
}

void add_before(list** head, int add_inf, int a) {
	//-добавление элемента после каждого отрицательного;
	if (*head != NULL) {
		list* ptr;
		list* predptr;
		ptr = *head;
		if (ptr->inf != a) {
			predptr = ptr;
			ptr = ptr->next;
			while (ptr != NULL) {
				if (ptr->inf == a) {
					list* add = new list;
					add->inf = add_inf;
					add->next = ptr;
					predptr->next = add;
					predptr = predptr->next;

				}
				ptr = ptr->next;
				predptr = predptr->next;
			}
		}
		else {
			list* add = new list;
			add->inf = add_inf;
			add->next = ptr;
			*head = add;
			predptr = ptr;
			ptr = ptr->next;
			while (ptr != NULL) {
				if (ptr->inf == a) {
					list* add = new list;
					add->inf = add_inf;
					add->next = ptr;
					predptr->next = add;
					predptr = predptr->next;
				}
				ptr = ptr->next;
				predptr = predptr->next;
			}
		}
	}
}

void print_list(list** head) {
	list* ptr;
	ptr = *head;
	cout << "Список " << endl;
	if (ptr == NULL) cout << " пуст";
	else {
		while (ptr != NULL) {
			cout << ptr->inf << " ";
			ptr = ptr->next;
		}
		cout << endl;
	}
}
void add_first(list** head, int add_inf) {
	list* add = new list;
	add->inf = add_inf;
	if (*head != NULL) {
		add->next = *head;
		*head = add;
	}
	else {
		add->next = NULL;
		*head = add;
	}
}
void dell_first(list** head) {
	if (*head != NULL) {
		list* del;
		del = *head;
		if ((*head)->next == NULL) {
			*head = NULL;
			delete del;
		}
		else
		{
			*head = (*head)->next;
			delete del;
		}
	}
	else {
		cout << " Список пуст" << endl;
	}
}

int main()
{

	system("chcp 1251");
	list** head = new list*;
	*head = NULL;
	while (true) {
		cout << " 1. Добавление в начало" << endl;
		cout << " 2. Добавление в конец " << endl;
		cout << " 3. Удаление первого элемента " << endl;
		cout << " 4. Выход" << endl;
		cout << " 5. Добавление после каждого заданного " << endl;
		cout << "6. Добавление перед каждым заданным " << endl;
		cout << " 7. Удаление после каждого заданного " << endl;

		cout << "Выберите пункт меню" << endl;

		int p;
		cin >> p;
		switch (p)
		{
		case 1: {
			int a;
			cout << " Введите добавляемое значение" << a<<endl;
			add_first(head, a); print_list(head);
			break; }
		case 2: {
			int a;
			cout << " Введите добавляемое значение" << a<<endl;
			add_last(head, a); print_list(head);
			break; }
		case 3: {
			dell_first(head); print_list(head);
			break; }
		case 4: {
			exit(0); break;
		}
		case 5: {
			int a, z;
			cout << " Введите добавляемое значение" << a<<endl;
			cout << " Введите после чего добавить" << z<<endl;
			add_after(head, a, z); print_list(head);
			break; }
		case 6: {
			int a, z;
			cout << " Введите добавляемое значение " << a<<endl;
			cout << " Введите перед чем добавить" << z << endl;
			add_before(head, a, z); print_list(head);
			break; }
		case 7: {
			int a;
			cout << " Введите после чего удалять " << endl; cin >> a;
			del_after(head, a); print_list(head);
			break; }
		default: {
			cout << "Нет такого пункта меню " << endl; break; }
		}
	}
}