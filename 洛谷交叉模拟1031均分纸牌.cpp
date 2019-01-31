#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
#define For(i, n, m) for(int i = n;i < m; ++i)//宏定义节省代码长度
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
int main() {
	int N, a[10010] = { 0 }, sum = 0, res = 0;
	N = read();
	For(i, 0, N) {
		a[i] = read();
		sum += a[i];
	}
	sum /= N;

	For(i, 0, N) {
		a[i] -= sum;
	}

	For(i, 0, N - 1) {
		if (a[i] != 0) {
			a[i + 1] += a[i];					// 全部往后移
			++res;
		}
	}

	// 总结: 不要有思维定式, 想去找最大值后, 移动方向不好判断, 不如全部确定一个方向, 就是全部往右移,
	//       比如全部减掉平均值之后, 第一堆 -1, 第二堆 -2, 第一堆全部移动到满足的时候 => 第一堆 0, 第二堆 -3, 要有这种虚拟的, 存在负的牌数的思想, 并不是它不够就不可以移动了, 因为可以有负的牌数

	write(res);
	putchar('\n');


	return 0;
}

/*
移牌规则为：在编号为1堆上取的纸牌，只能移到编号为2的堆上；在编号为N的堆上取的纸牌，只能移到编号为N−1的堆上；其他堆上取的纸牌，可以移到相邻左边或右边的堆上。

现在要求找出一种移动方法，用最少的移动次数使每堆上纸牌数都一样多。

shuru:
4
9 8 17 6

shuchu:
3
*/