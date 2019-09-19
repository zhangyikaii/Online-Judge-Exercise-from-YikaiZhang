#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}


// 简单的动规, 注意机器人只能往右或者往下走.
int uniquePaths(int m, int n) {
	int used[110][110];
	used[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		if (i != 0)
			used[i][0] = used[i - 1][0];
		for (int j = 1; j < m; ++j) {
			if (i != 0)
				used[i][j] = used[i - 1][j] + used[i][j - 1];
			else used[i][j] = used[i][j - 1];
		}
	}

	return used[n - 1][m - 1];
}

int main() {
	cout << (1 & 7) << endl;
	cout << uniquePaths(7, 3) << endl;

	return 0;
}




/*

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？




说明：m 和 n 的值均不超过 100。

示例 1:

输入: m = 3, n = 2
输出: 3
解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右
示例 2:

输入: m = 7, n = 3
输出: 28

*/