#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>

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

// beg: 2019年5月1日15:08:50
// end: 2019年5月1日14:46:54


#define FOR(i, s, n) for(int i = s; i < n; ++i)

vector<int> used;

vector<vector<int>> res;


void dfs(vector<int>& nums, int desNum, int cur, vector<int>& v) {
	if (v.size() == desNum) {
		res.push_back(v);
		return;
	}

	FOR(i, cur + 1, nums.size()) {
		if (used[i] == 0) {
			used[i] = 1;
			v.push_back(nums[i]);
			dfs(nums, desNum, cur + 1, v);
			v.pop_back();
			used[i] = 0;
		}
	}
}


vector<vector<int>> subsets(vector<int>& nums) {
	res.push_back(vector<int>());
	int n = nums.size();
	used.resize(n);

	FOR(i, 0, nums.size()) {
		vector<int> t;
		t.push_back(nums[i]);
		res.push_back(t);
	}

	res.push_back(nums);
	for (int i = 2; i < n; ++i) {
		vector<int> tmp;
		FOR(k, 0, n) {
			tmp.push_back(nums[k]);
			dfs(nums, i, k, tmp);
			tmp.pop_back();
		}
	}

	return res;
}

int main() {
	vector<int> v = { 0 };
	subsets(v);

	return 0;
}

