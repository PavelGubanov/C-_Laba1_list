#include "UFile.h"
#include <algorithm>
#include <list>
#include "RandomFunctor.h"

//������ ������ ��� ��� ��������� ������ � ����� TextFiles
string get_full_filename(string name)
{
	return "Files\\" + name + ".txt";
}

//���������� ���������� ����� N ������ ���������� ������� � ��������� �� -M �� M
//� ������� �����
void fill_file_cycle(int N, int M, string filename)
{
	ofstream fout(get_full_filename(filename));
	if (!fout.is_open()) {
		throw new exception("���� � ����� ������ �� ������� �������!");
	}
	RandomFunctor rf(M);
	for (int i = 0; i < N; i++) {
		fout << rf() << " ";
	}
	fout << endl;
	fout.close();
}

//���������� ���������� ����� N ������ ���������� ������� � ��������� �� -M �� M
//� �������������� ��������� std::generate
void fill_file_generate(int N, int M, string filename)
{
	ofstream fout(get_full_filename(filename));
	if (!fout.is_open()) {
		throw new exception("���� � ����� ������ �� ������� �������!");
	}
	list<int> tmp_list(N);
	generate(tmp_list.begin(), tmp_list.end(), RandomFunctor(M));
	auto iter = tmp_list.begin();
	while (iter != tmp_list.end()) {
		fout << *iter++ << " ";
	}
	fout << endl;
	fout.close();
}


