#include "MainMenu.h"
#include "UList.h"
#include "UFile.h"
#include <cstdio>
#include <string>
#include <locale>
#include <list>

using namespace std;

//������ ��������� �� ������� �� ����� ������
void get_eoln() 
{
	do {

	} while (getchar() != '\n');
}

//���� ����� � ����������� ��������� ��� �� �������������� ������� [min, max]
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

//���� ������ �� �������
string get_string(string text) 
{
	cout << text;
	string result_string;
	getline(cin, result_string);
	return result_string;
}

//������ ������� �������� ���� � ����������� �� ������� ��������� � ������
int print_main_menu(bool ListIsEmpty = false) {
	int stop_item = 2;
	cout << endl;
	cout << "�������� ���� �� ������� ����:" << "\n"
		 << "0 - ����� �� ���������" << "\n"
		 << "1 - ��������� ��������� ���� ���������� �������" << "\n"
		 << "2 - ������� ������ �� ���������� �����" << "\n";
	if (!ListIsEmpty) {
		cout << "3 - ��������� �������������� ������ ��� ������ modify" << "\n"
			 << "4 - ��������� �������������� ������ ��� ������ transform" << "\n"
			 << "5 - ��������� �������������� ������ ��� ������ for_each" << "\n"
			 << "6 - ����� ����� ���� ����� � ������" << "\n"
			 << "7 - ����� ������� �������������� ����� � ������" << "\n"
			 << "8 - ������� ������ � ������� ��� � ����" << "\n"
			 << "9 - �������� �������" << "\n";
		stop_item = 9;
	}
	cout << endl;
	return stop_item;
}

//������� ���� ��� ���������
void main_menu()
{
	setlocale(LC_ALL, "Russian");
	cout << "�������� ������ - ������� �� ������� ����� ����� ���� �����." << endl;
	int stop_item, cur_item = 1;
	list<int> List;
	while (cur_item != 0) 
	{
		stop_item = print_main_menu(List.empty());
		cur_item = get_num("��� ����� - ", "������! ����� ����� ����������� � ����. ��������� ����!", 0, stop_item);
		switch (cur_item)
		{
			case 1:
			{
				int M = get_num("������� ����� ����� M ��� ��������� [-M, M] ������������� ��������� ����� (�� ������ 1 � �� ����� 150):\n",
					"\n������! �������� ����� ��������� ��� ��������� ��������� �����! ��������� ����!\n", 0, 150);
				int N = get_num("������� ���������� N ��������� ����� (�� ������ 1 � �� ����� 150):\n",
					"\n������! �������� ����� ��������� ��� ��������� ��������� �����! ��������� ����!\n", 0, 150);
				string name = get_string("������� ��� ���������� ����� (��� ������������):\n");
				try {
					if (get_num("��� �� ������ ��������� ������? (1 - � ������� �����, 2. � ������� generate): ", "\n������. ��������� ����!\n", 1, 2) == 1)
						fill_file_cycle(N, M, name);
					else
						fill_file_generate(N, M, name);
					cout << "��������� ���� ������� �������� ���������� �������." << endl;
				}
				catch (exception e) 
				{
					cout << endl << e.what() << endl;
				}
				break;
			}
			case 2:
			{
				ifstream fi(get_full_filename(get_string("������� ��� �����: ")));
				if (!fi.is_open())
					cout << "�� ������ ������� ��������� ����." << endl;
				else
				{
					if (fi.peek() == EOF)
					{
						cout << "��������� ���� - ������." << endl;
					}
					else
					{
						List = fill_container(fi);
						cout << "��������� �������� ���������� �� ���������� �����." << endl;
					}
					fi.close();
				}
				break;
			}
			case 3:
			{
				if (get_num("��� ������� ���������� ������: 1 - � ������� ����������, 2 - � ������� ����������? ", "\n������, ��������� ����!\n", 1, 2) == 1)
				{
					List = modify(List);
				}
				else
				{
					List = modify(List.begin(), List.end());
				}
				cout << "\n��������� ������������.\n";
				break;
			}
			case 4:
			{
				if (get_num("��� ������� ���������� ������: 1 - � ������� ����������, 2 - � ������� ����������? ", "\n������, ��������� ����!\n", 1, 2) == 1)
				{
					transform(List);
				}
				else
				{
					transform(List.begin(), List.end());
				}
				cout << "\n��������� ������������.\n";
				break;
			}
			case 5:
			{
				if (get_num("��� ������� ���������� ������: 1 - � ������� ����������, 2 - � ������� ����������? ", "\n������, ��������� ����!\n", 1, 2) == 1)
				{
					for_each(List);
				}
				else
				{
					for_each(List.begin(), List.end());
				}
				cout << "\n��������� ������������.\n";
				break;
			}
			case 6:
			{
				cout << "����� ���� ����� � ������ ����� = " << sum(List) << endl;
				break;
			}
			case 7:
			{
				cout << "������� �������������� ����� � ������ = " << average(List) << endl;
				break;
			}
			case 8:
			{
				if (get_num("���� �� ������ ������� ������: 1 - � �������, 2 - � ����? ", "\n������, ��������� ����!\n", 1, 2) == 1)
				{
					print(List);
				}
				else
				{
					ofstream fout(get_full_filename(get_string("������� ��� �����:")));
					if (!fout.is_open())
					{
						cout << "\n�� ������� ������� ���� � ����� ������.\n";
					}
					else
					{
						fout << List;
						cout << "\n���� �������� ���������� ����������.\n";
						fout.close();
					}
				}
				break;
			}
			case 9:
			{
				List.clear();
				cout << "������ ������.";
				break;
			}
			case 0:
			{
				break;
			}
		}
	}
}
