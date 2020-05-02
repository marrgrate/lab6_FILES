#pragma once
#include <iostream>
#include <algorithm>
#define SIZE 10 //размер массива объединений

using namespace std;

union School
{
    unsigned short school;
    struct
    {
        unsigned school_number : 16;
        unsigned class_number : 8;
        unsigned char letter : 8;
    };
};

void print(School s);
char rand_letter();
void init(School* s);
bool compare(const School& a, const School& b);
bool operator ==(const School& s1, const School& s2);
bool find_repeating(School* array, int size, int ind);


