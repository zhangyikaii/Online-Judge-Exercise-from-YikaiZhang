#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>

using namespace std;


#define in(x) x=read()

#define MAXN 1000000

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int whoMin(int a, int b, int c, int N) {
	a = abs(a - N), b = abs(b - N), c = abs(c - N);
	int minn = min(a, min(b, c));
	return ((minn == a) ? 1 : ((minn == b) ? 2 : 3));
}

int sqrtNCeil(int N) {
	int M = N >> 2;
	int x = ceil(sqrt(M));
	int y[5];
	y[1] = 4 * x * x, y[2] = 4 * x * x + 4 * x + 1, y[3] = 4 * x * x - 4 * x + 1;

	if (y[1] == N || y[2] == N || y[3] == N) {
		return (y[1] == N) ? 2 * x : ((y[2] == N) ? 2 * x + 1 : 2 * x - 1);
	}

	return sqrtNCeil(y[whoMin(y[1], y[2], y[3], N)]);
}


int main() {
	for (int i = 2; i < 100; ++i) {
		int my = sqrtNCeil(i), right = ceil(sqrt(i));
		if (my != right) {
			cout << i << endl;
			cout << my << "  " << right << endl;
		}
	}
	
	return 0;
}

/*


*/