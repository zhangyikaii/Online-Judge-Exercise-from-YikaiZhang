#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define Fee(i, b, e) for(int i = (b); i <= (e); ++i)

#define INF 0x7fffff

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

int n, m;
string s[60];
int red[60], white[60], blue[60];

int main() {
	in(n), in(m);
	For(i, 0, n) {
		cin >> s[i];
	}

	For(i, 0, n) {
		For(j, 0, m) {
			switch (s[i][j])
			{
			case 'W':
				++white[i];
				break;
			case 'B':
				++blue[i];
				break;
			case 'R':
				++red[i];
				break;
			default:
				break;
			}
		}
	}

	For(i, 1, n) {
		red[i] += red[i - 1];
		blue[i] += blue[i - 1];
		white[i] += white[i - 1];
	}

	int res = 0xfffff;
	// 在 i 上面是W 包括i.
	For(i, 0, n - 2) {
		For(j, i + 1, n - 1) {
			int wNum = (i + 1) * m - white[i];
			int bNum = (j - i) * m - (blue[j] - blue[i]);
			int rNum = (n - 1 - j) * m - (red[n - 1] - red[j]);
			int sum = wNum + bNum + rNum;
			if (sum < res)
				res = sum;
		}
	}
	
	cout << res << endl;
	return 0;
}