#include "6.4_func.h"

void print(School s)
{
    cout << endl;
    cout << " ¹" << s.school_number << '\t' << s.class_number;
    cout << "'" << s.letter << "'" << endl;
}

//function generates letter from array alph[] randomly
char rand_letter()
{
    char alph[9] = "ÀÁÂÃÄÅÆÇ";
    char c;
    return c = alph[rand() % 8 + 0];
}

//structure initialization
void init(School* s)
{
    s->class_number = rand() % 11 + 1;
    s->school_number = rand() % 277 + 1;
    s->letter = rand_letter();
}

//comparison 
bool compare(const School& a, const School& b)
{
    if (a.school_number < b.school_number)
        return true;
    else return false;
}

//overloading of '=='
bool operator ==(const School& s1, const School& s2)
{
    return(s1.school_number == s2.school_number
        && s1.class_number == s2.class_number
        && s1.letter == s1.letter);
}

//function return 'true' if array[i] has repeating copies in  the hole array
bool find_repeating(School* array, int size, int ind)
{
    for (int j = ind + 1; j < size; j++)
        if (array[ind] == array[j])
            return true;
    return false;
}