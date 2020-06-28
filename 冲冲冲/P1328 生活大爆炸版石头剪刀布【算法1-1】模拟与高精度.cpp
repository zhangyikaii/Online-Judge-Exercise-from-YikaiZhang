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

int comp[10][10] = {
	{0, -1, 1, 1, -1},
	{0, 0, -1, 1, -1},
	{0, 0, 0, -1, 1},
	{0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0}
};

int n, a, b;
int arr[210], brr[210];

/*
161 9 52
0 1 3 1 2 4 3 2 2
0 1 4 2 3 1 1 2 3 1 1 4 0 0 2 4 4 2 0 1 0 3 3 1 3 1 3 4 1 3 1 2 4 2 1 2 0 4 2 3 1 0 4 1 0 4 0 2 3 2 0 3
*/

int main() {
	For(i, 0, 5) {
		For(j, i + 1, 5) {
			comp[j][i] = -comp[i][j];
		}
	}

	cin >> n >> a >> b;
	For(i, 0, a) {
		cin >> arr[i];
	}
	For(i, 0, b) {
		cin >> brr[i];
	}

	int ares = 0, bres = 0;
	For(i, 0, n) {
		int acur = arr[i % a], bcur = brr[i % b];
		if (comp[acur][bcur] == 1)
			++ares;
		else if (comp[acur][bcur] == -1)
			++bres;
	}
	cout << ares << " " << bres << endl;


	return 0;
}