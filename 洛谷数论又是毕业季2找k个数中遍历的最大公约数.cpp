#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

int n, t = 0, c[1000010];
// c[i]表示i作为因子的次数

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		t = max(t, x);
		// 记录目前最大能力值
		int m = sqrt(x);
		// 能力值的开方
		for (int i = 1; i <= m; i++) {
			// 有约数
			if (x % i == 0) {
				c[i]++;
				// i作为因子的次数++
				// 反向处理!!! 这就是只用到 sqrt(x) 的含义
				if (x != i * i)
					c[x / i]++;
				// 如果x不是i的平方，x / i 也是 x 的因子
				// 如果x是i的平方只记录i作为一次因子
			}
		}
	}
	int x = t;
	for (int i = 1; i <= n; i++) {
		// 很简单每次遍历 找 c[x] < i 就可以了, 没想到就是这么简单... 
		while (c[x] < i)
			x--;
		// 找出最大的默契值
		cout << x << endl;
		// 输出
	}
	return 0;
}
// 
// #define in(x) x=read()
// 
// inline int read()
// {
// 	int X = 0, w = 1;
// 	char ch = getchar();
// 	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
// 	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
// 	return X*w;
// }
// 
// int n, a[10010], tmpAns[110], ans[10010] = { 0 };
// 
// int main() {
// 	in(n);
// 	for (int i = 1; i <= n; ++i)
// 		in(a[i]);
// 
// 	sort(a + 1, a + n + 1);
// 
// 	for (int i = 1; i <= a[n]; ++i) {
// 		for (int k = 1; k <= n; ++k) {
// 			if (a[k] >= i && a[k] % i == 0)
// 				++tmpAns[i];
// 		}
// 	}
// 
// 	for (int i = a[n]; i >= 0; --i) {
// 		if (ans[tmpAns[i]] == 0)
// 			ans[tmpAns[i]] = i;
// 	}
// 
// 	for (int i = a[n] - 1; i >= 1; --i) {
// 		if (ans[i] == 0)
// 			ans[i] = ans[i + 1];
// 	}
// 	for (int i = 1; i <= n; ++i)
// 		printf("%d\n", ans[i]);
// 	return 0;
// }

/*
题目描述
彩排了一次，老师不太满意。当然啦，取每位同学的号数来找最大公约数显然不太合理。于是老师给每位同学评了一个能力值。于是现在问题变为，从n个学生中挑出k个人使得他们的默契程度（即能力值的最大公约数）最大。但因为节目太多了，而且每个节目需要的人数又不知道。老师想要知道所有情况下能达到的最大默契程度是多少。这下子更麻烦了，还是交给你吧~

PS：一个数的最大公约数即本身。

输入输出格式
输入格式：
第一行一个正整数n。

第二行为n个空格隔开的正整数，表示每个学生的能力值。

输出格式：
总共n行，第i行为k=i情况下的最大默契程度。

输入输出样例
输入样例#1：
4
1 2 3 4
输出样例#1：
4
2
1
1

*/

