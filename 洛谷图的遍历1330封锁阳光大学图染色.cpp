#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<string>
#include<algorithm>

using namespace std;

struct Edge {
	int t;
	int nexty;
}edge[200000];

int head[20000];
int cnt = 0;	// 链式前向星

// 存边
void add(int a, int b) {
	cnt++;
	edge[cnt].t = b;
	edge[cnt].nexty = head[a];
	head[a] = cnt;
}

bool used[20000] = { 0 };						// 是否遍历过
int col[20000] = { 0 };							// 每一个点的染色
int sum[2];										// 黑白两种染色各自的点数

// dfs 染色!
// 染色（返回false即impossible）
bool dfs(int node, int color) {
	// 如果已被染过色
	if (used[node]) {
		if (col[node] == color)
			return true;						// 如果仍是原来的颜色，即可行
		return false;							// 非原来的颜色，即产生了冲突，不可行
	}

	// 处理:
	used[node] = true;							// 记录 已经遍历过
	sum[col[node] = color]++;					// 这一种颜色的个数加 1，且此点的颜色也记录下来
	
	bool tf = true;								// 是否可行

	// 遍历边:
	for (int i = head[node]; i != 0 && tf; i = edge[i].nexty) {
		tf = tf && dfs(edge[i].t, 1 - color);	// 是否可以继续染色, 这个技巧很不错!!! 这样一次tf出错, 后面 && 的就都凉凉了
	}
	return tf;									// 返回是否完成染色
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int a, b;
	while (m--) {
		scanf("%d%d", &a, &b);
		add(a, b);
		add(b, a);					// 存的是有向边，所以存两次
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (used[i])
			continue;				// 如果此点已被包含为一个已经被遍历过的子图，则不需重复遍历
		sum[0] = sum[1] = 0;		// 初始化
		if (!dfs(i, 0))				// 如果不能染色
		{
			printf("Impossible");
			return 0;				// 直接跳出
		}
		ans += min(sum[0], sum[1]);	// 加上小的一个
	}
	printf("%d", ans);				// 输出答案
	return 0;
}

/*

题目描述
曹是一只爱刷街的老曹，暑假期间，他每天都欢快地在阳光大学的校园里刷街。河蟹看到欢快的曹，感到不爽。河蟹决定封锁阳光大学，不让曹刷街。

阳光大学的校园是一张由N个点构成的无向图，N个点之间由M条道路连接。每只河蟹可以对一个点进行封锁，当某个点被封锁后，与这个点相连的道路就被封锁了，曹就无法在与这些道路上刷街了。非常悲剧的一点是，河蟹是一种不和谐的生物，当两只河蟹封锁了相邻的两个点时，他们会发生冲突。

询问：最少需要多少只河蟹，可以封锁所有道路并且不发生冲突。

输入输出格式
输入格式：
第一行：两个整数N，M

接下来M行：每行两个整数A，B，表示点A到点B之间有道路相连。

输出格式：
仅一行：如果河蟹无法封锁所有道路，则输出“Impossible”，否则输出一个整数，表示最少需要多少只河蟹。

输入输出样例
输入样例#1：
3 3
1 2
1 3
2 3
输出样例#1：
Impossible


输入样例#2：
3 2
1 2
2 3
输出样例#2：
1


*/