//Написать программу для работы с базой данных, содержащей записи со
//сведениями о студентах : ФИО, возраст, пол, курс, успеваемость, в которой
//должны выполняться следующие действия :
//• создание файла
//• просмотр файла
//
//По исходному файлу определить студентов, имеющих средний балл успе-
//ваемости выше общего среднего балла. Сформировать файл из этих студентов.

#include "6.3_func_bin.h"
enum MODE
{
	TXT = 1,
	BIN
};

int main()
{
	while (true)
	{
		setlocale(LC_ALL, "Russian");
		int file_mode;	//file openning mode
		cout << "\tMAIN MENU\n"
			<< "Select a file mode\n1 - TXT\n2 - BIN\n";
		cin >> file_mode;

		switch (file_mode)
		{
		case TXT:
		{
			int n = file_mode_txt();
			if (n == 2) return 0;
			break;
		}
		case BIN:
		{
			int n = file_mode_bin();
			if (n == 2) return 0;
			break;
		}
		default: return 0;
		}
		system("pause");
		system("CLS");
	}
}

