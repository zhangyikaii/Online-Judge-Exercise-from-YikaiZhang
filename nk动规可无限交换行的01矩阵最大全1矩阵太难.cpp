#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define in(x) x=read()
#define For(i, a, b) for(int i = a; i < b; ++i)

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

int arr[5010][5010];
int n, m;

int main() {
	in(n);
	in(m);
	For(i, 0, n) {
		For(k, 0, m) {
			in(arr[i][k]);
		}
	}

	return 0;
}


/*


*/