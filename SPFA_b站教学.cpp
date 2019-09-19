#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 205;
vector<pair<int, int> > E[maxn];

int n, m;
int d[maxn], inq[maxn];
void init() {
	for (int i = 0; i < maxn; ++i) {
		E[i].clear();
		inq[i] = false;
		d[i] = 1e9;
	}	
}

int main() {
	while (cin >> n >> m) {
		init();
		for (int i = 0; i < m; ++i) {
			int x, y, z;
			cin >> x >> y >> z;
			E[x].push_back(make_pair(y, z));
			E[y].push_back(make_pair(x, z));
		}

		int s, t;
		// s 是开始的点.
		cin >> s >> t;

		queue<int> Q;
		Q.push(s), d[s] = 0, inq[s] = 1;
		while (!Q.empty()) {
			int now = Q.front();
			Q.pop();
			inq[now] = false;

			for (int i = 0; i < E[now].size(); ++i) {
				int v = E[now][i].first;
				// v 就是邻接的点.
				// 进行松弛?
				if (d[v] > d[now] + E[now][i].second) {
					d[v] = d[now] + E[now][i].second;

					if (inq[v] == true)
						continue;

					inq[v] = false;
					Q.push(v);
				}
			}

		}

		if (d[t] == 1e9)
			cout << "-1" << endl;
	}



	return 0;
}