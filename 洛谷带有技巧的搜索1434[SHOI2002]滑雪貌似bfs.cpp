#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
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

// 因为有最大值相关, 又每个点都要搜, 所以用记忆化搜索

int r, c, a[110][110], f[110][110], ans = 0;
int xx[4] = { 0, 0, 1, -1 }, yy[4] = { 1, -1, 0, 0 };

int dfs(int x, int y) {
	if (f[x][y] != -1)
		return f[x][y];

	int t = 1;
	for (int i = 0; i < 4; ++i) {
		int xt = x + xx[i], yt = y + yy[i];
		if (xt >= 1 && yt >= 1 && xt <= r && yt <= c && a[xt][yt] < a[x][y]) {
			t = max(dfs(xt, yt) + 1, t);			// 不断挖, 挖到最大值
		}
	}

	f[x][y] = t;
	return t;
}

int main() {
	for (int i = 0; i < 110; ++i) {
		for (int k = 0; k < 110; ++k)
			f[i][k] = -1;
	}
	in(r), in(c);
	for (int i = 1; i <= r; ++i) {
		for (int k = 1; k <= c; ++k) {
			in(a[i][k]);
		}
	}

	for (int i = 1; i <= r; ++i) {
		for (int k = 1; k <= c; ++k) {
			ans = max(ans, dfs(i, k));
		}
	}

	printf("%d\n", ans);
	
	return 0;
}

/*

题目描述
Michael喜欢滑雪。这并不奇怪，因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael想知道在一个区域中最长的滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子：

1   2   3   4   5
16  17  18  19   6
15  24  25  20   7
14  23  22  21   8
13  12  11  10   9

一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可行的滑坡为24－17－16－1（从24开始，在1结束）。当然25－24－23－...－3－2－1更长。事实上，这是最长的一条。

输入输出格式
输入格式：
输入的第一行为表示区域的二维数组的行数R和列数C（1≤R，C≤100）。下面是R行，每行有C个数，代表高度(两个数字之间用1个空格间隔)。

输出格式：
输出区域中最长滑坡的长度。

输入输出样例
输入样例#1：
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
输出样例#1：
25

*/