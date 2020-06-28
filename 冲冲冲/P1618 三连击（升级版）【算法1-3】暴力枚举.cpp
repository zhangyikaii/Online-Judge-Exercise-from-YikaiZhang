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

int a, b, c;

bool isUsed(int a, int used[]) {
	if (a >= 1000)
		return false;
	int x = a / 100 % 10, y = a / 10 % 10, z = a % 10;
	if (x == 0 || y == 0 || z == 0)
		return false;
	if (used[x] == 1 || used[y] == 1 || used[z] == 1)
		return false;
	if (x == y || y == z || x == z)
		return false;

	used[x] = 1, used[y] = 1, used[z] = 1;

	return true;
}

bool flag = false;

int main() {
	in(a), in(b), in(c);

	for (int i = 1; i < 10; ++i) {
		for (int k = 1; k < 10; ++k) {
			if (i == k)
				continue;
			for (int j = 1; j < 10; ++j) {
				if (j == k || j == i)
					continue;

				// 当前生成的数:
				int cur = i * 100 + k * 10 + j;

				// 等比例运算之后是不是整数.
				if (cur * b % a != 0)
					continue;
				if (cur * c % a != 0)
					continue;

				int bcur = cur * b / a, ccur = cur * c / a;
				int used[11] = { 0 };
				if (isUsed(bcur, used) && isUsed(cur, used) && isUsed(ccur, used)) {
					flag = true;
					cout << cur << " " << bcur << " " << ccur << endl;
				}
			}
		}
	}

	if (flag == false)
		cout << "No!!!" << endl;

	return 0;
}