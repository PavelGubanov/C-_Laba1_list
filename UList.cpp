#include "UList.h"
#include "TransformFunctor.h"
#include "ConventerFunctor.h"


//���������� ����� ��������� ������
int sum(list<int> &List)
{
	return sum(List.cbegin(), List.cend());
}

//���������� ����� ��������� ������ (�� ���� - ���������)
//(�� ���� - ��������� ������ � ����� ��������������� �������)
int sum(list<int>::const_iterator cbegin, list<int>::const_iterator cend)
{
	int result_sum = 0;
	auto iter = cbegin;
	while (iter != cend) {
		result_sum += *iter;
		iter++;
	}
	return result_sum;
}

//��������������: ��������� �� ������� ����� ������ ����� ���� ��� ����� (�� ���� - ���������)
list<int> modify(list<int>& List)
{
	return modify(List.begin(), List.end());
}

//���������� �������� ��������������� ��������� ������
float average(list<int>& List)
{
	return sum(List) / List.size();
}

//��������������: ��������� �� ������� ����� ������ ����� ���� ��� ����� 
//(�� ���� - ��������� ������ � ����� ��������������� �������)
list<int> modify(list<int>::iterator cbegin, list<int>::iterator cend)
{
	list<int> result_list;
	int sum_list = sum(cbegin, cend);
	auto iter = cbegin;
	while (iter != cend) {
		result_list.push_back(*iter - sum_list);
		iter++;
	}
	return result_list;
}

//�������������� � �������������� ��������� std::transform ������ ������� modify
//�� ���� - ��������� ������ � ����� ��������������� �������
void transform(list<int>::iterator begin, list<int>::iterator end)
{
	transform(begin, end, begin, TransformFunctor(sum(begin, end)));
}

//�������������� � �������������� ��������� std::transform ������ ������� modify
//�� ���� - ��������� list
void transform(list<int>& List)
{
	transform(List.begin(), List.end());
}

//�������������� � �������������� ��������� std::for_each ������ ������� modify
//�� ���� - ��������� ������ � ����� ��������������� �������
void for_each(list<int>::iterator begin, list<int>::iterator end)
{
	for_each(begin, end, ConventerFunctor(sum(begin, end)));
}

//�������������� � �������������� ��������� std::for_each ������ ������� modify
//�� ���� - ��������� list
void for_each(list<int>& List)
{
	for_each(List.begin(), List.end());
}

//���������� ��������� ������ ��� ���������� list
ostream& operator<<(ostream& out, const list<int>& List)
{
	auto iter = List.cbegin();
	while (iter != List.cend()) {
		out << *iter;
		if (iter != List.cend()) {
			out << ", ";
		}
		iter++;
	}
	out << endl;
	return out;
}

//������ ����������� ���������� �� �����
void print(const list<int>& List)
{
	cout << "\n������ ������ ����� ���: " << List;
}

list<int> fill_container(ifstream& fin)
{
	list<int> result_list;
	int tmp;
	while (!fin.eof()) 
	{
		if (fin >> tmp) 
		{
			result_list.push_back(tmp);
		}			
	}
	return result_list;
}
