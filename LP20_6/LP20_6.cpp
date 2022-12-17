/*Реализовать следующие функции для работы с однонаправленным
списком:
- добавление элемента в начало списка;
- удаление элемента после каждого четного;
- подсчет суммы элементов, значение которых меньше заданного;
-добавление элемента перед вторым четным;
- добавление элемента перед первым заданным.
Работу программы реализовать с помощью меню.*/


#include <iostream>
using namespace std;
struct list
{
    int data;
    struct list* next;
    int pred;
};
void add_first(list** head, int add_inf) {
    //добавление элемента в начало списка; 
    list* add = new list;
    add->data = add_inf;
    if (*head != NULL) {
        add->next = *head;
        *head = add;
    }
    else {
        add->next = NULL;
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
void del_after(list** head) {
    //- добавление элемента в конец списка;
    if (*head != NULL) {
        list* ptr;
        ptr = *head;
        while (ptr != NULL) {
            if (ptr->data % 2 == 0) {
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
int main()
{
    system("chcp 1251");
    list** head = new list*;
    *head = NULL;
    while (true)
    {
        cout << "1. добавление элемента в начало списка" << endl;
        cout << "2. удаление элемента после каждого четного " << endl;
        cout << "3. подсчет суммы элементов, значение которых меньше заданного" << endl;
        cout << "4. добавление элемента перед вторым четным " << endl;
        cout << "5. добавление элемента перед первым заданным " << endl;
        cout << "Выберите пункт меню-";

        int p, add_inf;
        cin >> p;
        cout << endl;
        switch (p)
        {
        case 1:
        {
            int a;
            cout << "Введите добавляемое значение" << endl;
            cin >> a;
            add_first(head, a);
            print_list(head);
            break;
        }
        case 2:
        {
            del_after(head); print_list(head);
            break; }
        }
        }
    }


