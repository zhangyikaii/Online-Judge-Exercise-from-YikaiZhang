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
//
//
//// 等价于要写一个大数减法 + 大数比大小.
//int main() {
//	int T;
//	in(T);
//
//	for (int id = 1; id <= T; ++id) {
//		int aIsNeg = 1, bIsNeg = 1;				// 注意这种可能有符号出现的加减法要设置标志位.
//		string a, b, c;
//		string res;
//		cin >> a >> b >> c;
//		if (a[0] == '-')
//			aIsNeg = -1;
//		else if (b[0] == '-')
//			bIsNeg = -1;
//
//		int goNum = 0;
//		int ia, ib;
//		for (ia = a.size() - 1, ib = b.size() - 1; ia >= 0 && ib >= 0; --ia, --ib) {
//			int tmp = aIsNeg * (a[ia] - '0') + bIsNeg * (b[ib] - '0') + goNum;
//			res = to_string(tmp % 10) + res;
//			goNum = tmp / 10;
//		}
//		// 如果有一位更长的情况.
//		if (ia != 0) {
//			for (; ia >= 0; --ia) {
//				int tmp = aIsNeg * (a[ia] - '0') + goNum;
//				res = to_string(tmp % 10) + res;
//				goNum = tmp / 10;
//			}
//		}
//		else if (ib != 0) {
//			for (; ib >= 0; --ib) {
//				int tmp = bIsNeg * (b[ib] - '0') + goNum;
//				res = to_string(tmp % 10) + res;
//				goNum = tmp / 10;
//			}
//		}
//
//		if (res.size() > c.size()) {
//			cout << "Case #" << id << ": true" << endl;
//		}
//		else if (res.size() < c.size()) {
//			cout << "Case #" << id << ": false" << endl;
//		}
//		else {
//			int i = 0;
//			for (i = 0; i < res.size(); ++i) {
//				if (res[i] > c[i]) {
//					cout << "Case #" << id << ": true" << endl;
//					break;
//				}
//				else if (res[i] < c[i]) {
//					cout << "Case #" << id << ": false" << endl;
//					break;
//				}
//			}
//
//			if (i == res.size()) {
//				cout << "Case #" << id << ": false" << endl;
//			}
//		}
//	}
//
//
//	return 0;
//}

// 下面是答案, 好像是想复杂了...

#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
LL a, b, c;
int t;
int main() {
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		LL sum;
		scanf("%lld%lld%lld", &a, &b, &c);
		sum = a + b;

		// f 是溢出标志, 根据两个加数判断是不是溢出了.
		// 某些情况如果溢出了, 就是大于了.
		bool f = false;
		if (a > 0 && b > 0 && sum < 0)
			f = true;
		else if (a < 0 && b < 0 && sum >= 0)
			f = false;
		else if (sum > c)
			f = true;
		else f = false;
		if (f)printf("true\n");
		else printf("false\n");
	}
	return 0;
}

/*




*/