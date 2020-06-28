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


// 答案就是斐波那契数列, 注意如何预处理, 加快速度.

// 下面是不通过的自己的答案
/*
int main() {
	int t;
	in(t);
	while (t--) {
		int n;
		in(n);
		int bef = 0, aft = 1, res = 0, mod = 998244353, tmp = 0;
		for (int i = 0; i < n; ++i) {
			res = (res + bef + aft) % mod;
			tmp = aft;
			aft = bef;
			bef = (tmp + bef) % mod;
		}

		printf("%d\n", res);
	}
	
	return 0;
}

*/


// 下面是答案:
#include<bits/stdc++.h>
typedef long long ll;
const ll mod = 998244353;
const int maxn = 10000007;
int a[maxn];


int main() {
	a[0] = 1;
	a[1] = 1;

	// 就是简单的遍历处理就可以了, 但是一定注意long long的问题.
	for (int i = 2; i < maxn; i++) 
		a[i] = (1ll * a[i - 1] + a[i - 2]) % mod;
	for (int i = 1; i < maxn; i++) 
		a[i] = (1ll * a[i] + a[i - 1]) % mod;
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", a[n - 1]);
	}

}


/*
链接：https://ac.nowcoder.com/acm/contest/928/A
来源：牛客网

题目描述
小巫女从小就喜欢吃火龙果，她有一个梦想，就是用魔法变出许许多多美味可口的火龙果，这样她就可以天天享受火龙果的美味啦！
聪明、善良又可爱的小巫女从 9012 年带回来一棵火龙果树树苗，在自家的院子里种下了一棵独一无二的火龙果树。
火龙果树自下到上一共有若干层，每一层都是由上一层对应的枝叶生长而来。
我们将火龙果树的树枝分为两类，未孕育枝只能生长出一枝已孕育枝，已孕育枝可以生长出一枝未孕育枝和一枝已孕育枝。
最初，小巫女种下了仅包含一个未孕育枝的火龙果树树苗开始生长。
在每一个生长周期中，处于最上层的所有树枝均会按照自己的生长方式生长出新的一层。
随着火龙果树的茁壮成长，小巫女想知道她的火龙果树在第 t 个生命周期后，一共含有多少条树枝。
小巫女相信你一定可以顺利的解决这个问题！
输入描述:
对于每个测试点包含多组数据。
第一行：一个整数 T，表示该测试点包含的数据组数。
接下来 T 行：每行包含一个整数t，其含义如题目所述。
输出描述:
共 T 行：每行包含一个整数ans，表示树枝的条数。
注意：由于答案可能很大，你只需要输出树枝条数对 998244353 取模后的值。
示例1
输入
复制
4
1
2
3
4
输出
复制
1
2
4
7
说明


*/