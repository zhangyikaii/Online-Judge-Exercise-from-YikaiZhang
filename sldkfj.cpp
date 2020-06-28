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

vector<int> brr[10100];
int arr[10100];
int main() {
	int n, a, b, curi = 1, duri = 1, ans = 0;
	in(n);
	FOR(i, 0, n - 1) {
		in(a), in(b);
		++arr[a];
		brr[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i) {
		if (arr[i] > arr[curi])
			curi = i;
	}
	ans += arr[curi];
	FOR(i, 0, brr[curi].size()) {
		--arr[brr[curi][i]];
	}
	arr[curi] = 0;

	for (int i = 1; i <= n; ++i) {
		if (arr[i] > arr[curi])
			curi = i;
	}

	ans += arr[curi];

	printf("%d\n", ans);
	
	return 0;
}