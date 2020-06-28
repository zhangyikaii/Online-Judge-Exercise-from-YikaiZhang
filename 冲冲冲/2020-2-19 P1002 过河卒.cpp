#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define INF 0x7fffff

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

// P1002 过河卒
int m, n;
int hx, hy;
ll dp[100][100];
int hous[40][40];
int ways[6][2] = {
	1, 1,
	1, -1,
	-1, 1,
	-1, -1
};

int main() {
	// 注意这种题不要先初始化一条边界, 这题初始化最开始那个点就OK了.

	// 因为这种就是不能跳的点(马控制点)为0最好, 而且其他点初始化也是为0.
	// 那么怎么判断并分开来呢? 就是把马的控制点挑出来. 遇到一个就判断是不是.
	// 数据很小就可以用类似hash的方式.
	in(m), in(n), in(hx), in(hy);
	++m;
	++n;
	++hx;
	++hy;

	For(i, 0, 4) {
		// 细致处理数组下标.
		if (hx + 2 * ways[i][0] >= 0 && hy + 1 * ways[i][1] >= 0)
			hous[hx + 2 * ways[i][0]][hy + 1 * ways[i][1]] = 1;
		if (hx + 1 * ways[i][0] >= 0 && hy + 2 * ways[i][1] >= 0)
			hous[hx + 1 * ways[i][0]][hy + 2 * ways[i][1]] = 1;
	}
	hous[hx][hy] = 1;

	dp[1][1] = 1;
	//For(i, 0, m + 1) {
	//	dp[i][0] = 1;
	//}
	//For(i, 0, n + 1) {
	//	dp[0][i] = 1;
	//}

	For(i, 1, m + 1) {
		For(j, 1, n + 1) {
			if (hous[i][j] == 0) {
				dp[i][j] = max(dp[i][j], dp[i][j - 1] + dp[i - 1][j]);
			}
		}
	}

	/*For(i, 1, m + 1) {
		For(j, 1, n + 1) {
			cout << dp[i][j] << "\t";
		}
		cout << endl;
	}*/
	
	printf("%lld\n", dp[m][n]);
	return 0;
}