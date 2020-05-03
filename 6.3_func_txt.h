#pragma once
#include <iostream>
#include<string>
#include <fstream>

#define PATH_TXT "C:\\Users\\pstolbovskaya\\source\\repos\\lab6_masha\\lab6_masha\\database.txt"

using namespace std;

struct Student
{
	char name[30];
	char last_name[30];
	unsigned int age;
	bool gender;	//1 - Ì | 0 - Æ
	unsigned int course; // 0 < course < 6
	float gpa; //grade point average
};

int file_mode_txt();
ifstream& read_txt(ifstream& in, Student& st);
string task_txt();
ostream& write_txt(ostream& out, const Student& st);
void show_file_txt(ifstream& file);
float s_to_float(string str);
void init_student(Student* st);
int valid_input_age(int num);
int valid_input_course(int num);
float valid_input_gpa(float num);