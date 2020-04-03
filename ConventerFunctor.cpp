#include "ConventerFunctor.h"

ConventerFunctor::ConventerFunctor(int sum)
{
	_sum = sum;
}

//перегрузка оператора вызова функции
void ConventerFunctor::operator()(int& x)
{
	x -= _sum;
}
