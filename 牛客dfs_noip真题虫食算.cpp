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
#include <queue>

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

bool used[30] = { false };
vector<int> res;
string a, b, c;
int aa[30], bb[30], cc[30];
int n;
bool flag = false;
vector<int> out;

bool check() {
	int goNum = 0, tmp = 0;
	int resn = res.size();
	for (int i = n - 1; i >= 0; --i) {
		if (aa[i] >= resn || bb[i] >= resn || cc[i] >= resn)
			return true;
		tmp = res[aa[i]] + res[bb[i]] + goNum;
		if (tmp % n != res[cc[i]])
			return false;
		goNum = tmp / n;
	}

	return true;
}

void dfs(int cur) {
	if (flag == true)
		return;
	if (cur == n) {
		/*FOR(i, 0, res.size())
			cout << res[i] << " ";
		cout << endl;*/
		if (check() == true) {
			flag = true;
			out = res;
		}
		return;
	}

	if (check() == false) {
		return;
	}

	FOR(i, 0, n) {
		if (used[i] == false) {
			used[i] = true;
			res.push_back(i);
			dfs(cur + 1);
			res.pop_back();
			used[i] = false;
		}
	}
}



int main() {
	in(n);

	cin >> a >> b >> c;

	for (int i = 0; i < n; ++i) {
		aa[i] = a[i] - 'A';
		bb[i] = b[i] - 'A';
		cc[i] = c[i] - 'A';
	}
	dfs(0);

	cout << out[0];
	FOR(i, 1, n)
		cout << " " << out[i];
	cout << endl;

	return 0;
}