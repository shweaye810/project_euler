#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int size = 20;
    long **grid = new long*[size+1];
    
    for (int i = 0; i <= size; i++) {
        grid[i] = new long[size + 1];
    }
    
    for (int i = 0; i <= size; i++) {
        grid[i][size] = 1;
        grid[size][i] = 1;
    }
    for (int i = 0; i <= size; i++) {
        for (int j = 0; j <= size; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    for (int i = size - 1; i >= 0; i--) {
        for (int j = size - 1; j >= 0; j--) {
            grid[i][j] = grid[i+1][j] + grid[i][j+1];
        }
    }
    
    cout << grid[0][0];
    return 0;
}

