#include <iostream>
#include <sstream>
#include "big_int.h"

using namespace std;

const long int CAP = 1e17;

Big_Int::Big_Int() : sz(3)
{
    for (int i = 0; i < sz; i++)
        num[i] = 0;
}

Big_Int::Big_Int(const string &s) : sz(3)
{
    for (int i = 0; i < sz; i++)
        num[i] = 0;
    int size = s.size(), i = 2;
    while (size > 0) {
        string tmp;
        if (size < 17)
            tmp = s.substr(0, size); 
        else
            tmp = s.substr(size - 17, 17);
        stringstream sstr(tmp);
        sstr >> num[i--];
        size -= 17;
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
    for (int i = 0; i < o.size(); i++)
        out << o.num[i];
    return out;
}

int Big_Int::size() const
{
    return sz;
}
