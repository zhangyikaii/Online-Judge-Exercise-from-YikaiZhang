//#include <iostream> 
//#include <cstdio> 
//#include <algorithm> 
//#include <cstring>
//#include <cmath>
//#include <cstdlib>
//#include <string>
//#include <string.h>
//#include <vector>
//#include <set>
//
//using namespace std;
//
//#define in(x) x=read()
//
//#define FOR(i, s, n) for(int i = s; i < n; ++i)
//
//typedef long long ll;
//
//inline int read() {
//	int X = 0, w = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X*w;
//}
//
//int arr[110], brr[110], crr[110];
//int dp[110][110];
//int main() {
//	int t, n;
//	in(t), in(n);
//
//	FOR(i, 1, n + 1) {
//		in(arr[i]);
//	}
//	FOR(i, 1, n + 1) {
//		in(brr[i]);
//	}
//	FOR(i, 1, n + 1) {
//		in(crr[i]);
//	}
//
//	
//	FOR(i, 1, n + 1) {
//		for (int k = t; k >= 0; --k) {
//			if (k >= crr[i])
//				dp[i][k] = max(dp[i - 1][k], dp[i][k - crr[i]] + arr[i] - (t - k) * brr[i]);
//			else
//				dp[i][k] = dp[i - 1][k];
//		}
//	}
//
//	cout << dp[n][0] << endl;
//
//	return 0;
//}


//luogu 1417 wjz 1611161121
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define LL long long 
using namespace std;
const LL MAXN = 100000 + 10;
LL T, n;
LL f[MAXN];
struct node    //c[x]*b[y]<c[y]*b[x]
{
	LL a, b, c;
} m[MAXN];
bool cmp(node x, node y)
{
	return x.c * y.b < y.c * x.b;
}
int main()
{
	cin >> T >> n;
	for (LL i = 1; i <= n; i++) cin >> m[i].a;
	for (LL i = 1; i <= n; i++) cin >> m[i].b;
	for (LL i = 1; i <= n; i++) cin >> m[i].c;
	sort(m + 1, m + 1 + n, cmp);


	for (LL i = 1; i <= n; i++) {
		for (LL j = T; j - m[i].c >= 0; j--)
			f[j] = max(f[j], f[j - m[i].c] + m[i].a - j * m[i].b);
	}
	LL maxx = 0;
	for (LL i = 1; i <= T; i++)
		maxx = max(f[i], maxx);
	cout << maxx;
	return 0;
}