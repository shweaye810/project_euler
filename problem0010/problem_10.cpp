/*
 * Jan 10 2015
 * 
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 */


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
int main()
{
	ofstream fout;
	fout.open ("prime");
	const int MAX_SIZE = 2000000;
	bool * is_prime = new bool[MAX_SIZE];
	/*
	 * make all numbers prime
	 */
	 for (int i = 0; i < MAX_SIZE; i++) {
		 is_prime[i] = true;
	 }
	 is_prime[0] = is_prime[1] = false;
	/*
	 * calculate prime
	 */
	 int multi;
	 for (int i = 2; i < MAX_SIZE; i++) {
		 if (is_prime[i]) {
			 for (int j = 2; j * i  < MAX_SIZE; j++) {
				 multi = j * i;
				 is_prime[multi] = false;
			 }
		 }
	 }
	/*
	 * print prime
	 * every 10 count, fout endl
	 */
	 /*
	int count = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		if (is_prime[i]) {
			fout << setw(6) << i;
			count++;
			if (count % 10 == 0)
				fout << endl;
		}
			
	}
	*/
	/*
	 * smprime = sum of all prime below 2 million
	 */
	long smprime = 0;
	for ( int i = 0; i < MAX_SIZE; i++) {
		if (is_prime[i]) {
			smprime += i;
		}
	}
	cout << "The sum of all primes below 2 million is " << smprime << endl;
	return 0;
}
