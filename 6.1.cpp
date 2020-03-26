#include "6.1.h"
#include <string>


void task_4_1()
{
//Определить  является  ли  введенный текст: идентификатором, записью целого числа.

	string text; 

	cout << "\nвведите строку:\t";
	rewind(stdin);
	getline(cin, text);	

	bool is_num = 1, //1- число, 0 - не число
		is_id = 1; //1 - идентификатор, 0 - не идентификатор

	//проверка на запись целого числа
	string num = "+-012346789";
	if (text.find_first_not_of(num) != SIZE_MAX) //поиск первой не-цифры,
		is_num = 0;								//find_first_not_of возвр номер символа, либо max size_t
	
	if (is_num)
		cout << "введено целое число";
	else   //проверка на ввод идентификатора
	{
		string id = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";
		if (text[0] >= '0' && text[0] <= '9')
			is_id = 0;
		else
		{
			if (text.find_first_not_of(id) != SIZE_MAX)
				is_id = 0;
		}
		if (is_id)
			cout << "\nвведен идентификатор\n";
	}
	if (!is_num && !is_id)
		cout << "\nвведенный текст не явяется идентификатором/записью целого числа\n";
}


//проверка на ввод числа
int valid_input(int n)
{
	while (true)
	{
		cin >> n;
		if (cin && n >= 2 && n <=16) return n;
		cin.clear();
		rewind(stdin);
		cout << "Неверное значение. Повторите ввод\t" << endl;
	}
}

void task_4_2()
{
//Преобразовать заданное целое число из p-ичной системы счисления в q-ичную (р, q ≤ 16);
//исходное число имеет не более n знаков).

	unsigned int p, q;
	cout << "Cистема счисления №1 (2 <= p <= 16): "; p = valid_input(p = 0);
	cout << "Сиситема счисления №2 (2 <= q <= 16): "; q = valid_input(q = 0);

	string number;
	cout << "Число в с/с №1: ";
	rewind(stdin);
	getline(cin, number);

	int dec_number = 0;
	int length = number.length();	//количество разрядов
	int n = 1;

	//перевод в десятичную систему
	for (int i = length - 1; i >= 0; i--) 
	{
		if (number[i] >= '0' && number[i] <= '9')
			dec_number += int(number[i] - '0') * n;
		else
			dec_number += (10 + int(number[i] - 'A')) * n;
		n *= p;
	}

	n = 0;	
	int rest;	//остаток от деления
	char result[100] = "";	

	//перевод в q-систему счисления
	do 
	{
		rest = dec_number % q;
		if (rest < 10)
			result[n] = char('0' + rest);
		else
			result[n] = char('A' + rest - 10);
		n++;
		dec_number /= q;
	} while (dec_number);


	cout << "Число в с/с №2: ";
	cout << result;

	cout << endl;
}

#define OUT

void lexem(string str, string separators, OUT string& res)
{
	unsigned int word_begin = 0, //позиция начала лексемы
		word_end = 0;			//позиция конца

	word_begin = str.find_first_not_of(separators, word_end);
	word_end = str.find_first_of(separators, word_begin);    

	while (word_begin < str.length())
	{
		string word = str.substr(word_begin, word_end - word_begin);  // 
		if (same_symbol_check(word) == 0)
			{ 
			if (res.length())	//если в строке для записи уже что-то есть
				res += " ";		//записывем туда пробел " "
		    res += word;        //запись подходящего слова в новую строку        
			}

		word_begin = str.find_first_not_of(separators, word_end); 
		word_end = str.find_first_of(separators, word_begin);  

		if (word_end >= str.length())
			word_end = str.length();
	}
}


bool same_symbol_check(string word)		//возвращает true - если в слове есть одинаковые символы, false - если нету
//проверяет наличие одинаковых символов в непустой последовательности символов
{										
	for (unsigned int i = 0; i < word.length(); i++)
		for (unsigned int j = i + 1; j < word.length(); j++)
			if (word[i] == word[j])
				return true;
	return false;
}

void task_4_3()
{
//Текст – непустая последовательность символов.
//Символы - разделители: «пробел», «.», «,», «:», «;», «!», «?», «-», «(», «)».
//Записать в новую строку слова исходной строки, в которых нет одинаковых символов. 

	string separator(" .,;!?-:()");   // определение и инициализация строки разделителей
	string s1, s2;				//s1 - исходная строка, s2 - строка для записи подходящих слов

	cout << "Введите текст \n";
	rewind(stdin);
	getline(cin, s1);          //  ввод исходной строки
	lexem(s1, separator, OUT s2);
	cout << s2 << endl;          // вывод полученной строки    
}
