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
#include <map>
#include <sstream>
#include <assert.h>
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

struct Data {
	int xx, yy, wayy, cost;
	Data() {}
	Data(int tx, int ty, int tw, int c = 0) : xx(tx), yy(ty), wayy(tw), cost(c) { }
};

int n, m;
int xw[10] = { -1, 0, 1, 0 };
int yw[10] = { 0, -1, 0, 1 };
int arr[110][110];
int used[110][110];
int begWay = 0;

int MySub(int a, int b) {
	int t = a - b;
	return t > 0 ? t : -t;
}

// 题解中的提示, 这里非常巧妙.
// 答案这里说得好哇!

// 每次从队首取出一个元素，根据这个元素旋转，直行，得到一个新的坐标，然后判断由这种方式到达的这个点是否是耗时最短的一种方式(类似于Dijkstra中的dis数组)，此处用f[i][j]数组表示，然后队列为空后，输出f[终点的x][终点的y]即可。

int main() {
	ios::sync_with_stdio(false);
	in(n);
	in(m);
	FOR(i, 0, n + 1) {
		FOR(k, 0, m + 1)
			used[i][k] = 0;
	}
	int tmp = 0;
	int ans = 0;
	FOR(i, 1, n + 1) {
		FOR(k, 1, m + 1) {
			in(tmp);
			if (tmp == 1) {
				arr[i][k] = 1;
				arr[i - 1][k] = 1;
				arr[i][k - 1] = 1;
				arr[i - 1][k - 1] = 1;
			}
		}
	}
	FOR(i, 0, n + 1) {
		arr[i][0] = 1;
		arr[i][m] = 1;
	}
	FOR(i, 0, m + 1) {
		arr[0][i] = 1;
		arr[n][i] = 1;
	}

	int sx, sy, ex, ey;
	in(sx), in(sy), in(ex), in(ey);
	char c;
	c = getchar();
	switch (c) {
	case 'N':
		begWay = 0;
		break;
	case 'S':
		begWay = 2;
		break;
	case 'W':
		begWay = 1;
		break;
	case 'E':
		begWay = 3;
		break;
		
	default:
		break;
	}

	queue<Data> q;
	q.push(Data(sx, sy, begWay, 1));
	used[sx][sy] = 1;

	int tcost = 0;
	while (!q.empty()) {
		Data qt = q.front();
		q.pop();
		// cout << "popp: " << qt.xx << "  " << qt.yy << endl;

		FOR(i, 0, 4) {
			for (int j = 1; j <= 3; ++j) {
				int txx = qt.xx + xw[i] * j, tyy = qt.yy + yw[i] * j;
				tcost = 1;
				int tmpp = MySub(i, qt.wayy);
				if (tmpp == 2)
					tcost += 2;
				else if (tmpp == 1 || tmpp == 3)
					tcost++;

				if (txx < n && txx > 0 && tyy > 0 && tyy < m && (used[txx][tyy] == 0 || used[txx][tyy] > qt.cost + tcost) && arr[txx][tyy] == 0) {
					q.push(Data(txx, tyy, i, qt.cost + tcost));
					// cout << "push: " << txx << "  " << tyy << endl;
					used[txx][tyy] = qt.cost + tcost;
				}
				else if (txx >= n || txx <= 0 || tyy >= m || tyy <= 0 || arr[txx][tyy] == 1)
					break;
			}
		}
	}

	//FOR(i, 0, n + 1) {
	//	FOR(k, 0, m + 1) {
	//		cout << used[i][k] << "   ";
	//	}
	//	cout << endl;
	//}


	printf("%d\n", used[ex][ey] - 1);

	

	return 0;
}
