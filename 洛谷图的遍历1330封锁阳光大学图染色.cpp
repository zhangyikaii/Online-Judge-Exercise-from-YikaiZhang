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