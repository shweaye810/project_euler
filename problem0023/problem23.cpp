#include <iostream>

#include "../divisor/divisor.h"

using namespace std;

int main()
{
    const int sz = 40001;
    vector<Divisor> d;
    vector<int> abt;
    for (int i = 0; i < sz; i++)
        d.push_back(Divisor(i));
    for (int i = 0; i < sz; i++) {
        if (d[i].sum() > i)
            abt.push_back(i);
    }
    bool wnt_num[sz * 2];
    for (int i = 0; i < sz; i++) {
        wnt_num[i] = true;
    }
    
    int x = abt.size(), y = 0;
    for (int i = 0; i < x; i++) {
        for (int j = i; j < x; j++) {
            y = abt[i] + abt[j];
            wnt_num[y] = false;
        }
    }
    long int ttl = 0;
    for (int i = 0; i < sz; i++) {
        if (wnt_num[i]) {
            ttl += i;
        }
    }
    cout << "The sum is " << ttl << endl << flush;

    return 0;
}
