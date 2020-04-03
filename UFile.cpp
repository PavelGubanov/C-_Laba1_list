#include "UFile.h"
#include <algorithm>
#include <list>
#include "RandomFunctor.h"

//создаёт полное имя для текстовых файлов в папке TextFiles
string get_full_filename(string name)
{
	return "Files\\" + name + ".txt";
}

//заполнение текстового файла N целыми случайными числами в диапазоне от -M до M
//с помощью цикла
void fill_file_cycle(int N, int M, string filename)
{
	ofstream fout(get_full_filename(filename));
	if (!fout.is_open()) {
		throw new exception("Файл с таким именем не удалось открыть!");
	}
	RandomFunctor rf(M);
	for (int i = 0; i < N; i++) {
		fout << rf() << " ";
	}
	fout << endl;
	fout.close();
}

//заполнение текстового файла N целыми случайными числами в диапазоне от -M до M
//с использованием алгоритма std::generate
void fill_file_generate(int N, int M, string filename)
{
	ofstream fout(get_full_filename(filename));
	if (!fout.is_open()) {
		throw new exception("Файл с таким именем не удалось открыть!");
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


