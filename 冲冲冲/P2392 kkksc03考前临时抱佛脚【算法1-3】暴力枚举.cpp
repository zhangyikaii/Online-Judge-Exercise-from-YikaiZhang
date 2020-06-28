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


//int a, b, c, d;
//int arr[30], brr[30], crr[30], drr[30];

//// 1, 2, 5, 7
//int solve(int arr[], int n) {
//	For(i, 1, n) {
//		arr[i] += arr[i - 1];
//	}
//
//	For(i, 0, n) {
//		if (arr[i] > arr[n - 1] - arr[i])
//			// return min(max(arr[i - 1], arr[n - 1] - arr[i - 1]), arr[i])
//			return min(arr[n - 1] - arr[i - 1], arr[i]);
//	}
//
//	return -1;
//}

int input[5];
int arr[30];

int main() {
	For(i, 0, 4)
		in(input[i]);

	int res = 0;
	For(i, 0, 4) {
		int sum = 0;
		Fee(j, 1, input[i]) {
			in(arr[j]);
			sum += arr[j];
		}

		int dp[3000] = { 0 };

		Fee(j, 1, input[i]) {
			Ree(k, sum / 2, arr[j]) {
				dp[k] = max(dp[k], dp[k - arr[j]] + arr[j]);
			}
		}
		res += (sum - dp[sum / 2]);
	}

	cout << res << endl;
	
	return 0;
}