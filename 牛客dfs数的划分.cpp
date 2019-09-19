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

int n, k, ans;

// dfs 用一个vector测试, 很不错.
// 注意什么时候不要了 弹栈回来不要了也就马上返回.

void dfs(int cur, int left, int bef, vector<int> &v) {
	if (cur == k - 1) {
		if (left >= bef) {
			// v.push_back(left);
			dfs(cur + 1, 0, left, v);
			// v.pop_back();
		}
		return;
	}
	if (cur == k) {
		/*FOR(i, 0, v.size())
			cout << v[i] << " ";
		cout << endl;*/
		++ans;
		return;
	}

	FOR(i, bef, left) {
		// v.push_back(i);
		dfs(cur + 1, left - i, i, v);
		// v.pop_back();
	}
}


int main() {
	in(n);
	in(k);

	vector<int> v;
	dfs(0, n, 1, v);

	cout << ans << endl;

	return 0;
}