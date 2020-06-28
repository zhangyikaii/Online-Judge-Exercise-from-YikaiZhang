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

int a, b, n;
int arr[300], used[300];

struct Data {
	int cur, num;
	Data() { }
	Data(int c, int n) : cur(c), num(n) { }
};

int main() {
	in(n), in(a), in(b);
	if (a == b) {
		cout << 0 << endl;
		return 0;
	}
	Fee(i, 1, n) {
		in(arr[i]);
	}

	queue<Data> q;

	q.push(Data(a, 0));
	used[a] = 1;
	while (!q.empty()) {
		Data now = q.front();
		q.pop();

		int n1 = now.cur + arr[now.cur], n2 = now.cur - arr[now.cur];
		if (n1 == b) {
			cout << now.num + 1 << endl;
			return 0;
		}
		if (n2 == b) {
			cout << now.num + 1 << endl;
			return 0;
		}
		if (n1 <= n && used[n1] == 0) {
			q.push(Data(n1, now.num + 1));
			used[n1] = 1;
		}
		if (n2 >= 1 && used[n2] == 0) {
			q.push(Data(n2, now.num + 1));
			used[n2] = 1;
		}
	}

	cout << -1 << endl;
	return 0;
}