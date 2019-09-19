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

#define FOR(i, s, n) for(int i = s; i < n; ++i)

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}


int main() {
	freopen("out.txt", "w", stdout);
	int n = 500;
	FOR(i, 1, n) {
		cout << i << endl;
	}
	cout << "0" << endl;
	cout << "0 ";
	FOR(i, n + 2, 3 * n)
		cout << i << " ";
	cout << endl;
	FOR(i, 0, 3 * n - n + 2)
		cout << endl;
	
	return 0;
}

/*
1
2 3
0



5 3
6
4 7

*/