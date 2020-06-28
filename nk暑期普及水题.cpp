#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<map>
#define INF 0xfffffff

#define CLR(a,b,Size) memset((a),(b),sizeof((a[0]))*(Size+1))
#define CPY(a,b) memcpy ((a), (b), sizeof((a)))
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

int a[1000010];
int f[10010][10010];


// 需要考虑压缩数组?
int main() {
	int n, m;
	
	int mod = 1e9 + 7;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int j = 1; j <= n; ++j) {
		for (int i = j; i <= n; ++i) {
			for (int k = 0; k < i; ++k) {
				f[i][j] = max(f[i][j], f[k][j - 1] + a[i]);
				f[i][j] = max(f[i][j], f[k][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = (ans + f[i][m]) % mod;
	}
	cout << ans << "\n";

	return 0;
}

/*

*/