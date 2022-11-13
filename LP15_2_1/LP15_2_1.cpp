/*
- фамилия;
- номер договора (уникален);
- номер группы;
- оценка
Добавить в приложение следующие функции, вызываемые из меню:
1. Удаление информации из выбранного бинарного файла о студенте с
выбранным номером договора.
2. Изменение информации о номере группы для всех студентов из
выбранного файла, имеющих неудовлетворительную отметку.
3. Вывод фамилий студентов с максимальной отметкой из выбранного
файла.
4. Изменение информации об оценке введенного по фамилии студента.
Файл вводит пользователь.*/

#include <iostream>
#include<fstream>
using namespace std;
struct student {
    char surname[10];
    int numDoc;
    int group;
    int mark;
};
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
        cout << "номер договора" << s.group << endl;
        cout << "номер группы" << s.group << endl;
        cout << "оценка" << s.mark << endl;
        file.read(reinterpret_cast<char*>(&s), sizeof(s));
    }
    file.close();
}
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
            cout << "Фамилия " << i + 1 << "-ого студента ";cin >> students[i].surname;
            cout << "номер договора " << i + 1 << "-ого студента "; cin >> students[i].numDoc;
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
            cout << "номер договора " << i + 1 << "-ого студента "; cin >> students.numDoc;
            cout << "номер группы" << i + 1 << "-ого студента"; cin >> students.group;
            cout << "Оценка" << i + 1 << "-ого студента"; cin >> students.mark;
            file.write(reinterpret_cast<char*>(&students), sizeof(students));
        }
        file.close();
    }
}
void del() {
    /* 1. Удаление информации из выбранного бинарного файла о студенте с
        выбранным номером договора. */
    student s;
    char name[10];
    cout << "введите имя файла\n";
    cin >> name;
    int n, c = 0;
    cout << "введите немер договора:";
    cin >> n;

    ifstream file(name, ios::binary);
    ofstream tmp("tmp.bin", ios::binary);

    file.read(reinterpret_cast<char*>(&s), sizeof(s));

    while (!file.eof())
    {
        cout << s.surname << "*-be gell" << endl;
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
void change() {
    /*2. Изменение информации о номере группы для всех студентов из
выбранного файла, имеющих неудовлетворительную отметку.*/
    student s;
    char name[10];

    cout << "введите имя/n";
    cin >> name;
    int n, group1;
    cout << "введите новую группу для лохов";
    cin >> group1;
    ifstream file(name, ios::binary);
    ofstream tmp("tmp.bin", ios::binary);
    file.seekg(0);
    file.read(reinterpret_cast<char*>(&s), sizeof(s));
    if (s.numDoc < 6) {

        while (!file.eof())
        {
            if (s.numDoc<6) {
                s.group= group1;
            }
            tmp.write(reinterpret_cast<char*>(&s), sizeof(s));
            file.read(reinterpret_cast<char*>(&s), sizeof(s));
           
        }
        file.close();
        tmp.close();
        remove(name);
        rename("tmp.bin", name);
    }
}
void max() {
    /*3. Вывод фамилий студентов с максимальной отметкой из выбранного
файла.*/
    student s;
    char name[10];

    cout << "введите имя/n";
    cin >> name;
    ifstream file(name, ios::binary);
    ofstream tmp("tmp.bin", ios::binary);
    file.seekg(0);
    file.read(reinterpret_cast<char*>(&s), sizeof(s));
    if (s.numDoc >= 6) {

        while (!file.eof())
        {
            cout << s.surname << "лучший ";
            tmp.write(reinterpret_cast<char*>(&s), sizeof(s));
            file.read(reinterpret_cast<char*>(&s), sizeof(s));

        }
        file.close();
        tmp.close();
        remove(name);
        rename("tmp.bin", name);
    }
}
void perem() {
    /*4. Изменение информации об оценке введенного по фамилии студента.*/
    student s;
    char name[10];
    cout << "введите имя/n";
    cin >> name;
    int n, mark1, c = 0;
    cout << "введите фамилию студента";
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

int main()
{
    setlocale(LC_ALL, "RUS");
    // делаем меню(ожидаем ввод)
    int input = 0;
    cout << "1. добавить в базу\n2. Удаление информации из выбранного бинарного файла о студенте с выбранным номером договора\n 3.  Изменение информации о номере группы для всех студентов из выбранного файла, имеющих неудовлетворительную отметку.\n 4. Вывод фамилий студентов с максимальной отметкой из выбранного файла.\n 5.Изменение информации об оценке введенного по фамилии студента\n ";
    cin >> input;
    switch (input)
    {
    case 1:
        create();
        break;
    case 2:
        del();
        break;
    case 3:
        change();
        break;
    case 4:
        max();
        break;
    case 5:
        perem();
        break;
    case 6:
        info();
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
