#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
using namespace std;

#define in(x) x=read()

inline int read()
{
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int point[200010] = { 0 }, n, k, a, b;

bool cmp(int a, int b) {
	return a < b;
}

int main() {
	in(n);
	in(k);
	for (int i = 1; i <= n - 1; ++i) {
		in(a);
		in(b);
		++point[a];
		++point[b];
	}

	sort(point + 1, point + n + 1, cmp);

	while (k--) {
		--point[n];

		++point[1];
		sort(point + 1, point + n + 1, cmp);
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (point[i] == 1)
			++ans;
	}

	printf("%d", ans);

	return 0;
}

/*

*/

