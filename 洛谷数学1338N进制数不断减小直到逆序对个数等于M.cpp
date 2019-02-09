#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
/***/
#define For(i, n, m) for(long long i = n;i < m; ++i)

inline long long read() {
	char s;
	long long k = 0, base = 1;
	while ((s = getchar()) != '-' && s != EOF&&!(s >= '0'&&s <= '9'));
	if (s == EOF)exit(0);
	if (s == '-')base = -1, s = getchar();
	while (s >= '0'&&s <= '9')
	{
		k = k * 10 + (s - '0');
		s = getchar();
	}
	return k * base;
}

// 靠逆序对越多字典序越大, 优先考虑往字典序小的放法, 逆序对的数目可以通过放置计算出来
// 记住逆序对是可以调整方法, 计算的!
// 注意从小的数开始放, 因为可以计算它的前面有多少数 是 以它为后逆序对数的

int main() {
	long long n = read(), needRev = read();
	long long ans[50010] = { 0 }, iAnsHead = 1, iAnsTail = n;

	// 从小到大放每一个数字 用一个1~5的例子去理解
	for (long long i = 1; i <= n; ++i) {
		long long maxRevNum = (n - i) * (n - 1 - i) / 2;
		// 两个分支, 看笔记
		if (maxRevNum >= needRev)	// 放第一个
			ans[iAnsHead++] = i;
		else {						// 放当前最后一个
			ans[iAnsTail--] = i;
			needRev -= (iAnsTail - iAnsHead + 1);
		}
	}

	printf("%d", ans[1]);
	for (long long i = 2; i <= n; ++i)
		printf(" %d", ans[i]);
	printf("\n");


	return 0;
}

/*
我们用1-N来表示日历的元素，第一天日历就是

1, 2, 3, … N

第二天，日历自动变为

1, 2, 3, … N, N-1

……每次它都生成一个以前未出现过的“最小”的排列——把它转为N+1进制后数的数值最小。
也就是N进制数改变数字的顺序, 然后减小一点, 这一点尽可能小



这题目精炼:
求逆序对为 M 的字典序最小数, 数都是由 1~N 构成.

输入:
5 4

输出:
1 3 5 4 2



// 就是1 2 3 4 5一步一步减小, 直到逆序对个数是 4 个的时候: 1 3 5 4 2 就输出

*/