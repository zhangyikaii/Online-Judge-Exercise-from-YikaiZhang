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

int MyAbs(int a, int b) {
	if (a - b < 0)
		return b - a;
	return a - b;
}

int arr[1010];

int dp[1010][10];

int main() {
	int n, m;
	in(n), in(m);

	for (int i = 1; i <= n; ++i) {
		in(arr[i]);
	}

	dp[1][0] = dp[1][1] = arr[1];
	for (int i = 2; i <= n; ++i) {
		if (arr[i] < arr[i - 1])
			dp[i][1] = 
	}
	
	return 0;
}