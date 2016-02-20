#include <iostream>

#include "calendar.h"

using namespace std;

int main()
{
    int ttl = 0, days = -6;
    for (int i = 1901; i < 2001; i++) {
        Year y(i);
        for (int j = 1; j <= MONTH_SIZE; j++) {
            days += y.get(j);
            days %= 7;
            if (days == 6)
                ttl++;
        }
    }
    cout << ttl << flush << endl;
    return 0;
}
