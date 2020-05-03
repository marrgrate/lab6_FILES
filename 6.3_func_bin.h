#pragma once
#include "6.3_func_txt.h"
#define PATH_BIN "C:\\Users\\pstolbovskaya\\source\\repos\\lab6_masha\\lab6_masha\\database.bin"

int file_mode_bin();
float get_average_bin(ifstream& i_file, Student& st);
void show_file_bin(fstream* file);
string task_bin();
