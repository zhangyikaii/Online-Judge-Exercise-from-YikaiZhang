#include<cstdio>
#include<cctype>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility> 
#include<functional>

int Read() {
	int x = 0; char c = getchar();
	while (!isdigit(c)) {
		c = getchar();
	}
	while (isdigit(c)) {
		x = x * 10 + (c ^ 48);
		c = getchar();
	}
	return x;
}

using std::priority_queue;
using std::pair;
using std::vector;
using std::make_pair;
using std::greater;

struct Edge {
	int to, next, cost;
	Edge() { }
	Edge(int a, int b, int c) : to(a), next(b), cost(c) { }
}edge[2500001];
int cnt, head[110005];

void add_edge(int u, int v, int c = 0) {
	edge[++cnt] = Edge{ v, head[u], c };
	head[u] = cnt;
}

int dis[110005];
bool vis[110005];

void Dijkstra(int s) {
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > points;		// 堆优化
	points.push(make_pair(0, s));
	while (!points.empty()) {
		int u = points.top().second;
		points.pop();
		if (!vis[u]) {
			vis[u] = 1;
			for (int i = head[u]; i; i = edge[i].next) {
				int to = edge[i].to;
				if (dis[to] > dis[u] + edge[i].cost) {
					dis[to] = dis[u] + edge[i].cost;
					points.push(make_pair(dis[to], to));
				}
			}
		}
	}
}

int main() {
	int n = Read(), m = Read(), k = Read(), s = Read(), t = Read();
	int u, v, c;
	for (int i = 0; i < m; ++i) {
		u = Read(), v = Read(), c = Read();
		add_edge(u, v, c);
		add_edge(v, u, c);
		for (int j = 1; j <= k; ++j) {
			add_edge(u + (j - 1)*n, v + j*n);
			add_edge(v + (j - 1)*n, u + j*n);
			add_edge(u + j*n, v + j*n, c);
			add_edge(v + j*n, u + j*n, c);
		}
	}
	// 预防奇葩数据, 就是不需要 k 次免费机会就到了终点 => 到某一层的终点即可 => 各层终点之间连接一条权值 0 的边
	for (int i = 1; i <= k; ++i) {
		add_edge(t + (i - 1)*n, t + i*n);
	}
	Dijkstra(s);
	printf("%d", dis[t + k*n]);
	return 0;
}

/*
// 分层图!!!
题目描述
Alice和Bob现在要乘飞机旅行，他们选择了一家相对便宜的航空公司。该航空公司一共在nn个城市设有业务，设这些城市分别标记为00到n-1n−1，一共有mm种航线，每种航线连接两个城市，并且航线有一定的价格。

Alice和Bob现在要从一个城市沿着航线到达另一个城市，途中可以进行转机。航空公司对他们这次旅行也推出优惠，他们可以免费在最多kk种航线上搭乘飞机。那么Alice和Bob这次出行最少花费多少？

输入输出格式
输入格式：
数据的第一行有三个整数，n,m,k，分别表示城市数，航线数和免费乘坐次数。
第二行有两个整数，s,t，分别表示他们出行的起点城市编号和终点城市编号。
接下来有m行，每行三个整数，a,b,ca,b,c，表示存在一种航线，能从城市aa到达城市bb，或从城市bb到达城市aa，价格为cc。

输出格式：
只有一行，包含一个整数，为最少花费。

输入输出样例
输入样例#1：
5 6 1
0 4
0 1 5
1 2 5
2 3 5
3 4 5
2 3 3
0 2 100
输出样例#1：
8
*/