#include <iostream>
// 不可运行...
using namespace std;
#define MAX 1000

struct Edge {
	int next, to;
};


int col_num = 0, dfs_num = 0, top = -1;
int head[MAX], dfn[MAX], low[MAX], vis[MAX], stack[MAX], color[MAX];
Edge edge[MAX];


int MyMin(int a, int b) {
	return a > b ? b : a;
}

void Tarjan(int x) {
	dfn[x] = ++dfs_num;
	low[x] = dfs_num;
	vis[x] = true;//是否在栈中
	stack[++top] = x;
	for (int i = head[x]; i != 0; i = edge[i].next){
		int temp = edge[i].to;
		if (!dfn[temp]){
			Tarjan(temp);
			low[x] = MyMin(low[x], low[temp]);
		}
		else if (vis[temp])low[x] = MyMin(low[x], dfn[temp]);
	}
	if (dfn[x] == low[x]) {//构成强连通分量
		vis[x] = false;
		color[x] = ++col_num;//染色
		while (stack[top] != x) {//清空
			color[stack[top]] = col_num;
			vis[stack[top--]] = false;
		}
		top--;
	}
}