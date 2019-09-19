#include <cstdio>
#include <stack>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, idx = 0, k = 1, Bcnt = 0;
int head[100];
int ins[100] = { 0 };
int dfn[100] = { 0 }, low[100] = { 0 };
int Belong[100];
stack <int> s;
struct edge
{
	int v, next;
}e[100];
int min(int a, int b)
{
	return a<b ? a : b;
}
void adde(int u, int v)
{
	e[k].v = v;
	e[k].next = head[u];
	head[u] = k++;
}
void readdata()
{
	int a, b;
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &a, &b);
		adde(a, b);
	}
}
void tarjan(int u)
{
	int v;
	dfn[u] = low[u] = ++idx;//每次dfs，u的次序号增加1
	s.push(u);//将u入栈
	ins[u] = 1;//标记u在栈内
	//访问从u出发的边
	for (int i = head[u]; i != -1; i = e[i].next) {
		v = e[i].v;
		if (!dfn[v])//如果v没被处理过
		{
			tarjan(v);//dfs(v)
			low[u] = min(low[u], low[v]);//u点能到达的最小次序号是它自己能到达点的最小次序号和连接点v能到达点的最小次序号中较小的
		}
		else if (ins[v])low[u] = min(low[u], dfn[v]);//如果v在栈内，u点能到达的最小次序号是它自己能到达点的最小次序号和v的次序号中较小的
	}
	if (dfn[u] == low[u])
	{
		Bcnt++;
		do
		{
			v = s.top();
			s.pop();
			ins[v] = 0;
			Belong[v] = Bcnt;
		} while (u != v);
	}
}
void work()
{
	for (int i = 1; i <= n; i++)if (!dfn[i])tarjan(i);
	printf("\n");
	for (int i = 1; i <= 6; i++)printf("%d %d\n", dfn[i], low[i]);
	printf("共有%d强连通分量，它们是:\n", Bcnt);
	for (int i = 1; i <= Bcnt; i++)
	{
		printf("第%d个:", i);
		for (int j = 1; j <= n; j++)
		{
			if (Belong[j] == i)printf("%d ", j);
		}
		printf("\n");
	}
}
int main()
{
	readdata();
	work();
	return 0;
}
/*
6 8
1 2
1 3
6 8
1 2
1 3
2 4
3 4
3 5
4 1
4 6
5 6
*/