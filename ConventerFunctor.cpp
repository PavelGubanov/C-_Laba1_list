#include "ConventerFunctor.h"

ConventerFunctor::ConventerFunctor(int sum)
{
	_sum = sum;
}

//���������� ��������� ������ �������
void ConventerFunctor::operator()(int& x)
{
	x -= _sum;
}
