#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("file.txt");
    int num_ltr[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8,
                     6, 9, 9, 11, 10, 10, 9, 11, 11, 10, 6, 9, 9, 11, 10, 10, 9,
                     11, 11, 10, 5, 8, 8, 10, 9, 9, 8, 10, 10, 9, 5, 8, 8, 10,
                     9, 9, 8, 10, 10, 9, 5, 8, 8, 10, 9, 9, 8, 10, 10, 9, 7, 10,
                     10, 12, 11, 11, 10, 12, 12, 11, 6, 9, 9, 11, 10, 10, 9, 11,
                     11, 10, 6, 9, 9, 11, 10, 10, 9, 11, 11, 10, 7};
/*    for (int i = 0; i <= 100; i++) {
      cout << i << " = " << num_ltr[i] << endl;
      }*/
    int hund = 0, tot = 0, rst = 0, crnt = 0;
    for (int n = 0; n < 1000; n++) {
        if (n < 100) {
            crnt = num_ltr[n];
        } else {
            hund = n / 100;
            rst = n % 100;
            if (rst == 0)
                crnt = num_ltr[hund] + num_ltr[100];
            else
                crnt = num_ltr[hund] + num_ltr[100] + 3 + num_ltr[rst];
        }
        tot += crnt;
    }
    tot += 11;
    cout << tot << " letters are used.\n";
    return 0;
    }
