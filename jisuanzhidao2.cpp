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
#include <assert.h>

using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(ll i = s; i < n; ++i)

typedef long long ll;

inline ll read() {
	ll X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

struct Data {
	int x[5], y[5];
	Data() {
		FOR(i, 0, 4) {
			x[i] = 0;
			y[i] = 0;
		}
	}
	void ff() {
		x[2] = x[0];
		y[2] = y[1];
		x[3] = x[1];
		y[3] = y[0];
	}

	Data(int x0, int y0, int x1, int y1) {
		x[0] = x0;
		y[0] = y0;
		x[1] = x1;
		y[1] = y1;
		ff();
	}
};

bool fun(int t, int a, int b) {
	if (t > a && t < b)
		return true;
	return false;
}

int main() {
	int t;
	in(t);
	while (t--) {
		int n;
		in(n);
		FOR(i, 0, n) {

		}
	}

	return 0;
}