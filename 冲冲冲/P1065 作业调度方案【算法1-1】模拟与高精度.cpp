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
int m, n;
int arr[500];
vector<int> mach[21], tim[21];
int machTime[21];

int main() {
	in(m), in(n);

	int tmp;
	For(i, 0, n) {
		For(j, 0, m) {
			cin >> tmp;
			mach[i].push_back(tmp);
		}
	}
	For(i, 0, n) {
		For(j, 0, m) {
			cin >> tmp;
			tim[i].push_back(tmp);
		}
	}

	int curMaxEnd = 0, curOrder = 0;
	For(i, 0, n) {
		For(j, 0, mach[i].size()) {
			if (mach[i][j] != 0) {

				break;
			}
		}
	}

	// sigh 题目看不懂.
	// 112332 这个排序的作用体现在哪里?

	return 0;
}