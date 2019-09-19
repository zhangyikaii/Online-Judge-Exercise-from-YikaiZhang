#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include<queue>
#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;

#define in(x) x=read()

struct Data {
	vector<int *> v;
};

int w[500010];

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n, m, tf, tw, whi, t, xx, yy;
int f[500010] = { 0 };
Data arr[500010];

int main() {
	in(n);
	in(m);
	for (int i = 1; i <= n; ++i) {
		in(tf);
		in(tw);
		f[i] = tf;
		arr[tf].v.push_back(&w[i]);
		w[i] = tw;

		t = f[tf];
		while (t != 0) {
			arr[t].v.push_back(&w[i]);
			t = f[t];
		}
	}

	for (int i = 0; i < m; ++i) {
		in(whi);
		in(xx);
		in(yy);
		if (whi == 1) {
			int n = arr[xx].v.size();
			w[xx] += yy;
			for (int i = 0; i < n; ++i) {
				*(arr[xx].v[i]) += yy;
			}
		}
		else {
			int n = arr[xx].v.size();
			w[xx] = yy;
			for (int i = 0; i < n; ++i) {
				*(arr[xx].v[i]) = yy;
			}
		}
	}


	for (int i = 1; i <= n; ++i) {
		cout << w[i] << " ";
	}
	cout << endl;

	return 0;
}
/*


*/