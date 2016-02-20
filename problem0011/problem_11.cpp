#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
template<typename T>
void print(T v)
{
    cout << setw(3) << v << ' ';
}
int main()
{
    ifstream fin("file.txt");
    const int SIZE = 20;
    int n = 0, ary[SIZE][SIZE] = {0};
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (fin >> n) {
                ary[i][j] = n;
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (ary[i][j] > 75)
                print(ary[i][j]);
            else
                print('_');
        }
        cout << endl;
    }
        
    return 0;
}
