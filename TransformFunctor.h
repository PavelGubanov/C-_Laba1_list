#pragma once

class TransformFunctor
{
	int _sum; // сумма всех элементов списка
public:
	TransformFunctor(int sum);

	//перегрузка оператора вызова функции
	int operator()(int x);
};

