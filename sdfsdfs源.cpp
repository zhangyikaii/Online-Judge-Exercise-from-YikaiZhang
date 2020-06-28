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


int main() {
	// freopen("out.txt", "w", stdout);
//	FOR(i, 1, 18000) {
//		cout << i << " ";
//	}
//	for (int i = 2; i <= 18020; ++i)
//		cout << endl;
	FOR(i, 0, 1000) {
		int n = rand() % 1000;
		FOR(k, 0, n) {
			cout << rand() % 1000 << " ";
		}
		cout << endl;
	}
	return 0;
}

