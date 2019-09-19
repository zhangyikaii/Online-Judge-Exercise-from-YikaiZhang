#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(int i = s; i < n; ++i)

#define MAXN 1000010

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

priority_queue<int, vector<int>, greater<int> > q;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	int n, cur = -1;
	in(n);
	char arr[100] = "";
	FOR(i, 0, n) {
		scanf("%s", arr);
		if (arr[0] == '-') {
			if (!q.empty())
				q.pop();
		}
		else if (arr[0] == '?') {
			printf("%d\n", cur);
		}
		else if (arr[0] == '+') {
			int tmp = 0;
			for (int i = 2; arr[i] != '\0'; ++i) {
				if (arr[i] <= '9' && arr[i] >= '0')
					tmp = tmp * 10 + arr[i] - '0';
			}
			q.push(tmp);
			if (cur == -1) {
				cur = tmp;
			}
			else
				cur = gcd(cur, tmp);
		}
		FOR(i, 0, 10)
			arr[i] = '\0';
	}
	return 0;
}