#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//������ ������ ��� ��� ��������� ������ � ����� TextFiles 
string get_full_filename(string name);

//���������� ���������� ����� N ������ ���������� ������� � ��������� �� -M �� M
//� ������� �����
void fill_file_cycle(int N, int M, string filename);

//���������� ���������� ����� N ������ ���������� ������� � ��������� �� -M �� M
//� �������������� ��������� std::generate
void fill_file_generate(int N, int M, string filename);