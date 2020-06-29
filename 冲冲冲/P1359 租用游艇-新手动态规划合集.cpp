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

int tmp, n;
int arr[210][210], dp[210];

int main() {
	in(n);
	Fee(i, 1, n) {
		Fee(j, i + 1, n) {
			in(tmp);
			arr[i][j] = arr[j][i] = tmp;
		}
	}

	Fee(i, 2, n) {
		For(j, 1, i) {
			if (dp[i] == 0)
				dp[i] = dp[j] + arr[i][j];
			else
				dp[i] = min(dp[i], dp[j] + arr[i][j]);
		}
	}

	cout << dp[n] << endl;
	

	return 0;
}