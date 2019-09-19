#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(int i = s; i < n; ++i)

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

// beg: 2019Äê5ÔÂ3ÈÕ21:39:38
// end: 

string arr[10];

int main() {
	int T;
	while (T--) {
		FOR(i, 0, 3) {
			cin >> arr[i];
		}
	}

	map<char, int> m[8];


	
	return 0;
}


/*

*/