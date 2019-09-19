#include<stdlib.h>
#include<iostream>
#include <time.h> 
using namespace std;
int main() 
{
	srand( (unsigned)time( NULL ) );
	unsigned int a, b;
	n = (rand() << 16) + rand();
	n %= 10000;
	n = (n % 2 == 0) ? n : n + 1;
	for (int i = 0; i < n / 2; ++i) {
		for (int i = 0; i < )
		a = (rand() << 16) + rand();
		b = (rand() << 16) + rand();
		a %= 25;
		b %= 25;
		cout << a << endl << b;
	}
	return 0;
}
