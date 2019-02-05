#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
using namespace std;
#define For(i, n, m) for(int i = n;i < m; ++i)

struct Pair {
	int first, second;
	Pair() { }
	Pair(int a, int b) : first(a), second(b) { }
};

inline int read() {
	char s;
	int k = 0, base = 1;
	while ((s = getchar()) != '-' && s != EOF&&!(s >= '0'&&s <= '9'));
	if (s == EOF)exit(0);
	if (s == '-')base = -1, s = getchar();
	while (s >= '0'&&s <= '9')
	{
		k = k * 10 + (s - '0');
		s = getchar();
	}
	return k * base;
}

// 题目中出现 最少 考虑bfs!!!
// dfs 太多了太容易爆了, 又不好剪枝
// bfs 加一项剪枝!!! 当前楼层已经访问过就不要再访问了!!!
// 加一个剪枝 访问过的楼层不要再放进去了, 然后! 就过了, 因为如果到不了B楼层就是其他楼层一直循环! 注意细节, 测试所有可能的案例! 能剪枝的就剪!

int a, b, n;
int arr[210], used[210] = { 0 };

int main() {
	n = read(), a = read(), b = read();

	for (int i = 1; i <= n; ++i) {
		arr[i] = read();
	}
	
	/*queue<pair<int, int>> q;
	q.push(make_pair(a, 0));*/

	queue<Pair> q;
	q.push(Pair(a, 0));
	int curLevel, curAns;
	while (!q.empty()) {
		curLevel = q.front().first, curAns = q.front().second;
		if (curLevel == b)
			break;
		q.pop();
		if (used[curLevel] == 0) {
			if (curLevel + arr[curLevel] <= n) {
				//q.push(make_pair(curLevel + arr[curLevel], curAns + 1));
				q.push(Pair(curLevel + arr[curLevel], curAns + 1));
			}
			if (curLevel - arr[curLevel] >= 0) {
				//q.push(make_pair(curLevel - arr[curLevel], curAns + 1));
				q.push(Pair(curLevel - arr[curLevel], curAns + 1));
			}
			used[curLevel] = 1;
		}
	}

	if (curLevel == b) {
		printf("%d\n", curAns);
	}
	else {
		printf("-1\n");
	}

	return 0;
}

/*
// dfs先搞一下?
int minn = 999999999, a, b, n;
int arr[210];

void dfs(int curNum, int level) {
	if (curNum == b && level < minn) {
		minn = level;
		return;
	}

	if (curNum + arr[curNum] <= n) {
		dfs(curNum + arr[curNum], level + 1);
	}
	if (curNum - arr[curNum] >= 1) {
		dfs(curNum - arr[curNum], level + 1);
	}
}


int main() {
	n = read(), a = read(), b = read();

	for (int i = 1; i <= n; ++i) {
		arr[i] = read();
	}

	dfs(a, 0);

	if (minn != 999999999)
		printf("%d\n", minn);
	else
		printf("-1\n");

	return 0;
}
*/
/*

电梯只有四个按钮：开，关，上，下。上下的层数等于当前楼层上的那个数字。当然，如果不能满足要求，相应的按钮就会失灵。

例如 3 3 1 2 5 表示:
从1楼开始。在1楼，按“上”可以到4楼，按“下”是不起作用的，因为没有−2楼。
问 A 到 B 要最少按多少次按钮

样例解释: 共有 5 楼, 问从1 -> 5最少需要按多少次

输入:
5 1 5
3 3 1 2 5

输出:
3

输出格式：
一行，即最少按键次数,若无法到达，则输出-1
*/
