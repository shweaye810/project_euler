#include <iostream>
using namespace std;
int main()
{
	int sum, square, answer;
	sum = square = 0;
	for (int i = 0; i <= 100; i++) {
		sum += i;
		square += (i * i);
	}
	sum *= sum;
	answer = sum - square;
	cout << answer;
}
