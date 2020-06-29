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

using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(int i = s; i < n; ++i)

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}


int main() {
	int res = 0;
	int n;
	string s;
	in(n);

	cin >> s;

	s = s + s + s;

	// 扩展三倍, 用中间一段.
	FOR(i, n, 2 * n) {
		int bef = 0, aft = 0;
		char bcur = 'w', acur = 'w';
		while (bef < n) {
			if (bef == 0 || s[i - 1 - bef] == 'w') {
				if (s[i - 1 - bef] != 'w')
					bcur = s[i - 1 - bef];
				++bef;
				continue;
			}
			if (bcur == 'w' && s[i - 1 - bef] != 'w') {
				bcur = s[i - 1 - bef];
				++bef;
				continue;
			}
			if (s[i - 1 - bef] != bcur)
				break;
			++bef;
		}
		while (aft < n - bef) {
			if (aft == 0 || s[i + aft] == 'w') {
				if (s[i + aft] != 'w')
					acur = s[i + aft];
				++aft;
				continue;
			}
			if (acur == 'w' && s[i + aft] != 'w') {
				acur = s[i + aft];
				++aft;
				continue;
			}
			if (s[i + aft] != acur)
				break;
			++aft;
		}

		res = max(res, bef + aft);
	}

	printf("%d\n", res);

	return 0;
}