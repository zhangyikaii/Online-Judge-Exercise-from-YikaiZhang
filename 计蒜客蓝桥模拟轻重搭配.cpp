#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Str
{
	int num;
	char c[20];
	Str() : num(1) { }
};

#define For(i, n, m) for(int i = n;i < m; ++i)
inline int read()
{
	char s;
	int k = 0, base = 1;
	while ((s = getchar()) != '-'&&s != EOF&&!(s >= '0'&&s <= '9'));
	if (s == EOF)exit(0);
	if (s == '-')base = -1, s = getchar();
	while (s >= '0'&&s <= '9')
	{
		k = k * 10 + (s - '0');
		s = getchar();
	}
	return k*base;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		write(-x);
	}
	else
	{
		if (x / 10)write(x / 10);
		putchar(x % 10 + '0');
	}
}

#define MAX 500010

int main() {
	int a[MAX] = { 0 };
	int n = read(), minu = 0;
	int tail = n - 1;
	For(i, 0, n) {
		a[i] = read();
	}

	sort(a, a + n);
	
	For(i, 0, n) {
		if (a[i] * 2 > a[tail--])
			break;
		++minu;
	}

	cout << n - minu << endl;

	return 0;
}
