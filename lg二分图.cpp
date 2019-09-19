#include<cstdio>
#define rg register
#define ci const int
#define cl const long long int

namespace IO {
	char buf[110];
}

template <typename T>
inline void qr(T &x) {
	char ch = getchar(), lst = ' ';
	while ((ch > '9') || (ch < '0')) lst = ch, ch = getchar();
	while ((ch >= '0') && (ch <= '9')) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	if (lst == '-') x = -x;
}

template <typename T>
inline void write(T x, const char aft, const bool pt) {
	if (x < 0) { putchar('-'); x = -x; }
	rg int top = 0;
	do {
		IO::buf[++top] = x % 10 + '0'; x /= 10;
	} while (x);
	while (top) putchar(IO::buf[top--]);
	if (pt) putchar(aft);
}

template <typename T>
inline T mmax(const T a, const T b) { return a > b ? a : b; }
template <typename T>
inline T mmin(const T a, const T b) { return a < b ? a : b; }
template <typename T>
inline T mabs(const T x) { return x < 0 ? -x : x; }

template <typename T>
inline void mswap(T &a, T &b) {
	T temp = a; a = b; b = temp;
}

const int maxn = 1010;
const int maxm = 1000010;

struct Edge {               //链式前向星
	int to, nxt;
};
Edge edge[maxm]; int hd[maxn], ecnt;
inline void cont(ci from, ci to) {
	Edge &e = edge[++ecnt];
	e.to = to; e.nxt = hd[from]; hd[from] = ecnt;
}

int n, m;
int mch[maxn], dfn[maxn];
/*
*dfn为时间戳数组，含义见下
*mch为match,其中match[i]=j代表右侧的i号点与左侧的j号点匹配。
*/

void reading();
bool dfs(ci, ci);

int main() {
	qr(n); qr(m);
	reading();
	rg int _ans = 0;
	for (rg int i = 1; i <= n; ++i) if (dfs(i, i)) ++_ans;
	write(_ans, '\n', true);
	return 0;
}

void reading() {
	rg int a, b, e = 0; qr(e);
	while (e--) {
		a = b = 0; qr(a); qr(b);
		if ((b > m) || (a > n)) continue;
		cont(a, b);
	}
}

bool dfs(ci u, ci vistime) {
	/*
	* vistime为时间戳
	* 具体的，对于点u，如果dfn[u]<>vistime
	* 则点u在本轮匹配中还没有被匹配到
	*/
	for (rg int i = hd[u]; i; i = edge[i].nxt) {
		int &to = edge[i].to;
		if (dfn[to] != vistime) {
			dfn[to] = vistime;
			if ((!mch[to]) || (dfs(mch[to], vistime))) {
				mch[to] = u; return true;
			}
		}
	}
	return false;
}


