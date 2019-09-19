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

#define FOR(i, s, n) for(int i = s; i < n; ++i)

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}
int res[1010] = { 0, 1, 2, 2, 3, 3 };


// 数学递推
// 比如				   1, 2, 3, 4, 5, 6
// 递推(减一次之后)成:  1, 2, 3, 1, 2, 3
// 所以就是 res[6] = res[3] + 1;
// 奇数的也是.

int main() {
	FOR(i, 6, 110) {
		res[i] = res[i / 2] + 1;
	}

	int t = 0, input;
	in(t);
	while (t--) {
		in(input);
		printf("%d\n", res[input]);
	}
	
	return 0;
}