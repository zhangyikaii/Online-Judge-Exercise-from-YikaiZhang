#include <queue>
#include <iostream> 
#include <cstdio> 
#include <cstdlib>
#include <algorithm> 
#include <cstring>
#include <map>
#include <cmath>
#include <string>
#include <functional>

using namespace std;

typedef long long ll;

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

priority_queue<int, vector<int>, greater<int> > sq;
priority_queue<int> bq;

void add(int x) {
	if (bq.empty()) {
		bq.push(x);
		return;
	}
	if (sq.empty()) {
		if (bq.top() <= x)
			sq.push(x);
		else {
			sq.push(bq.top());
			bq.pop();
			bq.push(x);
		}
		return;
	}
	if (sq.size() == bq.size()) {
		if (sq.top() >= x)
			bq.push(x);
		else {
			bq.push(sq.top());
			sq.pop();
			sq.push(x);
		}
	}
	else {
		if (bq.top() <= x)
			sq.push(x);
		else {
			sq.push(bq.top());
			bq.pop();
			bq.push(x);
		}
	}
}
int main() {
	int x;
	while (scanf("%d", &x) != EOF) {
		add(x);
		printf("%d ", bq.top());
	}
	
	return 0;
}