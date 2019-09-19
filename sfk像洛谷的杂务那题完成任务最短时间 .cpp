#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

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

int cnt = 0, n = 0;
int *head, *fini, *inDu, *weight;
queue<int> q;

struct Edge {
	int next, to;
} edge[200020];

// ¡¥ Ω«∞œÚ–«¥ÊÕº.
void add(int u, int v) {
	edge[++cnt].next = v;
	edge[cnt].to = head[u];
	head[u] = cnt;
	++inDu[v];
}

int topo() {
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (!inDu[i])
			q.push(i);
	}
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		fini[t] += weight[t];
		res = max(res, fini[t]);

		for (int k = head[t]; k; k = edge[k].to) {
			int nx = edge[k].next;
			--inDu[nx];
			fini[nx] = max(fini[nx], fini[t]);
			if (!inDu[nx])
				q.push(nx);
		}
	}

	return res;
}

int main() {
	int a, b;
	int tmp;
	in(n);
	head = new int[n + 10];
	fini = new int[n + 10];
	inDu = new int[n + 10];
	weight = new int[n + 10];
	FOR(i, 0, n + 10) {
		head[i] = fini[i] = inDu[i] = weight[i] = 0;
	}
	FOR(i, 0, n) {
		in(tmp);
		in(weight[tmp]);
	}

	while (scanf("%d %d", &a, &b) != EOF) {
		add(b, a);
	}

	printf("I have read the rules about plagiarism punishment\n%d\n", topo());
	
	return 0;
}