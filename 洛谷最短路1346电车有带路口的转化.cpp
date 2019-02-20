#include<cstdio>
using namespace std;
const int INF = 2e9, maxn = 101;
int n, beg, end, cur, flag, g[maxn][maxn], dis[maxn];
bool vis[maxn];

// 数据不大, 邻接矩阵存
// 切换开关次数用权值为 0, 1 表示, 精妙啊, 反正要切换就换一次, 就是过去然后权值(总距离)加1了, 然后搜一遍最短路

int main() {
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < maxn; j++)
			g[i][j] = INF;
	}

	for (int i = 0; i < maxn; i++)
		g[i][i] = 0;
	for (int i = 0; i < maxn; i++)
		dis[i] = INF;

	scanf("%d%d%d", &n, &beg, &end);

	for (int i = 0, m; i < n; i++) {
		scanf("%d", &m);
		// 直接就是当前行和这个路口的连接点连一条边, 默认通向的车站就是 0.
		for (int j = 0, d; j < m; j++) {
			scanf("%d", &d);
			if (j == 0)
				g[i + 1][d] = 0;
			else
				g[i + 1][d] = 1;
		}
	}

	// 开始dj
	cur = beg;
	vis[beg] = true; 
	dis[beg] = 0;
	while (!vis[end]) {
		// 访问邻接车站
		for (int i = 1; i <= n; i++) {
			// 访问过, 或者没有边.
			if (vis[i] || g[cur][i] == INF)
				continue;
			if (dis[i] > g[cur][i] + dis[cur])
				dis[i] = g[cur][i] + dis[cur];
		}

		// 更新cur: 放到邻接车站
		// 堆优化就是在这里弄的! 注意小根堆比较的是dis[].
		// 不用堆优化就是手动放到最小
		flag = INF;
		for (int i = 1; i <= n; i++) {
			if (vis[i] || dis[i] >= flag)
				continue;
			if (flag > dis[i]) {
				cur = i;
				flag = dis[i];
			}
		}
		// 断掉了.. 访问领接车站的for就凉凉了, 就是走不了.
		if (flag == INF) {
			printf("-1");
			return 0;
		}

		vis[cur] = true;
	}
	printf("%d ", dis[end]);

	return 0;
}
/*
题目描述
在一个神奇的小镇上有着一个特别的电车网络，它由一些路口和轨道组成，每个路口都连接着若干个轨道，每个轨道都通向一个路口（不排除有的观光轨道转一圈后返回路口的可能）。在每个路口，都有一个开关决定着出去的轨道，每个开关都有一个默认的状态，每辆电车行驶到路口之后，只能从开关所指向的轨道出去，如果电车司机想走另一个轨道，他就必须下车切换开关的状态。

为了行驶向目标地点，电车司机不得不经常下车来切换开关，于是，他们想请你写一个程序，计算一辆从路口A到路口B最少需要下车切换几次开关。

输入输出格式
输入格式：
第一行有3个整数2<=N<=100，1<=A，B<=N，分别表示路口的数量，和电车的起点，终点。

接下来有N行，每行的开头有一个数字Ki(0<=Ki<=N-1)，表示这个路口与Ki条轨道相连，接下来有Ki个数字表示每条轨道所通向的路口，开关默认指向第一个数字表示的轨道。

输出格式：
输出文件只有一个数字，表示从A到B所需的最少的切换开关次数，若无法从A前往B，输出-1。

输入输出样例
输入样例#1：
3 2 1
2 2 3
2 3 1
2 1 2
输出样例#1：
0
*/