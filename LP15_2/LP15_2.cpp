
#include <iostream>
#include<fstream>
using namespace std;
    /*Запись структуры в бинарный файл и чтение
структуры из бинарного файла

struct Worker {

char Name[256]; //Фамилия сотрудника

float salary; //Заработная плата

int age; //Возраст рабочего

};*/

    /*Worker teacher; //teacher - Записываемый в файл объект структуры

fstream f1 ;

int n; // количество сотрудников

f1.open("Wor.bin", ios::binary | ios::app|ios::out);

cout << " Введите количество человек: "; cin >> n;

cout << "\nВведите данные о человеке:";

for(int i=0; i<n; i++)

{

cout << "\n Введите имя: "; cin >> teacher.Name;

cout << " \n Введите возраст: "; cin >> teacher.age;

cout << "\n Введите ЗП: "; cin >> teacher.salary;

//Записываем структуру в файл

    f1.write(reinterpret_cast<char*>(&teacher), sizeof(teacher));

}

f1.close(); */

//Разработайте программу, реализующую работу с бинарными файлами .Необходимо хранить информацию о студентах колледжа :
//-фамилия;
//-номер группы;
//-оценка(Реализовать следующие функции, вызываемые из меню :
//ввод информации о студентах с клавиатуры и сохранение
// ее в бинарном файле с выбранным пользователем названием.
//просмотр содержимого бинарного файла с выбранным пользователем названием.
//вывод информации о студентах по введенной
//пользователем фамилии из выбранного пользователем файла.(Удалить студента из выбранного файла(по номеру / дз - фамилии)
//заменить оценку выбранного студента
    struct student {
        char surname[10];
        int group;
        int mark;
    };

    void create()
    {

        char name[10];
        cout << "введите имя файла\n";
        cin >> name;
        fstream file(name, ios::binary | ios::app);
        if (file)
        {
            file.seekp(0, ios::end);
            student students[3];
            int size;
            cout << "введите размер(до трех) \n";
            cin >> size;
            for (int i = 0; i < size; i++)
            {
                cout << "Фамилия " << i + 1 << "-ого студента ";
                cin >> students[i].surname;
                cout << "номер группы " << i + 1 << "-ого студента "; cin >> students[i].group;
                cout << "Оценка " << i + 1 << "-ого студента "; cin >> students[i].mark;
                file.write(reinterpret_cast<char*>(&students[i]), sizeof(students[i]));
                file.close();
            }
        }
        else
        {
            file.seekp(0);
            student students;
            int size;
            cout << "введите размер" << endl;
            cin >> size;
            for (int i = 0; i < size; i++)
            {
                cout << "фамилия" << i + 1 << "-ого студента"; cin >> students.surname;
                cout << "номер группы" << i + 1 << "-ого студента"; cin >> students.group;
                cout << "Оценка" << i + 1 << "-ого студента"; cin >> students.mark;
                file.write(reinterpret_cast<char*>(&students), sizeof(students));
            }
            file.close();
        }
    }
    void info()
    {
        student s;
        char name[10];
        cout << "введите имя файла\n";
        cin >> name;

        ifstream file(name, ios::binary);
        file.read(reinterpret_cast<char*>(&s), sizeof(s));
        if (!file)
        {
            cout << "нет файла" << endl;
            return;
        }
        while (!file.eof())
        {
            cout << "фамилия" << s.surname << endl;
            cout << "номер группы" << s.group << endl;
            cout << "оценка" << s.mark << endl;
            file.read(reinterpret_cast<char*>(&s), sizeof(s));
        }
        file.close();
    }
    void search()
    {
        student s;
        char name[10];
        cout << "введите имя/n";
        cin >> name;
        int g;
        cout << "введите номер группы\n";
        cin >> g;
        ifstream file(name, ios::binary);
        file.read(reinterpret_cast<char*>(&s), sizeof(s));
        while (!file.eof())
        {
            if (s.group == g)
            {
                cout << "фамилия" << s.surname << endl;
                cout << "номер группы" << s.group << endl;
                cout << "оценка" << s.mark << endl;
            }
            file.read(reinterpret_cast<char*>(&s), sizeof(s));
        }
    }

    void Change()
    {
        student s;
        char name[10];
        cout << "введите имя/n";
        cin >> name;
        int n, mark1, c = 0;
        cout << "введите номер студента";
        cin >> n;
        cout << "введите новую отметку";
        cin >> mark1;
        ifstream file(name, ios::binary);
        ofstream tmp("tmp.bin", ios::binary);
        file.read(reinterpret_cast<char*>(&s), sizeof(s));

        while (!file.eof())
        {
            if (c == n - 1) {
                s.mark = mark1;
            }
            tmp.write(reinterpret_cast<char*>(&s), sizeof(s));
            file.read(reinterpret_cast<char*>(&s), sizeof(s));
            c++;
        }
        file.close();
        tmp.close();
        remove(name);
        rename("tmp.bin", name);
    }


    void Dell()
    {

        student s;
        char name[10];
        cout << "введите имя файла\n";
        cin >> name;
        int n, c = 0;
        cout << "введите немер студента:";
        cin >> n;

        ifstream file(name, ios::binary);
        ofstream tmp("tmp.bin", ios::binary);

        file.read(reinterpret_cast<char*>(&s), sizeof(s));

        while (!file.eof())
        {
            cout << s.surname << "*" << endl;
            if (c != n - 1) {
                tmp.write(reinterpret_cast<char*>(&s), sizeof(s));

            }

            file.read(reinterpret_cast<char*>(&s), sizeof(s));
            c++;
        }

        file.close();

        tmp.close();

        remove(name);
        rename("tmp.bin", name);

    }
  
    int main() {


        setlocale(LC_ALL, "RUS");
        // делаем меню(ожидаем ввод)
        int input = 0;
        cout << "1. добавить в базу\n2. просмотр\n 3. поиск по фамилии\n 4. измениение отметки\n 5. удаление по номеру студента\n ";
        cin >> input;
        switch (input)
        {
        case 1:
            create();
            break;
        case 2:
            info();
            break;
        case 3:
            search();
            break;
        case 4:
            Change();
            break;
        case 5:
            Dell();
            break;
        default:
            break;
        }

    }








// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
