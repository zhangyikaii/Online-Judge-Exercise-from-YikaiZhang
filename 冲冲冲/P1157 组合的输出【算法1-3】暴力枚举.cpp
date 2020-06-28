#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define Fee(i, b, e) for(int i = (b); i <= (e); ++i)

#define INF 0x7fffff

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

int used[30];
int r, n;

void dfs(int tot) {
	if (tot == r) {
		for (int i = 1; i <= r; ++i) {
			cout << setw(3) << used[i];
		}
		cout << endl;
		return;
	}

	Fee(i, used[tot] + 1, n) {
		used[tot + 1] = i;
		dfs(tot + 1);
	}
}
int main() {
	in(n), in(r);

	dfs(0);
	return 0;
}