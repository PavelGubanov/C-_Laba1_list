#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//создаёт полное имя для текстовых файлов в папке TextFiles 
string get_full_filename(string name);

//заполнение текстового файла N целыми случайными числами в диапазоне от -M до M
//с помощью цикла
void fill_file_cycle(int N, int M, string filename);

//заполнение текстового файла N целыми случайными числами в диапазоне от -M до M
//с использованием алгоритма std::generate
void fill_file_generate(int N, int M, string filename);