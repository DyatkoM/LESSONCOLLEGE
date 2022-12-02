
/*
• номер группы (уникален);
• ФИО куратора;
• специальность;
• средний балл по группе.
Реализовать следующие функции, вызываемые из меню:
1. Ввод информации о группах с клавиатуры и сохранение ее в бинарном
файле с выбранным пользователем названием.
2. Просмотр содержимого бинарного файла с выбранным пользователем
названием.
3. Вывод информации о группах по введенной пользователем фамилии
куратора из выбранного пользователем файла.
4. Вывод информации обо всех группах со средним баллом ниже .*/

/*1. Удаление информации из выбранного бинарного файла о группе с
выбранным номером.
2. Изменение информации о ФИО куратора для всех групп из выбранного
файла, имеющих средний балл меньше, чем вводит пользователь.
3. Вывод названий специальностей с максимальным средним баллом из
выбранного файла.
4. Изменение информации о ФИО куратора по введенному номеру
группы. Файл вводит пользователь.*/
#include <iostream>
#include<fstream>
using namespace std;
struct student {
	int group;
	char surname[10];
	char spatual[10];
	int crMark;
};
void create()
{
	/*1. Ввод информации о группах с клавиатуры и сохранение ее в бинарном
файле с выбранным пользователем названием.*/
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
			cout << "номер группы (уникален) " << i + 1 << "-ого студента ";
			cin >> students[i].group;
			cout << "ФИО куратора " << i + 1 << "-ого студента "; cin >> students[i].surname;
			cout << "специальность " << i + 1 << "-ого студента "; cin >> students[i].spatual;
			cout << "средний балл по группе " << i + 1 << "-ого студента "; cin >> students[i].crMark;
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
			cout << "номер группы (уникален)" << i + 1 << "-ого студента "; cin >> students.group;
			cout << "ФИО куратора" << i + 1 << "-ого студента "; cin >> students.surname;
			cout << "Cпециальность" << i + 1 << "-ого студента "; cin >> students.spatual;
			cout << "Оценка" << i + 1 << "-ого студента "; cin >> students.crMark;
			file.write(reinterpret_cast<char*>(&students), sizeof(students));
		}
		file.close();
	}
}
void info()
{
	/*получение информации */
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
		cout << "номер группы" << s.group << endl;
		cout << "ФИО куратора" << s.surname << endl;
		cout << "Cпециальность" << s.spatual << endl;
		cout << "оценка" << s.crMark << endl;
		file.read(reinterpret_cast<char*>(&s), sizeof(s));
	}
	file.close();
}
void search()
{
	/*Вывод информации о группах по введенной пользователем фамилии
куратора из выбранного пользователем файла.*/
	student s;
	char name[10];
	cout << "введите имя/n";
	cin >> name;
	char g[10];
	cout << "введите фамилию куратора\n";
	cin >> g
	ifstream file(name, ios::binary);
	file.read(reinterpret_cast<char*>(&s), sizeof(s));
	while (!file.eof())
	{
		if (ctrcmp(g, s.surname) == 0)
		{
			cout << "фамилия " << s.group << endl;
			cout << "номер группы " << s.surname << endl;
			cout << "Cпециальность " << s.spatual << endl;
			cout << "оценка " << s.crMark << endl;
		}
		file.read(reinterpret_cast<char*>(&s), sizeof(s));
	}
}
void min()
{
	/*Вывод информации обо всех группах со средним баллом ниже.*/
	student s;
	char name[10];
	cout << "введите имя/n";
	cin >> name;
	ifstream file(name, ios::binary);
	file.read(reinterpret_cast<char*>(&s), sizeof(s));
	while (!file.eof())
	{
		if (s.crMark <= 7)
		{
			cout << "фамилия " << s.group << endl;
			cout << "номер группы " << s.surname << endl;
			cout << "Cпециальность " << s.spatual << endl;
			cout << "оценка " << s.crMark << endl;
		}
		file.read(reinterpret_cast<char*>(&s), sizeof(s));
	}
}
void bell() {
	/*1. Удаление информации из выбранного бинарного файла о группе с
выбранным номером.*/
	{

		student s;
		char name[10];
		cout << "введите имя файла\n";
		cin >> name;
		int n, c = 0;
		cout << "введите немер :";
		cin >> n;

		ifstream file(name, ios::binary);
		ofstream tmp("tmp.bin", ios::binary);

		file.read(reinterpret_cast<char*>(&s), sizeof(s));

		while (!file.eof())
		{
			cout << s.group << "*" << endl;
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
}
void change() {
	/*2. Изменение информации о ФИО куратора для всех групп из выбранного
файла, имеющих средний балл меньше, чем вводит пользователь.*/
	student s;
	char name[10];
	cout << "введите имя/n";
	cin >> name;
	int n, c = 0;
	char cyr[10];
	cout << "введите средный балл";
	cin >> n;
	ifstream file(name, ios::binary);
	ofstream tmp("tmp.bin", ios::binary);
	file.read(reinterpret_cast<char*>(&s), sizeof(s));

	while (!file.eof())
	{
		if (s.crMark < n) {
			cout << "введите нового куратора";
			cin >> cyr;
			s.surname = cyr;
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
void maxCpat() {
	/*3. Вывод названий специальностей с максимальным средним баллом из
выбранного файла.*/
	student s;
	char name[10];
	cout << "введите имя файла\n";
	cin >> name;
	int n;
	ifstream file(name, ios::binary);
	ofstream tmp("tmp.bin", ios::binary);

	file.read(reinterpret_cast<char*>(&s), sizeof(s));

	while (!file.eof())
	{
		cout << s.spatual << "*" << endl;
		if (s.crMark <= 5) {
			tmp.write(reinterpret_cast<char*>(&s), sizeof(s));

		}

		file.read(reinterpret_cast<char*>(&s), sizeof(s));

	}

	file.close();

	tmp.close();

	remove(name);
	rename("tmp.bin", name);


}
void() {
	/*Изменение информации о ФИО куратора по введенному номеру
	группы. Файл вводит пользователь*/
}
int main()
{
	setlocale(LC_ALL, "RUS");
	int input = 0;
	cout << "1. Ввод информации о группах с клавиатуры и сохранение ее в бинарном файле с выбранным пользователем названием.\n 2. Просмотр содержимого бинарного файла с выбранным пользователем названием.\n 3. Вывод информации о группах по введенной пользователем фамилии куратора из выбранного пользователем файла./n4. Вывод информации обо всех группах со средним баллом ниже\n";
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
		min();
		break;
	case 5:
		bell();
		break;
	case 6:
		maxCpat();
		break;

	default:
		break;
	}
}