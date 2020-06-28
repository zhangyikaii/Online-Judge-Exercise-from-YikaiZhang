#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define INF 0x7fffff

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

int n, m;

/*
* * * * *
* * * * *
*/

int main() {
	in(n), in(m);

	ll cir = 0, rec = 0;
	//int a = n, b = m;
	//while (a > 0 && b > 0) {
	//	cir += a * b;
	//	--a, --b;
	//}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i == j)
				cir += (n + 1 - i) * (m + 1 - j);
			else
				rec += (n + 1 - i) * (m + 1 - j);
		}
	}

	cout << cir << " " << rec << endl;

	return 0;
}