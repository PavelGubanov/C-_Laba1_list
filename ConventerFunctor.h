#pragma once

class ConventerFunctor
{
	int _sum;
public:
	ConventerFunctor(int sum);

	//перегрузка оператора вызова функции
	void operator()(int& x);
};

