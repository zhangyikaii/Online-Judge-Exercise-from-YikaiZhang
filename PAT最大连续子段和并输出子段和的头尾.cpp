#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define in(x) x=read()
#define For(i, a, b) for(int i = a; i < b; ++i)

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

int arr[100010] = { 0 }, dp[100010] = { 0 };
int beg[100010] = { 0 };
int main() {
	int n = 0;
	bool flag = false;
	in(n);
	for (int i = 1; i <= n; ++i) {
		in(arr[i]);
		if (arr[i] >= 0)
			flag = true;
	}
	
	dp[1] = arr[1];
	beg[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (dp[i - 1] < 0) {
			beg[i] = i;
			dp[i] = arr[i];
		}
		else {
			beg[i] = beg[i - 1];
			dp[i] = arr[i] + dp[i - 1];
		}
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}

	int befr = 1, endr = 1;
	int res = arr[1];
	for (int i = 1; i <= n; ++i) {
		if (dp[i] > res) {
			res = dp[i];
			befr = beg[i];
			endr = i;
		}
	}

	if (flag == false)
		printf("0 %d %d\n", arr[1], arr[n]);
	else
		printf("%d %d %d\n", res, arr[befr], arr[endr]);
	return 0;
}

/*
题目描述:

最大连续子段和, 并输出最大连续子段和的头尾.


*/