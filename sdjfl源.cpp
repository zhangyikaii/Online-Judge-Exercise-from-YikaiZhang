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

struct Data {
	int ks, js;
	bool operator<(const Data a) const {
		return this->ks < a.ks;
	}
};

Data arr[10010];
int dp[10010];

int main() {
	int n, m;
	in(n), in(m);

	for (int i = 1; i <= m; ++i) {
		in(arr[i].ks);
		in(arr[i].js);
	}

	sort(arr + 1, arr + 1 + n);

	for (int i = 1; i <= m; ++i) {
		
	}
	

	return 0;
}