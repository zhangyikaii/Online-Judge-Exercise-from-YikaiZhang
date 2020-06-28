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

int main() {
	int n;
	in(n);
	char arr[100] = "";
	FOR(i, 0, n) {
		scanf("%s", arr);
		if (arr[0] == '-') {
			if (!q.empty())
				q.pop();
		}
		else if (arr[0] == '?') {
			if (!q.empty())
				printf("%d\n", q.top());
			else
				printf("Error.\n");
		}
		else if (arr[0] == '+') {
			int tmp = 0;
			for (int i = 1; arr[i] != '\0'; ++i) {
				tmp = tmp * 10 + arr[i] - '0';
			}
			q.push(tmp);
		}
		FOR(i, 0, 10)
			arr[i] = '\0';
	}
	return 0;
}