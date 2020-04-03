#include "TransformFunctor.h"

TransformFunctor::TransformFunctor(int sum)
{
	_sum = sum;
}

//перегрузка оператора вызова функции
int TransformFunctor::operator()(int x)
{
	return x - _sum;
}
