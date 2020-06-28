#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <assert.h>
#include <istream>

using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(ll i = s; i < n; ++i)

typedef long long ll;

inline ll read() {
	ll X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}
ll n;

ll biao[5] = { 0, 2, 6, 20 };
ll mod = 1000000007;

ll c[1010][1010];
void Init() {
	c[0][0] = 1;
	c[1][0] = 1;
	c[1][1] = 1;
	c[0][1] = 1;
	for (int i = 2; i < 1008; ++i) {
		c[i][0] = 1;
		for (int k = 1; k <= i; ++k) {
			c[i][k] = (c[i - 1][k] + c[i - 1][k - 1]) % mod;
		}
	}
}

ll QuickPower(ll a, ll b)  {
	ll ans = 1, base = a;		// ans为答案，base为a^(2^n)
	while (b > 0) {
		// 这一位有 1 => 乘到 ans 上
		if (b & 1)				// &是位运算，b&1表示b在二进制下最后一位是不是1，如果是：
			ans = (ans * base) % mod;		// 把ans乘上对应的a^(2^n)

		base = (base * base) % mod;			// base自乘，由a^(2^n)变成a^(2^(n+1)), 记住base = a^(二进制表示中每一位值) 时刻准备乘到ans上, 只要这一位有 1 即可
		b >>= 1;				// 位运算，b右移一位，如101变成10（把最右边的1移掉了），10010变成1001。现在b在二进制下最后一位是刚刚的倒数第二位。结合上面b & 1食用更佳
	}
	return ans;
}

int main() {
	Init();
	while (true) {
		in(n);
		if (n == 0)
			break;

		if (n <= 3) {
			printf("%lld\n", biao[n]);
			continue;
		}

		ll base = QuickPower(4, n);
		ll sub = 0;
		for (int i = 1; i < n; i += 2) {
			sub = (((sub + c[n][i]) % mod) * (0x1 << (n - i))) % mod;
		}

		sub = (2 * sub) % mod;



		// printf("%lld\n", (base + mod - 2 * sub) % mod);
	}
	
	return 0;
}