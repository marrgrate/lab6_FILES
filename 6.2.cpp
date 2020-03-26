//Компоненты файла f – положительные вещественные числа. Получить файл g
//из чисел исходного файла, в котором записаны сначала все числа больше 1, затем
//остальные числа.

#include "6.2.h"


int func()
{
	ifstream in_tfile("C:\\Users\\pstolbovskaya\\source\\repos\\lab6_masha\\lab6_masha\\file1.txt");	//исходный файл
	ofstream out_tfile1("C:\\Users\\pstolbovskaya\\source\\repos\\lab6_masha\\lab6_masha\\file2.txt"), //для первой части массива
		out_tfile2("C:\\Users\\pstolbovskaya\\source\\repos\\lab6_masha\\lab6_masha\\file3.txt");	//для второй части массива

	if (!out_tfile1)
		cout << "Файл 2 не найден или " <<
		"заблокирован другой программой" << endl;
	if (!out_tfile2)
		cout << "Файл 3 не найден или " <<
		"заблокирован другой программой" << endl;
	if (!in_tfile)
		cout << "Файл 1 не найден или " <<
		"заблокирован другой программой" << endl;
	else
	{
		//text file
		float i;
		while (true)
		{
			in_tfile >> i;
			if (in_tfile.fail() && in_tfile.eof())
				break;
			if (i > 1)
				out_tfile1 << i << " ";
			else
				out_tfile2 << i << " ";
		}
		in_tfile.close();
		out_tfile2.close();

		ifstream in_file("file3.txt");
		if (!in_file)
			cout << "File openning error\n";
		else
			while (true)
			{
				in_file >> i;
				if (in_file.fail() && in_file.eof())
					break;
				out_tfile1 << i << " ";
			}

		in_file.close();
		out_tfile1.close();
	}

	//-----------------------------------//
		//binary
	cout << endl << "BINARY FILE" << endl;
	////заполнение исходного файла числами
	//ofstream out_bfile("file1.bin", ios::binary);
	//float num = 0, delta = 0.3;
	//if (!out_bfile)
	//	cout << "File openning error\n";
	//else
	//{
	//	for (num = 0; num <= 1.5; num += delta)
	//	{
	//		out_bfile.write((char*)&num, sizeof(num));
	//		cout << num << endl;
	//	}
	//	out_bfile.close();
	//}


	ifstream file1("file1.bin", ios::binary);
	ofstream file2("file2.bin", ios::binary),  //результирующий файл
		file3("file3.bin", ios::binary);

	if (!file2)
		cout << "файл 2 не найден или заблокирован другой программой" << endl;
	if (!file3)
		cout << "файл 3 не найден или заблокирован другой программой" << endl;
	if (!file1)
		cout << "файл 1 не найден или заблокирован другой программой" << endl;
	else
	{
		float num;
		file1.seekg(0, ios::end);
		streampos file_size = file1.tellg();
		cout << endl << "file size:\t" << file_size << " bytes" << endl;
		int count = file_size / sizeof(float);
		cout << "number of elements:\t" << count << endl;

		file1.seekg(0, ios::beg);
		for (int i = 0; i < count; i++)
		{
			file1.read((char*)&num, sizeof(num));
			cout << num << ' ';
			if (num > 1)
				file2.write((char*)(&num), sizeof(num));
			else
				file3.write((char*)&num, sizeof(num));
		}
		
		file1.close();
		file2.close();
		file3.close();

		ifstream file3("file3.bin", ios::binary);
		fstream file2("file2.bin", ios::binary | ios::in |ios::out);

		if (!file3)
			cout << "file3 openning error\n";
		else
		{
			file3.seekg(0, ios::end);
			streampos pos = file3.tellg();
			count = pos / sizeof(float);

			file3.seekg(0, ios::beg);
			file2.seekp(0, ios::end);
			for (int i = 0; i < count; i++)
			{
				file3.read((char*)&num, sizeof(num));
				file2.write((char*)&num, sizeof(num));
			}
		}
		file2.close();
		file3.close();
		
		//вывод
		ifstream f2("file2.bin");
		f2.seekg(0, ios::end);
		streampos pos = f2.tellg();
		count = pos / sizeof(float);
		cout << endl;

		if (f2)
		{
			f2.seekg(0, ios::beg);
			for (int i = 0; i < count; i++)
			{
				f2.read((char*)&num, sizeof(num));
				cout << num << ' ';
			}
			f2.close();
		}
		return 0;
	}
}

