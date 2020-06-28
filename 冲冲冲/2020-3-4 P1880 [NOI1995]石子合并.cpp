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

int n;
int arr[210], dp[210][210], dpMax[210][210];
int sum[210];


int getSum(int i, int j) {
	if (i > j)
		return 0;
	return sum[j] - sum[i - 1];
}


// 注意: i, j 表示包含arr[i]和arr[j]的区间的min. 因为i == j返回的是arr[i].
int getIJmin(int i, int j) {
	if (i > j)
		return 0;
	// 注意下面! 不是一个区间, 还没开始合并, 所以要return 0.
	if (i == j) {
		return 0;
	}
	if (j == i + 1) {
		return arr[i] + arr[j];
	}

	if (dp[i][j] != 0)
		return dp[i][j];

	For(k, i, j) {
		if (dp[i][j] == 0)
			dp[i][j] = getIJmin(i, k) + getIJmin(k + 1, j) + getSum(i, j);
		else
			dp[i][j] = min(dp[i][j], getIJmin(i, k) + getIJmin(k + 1, j) + getSum(i, j));
	}
	return dp[i][j];
}

int getIJmax(int i, int j) {
	if (i > j)
		return 0;
	if (i == j) {
		return 0;
	}
	if (j == i + 1) {
		return arr[i] + arr[j];
	}

	if (dpMax[i][j] != 0)
		return dpMax[i][j];

	For(k, i, j) {
		dpMax[i][j] = max(dpMax[i][j], getIJmax(i, k) + getIJmax(k + 1, j) + getSum(i, j));
	}
	return dpMax[i][j];
}


int main() {
	// 4
	// 4 5 9 4

	// 43
	// 54

	in(n);
	
	For(i, 1, n + 1) {
		in(arr[i]);
		sum[i] = sum[i - 1] + arr[i];
	}
	for (int i = n + 1; i <= 2 * n; ++i) {
		arr[i] = arr[i - n];
		sum[i] = sum[i - 1] + arr[i];
	}

	int resMin = 0x7fffff, resMax = 0;
	For(beg, 1, n + 1) {
		// 求每条链式合并的min max.
		// cout << getIJmin(beg, beg + n - 1) << endl;
		resMin = min(resMin, getIJmin(beg, beg + n - 1));
		resMax = max(resMax, getIJmax(beg, beg + n - 1));
	}


	printf("%d\n%d\n", resMin, resMax);

	return 0;
}