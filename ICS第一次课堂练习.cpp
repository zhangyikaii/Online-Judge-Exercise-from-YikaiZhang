#include <iostream>
using namespace std;
void toa(int x, int des) {
	char arr[500];
	cout << "$0x" << itoa(x, arr, 16) << "$ & ";
}

void f(int x) {
	char arr[500];
	cout << itoa(x, arr, 2) << endl;
}

int div32(int x) {
	return (((x & 0x80000000) >> 31) && (x & 0x1f)) + (x >> 5);
}

int main() {
	//int x = 193;
	//f((x + 0x1f) >> 5);
	//f(x / 32);
	//f(x >> 5);
	//cin >> x;
	//cout << x / 32 << endl;
	//cout << ~x + 1 << endl;
	//cout << ~((~x + 1) >> 5) + 1 << endl;
	//cout << -(-x / 32) << endl;
	//cout << ~(~x + 1) + 1 << endl;
	//f(-96);
	//f(-96 >> 5);
	//f(-96 / 32);
	//f(-23423);
	//f(-23423 / 32);
	//f(-23423 >> 5);
	//cin >> x;
	/*for (int i = -800; i < 214; ++i) {
		if (div32(i) != i / 32) {
			cout << "-----\n";
			cout << i << endl;
			f(i);
			f(div32(i));
			f(i / 32);
		}
	}*/
	//int x = 0x07, y = 0x55;

	//toa(x ^ y, 16); toa(x & y, 16); toa(x | y, 16);
	//toa((~x) | (~y), 16); toa(x & (!y), 16); toa(x && y, 16); toa(x || y, 16); toa(!x || !y, 16); toa(x && !y, 16);


	f((-4) ^ (-4 >> (32 - 3)) << (32 - 3));
	f(-4);

	return 0;

}