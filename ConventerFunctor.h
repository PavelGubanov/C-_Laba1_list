#pragma once

class ConventerFunctor
{
	int _sum;
public:
	ConventerFunctor(int sum);

	//���������� ��������� ������ �������
	void operator()(int& x);
};

