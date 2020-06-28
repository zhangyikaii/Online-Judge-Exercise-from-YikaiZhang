//#include <bits/stdc++.h>
//using namespace std;
//
//#define in(x) x=read()
//
//typedef long long ll;
//
//inline int read() {
//	int X = 0, w = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X * w;
//}
//
//// 1, 2, 4, 8, 16
//// 6
//// 1, 2, 1 + 2, 3, 1 + 3, 2 + 3, 1 + 2 + 3, 4, 
//
//ll myPow(ll a, ll b) {
//	ll res = 1;
//	while (b--) {
//		res *= a;
//	}
//
//	return res;
//}
//
//
//// 已经发现了规律, 敏锐一点就发现是二进制啦!!!
//
//int main() {
//	int n, tmpDes, cmpDes = 1, cur = 1, des;
//	ll ans = 0;
//	in(n);
//	in(des);
//	tmpDes = des;
//
//
//	while (tmpDes > 2) {
//		// cout << tmpDes << endl;
//
//		// 初始化一定不要忘记啊啊啊
//		cur = 0;
//		cmpDes = 1;
//		while (cmpDes < tmpDes) {
//			cmpDes <<= 1;
//			++cur;
//		}
//		
//		ans += myPow(n, cur - 2);
//		
//		tmpDes -= (1 << (cur - 2));
//	}
//
//	if (tmpDes != 0)
//		ans += myPow(n, tmpDes - 1);
//
//	printf("%lld\n", ans);
//
//
//
//
//	return 0;
//}
//
//
//
///*
//
//
//*/


#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

long long k, n, ans;
stack<int> S;

int main() {
	cin >> k >> n;
	while (n) S.push(n & 1), n >>= 1;
	while (!S.empty()) ans += S.top() * pow(k, S.size() - 1), S.pop();
	cout << ans << endl;
	return 0;
}
