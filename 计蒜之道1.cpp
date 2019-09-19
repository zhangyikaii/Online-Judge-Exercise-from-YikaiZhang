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
#include <sstream>
#include <assert.h>
#include <istream>

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

int arr[110] = { 0 };
int used[110] = { 0 };
int n;

int rett() {
	int dpp[110];
	FOR(i, 0, n) {
		dpp[i] = 1;
		if (used[i] == 1)
			continue;
		FOR(j, 0, i) {
			if (used[j] == 1)
				continue;
			if (arr[j] < arr[i] && dpp[j] + 1 > dpp[i]) {
				dpp[i] = dpp[j] + 1;
			}
		}
	}

	int maxx = 0;
	FOR(i, 0, n) {
		if (maxx < dpp[i])
			maxx = dpp[i];
	}

	return maxx;
}

int main() {
	int res = 0;
	in(n);
	for (int i = 0; i < n; i++) {
		in(arr[i]);
	}

	int stan = rett();

	FOR(i, 0, n) {
		used[i] = 1;
		if (rett() < stan)
			++res;
		used[i] = 0;
	}

	printf("%d\n", res);
	return 0;
}