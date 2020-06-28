#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long ll;
constexpr int N = 1e5 + 50;

ll n;
struct Node
{
	ll i, v;
	bool selected;
} a[N], b[N];

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int res = 0, neg = 1;
	char ch;
	do
	{
		ch = nc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res * neg;
}

int main()
{
	n = read();
	for (int i = 1; i <= n; ++i) a[i].v = read(), a[i].i = i;
	for (int i = 1; i <= n; ++i) b[i].v = read(), b[i].i = i;
	std::sort(a + 1, a + n + 1, [](Node p, Node q) { return p.v > q.v; });
	std::sort(b + 1, b + n + 1, [](Node p, Node q) { return p.v > q.v; });
	Node *A = a, *B = b;
	ll i = 1, j = 1, left = 0, right = 0, neg = 0;
	while ((A[i].v > 1 || B[j].v > 1) && i <= n && j <= n)
	{
		if (left > right)
		{
			std::swap(left, right);
			std::swap(i, j);
			std::swap(A, B);
		}
		if (A[i].v <= 1) break;
		A[i].selected = true;
		left += A[i++].v;
		++neg;
	}
	printf("%lld\n", std::min(left, right) - neg);

	// 这样子的cmp就非常6了.
	std::sort(a + 1, a + n + 1, [](Node p, Node q) { return p.i < q.i; });
	std::sort(b + 1, b + n + 1, [](Node p, Node q) { return p.i < q.i; });
	for (int i = 1; i <= n; ++i) printf("%d ", a[i].selected);
	printf("\n");
	for (int i = 1; i <= n; ++i) printf("%d ", b[i].selected);
	return 0;
}