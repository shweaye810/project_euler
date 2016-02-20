#include <iostream>
using namespace std;

int main()
{
	int x[10000], total = 0;
	x[0] = x[1] = 1;
	for (int i = 0; x[i] < 4000000; i++) {
		x[i+2] = x[i] + x[i+1];
	}
	cout << endl;
	for (int i = 0; x[i] < 4000000; i++) {
		if (x[i] % 2 == 0) {
			total += x[i];
		}
	}
	cout << total;
	return 0;
}
