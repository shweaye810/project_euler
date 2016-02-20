#include <iostream>

#include "calendar.h"

using namespace std;

Year::Year(int y) 
{
    m[2] = 28;
    if (y % 4 == 0)
        m[2] = 29;
    m[9] = m[4] = m[6] = m[11] = 30;
    m[1] = m[3] = m[5] = m[7] = m[8] = m[10] = m[12] = 31;
}

ostream& operator<<(ostream &out, const Year &o)
{
    for (int i = 1; i <= MONTH_SIZE; i++)
        out << i << " month has " << o.m[i] << " days.\n" << endl;
    return out;
}

int Year::get(int n)
{
    return this->m[n];
}
