#include <cstdio> 
#include <cstdlib> 
#include <iostream>
using namespace std;

// 可以用这个看 DataLab 每一步的变化
char str[100] = "";

void TwoPrint(int t) {
	cout << "10进制" << t << endl;
	for (int i = 0; i < 100; ++i)
		str[i] = '\0';

	_itoa(t, str, 2);
	for (int i = 0; i < 32 - strlen(str); ++i)
		printf("0");
	printf("%s\n", str);
}

int bang(int x)
{
	TwoPrint(x);
	//int tmpx = x & ( (~x) >> 1);
	int tmpx = x | ((~x) + 1);
	TwoPrint(tmpx);
	tmpx = tmpx >> 31;
	TwoPrint(tmpx);
	tmpx = tmpx + 1;
	return tmpx;
}

int main() {
	TwoPrint(0 | 13413);
	int x = 0, t = !x;
	cout << !((x >> 31) | (!x));
	TwoPrint(x);
	x >>= 31;
	TwoPrint(x);

	TwoPrint(x | t);


	return 0;
}