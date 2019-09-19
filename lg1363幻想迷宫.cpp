#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <queue>

using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(int i = s; i < n; ++i)

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

char arr[2020][2020];
bool used[2020][2020];

int xw[4] = { 0, 0, 1, -1 };
int yw[4] = { 1, -1, 0, 0 };

int n = 0, m = 0;

// 答案:
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//using namespace std;
//
//const int MAXN = 1500 + 1;
//const int dx[4] = { 1, -1, 0, 0 };
//const int dy[4] = { 0, 0, 1, -1 };
//
//int n, m;
//int st_x, st_y;
//int vis[MAXN][MAXN][3];
//bool fl, a[MAXN][MAXN];
//char ch;
//
//void dfs(int x, int y, int lx, int ly) {
//	if (fl) return;
	// 终止的时候!!! 如果这个点之前经过了. 就是在另外一个图上碰到了.
//	if (vis[x][y][0] && (vis[x][y][1] != lx || vis[x][y][2] != ly)) {
//		fl = 1;
//		return;
//	}
//	vis[x][y][1] = lx, vis[x][y][2] = ly, vis[x][y][0] = 1;				// 标记这个点为经过 了.
//	for (int i = 0; i<4; ++i) {
//		int xx = (x + dx[i] + n) % n, yy = (y + dy[i] + m) % m;
//		int lxx = lx + dx[i], lyy = ly + dy[i];
//		if (!a[xx][yy]) {
//			// 如果下一个点没有被经过 或者 注意这里是或者!!! 或者这个点被经过了但是现在到另外一个图上了.
//			if (vis[xx][yy][1] != lxx || vis[xx][yy][2] != lyy || !vis[xx][yy][0])
//				dfs(xx, yy, lxx, lyy);
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(false);
//	while (cin >> n >> m) {
//		fl = 0;
//		memset(a, 0, sizeof(a));
//		memset(vis, 0, sizeof(vis));
//		for (int i = 0; i<n; ++i)
//		for (int j = 0; j<m; ++j) {
//			cin >> ch;
//			if (ch == '#') a[i][j] = 1;
//			if (ch == 'S') st_x = i, st_y = j;
//		}
//		dfs(st_x, st_y, st_x, st_y);
//		if (fl) puts("Yes");
//		else puts("No");
//	}
//}



void dfs(int x, int y, int weiiix, int weiiiy, int sx, int sy, bool &flag) {
	if (flag == true)
		return;

	int tx, ty, weix, weiy;
	FOR(i, 0, 4) {
		weix = weiiix + xw[i];
		if (weix < 0) {
			tx = weix;
			do {
				tx += n;
			} while (tx < 0);
		}
		else
			tx = weix % n;

		weiy = weiiiy + yw[i];
		if (weiy < 0) {
			ty = weiy;
			do {
				ty += m;
			} while (ty < 0);
		}
		else
			ty = weiy % m;

		if (arr[tx][ty] == '#')			// 注意这里是因为第二个 else if 如果出现'#' 会出错, 
			continue;
		if (used[tx][ty] == false) {
			used[tx][ty] = true;
			// cout << "进 " << tx << ty << "  " << weix << weiy << endl;
			dfs(tx, ty, weix, weiy, sx, sy, flag);
			// cout << "弹 " << tx << ty << endl;
			used[tx][ty] = false;
		}
		else if (used[tx][ty] == true && weix != tx || weiy != ty) {
			// cout << " ------------- \n";
			flag = true;
			return;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);

	while (cin >> n >> m) {
		int sxx = 0, syy = 0;
		bool flag = false;
		FOR(i, 0, 2000) {
			FOR(j, 0, 2000)
				used[i][j] = false;
		}
		FOR(i, 0, n) {
			FOR(j, 0, m) {
				cin >> arr[i][j];
				if (arr[i][j] == 'S') {
					sxx = i;
					syy = j;
				}
			}
		}
		used[sxx][syy] = true;
		dfs(sxx, syy, sxx, syy, sxx, syy, flag);
		if (flag == true)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}