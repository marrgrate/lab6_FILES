//���������� ����������� � �������� ������ ��� ������������� �������� ����������. 
//������� ������� ������ ����� �� �����.
//������������� ��������� ������ ����� ��������.
//������������� �������� ������� ����������� �������� std::sort.
//����� ������������� �������� � ������� �� �� �����.

//10. ������������ ��� unsigned short, ������� ����: ����� ����� (1..277),
//�����(����� 1..11 � ������� ����� �..�).

#include "6.4_func.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    School s[SIZE];
    for (int i = 0; i < SIZE - 2; i++)
        init(s + i);

    //create some equal elements 
    s[SIZE - 1] = s[1];
    s[SIZE - 2] = s[0];

    cout << "\nSchool:\t" << "Class:\n";
    for (int i = 0; i < SIZE; i++)   
         print(s[i]);
   
    sort(s + 0, s + SIZE, compare);

    cout << "\n\tSORTED ARRAY\n";
    cout << "\nSchool:\t" << "Class:\n";
    for (int i = 0; i < SIZE; i++)
        print(s[i]);

    cout << "\n\tREPEATING ELEMENTS\n";
    bool flag = 0;
    for (int i = 0; i < SIZE; i++)
        if (find_repeating(s, SIZE, i))
        {
            print(s[i]);
            flag = 1;
        }
    if(!flag)
        cout << "No equal elements\n";

    return 0;
}