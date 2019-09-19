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

char arr[110][110];
char res[110][110];
char yiz[100] = "yizhong";

int n;

int xw[10] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int yw[10] = { 0, 0, 1, -1, 1, -1, 1, -1 };

void dfs(int cur, int xx, int yy, const int bef) {
	if (cur == 6) {
		int tx = xx, ty = yy;
		for (int k = 6; k >= 0; --k, tx -= xw[bef], ty -= yw[bef]) {
			res[tx][ty] = yiz[k];
		}
		return;
	}

	int tx = xx + xw[bef], ty = yy + yw[bef];
	if (tx < n && tx >= 0 && ty < n && ty >= 0 && arr[tx][ty] == yiz[cur + 1]) {
		dfs(cur + 1, tx, ty, bef);
	}
}
int main() {
	ios::sync_with_stdio(false);
	in(n);
	FOR(i, 0, n) {
		scanf("%s", &arr[i]);
		FOR(k, 0, n) {
			res[i][k] = '*';
		}
	}

	FOR(i, 0, n) {
		FOR(k, 0, n) {
			if (arr[i][k] == 'y') {
				FOR(j, 0, 8)
					dfs(0, i, k, j);
			}
		}
	}

	FOR(i, 0, n) {
		FOR(k, 0, n) {
			printf("%c", res[i][k]);
		}
		printf("\n");
	}

	return 0;
}
