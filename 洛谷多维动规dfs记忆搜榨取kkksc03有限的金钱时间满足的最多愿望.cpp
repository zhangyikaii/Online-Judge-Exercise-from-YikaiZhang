#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>
// 注意这种类似动规的 用一个f[]记录的 dfs记忆化搜索!!!
using namespace std;
int n, m, t;
struct Data {
	int tim, mon; 
} a[205];

int f[205][205][205];

int MyMax(int a, int b) {
	return a > b ? a : b;
}
// step表示第几个，money表示目前的钱，time表示目前的时间
int dfs(int step, int money, int time) {
	// 要return -1是因为之前搜索的时候直接拿来加也就是假设可以的，但是如果发现不符合条件就需要将之前的假设去掉，即return -1
	if (money < 0 || time < 0)
		return -1;

	// 记忆化
	if (f[step][money][time] != -1)
		return f[step][money][time];

	//越界 return
	if (step >= n)
		return 0;

	// dfs选择还是不选, 如果选了的话, 物品数要加一
	return f[step][money][time] = MyMax(dfs(step + 1, money - a[step + 1].mon, time - a[step + 1].tim) + 1, dfs(step + 1, money, time));
}

int main() {
	scanf("%d%d%d", &n, &m, &t);
	memset(f, -1, sizeof(f));
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].tim, &a[i].mon);

	printf("%d\n", dfs(0, m, t));

	return 0;
}


/*

这题就是 01 背包里面, 重量变成两个参量: 时间 + 金钱, 而01背包里的权值和, 变成都是1的(最大物品个数) 而已.

Kkksc03的时间和金钱是有限的，所以他很难满足所有同学的愿望。所以他想知道在自己的能力范围内，最多可以完成多少同学的愿望？

输入输出格式
输入格式：
第一行,n M T，表示一共有n(n<=100)个愿望，kkksc03 的手上还剩M(M<=200)元，他的暑假有T(T<=200)分钟时间。

第2~n+1行 mi,ti 表示第i个愿望所需要的金钱和时间。

输出格式：
一行，一个数，表示kkksc03最多可以实现愿望的个数。

输入输出样例
输入样例#1：
6 10 10
1 1
2 3
3 2
2 5
5 2
4 3
输出样例#1：
4

*/