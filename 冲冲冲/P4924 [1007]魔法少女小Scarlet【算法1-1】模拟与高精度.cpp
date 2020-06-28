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

int n, m, arr[510][510];
int trr[510][510];

// (0, 0), (0, 1), (0, 2), (0, 3), (0, 4)

// (1, 0), (1, 1), (1, 2), (1, 3), (1, 4)

// (2, 0), (2, 1), (2, 2), (2, 3), (2, 4)

// (3, 0), (3, 1), (3, 2), (3, 3), (3, 4)

void myRotate(int beg, int aft, int beg1, int aft1, int direction) {
	For(i, beg, aft) {
		For(j, beg1, aft1) {
			trr[i][j] = arr[i][j];
		}
	}

	if (direction == 0) {
		int i = beg, j = aft1 - 1;
		while (i < aft && j >= beg1) {
			// 现在i指向原来行, j指向目标对换列.
			for (int k = beg, l = beg1; k < aft && l < aft1; ++k, ++l)
				arr[k][j] = trr[i][l];
			++i, --j;
		}
	}
	else {
		int i = beg, j = beg1;
		while (i < aft && j < aft1) {
			for (int k = aft - 1, l = beg1; k >= beg && l < aft1; --k, ++l) {
				arr[k][j] = trr[i][l];
			}
			++i, ++j;
		}
	}
}

int main() {
	// 这题有点东西呀.
	cin >> n >> m;

	For(i, 0, n) {
		For(j, 0, n)
			arr[i][j] = i * n + j + 1;
	}

	For(i, 0, m) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--;
		b--;
		myRotate(a - c, a + c + 1, b - c, b + c + 1, d);
	}
	
	For(i, 0, n) {
		For(j, 0, n)
			cout << arr[i][j] << " ";
		cout << endl;
	}

	return 0;
}