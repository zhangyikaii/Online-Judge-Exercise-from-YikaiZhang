#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
using namespace std;


inline int read(){
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	if (f) return x;
	return 0 - x;
}

int pre[1010], nodeNum[1010]; // pre[a] == b表示a的父亲是b, nodeNum[i] == j表示根节点为i的树上有j个节点

void Init(int n) {
	// 最大的时候终止的时候 自己是自己的父亲
	for (int i = 1; i <= n; i++) {
		pre[i] = i;
		nodeNum[i] = 1;
	}
}

// 这是非递归的找父亲
int Find(int x) // Find(a)的返回值即是a的祖先 最大的那个
{
	int t = x;

	// 通过不断的找父亲操作，最终找到x的祖先，跳出就是自己是自己的祖先
	while (x != pre[x])
		x = pre[x];
	// 这里已经找到最老的祖先就是 x 了

	// 优化 避免树太长     这就是有在压缩优化了
	// 把这一路上的pre都直接指向最老祖先
	if (t != x) {
		int tFa = pre[t];  // 暂存t的父亲 
		pre[t] = x;        // 直接指向最老祖先
		t = tFa;           // 下一个次级的没有指向最老祖先的 一直递推往上找
	}

	return x;
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	//a,b的祖先一样，那么就不需要连接了
	if (a == b)
		return;

	// 注意这里接树的时候有遵循一个规则
	//a比b长，把b接到a树上 
	if (nodeNum[a] >= nodeNum[b]) {
		pre[b] = a;
		nodeNum[a] += nodeNum[b];
	}
	else {
		pre[a] = b;
		nodeNum[b] += nodeNum[a];
	}
}

bool Check(int x, int y) // 查找
{
	if (Find(x) == Find(y))
		return true;
	else
		return false;
}

int enemy[1010] = { 0 }, n, m;
char ch;
int a, b;

int main() {
	n = read();
	m = read();
	Init(n);

	for (int i = 1; i <= m; ++i) {
		ch = getchar();
		a = read();
		b = read();

		if (ch == 'F')
			Union(a, b);
		else {
			// 并查集一定要有这种首领的思想, a的敌人那一类, 就都归为Find(b)
			if (enemy[a] == 0)
				enemy[a] = Find(b);
			else
				Union(b, enemy[a]);

			if (enemy[b] == 0)
				enemy[b] = Find(a);
			else
				Union(a, enemy[b]);
		}
	}

	// 统计树根有几个, 就相当于统计有多少个堆(连通块)
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (pre[i] == i)
			++ans;
	}
	printf("%d", ans);

	return 0;
}

/*


题目描述
1920年的芝加哥，出现了一群强盗。如果两个强盗遇上了，那么他们要么是朋友，要么是敌人。而且有一点是肯定的，就是：

我朋友的朋友是我的朋友；

我敌人的敌人也是我的朋友。

两个强盗是同一团伙的条件是当且仅当他们是朋友。现在给你一些关于强盗们的信息，问你最多有多少个强盗团伙。

输入输出格式
输入格式：
输入文件gangs.in的第一行是一个整数N(2<=N<=1000)，表示强盗的个数（从1编号到N）。 第二行M(1<=M<=5000)，表示关于强盗的信息条数。 以下M行，每行可能是F p q或是E p q（1<=p q<=N），F表示p和q是朋友，E表示p和q是敌人。输入数据保证不会产生信息的矛盾。

输出格式：
输出文件gangs.out只有一行，表示最大可能的团伙数。

输入输出样例
输入样例#1：
6
4
E 1 4
F 3 5
F 4 6
E 1 2

输出样例#1：
3


*/