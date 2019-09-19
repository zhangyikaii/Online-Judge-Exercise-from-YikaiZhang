#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>

struct Data {
	int x, y, step;
	Data() : x(-1), y(-1), step(0) { }
	Data(int xx, int yy, int s = 0) : x(xx), y(yy), step(s) { }
};

using namespace std;

#define in(x) x=read()

#define MAXN 210

typedef long long ll;

// 这就是两个人同时走的最短路的和.

int MyMax(int a, int b) {
	return a > b ? a : b;
}

int MyMin(int a, int b) {
	return a > b ? b : a;
}

int xway[4] = { 0, 0, 1, -1 };
int yway[4] = { 1, -1, 0, 0 };

int main() {
	int n, m;
	while (cin >> n >> m) {
		char arr[MAXN][MAXN];
		int isGet[MAXN][MAXN];
		int ax, ay, bx, by, ans = 0x7fffffff;
		bool used[MAXN][MAXN];
		bool uu[MAXN][MAXN];
		for (int i = 0; i < MAXN; ++i) {
			for (int k = 0; k < MAXN; ++k) {
				used[i][k] = false;
				uu[i][k] = false;
				isGet[i][k] = 0x7fffffff;
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int k = 1; k <= m; ++k) {
				cin >> arr[i][k];
				if (arr[i][k] == 'Y') {
					ax = i, ay = k;
				}
				else if (arr[i][k] == 'M') {
					bx = i, by = k;
				}
				else if (arr[i][k] == '@') {
					isGet[i][k] = 0x7fffffff;
				}
			}
		}

		queue<Data> q;
		q.push(Data(ax, ay));
		used[ax][ay] = true;
		while (!q.empty()) {
			Data tmp = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int xt = tmp.x + xway[i], yt = tmp.y + yway[i];
				if (arr[xt][yt] == '@') {
					isGet[xt][yt] = MyMin(isGet[xt][yt], tmp.step + 1);
				}
				else if (used[xt][yt] == false && xt <= n && xt >= 1 && yt <= m && yt >= 1 && arr[xt][yt] == '.') {
					q.push(Data(xt, yt, tmp.step + 1));
					used[xt][yt] = true;
				}
			}
		}

		q.push(Data(bx, by));
		uu[bx][by] = true;
		while (!q.empty()) {
			Data tmp = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int xt = tmp.x + xway[i], yt = tmp.y + yway[i];
				if (arr[xt][yt] == '@') {
					ans = MyMin(ans, tmp.step + 1 + isGet[xt][yt]);
					// cout << tmp.step  << "---   " << xt << "  " << yt << endl;
				}
				else if (uu[xt][yt] == false && xt <= n && xt >= 1 && yt <= m && yt >= 1 && arr[xt][yt] == '.') {
					q.push(Data(xt, yt, tmp.step + 1));
					uu[xt][yt] = true;
				}
			}
		}


		printf("%d\n", ans * 11);
	}

	return 0;
}


/*



*/