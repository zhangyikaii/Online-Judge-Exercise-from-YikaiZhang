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
	return X*w;
}

vector<int> v[10010];

int main() {
	ios::sync_with_stdio(false);
	int a, b, c;
	int n;
	cin >> n;
	while (cin >> a >> b >> c) {
		v[a - 1].push_back(b - 1);
	}

	FOR(i, 0, n) {
		FOR(k, 0, v[i].size())
			cout << v[i][k] << " ";
		cout << endl;
	}

	return 0;
}