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


// 下面是答案 Dijkstra 好好捡回来.

#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

struct node {
	int v;	// 节点编号
	int cost;	// 边权值
	node(int _v, int _cost) : v(_v), cost(_cost) {}	// 构造函数
};

int N;	// 城市数量
int K;	// 道路条数
int INF = 1000000000;	// 无穷大数 
string start;	// 起始点城市名字
int happy[201];	// 存放各个城市的快乐值
map<string, int> stringToInt;	// 城市名字->编号
map<int, string> intToString; 	// 编号->城市名字
vector<node> graph[201];	// 无向图

// 从源点到点i的最少花费值.
int d[201];	// 记录从起始城市到达点i的最少花费值 
bool visited[201];	// 标记数组
vector<int> pre[201];	// 记录前一个节点 
vector<int> path;
vector<int> tempPath;
int optHappy = 0;
double optAverageHappy = 0.0;
int countt = 0;	// 记录最短路径条数 

void dijkstra(int s);
void dfs(int nowVisit);

int main() {
	cin >> N >> K >> start;
	stringToInt[start] = 0;	// 起始城市编号为0
	intToString[0] = start;	// 转化回来的map
	string city;
	int happyness;
	for (int i = 1; i <= N - 1; i++) {
		cin >> city >> happyness;
		// 用一个map把城市(字符串)转成数字.
		stringToInt[city] = i;
		intToString[i] = city;
		happy[i] = happyness;
	}
	string city1, city2;
	int cost;
	for (int i = 0; i < K; i++) {
		cin >> city1 >> city2 >> cost;
		int id1 = stringToInt[city1];
		int id2 = stringToInt[city2];
		graph[id1].push_back(node(id2, cost));
		graph[id2].push_back(node(id1, cost));
	}
	// graph就是邻接表存图.

	int destination = stringToInt["ROM"];
	dijkstra(0);
	dfs(destination);
	cout << countt << " " << d[destination] << " " << optHappy << " " << (int)optAverageHappy << endl;
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << intToString[path[i]];
		if (i != 0) {
			cout << "->";
		}
	}
	return 0;
}
// 打到一半发现这不是堆优化的, 还是要打标准的堆优化
//
//// Dijkstra 自己打一遍, 背下来.
//void dijkstraMy(int s) {
//	for (int i = 0; i < N; ++i) {
//		d[i] = INF;
//	}
//	d[s] = 0;	// 起始点 0.
//	for (int i = 0; i < N; ++i) {
//		int u = -1, min = INF;
//		for (int j = 0; j < N; ++j) {
//			// 如果没有访问过 j, 并且距离小于此轮 min. u 记录的是当前最小是到哪个点.
//			if (!visited[j] && d[j] < min) {
//				min = d[j];
//				u = j;
//			}
//		}
//
//		if (u == -1) {
//			// 说明所有点都访问过了.
//			return;
//		}
//		visited[u] = true;
//	}
//}

void dijkstra(int s) {
	for (int i = 0; i < N; i++) {
		d[i] = INF;
	}
	d[s] = 0;
	for (int i = 0; i < N; i++) {
		int u = -1, min = INF;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && d[j] < min) {
				min = d[j];
				u = j;
			}
		}
		if (u == -1) {
			return;
		}
		visited[u] = true;
		// 上面就相当于堆优化的出队一个元素.

		for (int j = 0; j < graph[u].size(); j++) {
			int v = graph[u][j].v;			// 访问邻居.
			int cost = graph[u][j].cost;
			if (!visited[v]) {
				if (d[u] + cost < d[v]) {
					d[v] = d[u] + cost;

					// 注意这里基于Dijkstra Skeleton的pre[]处理.
					pre[v].clear();
					pre[v].push_back(u);
				}
				// 放前驱结点, pre[v].clear();
				// pre[v].push_back(u);
				else if (d[u] + cost == d[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}

void dfs(int nowVisit) {
	// 反向dfs, 如果 == 0 就是说明到了源点.

	// 其实这个dfs完全可以写成循环.
	if (nowVisit == 0) {
		countt++;
		tempPath.push_back(nowVisit);
		int happyValue = 0;
		for (int i = tempPath.size() - 2; i >= 0; i--) {
			happyValue += happy[tempPath[i]];
		}
		double averageHappyValue = 1.0 * happyValue / (tempPath.size() - 1);
		if (happyValue > optHappy) {
			optHappy = happyValue;
			optAverageHappy = averageHappyValue;	// 也需要更新optAverageHappy的值 
			path = tempPath;
		}
		else if (happyValue == optHappy && averageHappyValue > optAverageHappy) {
			optAverageHappy = averageHappyValue;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(nowVisit);
	// 所有最短路到这个结点的上一个结点. 反向dfs遍历.
	// 太强了!
	for (int i = 0; i < pre[nowVisit].size(); i++) {
		dfs(pre[nowVisit][i]);
	}
	tempPath.pop_back();
}

/*

All Roads Lead to Rome (30)
时间限制 1000 ms 内存限制 65536 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述
Indeed there are many different tourist routes from our city to Rome.  You are supposed to find your clients the route with the least cost while gaining the most happiness.

输入描述:
Each input file contains one test case.  For each case, the first line contains 2 positive integers N (2<=N<=200), the number of cities, and K, the total number of routes between pairs of cities; followed by the name of the starting city.  The next N-1 lines each gives the name of a city and an integer that represents the happiness one can gain from that city, except the starting city.  Then K lines follow, each describes a route between two cities in the format "City1 City2 Cost".  Here the name of a city is a string of 3 capital English letters, and the destination is always ROM which represents Rome.


输出描述:
For each test case, we are supposed to find the route with the least cost.  If such a route is not unique, the one with the maximum happiness will be recommended.  If such a route is still not unique, then we output the one with the maximum average happiness -- it is guaranteed by the judge that such a solution exists and is unique.
Hence in the first line of output, you must print 4 numbers: the number of different routes with the least cost, the cost, the happiness, and the average happiness (take the integer part only) of the recommended route.  Then in the next line, you are supposed to print the route in the format "City1->City2->...->ROM".

输入例子:
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1

输出例子:
3 3 195 97
HZH->PRS->ROM


*/