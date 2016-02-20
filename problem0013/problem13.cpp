#include <iostream>
#include <fstream>

#include "big_int.h"

using namespace std;

int main()
{
    ifstream fin("file.txt");
    string s;
    Big_Int tt;

    while (fin >> s) {
        Big_Int tmp(s);
        tt += tmp;
    }
    cout << tt << endl;
    return 0;
}
