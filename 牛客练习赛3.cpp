#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <assert.h>

constexpr int N = 1e7 + 50;

int n, g, k, t, m, f[N], size[N];
long long mincost = 0;

struct Edge {
	int u, v, w;
	inline bool operator< (const Edge e) const { return w < e.w; }
} e[N];

inline char nc() {
	static char buf[10000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 10000000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
	int res = 0;
	char ch;
	do ch = nc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res;
}

inline void add(int u, int v, int w) {
	e[++m].u = u;
	e[m].v = v;
	e[m].w = w;
}

inline void find(int &x) {
	while (x != f[x])
		x = f[x] = f[f[x]];
}
inline void merge(int x, int y) {
	if (size[x] > size[y])
		std::swap(x, y);
	f[x] = y;
	size[y] += size[x];
}

inline void kruskal() {
	std::sort(e + 1, e + m + 1);
	// 遍历所有的边.
	for (int i = 1; i <= m; ++i) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		find(u); find(v);
		if (u != v)	{
			mincost += w;
			merge(u, v);
		}
		if (mincost > t)
			return;
	}
}

// 设立一个虚拟结点, 之前做过的没做过的没有关系的都连上这个结点, 无向!!!
// 注意保持DAG结构.
int main() {
	n = read() + 1, g = read(), k = read(), t = read();

	for (int i = 1; i < n; ++i) {
		f[i] = i;
		size[i] = 1;
		int T = read();
		assert(T <= 1000);
		add(i, n, T);
	}
	f[n] = n; size[n] = 1;

	// 求最小生成树的时候这条边就会被选出来
	for (int i = 1; i <= k; ++i)
		add(read(), n, 0);

	// 如果 u 可以(最小生成树的时候被选出来), 接下来v一定会选最好的 u->v 或者 v -> n;
	for (int i = 1; i <= g; ++i) {
		int u = read(), v = read(), w = read();
		add(u, v, w);
	}
	kruskal();
	puts(mincost <= t ? "Yes" : "No");
	return 0;
}
//#include <cstdio>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//const int N = 1000010;
//
//typedef long long ll;
//
//#define in(x) x=read()
//
//inline int read() {
//	int X = 0, w = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X*w;
//}
//
//const int maxn = 1000000 + 15;
//int n, m, sum, tot;
//int head[maxn], ru[maxn] = { 0 }, ts[maxn], cost[maxn], used[maxn], weight = 0;
//
//struct EDGE {
//	int to;
//	int next;
//	int w;
//	EDGE() : to(0), next(0), w(0) { }
//} edge[maxn << 2];
//
//void add(int x, int y, int w) {
//	edge[++sum].next = head[x];
//	edge[sum].to = y;
//	head[x] = sum;
//	edge[sum].w = w;
//}
//
//void topsort() {
//	queue <int> q;
//	// 单个的放进来
//	for (int i = 1; i <= n; i++) {
//		if (ru[i] == 0) {
//			q.push(i);
//			ts[++tot] = i;
//			// cout << i << endl;
//			if (used[i] == 0) {
//				weight += cost[i];
//			}
//			used[i] = 1;
//		}
//	}
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//		for (int i = head[u]; i; i = edge[i].next) {
//			int v = edge[i].to;
//			ru[v]--;
//			if (ru[v] == 0) {
//				q.push(v);
//				ts[++tot] = v;
//				if (used[v] == 0)
//					weight += edge[i].w;
//			}
//		}
//	}
//}
//int main() {
//	int n, m, k, t;
//	in(n);
//	in(m);
//	in(k);
//	in(t);
//	for (int i = 1; i <= n; ++i)
//		in(cost[i]);
//
//	// 学过的.
//	if (k == 0) {
//		getchar();
//	}
//	else {
//		int tmp;
//		for (int i = 1; i <= k; ++i) {
//			in(tmp);
//			used[tmp] = 1;
//		}
//	}
//
//	/*
//	
//	*/
//
//	// 关联的:
//	for (int i = 1; i <= m; i++) {
//		int u, v, costt;
//		in(u);
//		in(v);
//		in(costt);
//		if (used[u] == 1 && used[v] == 0)
//			add(u, v, costt);
//		else if (used[v] == 1 && used[u] == 0)
//			add(v, u, costt);
//		else
//			add(u, v, costt);
//
//		ru[v]++;
//	}
//	topsort();
//	
//	if (weight <= t) {
//		cout << "Yes" << endl;
//	}
//	else
//		cout << "No" << endl;
//	return 0;
//}
