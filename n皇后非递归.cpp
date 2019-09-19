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

vector<vector<string> > solveNQueens(int n) {
	// write your code here
	vector<vector<string> > result;
	if (n <= 0) {
		return result;
	}
	vector<int> cols;
	search(n, cols, result);
	return result;
}

void search(int n, vector<int> &cols, vector<vector<string> > &result) {
	if (cols.size() == n) {
		result.push_back(drawResult(cols, n));
		return;
	}
	for (int col = 0; col < n; col++) {
		if (!isValid(cols, col)) {
			continue;
		}
		cols.push_back(col);
		search(n, cols, result);
		cols.pop_back();
	}
}
bool isValid(vector<int> &cols, int col) {
	int row = cols.size();
	for (int i = 0; i < row; ++i) {
		if (cols[i] == col) {
			return false;
		}
		if (i - cols[i] == row - col) {
			return false;
		}
		if (i + cols[i] == row + col) {
			return false;
		}
	}
	return true;
}

// 返回值的写一个函数.
vector<string> drawResult(vector<int> &cols, int n) {
	vector<string> result;
	for (int i = 0; i < cols.size(); ++i) {
		// 注意这个string 的初始化.
		string temp(n, '.');
		temp[cols[i]] = 'Q';
		result.push_back(temp);
	}
	return result;
}