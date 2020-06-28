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
string name[100010];
int arr[100010];

int main() {
	in(m), in(n);
	For(i, 0, m) {
		cin >> arr[i] >> name[i];
	}
	int cur = 0;
	For(t, 0, n) {
		int k, l;
		cin >> k >> l;
		
		if (k ^ arr[cur] == 0) {
			cur = (cur + m)- l;
			while (cur < 0)
				cur += m;
			cur %= m;
		}
		else
			cur = (cur + l) % m;
		// cout << k << " " << l << " " << cur << endl;
	}

	cout << name[cur] << endl;

	return 0;
}