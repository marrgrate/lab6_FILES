#include "6.1.h"
//6.1. СТРОКИ STRING

//Выполнить задания 4.1, 4.2, 4.3, используя string - строки для представления
//данных.Задания выполнить через функции.

int main()
{
	setlocale(LC_ALL, "Russian");
	unsigned int n, counter = 3;

	cout << "Выберите задание:" << endl
		<< "1 - 4.1\n2 - 4.2\n3 - 4.3" << endl;
	while (counter)
	{
		cin >> n;
		if (cin && n > 0 && n < 4) break;
		counter--;
		cin.clear();
		rewind(stdin);
		cout << "Неверное значение. Повторите ввод\t" << endl;
	}

	switch (n) 
	{
	case 1:	task_4_1(); break;
	case 2:	task_4_2(); break;
	case 3: task_4_3();	break;
	default: return 0;
	}
	
	return 0;
}
