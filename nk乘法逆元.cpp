#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<map>
#define INF 0xfffffff
#define CLR(a,b,Size) memset((a),(b),sizeof((a[0]))*(Size+1))
#define CPY(a,b) memcpy ((a), (b), sizeof((a)))
using namespace std;
typedef long long ll;

#define in(x) x=read()

#define For(i, a, b) for(int i = a; i < b; ++i)

const int NN = 2e5 + 5;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}


inline ll readll() {
	ll X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}
ll n, ind[NN], arr[NN], brr[NN];

bool cmp(int x, int y) {
	return brr[x] * arr[y] > arr[x] * brr[y];
}

ll fpm(ll x, ll power, ll mod) {
	x %= mod;
	ll res = 1;
	for (; power != 0; power >>= 1, x = x * x % mod) {
		if (power & 1) {
			res *= x;
			res %= mod;
		}
	}

	return res;
}

const ll p = 1e9 + 7;

int main() {
	n = readll();
	For(i, 0, n) {
		arr[i] = readll();
		brr[i] = readll();

		ind[i] = i;       // 用数组下标去排序.
	}

	sort(ind, ind + n, cmp);

	// 分数取模, 乘法逆元

	For(i, 0, n)
		printf("%lld\n", brr[ind[i]] * fpm(arr[ind[i]], p - 2, p) % p);		// 注意每一个位置都要 mod p, 要细心!!!


	return 0;
}

/*
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int p = 1e9 + 7, N = 2e5 + 5;

ll n, a[N], b[N], f[N];

ll poww(ll x, ll y)
{
	ll ans = 1;
	while (y)
	{
		if (y & 1) ans = ans * x % p;
		y >>= 1;
		x = x * x % p;
	}
	return ans;
}

bool cmp(ll x, ll y)
{
	return b[x] * a[y] > a[x] * b[y];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i] >> b[i], f[i] = i;
	sort(f + 1, f + 1 + n, cmp);
	for (int i = 1; i <= n; i++)printf("%lld\n", b[f[i]] * poww(a[f[i]], p - 2) % p);
	return 0;
}

*/

/*
题目:

链接：https://ac.nowcoder.com/acm/contest/946/A
来源：牛客网

筱玛是一个热爱地理的好筱玛。最近，在《地理II》作业本上，筱玛学到了“贝塔指数”的概念：

在经济地理学中，交通的联结度表示交通网络的发达程度，通常用贝塔指数来计算与比较。若用VV表示一个交通网络中结点的数量，用EE表示边的数量，则贝塔指数的计算方式为：\beta=\frac{E}{V}β=
V
E
​
 。


“实践是检验真理的唯一标准”。作为一个热爱地理的好筱玛，她马上就把新学的知识应用到实践当中去。筱玛一口气出了nn张交通网络规划图，其中第ii张交通网络G_iG
i
​
 有V_iV
i
​
 个结点和E_iE
i
​
 条边。筱玛一眼就看出了哪张图好、哪张图坏。但是作为一个负责任的好筱玛，她必须带领同学们一起进步。因此，她需要你将所有的nn张图按照贝塔指数排序，并求出它们各自的贝塔指数在模10^9+710
9
 +7意义下的值。

输入描述:
第一行一个整数nn，表示交通网络规划图的数量。

接下来nn行，每行两个整数V_iV
i
​
 和E_iE
i
​
 ，分别表示图G_iG
i
​
 中的结点数量和边的数量。

输出描述:
输出共nn行，每行一个数，表示贝塔指数第ii大的交通网络的贝塔指数在模10^9+710
9
 +7意义下的值。
如果不能整除，输出分数取模后的结果。
示例1
输入
复制
1
1 3
输出
复制
3
说明
显然此时\beta=\frac{E}{V}=3β=
V
E
​
 =3。
 
 */

