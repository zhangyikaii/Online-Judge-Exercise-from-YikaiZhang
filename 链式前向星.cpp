#include <iostream>
using namespace std;

#define MAXM 500010
#define MAXN 10010

// 有向图链式前向星遍历实例!

struct Edge{
	int next;	// 下一条边的存储下标 (其实是输入顺序的前一条边)
	int to;		// 这条边的终点 
	int w;		// 权值 
};
Edge edge[MAXM];

int n, m, cnt;
int head[MAXN];  // head[i]表示以i为起点的第一条边 

// head[i] 存的是连接 i 点的最后输入的边, 然后找其他边可以通过 edge[i].next 去找前面输入的边

void Add(int u, int v, int w) {		// 起点u, 终点v, 权值w 
	// 前两句是为了连接起整个图的
	edge[++cnt].next = head[u];
	head[u] = cnt;					// 第一条边为当前边 

	edge[cnt].w = w;
	edge[cnt].to = v;
}

void Print() {
	int start;
	cout << "Begin with[Please Input]: \n";
	cin >> start;
	// i开始为第一条边，每次指向下一条(以0为结束标志)
	// 若下标从0开始，next应初始化-1 !!!
	for (int i = head[start]; i != 0; i = edge[i].next) {
		cout << "Start: " << start << endl;
		cout << "End: " << edge[i].to << endl;
		cout << "W: " << edge[i].w << endl << endl;
	}
}

int main() {
	int s, t, w;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> s >> t >> w;
		Add(s, t, w);
	}
	Print();
	return 0;
}
