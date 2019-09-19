#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(ll i = s; i < n; ++i)

typedef long long ll;

inline ll read() {
	ll X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}



int main() {
	ll t, n;
	in(t);


	while (t--) {
		ll a[1010], b[1010];
		ll ia = 0, ib = 0, tmp;
		bool flag = false;
		in(n);
		FOR(i, 0, n) {
			in(tmp);
			if (flag == true)
				continue;
			if (ia == 0)
				a[ia++] = tmp;
			else if (ib == 0)
				b[ib++] = tmp;
			else if (tmp > a[ia - 1])
				a[ia++] = tmp;
			else if (tmp > b[ib - 1])
				b[ib++] = tmp;
			else
				flag = true;
		}

		if (flag == true)
			printf("-1\n");
		else {
			ll t = (ib - ia > 0) ? (ib - ia) : (ia - ib);
			printf("%lld\n", t);
		}
	}
	
	/*1  1  8  2  4*/
	
	return 0;
}