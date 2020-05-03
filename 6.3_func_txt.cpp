#include "6.3_func_txt.h"

//structure initialization
void init_student(Student* st)
{
	cout << "student's first name:\t";
	cin >> st->name;
	cout << "student's last name:\t";
	cin >> st->last_name;
	cout << "age:\t";
	st->age = valid_input_age(st->age);
	cout << "gender (1 - male | 0 - female):\t";
	cin >> st->gender;
	cout << "course:\t";
	st->course = valid_input_course(st->course);
	cout << "average point:\t";
	cin >> st->gpa;
	system("cls");
}
int valid_input_age(int num)
{
	int counter = 3;
	while (counter)
	{
		cin >> num;
		if (cin && num < 50 && num > 15) return num;
		counter--;
		cin.clear();
		rewind(stdin);
		cout << "incorrect input. try again\t" << endl;
	}
	return num;
}
int valid_input_course(int num)
{
	int counter = 3;
	while (counter)
	{
		cin >> num;
		if (cin && num > 0 && num < 6) return num;
		counter--;
		cin.clear();
		rewind(stdin);
		cout << "incorrect input. try again\t" << endl;
	}
	return num;
}
float valid_input_gpa(float num)
{
	int counter = 3;
	while (counter)
	{
		cin >> num;
		if (cin && num >= 0 && num <= 10) return num;
		counter--;
		cin.clear();
		rewind(stdin);
		cout << "Incorrect input. try again\t" << endl;
	}
	return num;
}

void show_file_txt(ifstream& file)
{
	if (file.peek() == EOF) cout << "file is empty!\n";
	Student st;
	cout << "______________________________________________\n";
	while (!file.eof())
	{
		read_txt(file, st);
		cout << "name:\t\t" << st.last_name << ' ' << st.name << endl;
		cout << "age:\t\t" << st.age << endl;
		cout << "gender:\t\t"; (st.gender == 1) ? cout << "male" : cout << "female";
		cout << "\ncourse:\t\t" << st.course << endl;
		cout << "average point:\t" << st.gpa << endl;
		cout << "______________________________________________\n";
	}
}
float get_average_txt(ifstream& i_file, Student& st)
{
	int counter = 0;
	float sum = 0, average; //average = sum / counter
	while (!i_file.eof())
	{
		read_txt(i_file, st);
		sum += st.gpa;
		counter++;
	}
	average = sum / counter;

	cout << "\naverage point\t" << average << endl;
	return average;
}
string task_txt()
//сформировать новый файл из студентов, средний балл которых выше общего среднего балла
{
	//open existing file for reading
	ifstream i_file(PATH_TXT);

	Student st;
	float average = get_average_txt(i_file, st);	//getting an average point
	i_file.close();

	ifstream i_file2(PATH_TXT);
	string file_name = "c:\\users\\pstolbovskaya\\source\\repos\\lab6_masha\\lab6_masha\\good_students.txt";
	fstream o_file(file_name);	//new file
	if (!o_file)
	{
		cout << "file openning error\n";
		return "error";
	}
	else
	{
		while (!i_file2.eof())
		{
			read_txt(i_file2, st);
			if (st.gpa >= average)
				write_txt(o_file, st);
		}
		i_file2.close();
		o_file.close();
		return file_name;
	}
}
ostream& write_txt(ostream& out, const Student& st)
{
	if(out) out << endl;
	out << st.name << endl << st.last_name << endl
		<< st.age << endl << st.gender << endl
		<< st.course << endl << st.gpa;
	return out;
}
ifstream& read_txt(ifstream& in, Student& st)
{
	string str;
	in >> str;
	for (unsigned int i = 0; i < str.length(); i++)
		st.name[i] = str.c_str()[i];
	st.name[str.length()] = '\0';
	in >> str;
	for (unsigned int i = 0; i < str.length(); i++)
		st.last_name[i] = str[i];
	st.last_name[str.length()] = '\0';
	in >> str;
	st.age = stoi(str);
	in >> str;
	st.gender = stoi(str);
	in >> str;
	st.course = stoi(str);
	in >> str;
	float num = stof(str);
	st.gpa = s_to_float(str);
	return in;
}

float s_to_float(string str)
{
	if (str.empty()) return 0;
	float num;
	num = stof(str);
	unsigned int i = 0;
	if(str.find_first_of('.') == string::npos) return num;
	do
	{
		i++;
	}
	while (str[i] != '.');
	i++;
	int k = 1;
	while (i < str.length())
	{
		int s = str[i] - '0';
		num += s / (float)pow(10, k);
		k++;
		i++;
	}
	return num;
}
int file_mode_txt()
{
	cout << "welcome to the student database\n";
	while (true)
	{
		int choice;
		cout << "enter: \n"
			<< "\t1 - to print existing database on the screen\n"
			<< "\t2 - to add new items to the database\n"
			<< "\t3 - find good students\n"
			<< "or enter any other character to finish the program\n"
			<< "\nyour choice?\t";

		cin >> choice;

		Student st;	//structure instance
		ifstream file(PATH_TXT, ios::in);
		if (!file)
			cout << "file openning error\n";
		else
		{
			switch (choice)
			{
			case 1:
			{
				file.seekg(0, ios::beg);
				show_file_txt(file);
				break;
			}
			case 2:
			{
				char ch;
				//enter student data until 'n' pressed
				file.close();
				ofstream o_file(PATH_TXT, ios::out | ios::app);
				do
				{
					cout << "enter student data" << endl;
					init_student(&st);
					write_txt(o_file, st);
					cout << "continue? (y/n)";
					cin >> ch;
				} while (ch == 'y');
				o_file.close();
				break;
			}
			case 3:
			{
				string file_name = task_txt();
				ifstream i_file(file_name, ios::in);
				show_file_txt(i_file);
				i_file.close();
				break;
			}
			default: return 2;
			}
		}
		system("pause");
		system("cls");
		file.close();
	}
	return 1;
}