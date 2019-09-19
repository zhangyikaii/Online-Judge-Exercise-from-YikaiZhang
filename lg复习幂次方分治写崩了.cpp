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

int pow2(int a) {
	return (0x1 << (a - 1));
}

void dfs(int a) {
	if (a == 0)
		return;
	if (a == 1) {
		cout << "2(0)";
		return;
	}
	else if (a == 2) {
		cout << "2";
		return;
	}
	
	int cnt = 0;
	int arr[50] = { 0 };
	while (a != 0) {
		if ((a & 0x1) == 1) {
			arr[cnt] = pow2(cnt);
		}
		a >>= 1;
		++cnt;
	}

	if (cnt != 0) {
		cout << "2(";
		dfs(arr[cnt - 1]);
		cout << ")";
	}
	for (int i = cnt - 2; i >= 1; --i) {
		if (arr[i] != 0) {
			cout << "+2(";
			dfs(arr[i]);
			cout << ")";
		}
	}
}

int main() {
	int n;
	in(n);

	dfs(n);
	
	return 0;
}