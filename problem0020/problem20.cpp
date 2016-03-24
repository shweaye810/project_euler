#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../big_int/big_int.h"

using namespace std;

Big_Int fact(int n)
{
    if (n <= 1)
        return Big_Int("1");
    if (n == 2)
        return Big_Int("2");
    return Big_Int(to_string(n)) * fact(n - 1);
}
int main()
{
    Big_Int tt = fact(100);
    cout << tt << endl << flush;
    
    stringstream ss;
    ss << tt;

    string s;
    ss >> s;
    
    int n = 0;
    for (unsigned int i = 0; i < s.size(); i++)
        n += s[i] - '0';
    cout << n << endl << flush;
    return 0;
}
