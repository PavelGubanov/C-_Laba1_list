#pragma once
class RandomFunctor
{
	int _M;
public:
	RandomFunctor(int M);
	//перегрузка оператора вызова функции
	int operator()();
};

