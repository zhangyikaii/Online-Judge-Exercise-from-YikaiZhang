#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define INF 0x7fffff
#define MAX 70

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}


// 伤啊, 只可以0, 1, 2个附件.
// 干脆不打01背包了, 直接上组合+分组背包.

int N, m;
int v[MAX], p[MAX], q[MAX];
int f[MAX][32010];				// 前 i 个物品 花费 j 元
int major[MAX], sumMajor = 1;   // sumMajor 从1开始存 实际主件个数是 sumMajor - 1


int main() {
	N = read();
	m = read();

	for (int i = 0; i < MAX; ++i) {
		for (int k = 0; k < 32010; ++k) {
			f[i][k] = 0;
		}
	}

	for (int i = 1; i <= m; ++i) {
		in(v[i]);
		in(p[i]);
		in(q[i]);
		if (q[i] == 0) {
			major[sumMajor++] = i;     // 记录主件序号
		}
	}

	int iMajor = 1;

	for (int i = 0; i <= N; ++i)
		f[0][i] = 0;

	// 相当于构造主件的背包  只是加一个附件的循环 把最优附件选择加上去了
	for (int i = major[iMajor]; iMajor < sumMajor; ++iMajor) {

		i = major[iMajor];       // i: 主件对应输入数组的序号, 还原映射.

		// 这里考虑 不选主件 & 选且只选这个主件
		// 打一个 0 1.
		for (int k = N; k >= 0; --k) {
			if (k >= v[i])
				f[iMajor][k] = max(f[iMajor - 1][k], f[iMajor - 1][k - v[i]] + v[i] * p[i]);
			else
				f[iMajor][k] = f[iMajor - 1][k];
		}

		// k: 花费
		// 简单讲: 这里考虑 选主件且选附件
		for (int j = 1; j <= m; ++j) {
			// 判断：如果是这个主件的附件
			if (q[j] == i) {
				for (int k = N; k >= v[i] + v[j]; --k)
					f[iMajor][k] = max(f[iMajor][k], f[iMajor][k - (v[i] + v[j])] + v[i] * p[i] + v[j] * p[j]);
			}
		}
	}

	cout << f[sumMajor - 1][N] << endl;

	return 0;
}

