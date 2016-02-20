#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/special_functions/gamma.hpp>
#include <iostream>
#include <string>

using namespace boost::multiprecision;
using namespace std;

typedef number<cpp_dec_float<3000> > cpp_dec_float_x;

template<typename T>
void print(T &a)
{
    cout << a.str() << endl;
}

struct Stg {
    Stg(): num(0), i(0) {};
    
    int num;
    int i;
    cpp_dec_float_x ch;
};

int main()
{   
    const int SIZE = 1000;
    int cycle[SIZE] = {0};
    cpp_dec_float_x d, a = 1;
    Stg z;
    for (int i = SIZE - 1; i > 0; i--) {
        d = a / i;
        string s(d.str());
        int n = s.find('.');
        s.erase(0, n + 1);
        bool found = false;
        for (int j = 1; j < s.size() && !found; j++) {
            char *a = &s[j];
            if (*a == s[0] && *(a + 1) == s[1]) {
                string tmp = s.substr(0, j), tmp1 = s.substr(j, j);
                if (tmp == tmp1) {
                    found = true;
                    cycle[i] = tmp.size();
                    if (z.num < cycle[i]) {
                        z.num = cycle[i];
                        z.i = i;
                        z.ch = d;
                    }
                }
            }
        }
    }
    cout << "The number with the longest recurring cycle is " << z.i 
         << " with a length of " << z.num << endl;
    return 0;
}

