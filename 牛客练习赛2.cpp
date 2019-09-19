#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << std::endl << #x << '=' << x << std::endl

// 快速幂, 真的干净简练!
inline LL qpow(LL a, LL b, LL p) {
	LL res = 1;
	for (; b; b >>= 1, a = a * a % p) {
		if (b & 1)
			res = res * a % p;
	}
	return res;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		LL a, b, k1, k2;
		std::cin >> a >> b >> k1 >> k2;
		// 快速幂到那一位
		// 除法嘛, 想知道那位是什么 * pow(10, ..) 之后 % b就可以了.
		// 不要傻傻地打模拟, 真的是直接 % b 就可以了.
		LL ans = ((a % b) % b * qpow(10, k1 - 1, b)) % b;
		// 然后再暴力除就可以了.
		for (LL i = k1; i <= k2; i++, ans = ans % b) {
			ans *= 10;
			// DEBUG(ans);
			std::cout << ans / b;
		}
		std::cout << std::endl;
	}
	return 0;
}

//#include <cstdio>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int N = 1000010;
//
//typedef long long ll;
//
//#define in(x) x=read()
//
//inline int read() {
//	int X = 0, w = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X*w;
//}
//
//
//int main() {
//	int T;
//	in(T);
//	while (T--) {
//		cout << endl;
//		int ress[100010] = { 0 };
//		int n, m, k1, k2;
//
//		in(m);
//		in(n);
//		in(k1);
//		in(k2);
//
//		int used[15] = { 0 };
//		int period = 0, begPeriod = 0;
//		int cnt = 0;
//		bool isFir = false;
//
//		if (m / n > 0) {
//			m = (m % n) * 10;
//		}
//		else {
//			while (m / n < 1) {
//				m *= 10;
//				if (isFir == false)
//					isFir = true;
//				else
//					ress[++cnt] = 0;
//			}
//		}
//
//		do {
//			int tr = m / n, tl = m % n;
//			if (tr != 0 && used[tr] != 0) {
//				period = cnt + 1 - used[tr];
//				begPeriod = used[tr];
//				cout << "peri" << period << ", beg: " << begPeriod << endl;
//				break;
//			}
//			ress[++cnt] = tr;
//			used[tr] = cnt;
//			m = tl * 10;
//		} while (cnt <= k2);
//
//		if (cnt <= k2) {
//			if (k1 <= cnt) {
//				for (int i = k1; i <= cnt; ++i)
//					cout << ress[i];
//				for (int i = cnt + 1; i <= k2; ++i)
//					cout << ress[i - period];
//			}
//			else {
//				for (int i = k1; i <= k2; ++i) {
//					cout << ress[(i - begPeriod) % period + begPeriod];
//				}
//			}
//			
//			cout << endl;
//		}
//		else {
//			for (int i = k1; i <= k2; ++i) {
//				cout << ress[i];
//			}
//		}
//	}
//
//	
//	return 0;
//}
