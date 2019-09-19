#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010, MAXM = 500010;


// 链式前向星, 别忘了!
struct edge {
	int to, w, next;
};

edge e[MAXM];
int head[MAXN], dis[MAXN], cnt;
bool vis[MAXN];
int n, m, s;

inline void add(int u, int v, int w) {
	++cnt;
	e[cnt].w = w;
	e[cnt].to = v;
	e[cnt].next = head[u]; // 注意这句!
	head[u] = cnt;
}

// 因为要在队列里面比较距离大小, 所以一定要重载.
// 队列里面有下标, 有当前到这个点的距离.
struct node {
	int dis;
	int ind;
	node() { }
	node(int d, int p) : dis(d), ind(p) { }

	bool operator <(const node& x) const {
		return x.dis < dis;
	}
};


priority_queue<node> q;
inline void dijkstra() {
	dis[s] = 0;
	// s 算法起始点 这里放成了全局变量.
	q.push(node(0, s));					/////////////////

	while (!q.empty()) {
		node tmp = q.top();				//////////////////
		q.pop();

		int x = tmp.ind, d = tmp.dis;

		// 如果x已经被访问过. 如果已经访问过, 就继续
		if (vis[x])
			continue;
		vis[x] = 1;
		// 访问的记录是在拿出队列准备处理的时候.

		// 遍历i的邻居.
		for (int i = head[x]; i; i = e[i].next) {
			int nei = e[i].to;
			// 下面这个非常关键.
			// 就是在队列拿出最近距离之后其他点的更新.
			
			// 通过 x 到达 nei 的距离更小, 就更新
			// 如果要算多条相同路径并输出路径的, 还要加上 相等时候的记录, 详见PAT最短路并输出路径通罗马的路.cpp

			// if (dis[nei] > dis[x] + e[i].w)
			// 注意只有更新 而且没有被访问过这种节点才可以入队.
			if (dis[nei] > dis[x] + e[i].w) {
				dis[nei] = dis[x] + e[i].w;
				// 如果nei没有被访问过, 就入队
				// 这就是每一层更新, 邻居节点的d[]入队
				if (!vis[nei]) {
					q.push(node(dis[nei], nei));				///////////////
				}
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i <= n; ++i)dis[i] = 0x7fffffff;
	for (register int i = 0; i < m; ++i) {
		register int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		add(u, v, d); // 有向图, 加一次.
	}
	dijkstra();
	for (int i = 1; i <= n; i++)
		printf("%d ", dis[i]);

	return 0;
}



