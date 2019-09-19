#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include <time.h>
using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(int i = s; i < n; ++i)

typedef long long ll;

struct Data {
	int a, b, c;
	Data(int aa, int bb, int cc) : a(aa), b(bb), c(cc) { }
};

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}


const int MAXN = 1000010;
bool isPrime[MAXN];
int prime[MAXN];
int cnt = 0;
void Init()
{
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= MAXN; i++) {
		if (isPrime[i]) {
			prime[cnt++] = i;
		}
		for (int j = 0; j < cnt && i * prime[j] < MAXN; j++) {
			isPrime[i * prime[j]] = false;
			if (!(i % prime[j]))
				break;
		}
	}
	return;
}
//bool IsPrime(int n) {
//	if (n == 1)
//		return false;
//	if (n == 2 || n == 3)
//		return true;
//	if (n % 6 != 1 && n % 6 != 5)
//		return false;
//	for (register int i = 5; i * i <= n; i += 6) {
//		if (n % i == 0 || n % (i + 2) == 0)
//			return false;
//	}
//	return true;
//}

int ress[10000] = { 0 };

int main() {
	/*time_t a = time(0);*/
	Init();
	int l, r;
	vector<Data> v;
	in(l), in(r);

	FOR(i, l, r + 1) {
		// a = time(0);
		// cout << i << endl;
		if (i < cnt && isPrime[i] == true)
			continue;
		int t = i, countt = 0, k;
		do {
			for (k = 0; k < cnt && prime[k] * prime[k] <= t; ++k) {
				while (t % prime[k] == 0) {
					t /= prime[k];
					ress[countt++] = prime[k];
				}
				if (countt >= 1)
					break;
				if (t < MAXN && isPrime[t] == true)
					break;
			}
			/*time_t tt = time(0) - a;
			if (tt > 1)
				cout << i << "   kkk" << endl;*/
			if (prime[k] * prime[k] > t || countt >= 1 || t < cnt && isPrime[t] == true)
				break;
		} while (t != 1);
		if (countt == 2 && t == 1) {
			v.push_back(Data(i, ress[0], ress[1]));
			// cout << i << endl;
		}
		else if (countt == 1 && (t < cnt && isPrime[t] == true) || prime[k] * prime[k] > t) {
			v.push_back(Data(i, ress[0], t));
			// cout << i << endl;
		}
	}

	cout << v.size() << endl;
	for (auto i : v) {
		cout << i.a << " " << i.b << " " << i.c << endl;
	}
	return 0;
}


/*

链接：https://ac.nowcoder.com/acm/contest/637/C
来源：牛客网

题目描述
最近张老师对半素数感兴趣。半素数(semi-prime)是可以表示成两个素数乘积的数。比如4和10是半素数，因为4=2×2，10=2×5。而8不是半素数，因为8=2×2×2。他想知道某一个l到r的闭区间内有多少个这样的数。但是这个问题太困难了，他想让你帮他解决。
输入描述:
输入一行，包含两个数l,r(1<=l<=r<=1010，r-l<=105)，表示所求闭区间
输出描述:
第一行一个数n，表示一共有多少个半素数。
后面跟n行，每行三个整数pi ai bi，表示pi是半素数，是两个素数ai和bi的乘积
输出的n个半素数按照递增的顺序。对于每一行，ai<=bi
示例1
输入
复制
1 10
输出
复制
4
4 2 2
6 2 3
9 3 3
10 2 5

*/