#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

#define in(x) x=read()

#define MAXN 1000000

typedef long long ll;

ll tmpMask1 = (0x55) | (0x55 << 8);
ll mask1 = (tmpMask1) | (tmpMask1 << 16); // 得到掩码 01010101...01010101

ll tmpMask2 = (0x33) | (0x33 << 8);
ll mask2 = (tmpMask2) | (tmpMask2 << 16); // 得到掩码 00110011...00110011

ll tmpMask3 = (0x0f) | (0x0f << 8);
ll mask3 = (tmpMask3) | (tmpMask3 << 16); // 得到掩码  00001111...00001111

ll mask4 = (0xff) | (0xff << 16);          // 得到掩码  0000 0000 1111 1111 0000 0000 1111 1111

ll mask5 = (0xff) | (0xff << 8);          // 得到掩码：0000 0000 0000 0000 1111 1111 1111 1111

ll bitCount(ll x) {
	ll countt;

	// 下面有规律的
	countt = (x & mask1) + ((x >> 1) & mask1);
	countt = (countt & mask2) + ((countt >> 2) & mask2);
	countt = (countt & mask3) + ((countt >> 4) & mask3);
	countt = (countt & mask4) + ((countt >> 8) & mask4);
	countt = (countt & mask5) + ((countt >> 16) & mask5);

	return countt;
}


inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n;
ll two[100] = { 0 }, res = 4;
ll tmp;

int main() {
	for (ll i = 1; i <= 31; ++i) {
		two[i] = 1 << (ll)i;
	}
	in(n);
	if (n == 2)
		printf("4\n");
	else if (n == 1)
		printf("2\n");
	else {
		for (int i = 3; i <= n; ++i) {
			tmp = bitCount(i);
			res += two[tmp];
		}
		printf("%lld\n", res);
	}

	return 0;
}


/*

// 组合数每个模2再求和, 数据超大

读入 nnn, 输出


输入格式
读入 1≤n≤1071 \le n \le 10^71≤n≤10
​7
​​ .

样例
样例输入 1
10
样例输出 1
36

*/