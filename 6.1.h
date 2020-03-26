#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#define OUT

using namespace std;

void task_4_1();
void task_4_2();
void task_4_3();
int valid_input(int n);
void lexem(string str, string delim, OUT string& res);
bool same_symbol_check(string word);