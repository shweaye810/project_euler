#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost::multiprecision;

const int sz = 100000;
static cpp_int fib_num[sz];

cpp_int fib(int n);

cpp_int fib_hlp(int n)
{    
    if (fib_num[n] != -1)
        return fib_num[n];
    cpp_int tmp = fib(n);
    fib_num[n] = tmp;
    return tmp;
}

cpp_int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 2 || n == 1)
        return 1;

    cpp_int tmp = fib_hlp(n - 1), tmp1 = fib_hlp(n - 2);
    return tmp + tmp1;
}

int main()
{    
    for (int i = 0; i < sz; i++) {
        fib_num[i] = -1;
    }
    cpp_int i = 0, j = 0;
    for (int i = 4000; i < 7000; i++) {
        j = fib(i);
        string s = j.str();
        if (s.size() == 1000) {
            cout << "index: " << i << endl
                 << j << " is the first term in fib seq to contain 1000 digits."
                 << endl;
            break;
        }
    }
    return 0;
}
