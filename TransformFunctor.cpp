#include "TransformFunctor.h"

TransformFunctor::TransformFunctor(int sum)
{
	_sum = sum;
}

//���������� ��������� ������ �������
int TransformFunctor::operator()(int x)
{
	return x - _sum;
}
