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

#define MAX 1000005
int sol(char *a, char *b) {
	int aSize = strlen(a) - 1, bSize = strlen(b) - 1;
	for (; aSize >= 0 && bSize >= 0; --aSize, --bSize) {
		if (a[aSize] != b[bSize])
			return -1;
	}
	if (aSize >= 0)
		return 0;
	else if (bSize >= 0)
		return 1;
	else
		return 2;
}

int main() {
	int n = read();
	int iArr = 0;
	Str arr[100010];

	for (; iArr < n; ++iArr) {
		gets(arr[iArr].c);
		For(k, 0, iArr) {
			if (sol(arr[k].c, arr[iArr].c) == 0) {
				arr[iArr].num++;
			}
			else if (sol(arr[k].c, arr[iArr].c) == 1) {
				arr[k].num++;
			}
			else if (sol(arr[k].c, arr[iArr].c) == 2) {
				arr[k].num++;
				arr[iArr].num++;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%d\n", arr[i].num);
	}


	return 0;
}

