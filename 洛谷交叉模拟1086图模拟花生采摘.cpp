#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

struct mm
{
	int x, y, val;
	bool operator< (mm a) {
		return this->val > a.val;
	}
	bool operator>(mm a) {
		return this->val < a.val;
	}
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

int MyAbs(int a) {
	return a > 0 ? a : -a;
}

int main() {
	mm a[410];
	int cur = 0;
	int m, n, limit;
	int mapp[30][30];
	m = read();
	n = read();
	limit = read();
	For(i, 0, m) {
		For(k, 0, n) {
			mapp[i][k] = read();
			if (mapp[i][k] != 0) {
				a[cur].x = k;
				a[cur].y = i;
				a[cur].val = mapp[i][k];
				++cur;
			}
		}
	}

	sort(a, a + cur);

	int curTime = a[0].y + 2, res = a[0].val;
	if (curTime + a[0].y + 1 > limit) {
		printf("0\n");
		return 0;
	}

	int tmpPlus = 0;

	For(i, 1, cur) {
		tmpPlus = MyAbs(a[i].x - a[i - 1].x) + MyAbs(a[i].y - a[i - 1].y) + 1;
		if (curTime + tmpPlus + a[i].y + 1 > limit) {
			break;
		}
		curTime += tmpPlus;
		res += a[i].val;
	}

	printf("%d\n", res);	

	return 0;
}

/*
我们假定多多在每个单位时间内，可以做下列四件事情中的一件：

1) 从路边跳到最靠近路边（即第一行）的某棵花生植株；

2) 从一棵植株跳到前后左右与之相邻的另一棵植株；

3) 采摘一棵植株下的花生；

4) 从最靠近路边（即第一行）的某棵花生植株跳回路边。

现在给定一块花生田的大小和花生的分布，请问在限定时间内，多多最多可以采到多少个花生？注意可能只有部分植株下面长有花生，假设这些植株下的花生个数各不相同。

输入:
6 7 21
0 0 0 0 0 0 0
0 0 0 0 13 0 0
0 0 0 0 0 0 7
0 15 0 0 0 0 0
0 0 0 9 0 0 0
0 0 0 0 0 0 0

输出:
37

输入:
6 7 20
0 0 0 0 0 0 0
0 0 0 0 13 0 0
0 0 0 0 0 0 7
0 15 0 0 0 0 0
0 0 0 9 0 0 0
0 0 0 0 0 0 0

输出:
28

*/