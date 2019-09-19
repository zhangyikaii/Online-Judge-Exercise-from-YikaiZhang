#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>			// 有sqrt就要
using namespace std;

#define in(x) x=read()

#define MAXN 500

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

// 简单的预处理 + dfs试一下吧.
// 注意最简单的剪枝, if (curAns > ans) return;

int n;
double res = 0xfffffff;
double a[30][2], dis[30][30];
bool used[30] = { false };

// 这是最标准的dfs了...
void dfs(double curAns, int bef, int level) {
	if (curAns > res)
		return;
	if (level == n) {
		/*for (int i = 0; i <= n; ++i)
			cout << debug[i] << " ";
		cout << endl;*/
		res = res > curAns ? curAns : res;
		// cout << res << endl;
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (used[i] == false) {
			used[i] = true;
			dfs(curAns + dis[bef][i], i, level + 1);
			used[i] = false;
		}
	}
}

double getDis(int x, int y) {
	if (x == y)
		return 0;

	return sqrt((a[x][0] - a[y][0]) * (a[x][0] - a[y][0]) + (a[x][1] - a[y][1]) * (a[x][1] - a[y][1]));
}


int main() {
	in(n);

	// 简单题注意特判
	if (n == 0) {
		printf("0\n");
		return 0;
	}

	a[0][0] = a[0][1] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%lf", &a[i][0]);				// double 是 %lf !!!!!!!!!!!!!!
		scanf("%lf", &a[i][1]);
	}

	// printf("%.6f\n", a[1][0]);

	for (int i = 0; i <= n; ++i) {
		for (int k = 0; k <= n; ++k) {
			dis[i][k] = getDis(i, k);
		}
	}

	dfs(0, 0, 0);

	printf("%.2f\n", res);				// 注意输出保留两位小数是怎么样!!!

	return 0;
}

/*

题目描述
房间里放着n块奶酪。一只小老鼠要把它们都吃掉，问至少要跑多少距离？老鼠一开始在(0,0)点处。

输入输出格式
输入格式：
第一行一个数n (n<=15)

接下来每行2个实数，表示第i块奶酪的坐标。

两点之间的距离公式=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))

输出格式：
一个数，表示要跑的最少距离，保留2位小数。

输入输出样例
输入样例#1：
4
1 1
1 -1
-1 1
-1 -1
输出样例#1：
7.41

*/