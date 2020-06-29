#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define Fee(i, b, e) for(int i = (b); i <= (e); ++i)
#define Ree(i, b, e) for(int i = (b); i >= (e); --i)

#define INF 0x7fffff

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

int n;
int arr[30];
int adj[30][30], tmp;
int main() {
	in(n);
	Fee(i, 1, n)
		in(arr[i]);

	Fee(i, 1, n) {
		Fee(j, i + 1, n) {
			in(tmp);
			if (tmp == 1) {
				adj[i][j] = adj[j][i] = 1;
			}
		}
	}


	
	return 0;
}