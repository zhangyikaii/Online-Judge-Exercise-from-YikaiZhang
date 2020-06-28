#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define INF 0x7fffff

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

int n;
int res[10010][11], ires = 0;

int tmp[11];

void dfs(int cur, int sum) {
	if (cur == 10 && sum == n) {
		For(i, 1, 11) {
			res[ires][i] = tmp[i];
		}
		++ires;
		return;
	}

	if (cur == 10 && sum != n)
		return;

	For(i, 1, 4) {
		tmp[cur + 1] = i;
		dfs(cur + 1, sum + i);
	}
	
}
int main() {
	in(n);
	if (n < 10) {
		cout << 0 << endl;
		return 0;
	}

	dfs(0, 0);

	cout << ires << endl;
	For(i, 0, ires) {
		For(j, 1, 11)
			cout << res[i][j] << " ";
		cout << endl;
	}


	return 0;
}