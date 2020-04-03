#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>

using namespace std;

//вычисление суммы элементов списка (на вход - контейнер)
int sum(list<int>& List);

//вычисление суммы элементов списка (на вход - контейнер)
//(на вход - итераторы начала и конца обрабатываемого участка)
int sum(list<int>::const_iterator cbegin, list<int>::const_iterator cend);

//преобразование: вычитание из каждого числа списка суммы всех его чисел (на вход - контейнер)
list<int> modify(list<int>& List);

//вычисление среднего арифметического элементов списка
float average(list<int>& List);

//преобразование: вычитание из каждого числа списка суммы всех его чисел 
//(на вход - итераторы начала и конца обрабатываемого участка)
list<int> modify(list<int>::iterator cbegin, list<int>::iterator cend);

//преобразование с использованием алгоритма std::transform вместо функции modify
//на вход - итераторы начала и конца обрабатываемого участка
void transform(list<int>::iterator begin, list<int>::iterator end);

//преобразование с использованием алгоритма std::transform вместо функции modify
//на вход - контейнер list
void transform(list<int>& List);

//преобразование с использованием алгоритма std::for_each вместо функции modify
//на вход - итераторы начала и конца обрабатываемого участка
void for_each(list<int>::iterator begin, list<int>::iterator end);

//преобразование с использованием алгоритма std::for_each вместо функции modify
//на вход - контейнер list
void for_each(list<int>& List);

//перегрузка оператора вывода для контейнера list
ostream& operator <<(ostream& out, const list<int>& List);

//печать содержимого контейнера на экран
void print(const list<int>& List);

//Заполнение контейнера числами из полученного файла
list<int> fill_container(ifstream& f);