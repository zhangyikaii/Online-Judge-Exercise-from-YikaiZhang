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

/*

int v[100010], s[100010];
int indv[100010], inds[100010];


// bq是大根堆, sq是小根堆.
priority_queue<int> bq;
priority_queue<int, vector<int>, greater<int> > sq;

bool cmps(int a, int b) {
	return s[a] > s[b];
}

bool cmpv(int a, int b) {
	return v[a] < v[b];
}

int main() {
	int n;
	in(n);
	
	For(i, 0, n) {
		indv[i] = i;
		inds[i] = i;
	}

	For(i, 0, n) {
		in(v[i]);
		in(s[i]);
	}

	sort(indv, indv + n, cmpv);
	sort(inds, inds + n, cmps);

	int curLimit = 0;
	for (int i = n - 1; i >= 0; --i) {

	}
	For(i, 0, n) {
		curLimit = s[inds[i]];

	}
	return 0;
}

*/


// 写崩了, 下面是答案:
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std; 

int n;
long long ans, curLimit, res;

// 一个士兵的限制和val要关联起来, 就用一个结构体 + 排序.
struct node { 
	long long v, s;
}a[100001];

inline bool cmp(node x, node y) { 
	return x.s > y.s; 
}

priority_queue<long long> q;

int main()
{
	scanf("%d", &n);
	for (register int i = 1; i <= n; i++) 
		scanf("%lld%lld", &a[i].v, &a[i].s);

	sort(a + 1, a + 1 + n, cmp);
	curLimit = n;

	// 按照 s[] (limit) 从大到小顺序遍历.
	for (register int i = 1; i <= n; i++) {
		curLimit = a[i].s;

		// 动态维护一个小根堆. 这很重要, 因为每一时刻对每一从大到小人数限制, 删人就是从动态的小根堆里面删除.
		q.push(-a[i].v);
		ans += a[i].v;

		// 如果人数超过限制, 就从小根堆里面删.
		while (q.size() > curLimit)
			ans += q.top(), q.pop();
		res = max(res, ans);
	}
	printf("%lld", res);
}

/*

链接：https://ac.nowcoder.com/acm/contest/1080/C
来源：牛客网

题目描述
在一个游戏中，tokitsukaze需要在n个士兵中选出一些士兵组成一个团去打副本。
第i个士兵的战力为v[i]，团的战力是团内所有士兵的战力之和。
但是这些士兵有特殊的要求：如果选了第i个士兵，这个士兵希望团的人数不超过s[i]。(如果不选第i个士兵，就没有这个限制。)
tokitsukaze想知道，团的战力最大为多少。
输入描述:
第一行包含一个正整数n(1≤n≤10^5)。
接下来n行，每行包括2个正整数v,s(1≤v≤10^9,1≤s≤n)。
输出描述:
输出一个正整数，表示团的最大战力。
示例1
输入
复制
2
1 2
2 2
输出
复制
3
示例2
输入
复制
3
1 3
2 3
100 1
输出
复制
100

*/