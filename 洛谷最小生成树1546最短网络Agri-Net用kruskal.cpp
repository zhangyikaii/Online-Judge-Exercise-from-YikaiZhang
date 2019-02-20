// 并查集 + 快排 并查集模板不要忘了, kruskal 还需要复习!
// 这题就是裸的 kruskal
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

const int MAX_NODE = 110, MAX_EDGE = 10000;

int pre[MAX_NODE], nodeNum[MAX_NODE]; // pre[a] == b表示a的父亲是b, nodeNum[i] == j表示根节点为i的树上有j个节点

struct Edge {
	int u; //边连接的一个顶点编号
	int v; //边连接另一个顶点编号
	int w; //边的权值

	Edge() : u(-1), v(-1), w(-1) { }
};

// 这是sort要用的函数 重写
bool cmp(const Edge &a, const Edge &b) {
	return a.w < b.w;
}

void init(int n) {
	// 最大的时候终止的时候 自己是自己的父亲
	for (int i = 1; i <= n; i++) {
		pre[i] = i;
		nodeNum[i] = 1;
	}
}

// 这是非递归的找父亲
// findFather(a)的返回值即是a的祖先 最大的那个
int findFather(int x) {
	int t = x;

	// 通过不断的找父亲操作，最终找到x的祖先，跳出就是自己是自己的祖先
	while (x != pre[x])
		x = pre[x];
	// 这里已经找到最老的祖先就是 x 了

	// 优化 避免树太长 在压缩优化了
	if (t != x) {
		int tFa = pre[t];  // 暂存t的父亲 
		pre[t] = x;        // 直接指向最老祖先
		t = tFa;           // 下一个次级的没有指向最老祖先的 一直递推往上找
	}

	return x;
}

void Union(int a, int b) {
	a = findFather(a);
	b = findFather(b);

	// a, b的祖先一样，那么就不需要连接了
	if (a == b)
		return;

	// 注意这里接树的时候有遵循一个规则
	// a比b长，把b接到a树上
	if (nodeNum[a] >= nodeNum[b]) {
		pre[b] = a;
		nodeNum[a] += nodeNum[b];
	}
	else {
		pre[a] = b;
		nodeNum[b] += nodeNum[a];
	}
}

void Kruskal(const Edge edges[], int n, int m) {
	int cost = 0, e1 = 0, e2 = 0;
	init(n);
	// 按权值从小到大
	for (int i = 0; i < m; i++) {
		e1 = findFather(edges[i].u);
		e2 = findFather(edges[i].v);
		// 若当前边连接的两个结点在不同集合中，选取该边并合并这两个集合
		if (e1 != e2) {
			cost += edges[i].w;				// 最小生成树的权值加上去
			Union(edges[i].u, edges[i].v);	 // 合并当前边连接的两个顶点所在集合
		}
	}

	cout << cost << endl;
}

// 读入优化
int getin() {
	int x = 0;
	char ch = getchar();
	while (ch<'0' || ch>'9')
		ch = getchar();
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x;
}

Edge edges[MAX_EDGE];

int main() {
	int n, tmp, cnt = 0;
	n = getin();

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			tmp = getin();
			if (j < i) {
				edges[++cnt].u = i;
				edges[cnt].v = j;
				edges[cnt].w = tmp;
			}
		}
	}

	sort(edges + 1, edges + cnt + 1, cmp); //排序之后，可以以边权值从小到大的顺序选取边
	Kruskal(edges, n, cnt);

	return 0;
}

/*

题目背景
农民约翰被选为他们镇的镇长！他其中一个竞选承诺就是在镇上建立起互联网，并连接到所有的农场。当然，他需要你的帮助。

题目描述
约翰已经给他的农场安排了一条高速的网络线路，他想把这条线路共享给其他农场。为了用最小的消费，他想铺设最短的光纤去连接所有的农场。

你将得到一份各农场之间连接费用的列表，你必须找出能连接所有农场并所用光纤最短的方案。每两个农场间的距离不会超过100000

输入输出格式
输入格式：
第一行： 农场的个数，N（3<=N<=100）。

第二行..结尾: 后来的行包含了一个N*N的矩阵,表示每个农场之间的距离。理论上，他们是N行，每行由N个用空格分隔的数组成，实际上，他们限制在80个字符，因此，某些行会紧接着另一些行。当然，对角线将会是0，因为不会有线路从第i个农场到它本身。

输出格式：
只有一个输出，其中包含连接到每个农场的光纤的最小长度。

输入输出样例
输入样例#1：
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0
输出样例#1：
28

*/
