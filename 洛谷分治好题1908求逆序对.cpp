#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
using namespace std;
#define For(i, n, m) for(ll i = n;i < m; ++i)
#define ll long long

inline ll read() {
	char s;
	ll k = 0, base = 1;
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

ll a[500010], discre[500010], n, c[500010] = { 0 }, ans = 0, rankArr[500010] = { 0 };

bool CmpDiscretize(ll &x, ll &y) {
	return a[x] > a[y];
}

void Add(ll x)  //树状数组加入 
{
	for (; x <= n; x += (x&-x))
		c[x]++;  //因为这里只需要1，所以我就写出c[x]++了
}
ll Sum(ll x)  //树状数组求和，同上面的sum(x)
{
	ll s = 0;  //计数的变量
	for (; x>0; x -= (x&-x))  //累计
		s += c[x];
	return s;  //返回结果
}
/*
数组都从1开始存
逆序对就是序列中ai>aj且i<j的有序对, 定义此时aj为后逆序数, ai是前逆序数.
比如原数组t[] = { 1, 3, 2 };
排序离散出来的一个a[] = { 3, 1, 2 }, a[]表示元素是第几大的数组, 就像a[1] = 3表示t[1] = 1在t[]中是第3大的数
然后把a[]当做下标加入, 就是树状数组中的A[a[i]] = 1, 遍历i全部加进去同时求前i项和.
这样算的话, 就是按照t[]的从左到右顺序, 求以t[i]为后逆序数的前逆序数个数.

还有一种算法:
排序离散出来一个a[] = { 2, 3, 1 }, a[i]表示第i大元素的下标位置
同样把a[]当做下标加入, 就是树状数组中的A[a[i]] = 1, 遍历i全部加进去同时求前i项和.
这样算的话, 就是按照t[]元素的从大到小顺序计算以此元素为后逆序数的的前逆序数个数. 这样也是对的因为计算前逆序数只要知道比这个元素大的其他元素的位置
*/

int main() {
	// freopen("testdata.in", "r", stdin);
	n = read();
	for (ll i = 1; i <= n; ++i) {
		a[i] = read();
		discre[i] = i;
	}

	sort(discre + 1, discre + n + 1, CmpDiscretize);

	for (ll i = 1; i <= n; ++i)
		rankArr[discre[i]] = i;

	for (ll i = 1; i <= n; ++i) {
		Add(rankArr[i]);
		cout << ans << endl;
		ans += Sum(rankArr[i] - 1);
	}

	cout << ans << endl;


	return 0;
}

/*
逆序对就是序列中ai>aj且i<j的有序对。知道这概念后，他们就比赛谁先算出给定的一段正整数序列中逆序对的数目。

输入:
6
5 4 2 6 3 1


输出:
11
*/