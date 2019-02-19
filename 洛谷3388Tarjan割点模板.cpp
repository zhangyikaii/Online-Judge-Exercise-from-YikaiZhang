#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>

#define F(x,y,z) for (int x=y;x<=z;++x)
#define ll long long
using namespace std;
int head[1000005], vis[1000005], k, ans[1000005], dfn[1000005], low[1000005], t, tot, rt;

struct edg {
	int to, next;
}e[2000005];
void add(int x, int y) {
	e[++tot].to = y; e[tot].next = head[x]; head[x] = tot;
}

// root 是本次搜索的根的点
void Tarjan(int root, int cur) {
	vis[cur] = 1;
	dfn[cur] = ++t;
	low[cur] = t;
	int flag = 0;
	for (int j = head[cur]; j; j = e[j].next) {
		int p = e[j].to;
		if (!vis[p]) {
			if (cur == root)
				rt++;
			Tarjan(root, p);
			low[cur] = min(low[cur], low[p]);
			if (low[p] >= dfn[cur] && cur != root && !flag) {
				ans[++k] = cur;
				flag = 1;
			}
		}
		else {
			low[cur] = min(low[cur], dfn[p]);		// !!!!!!!!!!!!!!!!???
		}
	}
	if (rt >= 2 && cur == root)
		ans[++k] = root;
	return;
}
int main()
{
	int x, y, n, m;
	scanf("%d%d", &n, &m);
	F(i, 1, m) {
		scanf("%d%d", &x, &y);
		add(x, y); add(y, x);
	}
	F(i, 1, n) {
		if (!vis[i]) {
			rt = 0; 
			t = 0; 
			Tarjan(i, i);
		}
	}
	sort(ans + 1, ans + k + 1);
	printf("%d\n", k);
	F(i, 1, k)
		printf("%d ", ans[i]);
	return 0;
}

/*

题目背景
割点

题目描述
给出一个nn个点，mm条边的无向图，求图的割点。


输入输出样例
输入样例#1：
6 7
1 2
1 3
1 4
2 5
3 5
4 5
5 6
输出样例#1：
1
5


// 第一行是输出割点个数, 第二行是具体点
*/