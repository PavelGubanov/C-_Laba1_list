#pragma once

class TransformFunctor
{
	int _sum; // ����� ���� ��������� ������
public:
	TransformFunctor(int sum);

	//���������� ��������� ������ �������
	int operator()(int x);
};

