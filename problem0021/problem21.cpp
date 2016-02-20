#include <iostream>

#include "divisor.h"
using namespace std;

int main()
{
    const int sz = 10001;
    vector<Divisor> d;
    for (int i = 0; i < sz; i++)
        d.push_back(Divisor(i));
    for (int i = 1; i < sz; i++) {
        for (int j = 1; j < sz; j++) {
            if ((i != j) && (d[i].sum() == j) && (i == d[j].sum())) {
                cout << i << " and " << j << " is equal. Sum is " << d[i].sum()
                     << " and " << d[j].sum() << endl << flush;
                d[i].set_amicable_number(j);
                d[j].set_amicable_number(i);
            }
        }
    }
    int ttl = 0;
    for (int i = 0; i < sz; i++) {
        if (d[i].is_amicable_number()) {
            ttl += i;
        }
    }
    cout << "The sum of all amicable number under 10000 is " << ttl << endl << flush;
    return 0;
}
