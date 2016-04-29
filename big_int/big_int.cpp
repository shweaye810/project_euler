#include <iostream>
#include <sstream>
#include <memory>

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

const Big_Int &Big_Int::operator+(const Big_Int &o) const
{
    unique_ptr<Big_Int> tmp(new Big_Int);
    for (int i = o.size() - 1; i >= 0; i--) {
        tmp->num[i] = tmp->num[i] + this->num[i] + o.num[i];
        if (i > 0) {
            tmp->num[i - 1] = tmp->num[i - 1] + tmp->num[i] / CAP;
            tmp->num[i] %= CAP;
        }
    }
    return *tmp;
}

const Big_Int &Big_Int::operator+=(const Big_Int &o)
{
    *this = *this + o;
    return *this;
}

const Big_Int &Big_Int::operator*(const Big_Int &o) const
{
    unique_ptr<Big_Int> tmp(new Big_Int);
    for (int i = o.size() - 1; i >= 0; i--) {
        for(int j = this->size() - 1, k = i; j >= 0; j--) {
            tmp->num[k] =  tmp->num[k] +  o.num[i] * this->num[j];
            if (k > 0) {
                tmp->num[k - 1] = tmp->num[k - 1] + tmp->num[k] / CAP;
                tmp->num[k] %= CAP;
                k--;
            }
        }
    }
    return *tmp;
}

const Big_Int &Big_Int::operator*=(const Big_Int &o)
{
    *this = *this * o;
    return *this;
}
ostream &operator<<(ostream &out, const Big_Int &o)
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

const int Big_Int::size() const
{
    return sz;
}
