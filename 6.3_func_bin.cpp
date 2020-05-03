#include "6.3_func_bin.h"

void show_file_bin(fstream* file)
{
	if (file->peek() == EOF) 
	{
		cout << "file is empty!\n"; return;
	}
	Student st;
	file->read(reinterpret_cast<char*>(&st), sizeof(st));
	cout << "______________________________________________\n";
	while (!file->eof())
	{
		cout << "name:\t\t" << st.last_name << ' ' << st.name << endl;
		cout << "age:\t\t" << st.age << endl;
		cout << "gender:\t\t"; (st.gender == 1) ? cout << "male" : cout << "female";
		cout << "\ncorse:\t\t" << st.course << endl;
		cout << "average point:\t" << st.gpa << endl;
		cout << "______________________________________________\n";
		file->read(reinterpret_cast<char*>(&st), sizeof(st));
	}
}
float get_average_bin(ifstream& i_file, Student& st)
{
	int counter = 0;
	float sum = 0, average; //average = sum / counter
	while (!i_file.eof())
	{
		i_file.read(reinterpret_cast<char*>(&st), sizeof(st));
		sum += st.gpa;
		counter++;
	}
	average = sum / counter;

	cout << "\naverage point\t" << average << endl;
	return average;
}
string task_bin()
//return new file name
//сформировать новый файл из студентов, средний балл которых выше общего среднего балла
{
	//open existing file for reading
	ifstream i_file(PATH_BIN, ios::binary);

	Student st;
	float average = get_average_bin(i_file, st);	//getting an average point
	i_file.close();

	ifstream i_file2(PATH_BIN, ios::binary | ios::in);
	i_file.seekg(0, ios::beg);	// set file pointer to the begining

	//new file
	string file_name = "C:\\users\\pstolbovskaya\\source\\repos\\lab6_masha\\lab6_masha\\good_students.bin";
	ofstream o_file(file_name, ios::binary | ios::out);
	if (!o_file)
	{
		cout << "file openning error\n";
		return "error";
	}
	else
	{
		i_file2.read(reinterpret_cast<char*>(&st), sizeof(st));
		while (!i_file2.eof())
		{
			if (st.gpa >= average)
				o_file.write(reinterpret_cast<char*>(&st), sizeof(st));
			i_file2.read(reinterpret_cast<char*>(&st), sizeof(st));
		}
		i_file2.close();
		o_file.close();
		return file_name;
	}
}
int file_mode_bin()
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
		Student st;	
		fstream o_file(PATH_BIN, ios::binary | ios::app | ios::in | ios::out);
		if (!o_file.is_open())
			cout << "file openning error\n";
		else
		{
			switch (choice)
			{
			case 1:
			{
				o_file.seekg(0);
				show_file_bin(&o_file);
				break;
			}
			case 2:
			{
				char ch;
				//enter student data until 'n' pressed
				do
				{
					cout << "enter student data" << endl;
					init_student(&st);
					o_file.write(reinterpret_cast<char*>(&st), sizeof(Student));	//write to file
					cout << "continue? (y/n)";
					cin >> ch;
				} while (ch == 'y');
				break;
			}
			case 3:
			{
				string file_name = task_bin();
				fstream file(file_name, ios::binary | ios::in | ios::out);
				show_file_bin(&file);
				file.close();
				break;
			}
			default: return 2;
			}
		}
		system("pause");
		system("cls");
		o_file.close();
	}
	return 1;
}