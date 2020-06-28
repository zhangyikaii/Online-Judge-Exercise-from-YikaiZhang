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

int MyAbs(int a, int b) {
	if (a - b < 0)
		return b - a;
	return a - b;
}

int arr[100010] = { 0 };
int n, m, c;

bool judge(int mid) {
	int ll = 1, rr = 2;
	int num = 0;
	while (rr <= n) {
		while (rr <= n && rr - ll < c && arr[rr] - arr[ll] <= mid)
			++rr;
		if (rr != n + 1)
			--rr;
		++num;

		ll = rr + 1;
		rr = rr + 2;
	}
	if (rr == n + 1)
		++num;
	// cout << mid << "  " << num << endl;
	if (num <= m)
		return true;
	return false;
}


int main() {
	in(n), in(m), in(c);
	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		in(arr[i]);
	}

	sort(arr + 1, arr + 1 + n);
	int l = 0, r = arr[n];
	while (l < r) {
		int mid = ((l + r) >> 1);
		if (judge(mid) == true) {
			ans = mid;
			r = mid;
		}
		else
			l = mid + 1;
	}
	printf("%d\n", ans);

	
	return 0;
}