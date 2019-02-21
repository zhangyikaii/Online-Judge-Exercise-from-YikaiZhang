#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

const int maxn = 10000 + 15;
int n, m, sum, tim, top, s;
int p[maxn], head[maxn], sd[maxn], dfn[maxn], low[maxn]; //  DFN(u)为节点u搜索被搜索到时的次序编号(时间戳)，Low(u)为u或u的子树能够追溯到的最早的栈中节点的次序号 
int stac[maxn], vis[maxn]; // 栈只为了表示此时是否有父子关系 
int h[maxn], in[maxn], dist[maxn];

// from 边源自点, to 边指向点
struct EDGE {
	int to; 
	int next; 
	int from;
}edge[maxn * 10], ed[maxn * 10];

void add(int x, int y) {
	edge[++sum].next = head[x];
	edge[sum].from = x;
	edge[sum].to = y;
	head[x] = sum;
}
void tarjan(int x) {
	low[x] = dfn[x] = ++tim;
	stac[++top] = x;			// 点入栈
	vis[x] = 1;
	// 遍历当前点周围的点
	for (int i = head[x]; i; i = edge[i].next) {
		int v = edge[i].to;
		// 如果没有经过
		if (!dfn[v]) {
			// cout << v << " ";
			tarjan(v);			// dfs
			low[x] = min(low[x], low[v]);	// low[x]始终取自己子树low[v]的较小值，那么什么情况会使得dfn[u]又"重新"和low[u]相等呢，就是在u的子树中有一条边
		}
		// 如果经过了, 就更新low[], 这里就是构成环了!!!
		else if (vis[v]) {
			// cout << v << "d ";
			low[x] = min(low[x], low[v]);
		}
		//else {
		//	// printf("okkkk\n");
		//	// 这个分支就是, dfs遇到了一个已经走过的结点, 但是回溯已经把它弹栈了, 就是两个孩子之间有链接一条边, 但是显然构不成环
		//}
	}
	// cout << endl;

	// 缩点, 以x的环所有权值加在 p[x]
	if (dfn[x] == low[x]) {
		int y;
		// 当栈不空, 栈发挥作用啦, 可以知道以x为起点的一路下来dfs有什么元素
		while (y = stac[top--]) {
			sd[y] = x;			// 为了下面拓扑排序 if (sd[i] == i... 中找到每个环中领头的那个点(也是为了找到对的p[]), 表示这个点在新环中
			vis[y] = 0;			// 为下一次做准备, 这一次以 x 开始的全部搞出来归为零
			if (x == y)
				break;
			p[x] += p[y];
		}
	}
}
int topo() {
	queue <int> q;
	for (int i = 1; i <= n; i++) {
		// 入度为0的先入队
		if (sd[i] == i && !in[i]) {
			q.push(i);
			dist[i] = p[i];
		}
	}
	// k 从队里不断拿出来, k 的序列就是拓扑排序!!!
	while (!q.empty()) {
		int k = q.front();
		q.pop();

		for (int i = h[k]; i; i = ed[i].next) {
			int v = ed[i].to;
			dist[v] = max(dist[v], dist[k] + p[v]);		// 新图上dp!!! k是当前点(环), v是邻接的点(环), 不断往下选择最大的下一个环(点) // 注意这里的dp为了无后效性, 一定要拓扑排序, 就是从队里不断拿出来!!!
			in[v]--;			// 周围的入度减一
			// 如果入度为0了, 入队
			if (in[v] == 0) 
				q.push(v);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, dist[i]);
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
	}
	for (int i = 1; i <= n; i++) {
		// 如果这个点没有经过
		if (!dfn[i])
			tarjan(i);
	}

	for (int k = 1; k <= m; k++) {
		int x = sd[edge[k].from], y = sd[edge[k].to];
		// 建新图, 如果 x == y 就是tarjan之后是在一个环里面的了
		if (x != y) {
			// 下面是小的add()
			ed[++s].next = h[x];
			ed[s].to = y;
			ed[s].from = x;
			h[x] = s;			// 新图 head[]
			in[y]++;			// 为拓扑排序用的, 各点入度, 这边顺便求
		}
	}

	printf("%d", topo());
	return 0;
}

/*
题目背景
缩点+DP

题目描述
给定一个n个点m条边有向图，每个点有一个权值，求一条路径，使路径经过的点权值之和最大。你只需要求出这个权值和。

允许多次经过一条边或者一个点，但是，重复经过的点，权值只计算一次。

输入输出格式
输入格式：
第一行，n,m

第二行，n个整数，依次代表点权

第三至m+2行，每行两个整数u,v，表示u->v有一条有向边

输出格式：
共一行，最大的点权之和。

输入输出样例
输入样例#1：
2 2
1 1
1 2
2 1
输出样例#1：
2



输入:
10 20
970 369 910 889 470 106 658 659 916 964
3 2
3 6
3 4
9 5
8 3
5 8
9 1
9 7
9 8
7 5
3 7
7 8
1 7
10 2
1 10
4 8
2 6
3 1
3 5
8 5

输出:
6911

// md笔记里面的图:
6 8
1 1 1 1 1 1
1 2
1 3
4 1
3 4
2 4
3 5
4 6
5 6
*/