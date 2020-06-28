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
#include <map>
#include <sstream>

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

string s;

int getNum(int beg, int endd) {
	char tmp[10010] = "";
	int ti = 0;
	FOR(i, beg + 1, endd) {
		tmp[ti++] = s[i];
	}

	return atoi(tmp);
}

int main() {
	ll n;
	in(n);
	cin >> s;
	ll sn = s.size();
	ll i = 0;
	ll k;
	while (i < sn) {
		if (s[i] == '-') {
			for (k = i + 1; k < sn; ++k) {
				if (s[k] > '9' || s[k] < '0') {
					n -= getNum(i, k);
					i = k;
					break;
				}
			}
			if (k == sn) {
				n -= getNum(i, k);
				i = k;
			}
		}

		if (s[i] == '*') {
			for (k = i + 1; k < sn; ++k) {
				if (s[k] > '9' || s[k] < '0') {
					n *= getNum(i, k);
					i = k;
					break;
				}
			}
			if (k == sn) {
				n *= getNum(i, k);
				i = k;
			}
		}

		if (s[i] == '+') {
			for (k = i + 1; k < sn; ++k) {
				if (s[k] > '9' || s[k] < '0') {
					n += getNum(i, k);
					i = k;
					break;
				}
			}
			if (k == sn) {
				n += getNum(i, k);
				i = k;
			}
		}

		if (s[i] == '%') {
			for (k = i + 1; k < sn; ++k) {
				if (s[k] > '9' || s[k] < '0') {
					n %= getNum(i, k);
					i = k;
					break;
				}
			}
			if (k == sn) {
				n %= getNum(i, k);
				i = k;
			}
		}

		if (s[i] == '^') {
			n *= n;
			i += 2;
		}
	}

	cout << ((n >= 0) ? n : -n) << endl;

	return 0;
}

