#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
#include <cmath>
#include <string>
using namespace std;

typedef long long ll;

#define in(x) x=read()

inline ll read() {
	ll X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

ll MyMin(ll a, ll b) {
	return a > b ? b : a;
}

ll t;

ll kinds(ll t, ll &sum) {
	ll res = 0, sqt = sqrt(t);
	for (ll i = 1; i <= sqt; ++i) {
		if (t % i == 0) {
			// cout << t / i << "  " << i << "  " << t / i + i << endl;
			sum += ((t / i) % 1000000007 * i) % 1000000007 * (t / i + i);
			++res;
		}
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);

	in(t);
	while (t--) {
		ll n, sqn, sum = 0;
		in(n);
		sqn = sqrt(n);

		if (n % 4 != 0 && sqn * sqn != n) {
			cout << "0 0" << endl;
			continue;
		}
		
		if (n % 4 == 0 && sqn * sqn != n) {
			cout << kinds(n / 4, sum) << " ";
			cout << sum << endl;
		}
		else if (n % 4 != 0 && sqn * sqn == n) {
			cout << "infty" << endl;
		}

	}
	

	return 0;
}

/*


*/