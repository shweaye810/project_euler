/*
 * Jan 10 2015
 * 
 * A palindromic number reads the same both ways. The largest palindromic
 * made from the product of two 2-digit is 9009 = 91 x 99.
 * Find the largest palindrome made from the product of two 3-digit.
 */

#include <iostream>
using namespace std;
int main()
{
	/*
	 * multi = i * j
	 * calculate multi in first 2 nested loop
	 * and break they apart in z loop
	 * 
	 * a and b loop to see if number in num_ary are palindromic
	 * if they are, then print.
	 */
	bool found = false;
	int multi, num_ary[6], tmp;
	for (int i = 999; i > 900 && !found; i--) {
		for (int j = i; j > 900; j--) {
			tmp = multi = i * j;
			for (int z = 5; tmp > 0; z--) {
				num_ary[z] = tmp % 10;
				tmp /= 10;
			}
			int a, b;
			for (a = 0, b = 5; num_ary[a] == num_ary[b] && a < b; a++, b--);
			if (a > b) {
				found = true;
				for (int c = 0; c < 6; c++)
					cout << num_ary[c];
				cout << endl;
			}
		}
	}
	return 0;
}			
