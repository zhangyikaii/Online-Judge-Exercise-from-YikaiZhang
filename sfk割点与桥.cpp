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

using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(int i = s; i < n; ++i)

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

struct Edge {
	int next, to;
} edge[200020];

struct Data {
	int fir, sec;
	bool operator<(const Data &b) const {
		if (this->fir == b.fir) {
			return sec < b.sec;
		}
		return this->fir < b.fir;
	}
};

int n, m, idx, cnt, tot;
int *head, *dfn, *low;
bool *cut;
Data res[10010];
int iRes = 0;

// Á´Ê½Ç°ÏòÐÇ´æÍ¼.
void add(int x, int y) {
	edge[++cnt].next = y;
	edge[cnt].to = head[x];
	head[x] = cnt;
}

int tarjan(int u, int fa) {
	int lowu = ++idx;
	dfn[u] = idx;
	int child = 0;
	for (int i = head[u]; i != 0; i = edge[i].to) {
		int v = edge[i].next;
		if (dfn[v] == 0) {
			child++;
			int lowv = tarjan(v, u);
			lowu = min(lowu, lowv);
			if (lowv >= dfn[u]) {
				if (lowv > dfn[u]) {
					int sma = min(v, u), lar = max(v, u), i = 0;
					for (i = 0; i < iRes; ++i) {
						if (res[i].fir == sma && res[i].sec == lar)
							break;
					}
					if (i == iRes) {
						res[iRes].fir = sma;
						res[iRes].sec = lar;
						++iRes;
					}
				}
				cut[u] = 1;
			}
		}
		else if (dfn[v] < dfn[u] && v != fa) {
			lowu = min(lowu, dfn[v]);
		}
	}
	if (fa == 0 && child == 1) {
		cut[u] = 0;
	}
	low[u] = lowu;

	return lowu;
}


int main() {
	in(n);
	head = new int[n + 10];
	dfn = new int[n + 10];
	low = new int[n + 10];
	cut = new bool[n + 10];
	FOR(i, 0, n + 10) {
		head[i] = dfn[i] = low[i] = 0;
		cut[i] = false;
	}
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF) {
		add(a + 1, b + 1);
		add(b + 1, a + 1);
	}
	for (int i = 1; i <= n; i++) {
		if (dfn[i] == 0)
			tarjan(i, 0);
	}

	printf("wo yi yue du guan yu chao xi de shuo ming\n");
	for (int i = 1; i <= n; i++) {
		if (cut[i])
			printf("%d\n", i - 1);
	}

	sort(res, res + iRes);
	FOR(i, 0, iRes) {
		printf("%d %d\n", res[i].fir - 1, res[i].sec - 1);
	}
	return 0;
}