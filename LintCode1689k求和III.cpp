#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

typedef long long ll;

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

void dfs(vector<int> &v, int k, int target, int cur, int sum, int index, int &res) {
	if (sum > target)
		return;
	if (cur == k && sum == target) {
		++res;
		return;
	}

	int n = v.size();
	for (int i = index; i < n; ++i) {
		dfs(v, k, target, cur + 1, sum + v[i], i + 1, res);
	}
}

int getAns(vector<int> &a, int k, int target) {
	// write your code here
	vector<int> av, bv;
	int n = a.size(), res = 0;
	for (int i = 0; i < n; ++i) {
		if ((a[i] & 1) == 1)
			av.push_back(a[i]);
		else
			bv.push_back(a[i]);
	}
	dfs(av, k, target, 0, 0, 0, res);
	dfs(bv, k, target, 0, 0, 0, res);
	return res;
}

int main() {
	int k = 2, target = 4;
	vector<int> a = { 1, 2, 3, 4 };
	cout << getAns(a, k, target) << endl;

	return 0;
}