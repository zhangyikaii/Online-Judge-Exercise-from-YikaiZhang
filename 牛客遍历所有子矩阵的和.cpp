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
#include <queue>

using namespace std;
#define ll long long
const int maxn = 1005;
int n, m, len;
ll a[maxn], b[maxn], c[maxn*maxn];

//ll div(ll limit) {
//	// 二分查找要会背, 不然要调很久.
//	ll id = 0;
//	int l = 1, r = len;
//	// 这里是 <= 
//	while (l <= r) {
//		int mid = (l + r) / 2;
//
//		// 可能可以的时候, 直接id = mid 记录了.
//		if (c[mid] <= limit)
//			id = mid, l = mid + 1;
//		else
//			r = mid + 1;
//	}
//
//	return id;
//}
ll work(ll limit)
{
	ll id = 0;
	int l = 1, r = len;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (c[mid] <= limit)
			id = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	return id;
}

// a[] 的所有段的和
// 真实题目中 的那个 a * b矩阵的, 其实就是这里a, b 所有子段的和然后乘起来的答案.

ll cal(ll limit)
{
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			// 因为这里 x * b 的某一子段和 == limit 就是真实题目的那个矩阵的了.
			ll x = a[i] - a[j - 1];
			ans += work(limit / x);
		}
	}
	return ans;
}
int main()
{
	ll L, R;
	scanf("%d%d%lld%lld", &n, &m, &L, &R);
	for (int i = 1, x; i <= n; i++)
	{
		scanf("%d", &x);
		a[i] = a[i - 1] + x;
	}
	for (int i = 1, x; i <= m; i++)
	{
		scanf("%d", &x);
		b[i] = b[i - 1] + x;
		for (int j = 1; j <= i; j++)
			c[++len] = b[i] - b[j - 1];
	}

	// c[] 就是b的所有子段的和.
	sort(c + 1, c + len + 1);
	printf("%lld\n", cal(R) - cal(L - 1));
	return 0;
}