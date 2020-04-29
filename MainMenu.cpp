#include "MainMenu.h"
#include "UList.h"
#include "UFile.h"
#include <cstdio>
#include <string>
#include <locale>
#include <list>

using namespace std;

//чтение элементов из консоли до конца строки
void get_eoln() 
{
	do {

	} while (getchar() != '\n');
}

//ввод числа с последующей проверкой его на принадлежность отрезку [min, max]
int get_num(string str, string err, int min, int max) 
{
	int num;
	cout << str;
	cin >> num;
	get_eoln();
	while (num < min || num > max) {
		cout << str;
		cin >> num;
		get_eoln();
	}
	return num;
}

//ввод строки из консоли
string get_string(string text) 
{
	cout << text;
	string result_string;
	getline(cin, result_string);
	return result_string;
}

//печать пунктов главного меню в зависимости от наличия элементов в списке
int print_main_menu(bool ListIsEmpty = false) {
	int stop_item = 2;
	cout << endl;
	cout << "Выберите один из пунктов меню:" << "\n"
		 << "0 - выйти из программы" << "\n"
		 << "1 - заполнить текстовый файл случайными числами" << "\n"
		 << "2 - считать список из текстового файла" << "\n";
	if (!ListIsEmpty) {
		cout << "3 - выполнить преобразование списка при помощи modify" << "\n"
			 << "4 - выполнить преобразование списка при помощи transform" << "\n"
			 << "5 - выполнить преобразование списка при помощи for_each" << "\n"
			 << "6 - найти сумму всех чисел в списке" << "\n"
			 << "7 - найти среднее арифметическое чисел в списке" << "\n"
			 << "8 - вывести список в консоль или в файл" << "\n"
			 << "9 - очистить очередь" << "\n";
		stop_item = 9;
	}
	cout << endl;
	return stop_item;
}

//главное меню для программы
void main_menu()
{
	setlocale(LC_ALL, "Russian");
	cout << "Основная задача - вычесть из каждого числа сумму всех чисел." << endl;
	int stop_item, cur_item = 1;
	list<int> List;
	while (cur_item != 0) 
	{
		stop_item = print_main_menu(List.empty());
		cur_item = get_num("Ваш выбор - ", "Ошибка! Такой пункт отсутствует в меню. Повторите ввод!", 0, stop_item);
		switch (cur_item)
		{
			case 1:
			{
				int M = get_num("Введите целое число M для диапозона [-M, M] генерирования случайных чисел (не меньше 1 и не более 150):\n",
					"\nОшибка! Введённое число находится вне диапозона возможных чисел! Повторите ввод!\n", 0, 150);
				int N = get_num("Введите количество N случайных чисел (не меньше 1 и не более 150):\n",
					"\nОшибка! Введённое число находится вне диапозона возможных чисел! Повторите ввод!\n", 0, 150);
				string name = get_string("Введите имя текстового файла (без спецификации):\n");
				try {
					if (get_num("Как вы хотите заполнить список? (1 - с помощью цикла, 2. с помощью generate): ", "\nОшибка. Повторите ввод!\n", 1, 2) == 1)
						fill_file_cycle(N, M, name);
					else
						fill_file_generate(N, M, name);
					cout << "Указанный файл успешно заполнен случайными числами." << endl;
				}
				catch (exception e) 
				{
					cout << endl << e.what() << endl;
				}
				break;
			}
			case 2:
			{
				ifstream fi(get_full_filename(get_string("Введите имя файла: ")));
				if (!fi.is_open())
					cout << "Не удаётся открыть указанный файл." << endl;
				else
				{
					if (fi.peek() == EOF)
					{
						cout << "Указанный файл - пустой." << endl;
					}
					else
					{
						List = fill_container(fi);
						cout << "Контейнер заполнен элементами из указанного файла." << endl;
					}
					fi.close();
				}
				break;
			}
			case 3:
			{
				if (get_num("Как следует обработать список: 1 - с помощью переменной, 2 - с помощью итераторов? ", "\nОшибка, повторите ввод!\n", 1, 2) == 1)
				{
					List = modify(List);
				}
				else
				{
					List = modify(List.begin(), List.end());
				}
				cout << "\nКонтейнер преобразован.\n";
				break;
			}
			case 4:
			{
				if (get_num("Как следует обработать список: 1 - с помощью переменной, 2 - с помощью итераторов? ", "\nОшибка, повторите ввод!\n", 1, 2) == 1)
				{
					transform(List);
				}
				else
				{
					transform(List.begin(), List.end());
				}
				cout << "\nКонтейнер преобразован.\n";
				break;
			}
			case 5:
			{
				if (get_num("Как следует обработать список: 1 - с помощью переменной, 2 - с помощью итераторов? ", "\nОшибка, повторите ввод!\n", 1, 2) == 1)
				{
					for_each(List);
				}
				else
				{
					for_each(List.begin(), List.end());
				}
				cout << "\nКонтейнер преобразован.\n";
				break;
			}
			case 6:
			{
				cout << "Сумма всех чисел в списке равна = " << sum(List) << endl;
				break;
			}
			case 7:
			{
				cout << "Среднее арифметическое чисел в списке = " << average(List) << endl;
				break;
			}
			case 8:
			{
				if (get_num("Куда Вы хотети вывести список: 1 - в консоль, 2 - в файл? ", "\nОшибка, повторите ввод!\n", 1, 2) == 1)
				{
					print(List);
				}
				else
				{
					ofstream fout(get_full_filename(get_string("Введите имя файла:")));
					if (!fout.is_open())
					{
						cout << "\nНе удалось создать файл с таким именем.\n";
					}
					else
					{
						fout << List;
						cout << "\nФайл заполнен элементами контейнера.\n";
						fout.close();
					}
				}
				break;
			}
			case 9:
			{
				List.clear();
				cout << "Список очищен.";
				break;
			}
			case 0:
			{
				break;
			}
		}
	}
}
