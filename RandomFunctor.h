#pragma once
class RandomFunctor
{
	int _M;
public:
	RandomFunctor(int M);
	//���������� ��������� ������ �������
	int operator()();
};

