#include<stdlib.h>
#include<iostream>
#include <time.h> 
using namespace std;
int main() 
{
	srand( (unsigned)time( NULL ) );
	unsigned int a, b;
	a = (rand() << 16) + rand();
	b = (rand() << 16) + rand();
	a %= 100000;
	b %= 100000;
	cout << a << endl << b; 
	return 0;
}
