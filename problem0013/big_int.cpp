#include <iostream>
#include <sstream>
#include "big_int.h"

using namespace std;

const long int NUM_DIGIT = 9;
const long int CAP = 1e9;

Big_Int::Big_Int() : sz(ARY_SIZE)
{
    for (int i = 0; i < sz; i++)
        num[i] = 0;
}

Big_Int::Big_Int(const string &s) : sz(ARY_SIZE)
{
    for (int i = 0; i < sz; i++)
        num[i] = 0;
    int size = s.size(), i = ARY_SIZE - 1;
    while (size > 0) {
        string tmp;
        if (size < NUM_DIGIT)
            tmp = s.substr(0, size); 
        else
            tmp = s.substr(size - NUM_DIGIT, NUM_DIGIT);
        stringstream sstr(tmp);
        sstr >> num[i--];
        size -= NUM_DIGIT;
    }
}

Big_Int::Big_Int(const Big_Int &other) : sz(other.sz)
{
    for (int i = 0; i < sz; i++)
        num[i] = other.num[i];
}
                                         
Big_Int Big_Int::operator+(const Big_Int &o)
{
    Big_Int tmp;
    for (int i = o.size() - 1; i >= 0; i--) {
//        cout << this->num[i] << " + " << o.num[i] << " + " << tmp.num[i];
        tmp.num[i] = tmp.num[i] + this->num[i] + o.num[i];
//        cout << " = " << tmp.num[i] << endl;

        if (i > 0) {
            tmp.num[i - 1] = tmp.num[i] / CAP;
            tmp.num[i] %= CAP;
        }
    }
    return tmp;
}

Big_Int Big_Int::operator+=(const Big_Int &o)
{
    *this = *this + o;
    return *this;
}
ostream& operator<<(ostream &out, const Big_Int &o)
{
    bool num_start = false;
    for (int i = 0; i < o.size(); i++) {
        if (!num_start && o.num[i] > 0)
            num_start = true;
        if (num_start || (i + 1) == o.size())
        out << o.num[i];
    }
    return out;
}

int Big_Int::size() const
{
    return sz;
}
