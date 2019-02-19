#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
#define in(a) a=read()
#define N 1005
#define mod 10007

inline ll read() {
	ll X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}


ll c[N][N];
ll a, b, k, n, m;
ll pow(ll x, ll y) {
	ll ans = 1, pas = x;
	while (y) {
		if (y & 1)
			ans *= pas%mod, ans %= mod;
		pas = (pas*pas) % mod;
		y >>= 1;
	}
	return ans % mod;
}

// 记忆化搜索
ll dfs(ll n, ll m){
	if (!m)
		return c[n][m] = true; 
	if (m == 1)
		return c[n][m] = n;
	if (c[n][m])
		return c[n][m];
	if (n - m < m)
		m = n - m;
	return
		c[n][m] = (dfs(n - 1, m) + dfs(n - 1, m - 1)) % mod;
}

int main() {
	scanf("%lld%lld%lld%lld%lld", &a, &b, &k, &n, &m);
	c[1][0] = c[1][1] = 1; 
	a %= mod;
	b %= mod;
	ll ans = 1;
	ans *= (pow(a, n) * pow(b, m)) % mod;
	if (n > m)
		n = m;
	ans *= dfs(k, n) % mod; 
	ans %= mod;

	printf("%lld", ans);
	return 0;
}

/*
题目描述
给定一个多项式(by+ax)^k请求出多项式展开后 x^n \times y^m 项的系数。

输入:
1 1 3 1 2

(就是 a, b, k, n, m)

输出:
3

*/