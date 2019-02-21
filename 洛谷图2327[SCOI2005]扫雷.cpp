#include<iostream> 
#include<cstdio> 
#include<algorithm> 
#include <cstring>
using namespace std;

#define in(x) x=read()
#define MAXN 2010

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}
int n, a[10010] = { 0 }, b[10010] = { 0 }, ans = 0;

bool check() {
	for (int i = 2; i <= n - 1; ++i) {
		b[i + 1] = a[i] - b[i] - b[i - 1];
		if (b[i + 1] != 0 && b[i + 1] != 1)
			return false;
	}

	if (b[n] + b[n - 1] == a[n])
		return true;

	return false;
}
int main() {
	in(n);
	for (int i = 1; i <= n; ++i) {
		in(a[i]);
	}

	if (a[1] == 3) {
		printf("0\n");
		return 0;
	}
	else if (a[1] == 2) {
		b[1] = b[2] = 1;
		if (check() == true)
			++ans;
	}
	else if (a[1] == 1) {
		b[1] = 1, b[2] = 0;
		if (check() == true)
			++ans;
		b[1] = 0, b[2] = 1;
		if (check() == true)
			++ans;
	}
	else if (a[1] == 0) {
		b[1] = b[2] = 0;
		if (check() == true)
			++ans;
	}

	printf("%d\n", ans);

	return 0;
}

/*

// 注意每个点的扫雷信息都要加入判断, 都可能能造成这种雷的摆法不对.

相信大家都玩过扫雷的游戏。那是在一个n×m的矩阵里面有一些雷，要你根据一些信息找出雷来。万圣节到了，“余”人国流行起了一种简单的扫雷游戏，这个游戏规则和扫雷一样，如果某个格子没有雷，那么它里面的数字表示和它8连通的格子里面雷的数目。现在棋盘是n×2的，第一列里面某些格子是雷，而第二列没有雷，如下图：


由于第一列的雷可能有多种方案满足第二列的数的限制，你的任务即根据第二列的信息确定第一列雷有多少种摆放方案。

输入输出格式
输入格式：
第一行为N，第二行有N个数，依次为第二列的格子中的数。（1<= N <= 10000）

输出格式：
一个数，即第一列中雷的摆放方案数。

输入输出样例
输入样例#1：
2
1  1
输出样例#1：
2

*/