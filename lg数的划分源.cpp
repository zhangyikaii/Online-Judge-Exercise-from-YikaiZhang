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

int x, y;
int res = 0;

void dfs(int left, int num, int bef) {
	if (num == y && left == 0) {
		++res;
		return;
	}
	
	if (num < y) {
		for (int i = bef; i <= left; ++i) {
			dfs(left - i, num + 1, i);
		}
	}
}

int main() {

	in(x);
	in(y);

	dfs(x, 0, 1);

	cout << res << endl;

	return 0;
}