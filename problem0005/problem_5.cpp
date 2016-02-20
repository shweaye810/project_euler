#include <iostream>
using namespace std;
int main()
{
	int num = 2520, remdr, count;
	do {
		count = 0;
		for (int i = 1; i <= 20; i++) {
			remdr = num % i;
			if (remdr > 0)
				num++;
			else
				count++;
		}
	} while (count < 20);
	cout << num;
	return 0;
}	
