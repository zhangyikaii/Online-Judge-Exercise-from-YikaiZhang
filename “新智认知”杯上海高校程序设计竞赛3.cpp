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

int n, m, sn;
string s;
map<string, bool> mm;

int main() {
	// ios::sync_with_stdio(false);
	in(n);
	in(m);

	cin >> s;

	for (int i = m; i <= n; ++i) {
		for (int k = 0; k <= n - i; ++k) {
			// cout << i << "  " << k << endl;
			// cout << s.substr(k, i) << endl;
			mm[s.substr(k, i)] = true;
		}
	}

	cout << mm.size() << endl;

	return 0;
}
/*


*/