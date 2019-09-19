// 复习组合数模板, 就是靠那个公式打表
#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>

// 答案
// 此类题可以找规律...
//#include<iostream>
//using namespace std;
//int ans[1005][1005], q, n, m;
//int main() {
//	for (int i = 1; i <= 1000; i++)
//	for (int j = 1; j <= 1000; j++) {
//		ans[i][j] = (ans[i - 1][j - 1] + ans[i - 1][j] + i) % 19260817;
//	}
//	cin >> q;
//	while (q--) {
//		cin >> n >> m;
//		cout << ans[m][n] << endl;
//	}
//	return 0;
//}

using namespace std;

#define in(x) x=read()

#define MAXN 1000

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int c[MAXN + 10][MAXN + 10];

// 组合数模板一定要背啊!!!
void Init() {
	c[0][0] = 1;
	c[1][0] = 1;
	c[1][1] = 1;
	c[0][1] = 1;
	// 用高中那个递推式, 从 i = 2 开始
	for (int i = 2; i < MAXN; ++i) {
		c[i][0] = 1;
		for (int k = 1; k <= i; ++k) {
			c[i][k] = (c[i - 1][k] + c[i - 1][k - 1]) % 19260817;
		}
	}
}

int q, n, m;

int main() {
	Init();
	in(q);
	
	while (q--) {
		in(n);
		in(m);
		int ans = 0;
		for (int i = 1; i <= m; ++i) {
			for (int k = 1; k <= i && k <= n; ++k) {
				ans += c[i][k];
			}
			ans %= 19260817;
		}

		printf("%d\n", ans);
	}

	return 0;
}




/*


*/