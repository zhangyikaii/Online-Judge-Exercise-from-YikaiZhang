#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

/*



*/


#define in(x) x=read()
#define xw x+xway[i]
#define yw y+yway[i]


inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;

	np->s.x = np->s.y;

	np->s.x = np->s.y;
	np->p = &(np->s.x);
	np->next = np;


}

int MyMin(int a, int b) {
	return a > b ? b : a;
}

void Swap(int arr[], int i, int j) {
	if (i == j)
		return;

	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}

int xway[5] = { 0, 1, -1, 0, 0 }, yway[5] = { 0, 0, 0, 1, -1 };
int n, m;
char mapp[110][110];
int used[510][510], maxx = 0xffffff;
int ax = -1, bx, ay, by;
int f[510][510][5];				// f[x][y][i] = 到了(x, y) 这个点, 上一层方向是 i, 所需要的最小拐弯次数
int anss[510][510];

void dfs(int x, int y, int curTurn, int curNum) {
	if (bx == x && y == by) {
		if (maxx > curNum)
			maxx = curNum;
	}


	// 记住这种半路上剪枝的记忆化搜索, 不一定要返回, 可以中间记录, 如果走过了 1. 结果更好就继续更新, 2. 结果更差就剪枝直接返回了.
	if (f[x][y][curTurn] > curNum)
		f[x][y][curTurn] = curNum;
	else
		return;

	// cout << "cur- " << x << " " << y << endl;
	int xt = x + xway[curTurn], yt = y + yway[curTurn];
	if (xt <= n && xt >= 1 && yt <= m && yt >= 1 && used[xt][yt] == 0 && mapp[xt][yt] == '.') {
		used[xt][yt] = 1;
		// cout << "1---   " << xt << "  " << yt << endl;
		dfs(xt, yt, curTurn, curNum);
		used[xt][yt] = 0;
	}

	for (int i = 1; i <= 4; ++i) {
		if (i != curTurn && xw <= n && xw >= 1 && yw <= m && yw >= 1 && used[xw][yw] == 0 && mapp[xw][yw] == '.') {
			used[xw][yw] = 1;
			// cout << "2---   " << xw << "  " << yw << endl;
			dfs(xw, yw, i, curNum + 1);
			used[xw][yw] = 0;
		}
	}


}

int main() {
	for (int i = 0; i < 510; ++i) {
		for (int k = 0; k < 510; ++k) {
			used[i][k] = 0;
			for (int j = 0; j < 5; ++j)
				f[i][k][j] = 0xfff;
		}
	}
	in(m);
	in(n);
	for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <= m; ++k) {
			cin >> mapp[i][k];
			if (mapp[i][k] == 'C' && ax == -1) {
				ax = i;
				ay = k;
				mapp[i][k] = '.';
			}
			else if (mapp[i][k] == 'C' && ax != -1) {
				bx = i;
				by = k;
				mapp[i][k] = '.';
			}
		}
	}

	used[ax][ay] = 1;
	dfs(ax, ay, 0, -1);

	/*for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <= m; ++k) {
			int t = min(f[i][k][1], f[i][k][2]), tt = min(f[i][k][3], f[i][k][4]);
			anss[i][k] = min(t, tt);
			cout << anss[i][k] << "\t";
		}
		cout << endl;
	}*/

	printf("%d\n", maxx);
	
	return 0;
}


/*

题目描述
The cows have a new laser-based system so they can have casual conversations while out in the pasture which is modeled as a W x H grid of points (1 <= W <= 100; 1 <= H <= 100).

The system requires a sort of line-of-sight connectivity in order to sustain communication. The pasture, of course, has rocks and trees that disrupt the communication but the cows have purchased diagonal mirrors ('/' and '\' below) that deflect the laser beam through a 90 degree turn. Below is a map that illustrates the

problem.

H is 8 and W is 7 for this map. The two communicating cows are notated as 'C's; rocks and other blocking elements are notated as '*'s:

7 . . . . . . .         7 . . . . . . .
6 . . . . . . C         6 . . . . . /-C
5 . . . . . . *         5 . . . . . | *
4 * * * * * . *         4 * * * * * | *
3 . . . . * . .         3 . . . . * | .
2 . . . . * . .         2 . . . . * | .
1 . C . . * . .         1 . C . . * | .
0 . . . . . . .         0 . \-------/ .
0 1 2 3 4 5 6           0 1 2 3 4 5 6
Determine the minimum number of mirrors M that must be installed to maintain laser communication between the two cows, a feat which is always possible in the given test data.

奶牛们都改用激光进行通讯了.

在W*H的牧场上，一些地方有树木和石头遮挡激光，所以，奶 牛打算使用对角镜来进行激光通讯.两只奶牛的位置是固定的，对角镜能把光线旋转90度.

输入输出格式
输入格式：
* Line 1: Two space separated integers: W and H

* Lines 2..H+1: The entire pasture.

输出格式：
* Line 1: A single integer: M

输入输出样例
输入样例#1：
7 8
.......
......C
......*
*****.*
....*..
....*..
.C..*..
.......
输出样例#1：
3

*/

// 看一遍题解然后自己写!!!
//
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//using namespace std;
//
//const int dx[] = { 1, 0, -1, 0 };
//const int dy[] = { 0, 1, 0, -1 };
//
//int n, m, ans(199), f[502][502][4];
//char a[502][502];
//bool vis[501][501];
//
//void dfs(int i, int j, int c, int d) { //c为转弯次数，d为方向
//	if (d != -1 && f[i][j][d] <= c) 
//		return; //记忆化取最优解 
//	if (d != -1) 
//		f[i][j][d] = c; //记录最优解 
//	if (a[i][j] == 'C') {
//		if (ans > c)
//			ans = c;
//		return;
//	}
//	int nx, ny;
//	if (d != -1) { //同方向搜索 
//		nx = i + dx[d], ny = j + dy[d];
//		if (nx >= 1 && ny >= 1 && nx <= n && ny <= m && !vis[nx][ny] && a[nx][ny] != '*') {
//			vis[nx][ny] = true;
//			dfs(nx, ny, c, d);
//			vis[nx][ny] = false;
//		}
//	}
//	for (int k = 0; k<4; k++) { //异方向搜索 
//		if (k == d) continue;
//		nx = i + dx[k], ny = j + dy[k];
//		if (nx >= 1 && ny >= 1 && nx <= n && ny <= m) {
//			if (vis[nx][ny] || a[nx][ny] == '*')
//				continue;
//			vis[nx][ny] = true;
//			dfs(nx, ny, c + (d != -1), k);
//			vis[nx][ny] = false;
//		}
//	}
//}
//
//int main() {
//	scanf("%d %d\n", &m, &n);
//	memset(f, 127, sizeof f); //f初始值INF 
//	for (int i = 1; i <= n; i++) gets(a[i] + 1);
//	for (int i = 1; i <= n; i++)
//	for (int j = 1; j <= m; j++) {
//		if (a[i][j] != 'C') continue;
//		vis[i][j] = true;
//		a[i][j] = '*'; //以防被误认为是终点 
//		dfs(i, j, 0, -1);
//		printf("%d\n", ans);
//		return 0;
//	}
//	return 0;
//}