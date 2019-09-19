#include <iostream>
using namespace std;
int main() {
	unsigned int a = 0xffffffff;
	unsigned int b = a + 1;
	
	cout << b << endl;
	// cout << b << endl;
	unsigned int c = 13, d = 13;

	cout << c + b <<  " " << c - b << endl;

	//int b = a;
	//cout << -a << endl;
	//b -= a;

	//printf("%d\n%d", a, b);


	return 0;
}