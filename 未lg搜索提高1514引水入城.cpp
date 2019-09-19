//#include <iostream> 
//#include <cstdio> 
//#include <algorithm> 
//#include <cstring>
//#include <cmath>
//#include <cstdlib>
//#include <string>
//using namespace std;
//
//#define in(x) x=read()
//
//struct Data  {
//	int x, y;
//	Data() : x(-1), y(-1)  { }
//};
//
//inline int read()  {
//	int X = 0, w = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9')  { if (ch == '-') w = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X*w;
//}
//
//int MyMin(int a, int b)  {
//	return a > b ? b : a;
//}
//
//void Swap(int arr[], int i, int j)  {
//	if (i == j)
//		return;
//
//	arr[i] = arr[i] ^ arr[j];
//	arr[j] = arr[i] ^ arr[j];
//	arr[i] = arr[i] ^ arr[j];
//}
//
//int n, m, arr[510][510];
///* 我的思路:
//dfs 把最上面一行每一个点建立引水站 对 最下面一行造成的影响( 覆盖了l -> r )求出来, 在dfs最上面一层所有排序, 看哪种排序最下面一层是满的而且最上面用的个数最少.*/
//
//int main()  {
//	in(n);
//	in(m);
//	for (int i = 1; i <= n; ++i)  {
//		for (int k = 1; k <= m; ++k)  {
//			in(arr[i][k]);
//		}
//	}
//
//
//	
//	return 0;
//}
//
//
///*
//
//
//题目描述
//在一个遥远的国度，一侧是风景秀美的湖泊，另一侧则是漫无边际的沙漠。该国的行政区划十分特殊，刚好构成一个NN 行 \times M×M 列的矩形，如上图所示，其中每个格子都代表一座城市，每座城市都有一个海拔高度。
//
//
//
//为了使居民们都尽可能饮用到清澈的湖水，现在要在某些城市建造水利设施。水利设施有两种，分别为蓄水厂和输水站。蓄水厂的功能是利用水泵将湖泊中的水抽取到所在城市的蓄水池中。
//
//因此，只有与湖泊毗邻的第11 行的城市可以建造蓄水厂。而输水站的功能则是通过输水管线利用高度落差，将湖水从高处向低处输送。故一座城市能建造输水站的前提，是存在比它海拔更高且拥有公共边的相邻城市，已经建有水利设施。由于第NN 行的城市靠近沙漠，是该国的干旱区，所以要求其中的每座城市都建有水利设施。那么，这个要求能否满足呢？如果能，请计算最少建造几个蓄水厂；如果不能，求干旱区中不可能建有水利设施的城市数目。
//
//输入输出格式
//输入格式：
//每行两个数，之间用一个空格隔开。输入的第一行是两个正整数N,MN,M，表示矩形的规模。接下来NN 行，每行MM 个正整数，依次代表每座城市的海拔高度。
//
//输出格式：
//两行。如果能满足要求，输出的第一行是整数11，第二行是一个整数，代表最少建造几个蓄水厂；如果不能满足要求，输出的第一行是整数00，第二行是一个整数，代表有几座干旱区中的城市不可能建有水利设施。
//
//输入输出样例
//输入样例#1：
//2 5
//9 1 5 4 3
//8 7 6 1 2
//输出样例#1：
//1
//1
//输入样例#2：
//3 6
//8 4 5 6 4 4
//7 3 4 3 3 3
//3 2 2 1 1 2
//输出样例#2：
//1
//3
//
//
//
//*/


// 认真读一下记忆化搜索的题解! 然后自己写
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;
#define maxn 510

// 方向的那个
#define nx x+xx[i]
#define ny y+yy[i]

int l[maxn][maxn], r[maxn][maxn];
int high[maxn][maxn];
int n, m;
bool vis[maxn][maxn];
int xx[4] =  { -1, 0, 1, 0 };
int yy[4] =  { 0, 1, 0, -1 };
int qx[maxn*maxn], qy[maxn*maxn];

// dfs 探测方向用宏定义的技巧!
// 
inline void dfs(int x, int y) {
	vis[x][y] = true;
	for (int i = 0; i<4; i++) {

		if (nx<1 || nx>n || ny<1 || ny>m) 
			continue;

		if (high[nx][ny] >= high[x][y])
			continue;

		if (!vis[nx][ny])
			dfs(nx, ny);

		// l[x][y]: (x, y) 这个点弄, 最底层可以水到的最小值.
		// 走一个方向, 走到新的位置就更新?
		l[x][y] = min(l[x][y], l[nx][ny]);
		r[x][y] = max(r[x][y], r[nx][ny]);
	}
}

inline int read() {
	int ret = 0;
	char c = getchar();
	while (c<'0' || c>'9') c = getchar();
	while (c >= '0' && c <= '9') {
		ret = ret * 10 + c - '0';
		c = getchar();
	}
	return ret;
}

int main() {
	n = read();
	m = read();
	// memset 只可以用来设置 0.
	memset(vis, false, sizeof(vis));
	memset(l, 0x3f, sizeof(l));
	memset(r, 0, sizeof(r));
	for (int i = 1; i <= m; i++)
		l[n][i] = r[n][i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			high[i][j] = read();
	}

	// dfs 就只弄第一行.
	for (int i = 1; i <= m; i++) {
		if (!vis[1][i])
			dfs(1, i);
	}
	bool flag = false;
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		if (!vis[n][i]) {
			flag = true;
			cnt++;
		}
	}
	if (flag) {
		puts("0");
		printf("%d", cnt);
		return 0;
	}
	int left = 1;
	while (left <= m) {
		int maxr = 0;
		for (int i = 1; i <= m; i++) {
			if (l[1][i] <= left)
				maxr = max(maxr, r[1][i]);
		}
		cnt++;
		left = maxr + 1;
	}
	puts("1");
	printf("%d", cnt);
}