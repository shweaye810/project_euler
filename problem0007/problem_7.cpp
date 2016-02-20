#include <iostream>
#include <iomanip>
#include "Number.h"

using namespace std;
int main()
{
	const double GIVEN = 600851475143;
	const int MAX_SIZE = 2000000;
	Number * y = new Number[MAX_SIZE];
	/*
	 * calculate prime
	 */
	 int count, target_count = 10001, g = 0;
	 for (int i = 2; i < MAX_SIZE && g < target_count; i++) {
		 count = 0;
		 for (int j = 2; j < i; j++) {
			 if (i % j == 0)
				count++;
		}
		if (count == 0) {
			g++;
			y[i].make_prime();
		}
	}
	/*
	for (int i = 0; i < MAX_SIZE; i++) {
		if (y[i].get_prime()) 
			cout << setw(8) << i;
	}
	*/
	count = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		if (y[i].get_prime() && count <= target_count) {
			count++;
		}
		if (count == 10001) {
			cout << count << " prime is " << i << endl;
			break;
		}
	}

	return 0;
}
