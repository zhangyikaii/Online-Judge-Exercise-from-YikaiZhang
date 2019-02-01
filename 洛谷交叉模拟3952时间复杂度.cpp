#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
using namespace std;
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

bool isNum(char a) {
	if (a <= '9' && a >= '0')
		return true;
	return false;
}

int MyMax(int a, int b) {
	return a > b ? a : b;
}
int main() {
	int T = read(), a;
	while (T--) {
		int mapp[30] = { 0 };
		int comp = 0, oneComp = 0, maxx = 0;
		a = read();
		char o[15] = "", tmp[30] = "";
		gets(o);
		if (a != 1) {
			while (a--) {
				gets(tmp);
				// 复杂度 + 1
				if (tmp[0] == 'F') {
					if (mapp[tmp[2] - 'a'] == 0 && isNum(tmp[4]) && tmp[6] == 'n') {
						++comp;
						maxx = MyMax(maxx, comp);
					}
					else if (mapp[tmp[2] - 'a'] == 0 && isNum(tmp[4]) && isNum(tmp[6])) {
						++oneComp;
					}
				}
				else if (tmp[0] == 'E') {
					if (oneComp != 0)
						--oneComp;
					else
						--comp;
				}
			}
			if (comp != 0) {
				cout << "ERR" << endl;
			}
			else {
				if ((strlen(o) >= 5 && o[4] - '0' == maxx) || (strlen(o) == 4 && o[2] - '0' == 1 && oneComp == 0)) {
					cout << "Yes" << endl;
				}
				else
					cout << "No" << endl;
			}
		}
		else {
			gets(tmp);
			cout << "ERR" << endl;
		}
	}
	
	return 0;
}

/*
接下来每个程序的第一行包含一个正整数 L 和一个字符串，L 代表程序行数，字符 串表示这个程序的复杂度，O(1)表示常数复杂度，O(n^w)表示复杂度为n^w，其 中w是一个小于100的正整数（输入中不包含引号），输入保证复杂度只有O(1)和O(n^w) 两种类型。

输入:
8
2 O(1)
F i 1 1
E
2 O(n^1)
F x 1 n
E
1 O(1)
F x 1 n
4 O(n^2)
F x 5 n
F y 10 n
E
E
4 O(n^2)
F x 9 n
E
F y 2 n
E
4 O(n^1)
F x 9 n
F y n 4
E
E
4 O(1)
F y n 4
F x 9 n
E
E
4 O(n^2)
F x 1 n
F x 1 10
E
E

输出:
Yes
Yes
ERR
Yes
No
Yes
Yes
ERR
*/