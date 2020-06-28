#include <iostream>
using namespace std;
int main() {
	char arr[1000];
	int a = 1 << 31, b;
	int x = 1 << 31;
	cout << itoa(x, arr, 2) << endl;
	x |= (x >> 1);
	cout << itoa(x, arr, 2) << endl;
	x |= (x >> 2);
	cout << itoa(x, arr, 2) << endl;
	x |= (x >> 4);
	cout << itoa(x, arr, 2) << endl;
	x |= (x >> 8);
	cout << itoa(x, arr, 2) << endl;
	x |= (x >> 16);
	cout << itoa(x, arr, 2) << endl;
	cout << ":  " << itoa(((~x >> 1) ^ (1 << 31)), arr, 2) << endl;
	// cout << itoa(~x >> 1, arr, 2) << endl;
	b = (x) & x;
	cout << itoa(b, arr, 2) << endl;
	b = b >> 1;
	cout << itoa(b, arr, 2) << endl;
	cout << itoa(x ^ b, arr, 2) << endl;

	



	return 0;
}