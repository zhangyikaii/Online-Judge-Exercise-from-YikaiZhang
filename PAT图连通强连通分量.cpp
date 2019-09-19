#include <bits/stdc++.h>

using namespace std;

vector<int> vec[10010];
int f[10010];
int n;
char ch;

int find(int to) {
	int a = to;
	while (f[a] != a)
		a = f[a];

	while (to != a) {
		int tmp = f[to];
		f[to] = a;
		to = tmp;
	}

	return a;
}

void Union(int a, int b) {
	int fa = find(a), fb = find(b);

	if (fa != fb)
		f[fa] = fb;
}


// 注意注意这题路是双向的, 所以就不存在强连通之类的概念!!!
void dfs(int& flag, int beg, int &des, int used[]) {
	if (flag == 1)
		return;

	for (int i = 0; i < vec[beg].size(); ++i) {
		Union(beg, vec[beg][i]);
		if (vec[beg][i] == des) {
			flag = 1;
			return;
		}
		if (!used[vec[beg][i]]) {
			used[vec[beg][i]] = 1;
			dfs(flag, vec[beg][i], des, used);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		f[i] = i;

	cin >> ch;
	while (ch != 'S') {
		int a, b;
		cin >> a >> b;
		if (ch == 'I') {
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		else {
			if (find(a) == find(b))
				cout << "yes" << endl;
			else {
				int flag = 0, used[10010] = { 0 };
				dfs(flag, a, b, used);
				if (flag == 0)
					cout << "no" << endl;
				else
					cout << "yes" << endl;
			}

		}

		cin >> ch;
	}

	int used[10010] = { 0 }, flag = 0, des = -1, ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (f[i] == i && used[i] == 0) {
			dfs(flag, i, des, used);
		}
	}

	set<int> resSet;
	for (int i = 1; i <= n; ++i) {
		resSet.insert(find(i));
	}

	ans = resSet.size();
	if (ans == 1)
		cout << "The network is connected." << endl;
	else
		cout << "There are " << ans << " components." << endl;

	return 0;
}


