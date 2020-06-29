#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define Fee(i, b, e) for(int i = (b); i <= (e); ++i)
#define Ree(i, b, e) for(int i = (b); i >= (e); --i)

#define INF 0x7fffff

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

int n, m;
int arr[110][110], res[110][110];
int xw[5] = { 0, 0, -1, 1 };
int yw[5] = { -1, 1, 0, 0 };
int ans = 0;

int dfs(int x, int y) {
	if (res[x][y])
		return res[x][y];
	res[x][y] = 1;
	For(i, 0, 4) {
		int nx = x + xw[i], ny = y + yw[i];
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && arr[nx][ny] < arr[x][y]) {
			dfs(nx, ny);
			if (res[nx][ny] + 1 > res[x][y]) {
				res[x][y] = res[nx][ny] + 1;
			}
		}
	}
	return res[x][y];
}
int main() {
	in(n), in(m);
	Fee(i, 1, n) {
		Fee(j, 1, m) {
			in(arr[i][j]);
		}
	}

	res[1][1] = 1;

	Fee(i, 1, n) {
		Fee(j, 1, m) {
			dfs(i, j);
		}
	}

	Fee(i, 1, n) {
		Fee(j, 1, m) {
			ans = max(ans, res[i][j]);
		}
	}

	
	cout << ans << endl;

	return 0;
}