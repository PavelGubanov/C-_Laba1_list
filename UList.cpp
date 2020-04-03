#include "UList.h"
#include "TransformFunctor.h"
#include "ConventerFunctor.h"


//вычисление суммы элементов списка
int sum(list<int> &List)
{
	return sum(List.cbegin(), List.cend());
}

//вычисление суммы элементов списка (на вход - контейнер)
//(на вход - итераторы начала и конца обрабатываемого участка)
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

//преобразование: вычитание из каждого числа списка суммы всех его чисел (на вход - контейнер)
list<int> modify(list<int>& List)
{
	return modify(List.begin(), List.end());
}

//вычисление среднего арифметического элементов списка
float average(list<int>& List)
{
	return sum(List) / List.size();
}

//преобразование: вычитание из каждого числа списка суммы всех его чисел 
//(на вход - итераторы начала и конца обрабатываемого участка)
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

//преобразование с использованием алгоритма std::transform вместо функции modify
//на вход - итераторы начала и конца обрабатываемого участка
void transform(list<int>::iterator begin, list<int>::iterator end)
{
	transform(begin, end, begin, TransformFunctor(sum(begin, end)));
}

//преобразование с использованием алгоритма std::transform вместо функции modify
//на вход - контейнер list
void transform(list<int>& List)
{
	transform(List.begin(), List.end());
}

//преобразование с использованием алгоритма std::for_each вместо функции modify
//на вход - итераторы начала и конца обрабатываемого участка
void for_each(list<int>::iterator begin, list<int>::iterator end)
{
	for_each(begin, end, ConventerFunctor(sum(begin, end)));
}

//преобразование с использованием алгоритма std::for_each вместо функции modify
//на вход - контейнер list
void for_each(list<int>& List)
{
	for_each(List.begin(), List.end());
}

//перегрузка оператора вывода для контейнера list
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

//печать содержимого контейнера на экран
void print(const list<int>& List)
{
	cout << "\nДанный список имеет вид: " << List;
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
