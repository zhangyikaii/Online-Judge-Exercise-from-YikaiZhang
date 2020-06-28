#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define in(x) x=read()
#define For(i, a, b) for(int i = a; i < b; ++i)

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

int arr[50], brr[50];

int a, b, c;

int main() {
	scanf("%d.%d.%d %d.%d.%d", &arr[1], &arr[2], &arr[3], &brr[1], &brr[2], &brr[3]);

	c = (brr[3] + arr[3]) % 29;
	int goNum = (brr[3] + arr[3]) / 29;
	b = (brr[2] + arr[2] + goNum) % 17;
	goNum = (brr[2] + arr[2] + goNum) / 17;
	a = (brr[1] + arr[1] + goNum);

	cout << a << "." << b << "." << c << endl;
	
	return 0;
}

/*


题目描述
If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- as Hagrid explained it to Harry, "Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough."  Your job is to write a program to compute A+B where A and B are given in the standard form of "Galleon.Sickle.Knut" (Galleon is an integer in [0, 107], Sickle is an integer in [0, 17), and Knut is an integer in [0, 29)).

输入描述:
Each input file contains one test case which occupies a line with A and B in the standard form, separated by one space.


输出描述:
For each test case you should output the sum of A and B in one line, with the same format as the input.

输入例子:
3.2.1 10.16.27

输出例子:
14.1.28




*/