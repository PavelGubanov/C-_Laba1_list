#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>

using namespace std;

//���������� ����� ��������� ������ (�� ���� - ���������)
int sum(list<int>& List);

//���������� ����� ��������� ������ (�� ���� - ���������)
//(�� ���� - ��������� ������ � ����� ��������������� �������)
int sum(list<int>::const_iterator cbegin, list<int>::const_iterator cend);

//��������������: ��������� �� ������� ����� ������ ����� ���� ��� ����� (�� ���� - ���������)
list<int> modify(list<int>& List);

//���������� �������� ��������������� ��������� ������
float average(list<int>& List);

//��������������: ��������� �� ������� ����� ������ ����� ���� ��� ����� 
//(�� ���� - ��������� ������ � ����� ��������������� �������)
list<int> modify(list<int>::iterator cbegin, list<int>::iterator cend);

//�������������� � �������������� ��������� std::transform ������ ������� modify
//�� ���� - ��������� ������ � ����� ��������������� �������
void transform(list<int>::iterator begin, list<int>::iterator end);

//�������������� � �������������� ��������� std::transform ������ ������� modify
//�� ���� - ��������� list
void transform(list<int>& List);

//�������������� � �������������� ��������� std::for_each ������ ������� modify
//�� ���� - ��������� ������ � ����� ��������������� �������
void for_each(list<int>::iterator begin, list<int>::iterator end);

//�������������� � �������������� ��������� std::for_each ������ ������� modify
//�� ���� - ��������� list
void for_each(list<int>& List);

//���������� ��������� ������ ��� ���������� list
ostream& operator <<(ostream& out, const list<int>& List);

//������ ����������� ���������� �� �����
void print(const list<int>& List);

//���������� ���������� ������� �� ����������� �����
list<int> fill_container(ifstream& f);