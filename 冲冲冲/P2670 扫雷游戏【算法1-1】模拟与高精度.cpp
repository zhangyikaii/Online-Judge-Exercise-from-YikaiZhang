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

int arr[110][110], n, m;

bool judge(int a, int b) {
	if (a >= 0 && a < n && b >= 0 && b < m)
		return true;

	return false;
}

int main() {
	cin >> n >> m;
	char ch;
	For(i, 0, n) {
		For(j, 0, m) {
			cin >> ch;
			if (ch == '*') {
				arr[i][j] = 1;
			}
		}
	}

	For(i, 0, n) {
		For(j, 0, m) {
			if (arr[i][j] == 1) {
				cout << '*';
				continue;
			}
			int sum = 0;
			For(k, i - 1, i + 2) {
				For(l, j - 1, j + 2) {
					if (k == i && l == j)
						continue;
					if (judge(k, l) && arr[k][l] == 1) {
						sum++;
					}
				}
			}
			cout << sum;
		}
		cout << endl;
	}

	return 0;
}