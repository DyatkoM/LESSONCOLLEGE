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
    //- удаление элемента после каждого четного
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
int pr_otr(list** head, int a)
{
    //подсчет суммы элементов, значение которых меньше заданного
    list* ptr = *head;
    int pr = 0;

    while (ptr != NULL)
    {
        if (ptr->data < a)
        {
            pr += ptr->data;
        }
        ptr = ptr->next;
    }
    return pr;
}
void second_nech(list** head, int add_inf)
{
    //добавление элемента перед вторым четным
    int count = 0;
    if (*head != NULL)
    {
        list* ptr;
        list* predptr;
        ptr = *head;
        int b;
        predptr = ptr;
        ptr = ptr->next;
        while (ptr != NULL)
        {
            b = ptr->data;
            if (b % 2 == 0)
            {
                count++;
            }
            if (count == 2)
            {
                list* add = new list;
                add->data = add_inf;
                add->next = ptr;
                predptr->next = add;
                predptr = predptr->next;
            }
            ptr = ptr->next;
            predptr = predptr->next;
        }
    }
}

void add_before(list** head, int add_inf, int a) {
    //добавление элемента перед первым заданным.
    if (*head != NULL) {
        list* ptr;
        list* predptr;
        ptr = *head;
        if (ptr->data != a) {
            predptr = ptr;
            ptr = ptr->next;
            while (ptr != NULL) {
                if (ptr->data == a) {
                    list* add = new list;
                    add->data = add_inf;
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
            add->data = add_inf;
            add->next = ptr;
            *head = add;
            predptr = ptr;
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
            break;
        }
        case 3:
        {
            int a;
            cout << " Введите значение для подсчета суммы эл меньше его ";
            cin >> a;
            cout << "подсчет суммы элементов, значение которых меньше заданного" << pr_otr(head,a) << endl;
            print_list(head);
            break;
        }
        case 4: {
            //4. добавление элемента перед вторым четным 
            cout << "Введите добавляемое значение " << endl;
            cin >> add_inf;
            second_nech(head, add_inf);
            print_list(head);
            break;
        }
        
        case 5: {
            //добавление элемента перед первым заданным
            int a, z;
          
            cout << " Введите добавляемое значение ";
            cin >> a;
            cout << " Введите перед чем добавить ";
            cin >> z;
            add_before(head, a, z); print_list(head);
            break; }
        }
        }
    }


