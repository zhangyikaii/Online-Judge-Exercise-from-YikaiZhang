#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
using namespace std;

#define in(x) x=read()

struct Data
{
	int a, b;
};

inline int read()
{
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n, m, l, r, ans = 1;
Data arr[200010], tmp[200010];

bool cmp1(Data aa, Data bb) {
	return aa.a < bb.a;
}

bool cmp2(Data aa, Data bb) {
	return aa.b < bb.b;
}

int main() {
	in(n);

	for (int i = 1; i <= n; ++i) {
		in(arr[i].a);
		in(arr[i].b);
	}

	in(m);

	while(m--) {
		in(l);
		in(r);
		int iTmp = 0;
		for (int k = l; k <= r; ++k) {
			tmp[iTmp++] = arr[k];
		}
		int nTmp = r - l + 1;
		sort(tmp, tmp + nTmp, cmp1);
		if (tmp[nTmp - 1].a > tmp[0].a) {
			for (int i = nTmp - 1; tmp[i].a == tmp[i - 1].a; --i) {
				ans *= (tmp[i].a ^ tmp[i].b) % 1000000007;
			}
		}

		iTmp = 0;
		for (int k = l; k <= r; ++k) {
			tmp[iTmp++] = arr[k];
		}
		sort(tmp, tmp + nTmp, cmp2);
		if (tmp[nTmp - 1].b > tmp[0].b) {
			for (int i = nTmp - 1; tmp[i].a == tmp[i - 1].a; --i) {
				ans *= (tmp[i].a ^ tmp[i].b) % 1000000007;
			}
		}
		printf("%d", ans);
	}

	return 0;
}

/*

*/

