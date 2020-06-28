#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
#include <cmath>
#include <string>
using namespace std;

typedef long long ll;

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n;
string s, res = "";
int del[10010] = { 0 };
bool isDel[10010] = { false };
map<char, int> mm;

// 关键就在每次相同比较, 如果出现选择保留前面的, 那么就固定是保留这一个了.

int main() {
	ios::sync_with_stdio(false);

	cin >> s;
	n = s.length();

	for (int i = 0; i < n; ++i) {
		if (mm[s[i]] == 0) {
			mm[s[i]] = i + 1;
		}
		else {
			if (isDel[mm[s[i]] - 1] == true) {
				del[i] = 1;
				continue;
			}
			// 保留前面
			if (s[mm[s[i]]] > s[mm[s[i]] - 1]) {
				del[mm[s[i]] - 1] = 0;				// 原来设定的不用删了.
				isDel[mm[s[i]] - 1] = true;
				del[i] = 1;
			}
			// 保留后面.
			else {
				del[mm[s[i]] - 1] = 1;
				mm[s[i]] = i + 1;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		// cout << del[i];
		if (del[i] == 0)
			res += s[i];
	}
	// cout << endl;

	cout << res << endl;

	return 0;
}
/*


*/