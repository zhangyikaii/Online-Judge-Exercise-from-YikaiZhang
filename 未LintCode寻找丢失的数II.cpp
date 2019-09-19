#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

// 570. 寻找丢失的数 II 有分割的多种可能的问题, 就去暴搜没关系
int sumN = 0;

/*
*/
void dfs(int cur, map<int, int> &m, string &s, int n, int &res) {
	if (m.size() >= 18) {
		cout << endl;
	}
	if (cur >= s.size() && m.size() == n - 1) {
		for (int i = 1; i <= n; ++i) {
			if (m[i] == 0) {
				cout << i << endl;
				res = i;
				return;
			}
		}
		return;
	}
	else if (cur > s.size())
		return;

	if (cur != s.size() - 1) {
		if (n / 10 != 0 && s[cur] == '0' + (n / 10) && s[cur + 1] == '0' + (n % 10)) {
			m[s[cur] - '0'] = 1;
			dfs(cur + 1, m, s, n, res);
			m[s[cur] - '0'] = 0;
			m[(s[cur] - '0') * 10 + s[cur + 1] - '0'] = 1;
			dfs(cur + 2, m, s, n, res);
			m[(s[cur] - '0') * 10 + s[cur + 1] - '0'] = 0;
		}
		else {
			m[s[cur] - '0'] = 1;
			dfs(cur + 1, m, s, n, res);
			m[s[cur] - '0'] = 0;
		}
	}
	else {
		m[s[cur] - '0'] = 1;
		dfs(cur + 1, m, s, n, res);
		m[s[cur] - '0'] = 0;
	}
}
int findMissing2(int n, string &str) {
	// write your code here
	map<int, int > m;
	int res = 0;
	dfs(0, m, str, n, res);

	return res;
}

int main() {
	string a = "19201234567891011121314151618";
	findMissing2(20, a);

	return 0;
}