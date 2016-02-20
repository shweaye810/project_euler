#include <iostream>
#include <iomanip>
#include "Number.h"

using namespace std;
int main()
{
	long long int GIVEN = 600851475143;
	const int MAX_SIZE = 2000000;
	Number * y = new Number[MAX_SIZE];
	/*
	 * calculate prime
	 * count is for prime
	 * c is number required for target_count
	 */
	 int count, target_count = 10001, c = 0;
	 for (int i = 2; i < MAX_SIZE && c < target_count; i++) {
		 count = 0;
		 for (int j = 2; j < i; j++) {
			 if (i % j == 0)
				count++;
		}
		if (count == 0) {
			c++;
			y[i].make_prime();
		}
	}
	/*
	for (int i = 0; i < MAX_SIZE; i++) {
		if (y[i].get_prime()) 
			cout << setw(8) << i;
	}
	*/
	/*
	 * print answer
	 */
	for (int i = MAX_SIZE - 1; i > 2; i--) {
		if (y[i].get_prime() && GIVEN % i == 0) {
			cout << "The answer is " << i;
			break;
		}
	}	

	return 0;
}
