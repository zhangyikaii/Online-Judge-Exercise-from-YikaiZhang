#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

typedef long long ll;

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int arr[20][20], n;
int used[20] = { 0 };
int res = -1;

void dfs(int curWei, int num, int nextFind) {
	if (num == n - 1 && curWei > res) {
		res = curWei;
		return;
	}

	FOR(i, 1, n) {
		if (used[i] == 0) {
			used[i] = 1;
			dfs(curWei + arr[i][nextFind], num + 1, i);
			used[i] = 0;
		}
	}
}

int main() {
	in(n);
	FOR(i, 1, n) {
		FOR(k, 1, n) {
			in(arr[i][k]);
		}
	}

	//FOR(i, 1, n) {
	//	used[i] = 1;
	//	dfs(arr[i][i], 0, i);
	//	used[i] = 0;
	//}

	cout << res << endl;

	return 0;
}