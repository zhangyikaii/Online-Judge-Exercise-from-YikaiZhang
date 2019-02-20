#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <functional>
#include <cstdlib>
using namespace std;

const int inf = 1000000010;// 要比blood大
// e[] 存边, 权值w表示会损失的血量.

struct node {
	int from, to, w, next;
}e[100010];// 边数组开双倍

int n, m, blood, tot = 0;
int cityCost[10010], cost[10010];
int head[10010], d[10010];
bool vis[10010];

struct cmp {
	bool operator()(int a, int b) {
		return d[a] > d[b];
	}
};
// 注意这个cmp的搭配
priority_queue<int, vector<int>, cmp> q;
// priority_queue<int, vector<int>, greater<int> >q;	// 小根堆

void addedge(int x, int y, int t) {
	tot++;
	e[tot].from = x;
	e[tot].to = y;
	e[tot].w = t;
	e[tot].next = head[x];
	head[x] = tot;
	return;
}

bool check(int x) {
	if (x < cityCost[1] || x < cityCost[n])
		return false;
	int i;
	for (i = 1; i <= n; i++)
		d[i] = inf;
	for (i = 1; i <= n; i++) {
		if (cityCost[i] > x)
			vis[i] = true;
		else
			vis[i] = false;
	}

	// 理解一下dijkstral的写法, 堆优化!!!
	d[1] = 0;
	q.push(1);
	while (!q.empty()) {
		int now = q.top();
		q.pop();
		if (vis[now])
			continue;
		vis[now] = true;
		for (i = head[now]; i; i = e[i].next) {
			// d[] 一直是选小的权值 ( 失血值 ), 最后判断可不可以走
			// 这里是关键:
			if (d[e[i].to] > e[i].w + d[now]) {
				d[e[i].to] = e[i].w + d[now];
				q.push(e[i].to);
			}
		}
	}
	if (d[n] <= blood)
		return true;
	else
		return false;
}

int main() {
	int i, j, k, t, ans, maxcost = 0;
	scanf("%d%d%d", &n, &m, &blood);
	for (i = 1; i <= n; i++){
		scanf("%d", &cityCost[i]);
		cost[i] = cityCost[i];
	}
	for (i = 1; i <= m; i++) {
		scanf("%d%d%d", &j, &k, &t);
		if (j == k)
			continue;
		addedge(j, k, t);
		addedge(k, j, t);
	}
	sort(cost + 1, cost + n + 1);		// 二分cost数组更快 否则会T一个点
	int l = 1, r = n, mid;

	// 交最多
	if (!check(cost[n])) {
		printf("AFK\n");
		return 0;
	}
	ans = cost[n];
	while (l <= r){
		mid = (l + r) >> 1;			// 二分..
		if (check(cost[mid])) {
			ans = cost[mid];
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}
/*
每个城市(结点)有一个过路费, 每一条路有一个血量, 

输入输出格式
输入格式：
第一行3个正整数，n，m，cityCost。分别表示有n个城市，m条公路，歪嘴哦的血量为cityCost。

接下来有n行，每行1个正整数，fi。表示经过城市i，需要交费fi元。

再接下来有m行，每行3个正整数，ai，bi，ci(1<=ai，bi<=n)。表示城市ai和城市bi之间有一条公路，如果从城市ai到城市bi，或者从城市bi到城市ai，会损失ci的血量。

输出格式：
仅一个整数，表示歪嘴哦交费最多的一次的最小值。注意是交费最多的一次费用的最小值.

如果他无法到达奥格瑞玛，输出AFK。

输入输出样例
输入样例#1：
4 4 8
8
5
6
10
2 1 2
2 4 1
1 3 4
3 4 3

输出样例#1：
10

//题目："他所经过的所有城市中最多的一次收取的费用的最小值是多少？"
//这句话的意思实际上是指：
//         对于一条路径 a ， 定义函数f(a)。
//         对于路径上的所有点权构成的集合s， 满足f(a)=max(s)
//         而对于一张图，从起点到终点存在多条路径a1,a2,a3...
//         对于所有可能的路径a1,a2,a3...，均存在对应的f(a1),f(a2),f(a3)...
//         求f(a1),f(a2),f(a3)...中的最小值

*/