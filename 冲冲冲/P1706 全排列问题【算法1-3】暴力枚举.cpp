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

int tmp[20];
int n;
int used[20];

void dfs(int tot) {
	if (tot == n) {
		Fee(i, 1, n)
			cout << setw(5) << tmp[i];
		cout << endl;
		return;
	}

	Fee(i, 1, n) {
		if (used[i] == 0) {
			used[i] = 1;
			tmp[tot + 1] = i;
			dfs(tot + 1);
			used[i] = 0;
		}
	}
}
int main() {
	in(n);

	dfs(0);
	return 0;
}