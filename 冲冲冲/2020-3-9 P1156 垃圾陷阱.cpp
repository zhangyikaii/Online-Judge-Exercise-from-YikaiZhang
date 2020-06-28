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

struct Data {
	int inTime, energy, height;
	Data() {
		inTime = 0, energy = 0, height = 0;
	}
};

int d, g;
Data arr[110];
int dp[110][110];

bool cmp(Data a, Data b) {
	return a.inTime < b.inTime;
}

int main() {
	in(d), in(g);
	For(i, 0, g) {
		in(arr[i].inTime), in(arr[i].energy), in(arr[i].height);
	}

	sort(arr, arr + g, cmp);

	For(i, 0, g) {
		//For(v, 0, arr[i].height) {
		//	dp[i][v] = max(dp[i - 1][v], dp[i - 1][v] + arr[i].energy);
		//}
		//For(v, arr[i].height, d + 1) {
		//	dp[i][v] = max(dp[i][v],
		//		max(dp[i - 1][v] + arr[i].energy, dp[i - 1][v - arr[i].height]));
		//}
		
		for (int v = d; v >= arr[i].height; --v) {
			dp[i][v] = max(dp[i][v], 
				max(dp[i - 1][v] + arr[i].energy, dp[i - 1][v - arr[i].height]));
		}
		for (int v = arr[i].height - 1; v >= 0; --v) {
			dp[i][v] = max(dp[i - 1][v], dp[i - 1][v] + arr[i].energy);
		}
	}

	printf("%d\n", dp[g - 1][d]);


	return 0;
}