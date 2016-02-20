#include <iostream>
using namespace std;

int main()
{
	int total = 0;
	for (int i = 1; (i * 3) < 1000; i++) {
		cout << i << endl;
		total += i * 3;
	}
	for (int j = 1; (j * 5) < 1000; j++) {
		if (((j * 5) % 3) != 0) {
			total += j * 5;
		}
	}
	cout << total;
	return 0;
}
