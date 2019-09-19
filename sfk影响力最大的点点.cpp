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
#include <map>
#include <assert.h>

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

vector<vector<int> > vec, rvec;

int *mark, *stac, *vis, *used, *poiWei;
int n = 0, m, t/*dfs1中是逆后序，dfs2中是栈顶*/, ans;

#define ri register int

// 逆后序处理
void dfs1(int x) {
	vis[x] = true;
	assert(x < vec.size());
	for (ri i = 0; i < vec[x].size(); ++i) {
		// cout << vec[x][i] << endl;
		assert(x < vec.size());
		assert(i < vec[x].size());
		if (!vis[vec[x][i]])
			dfs1(vec[x][i]);
	}

	stac[++t] = x;//最后再压入自己
	return;
}

// 强连通分量
void dfs2(int x, const int tag) {
	mark[x] = tag;
	for (int i = 0; i < rvec[x].size(); ++i) {
		if (!mark[rvec[x][i]]) {
			dfs2(rvec[x][i], tag);
		}
	}
}


void dfsOld(int beg, int used[], int &tAns) {
	FOR(i, 0, vec[beg].size()) {
		int &nei = vec[beg][i];
		if (used[nei] == 0) {
			++tAns;
			// cout << nei << "   k   ";
			used[nei] = 1;
			dfsOld(nei, used, tAns);
			used[nei] = 0;
		}
	}
}




/*
1
2
0 3
4
5
3
*/

int main() {
	// freopen("out.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int tRes = 0, curMax = 0;
	char buf[100010] = "";
	int tmp;
	int bef = 0;
	
	vec.resize(20010);
	rvec.resize(20010);

	
	while (cin.getline(buf, 100010)) {
		bef = 0;
		int i;
		++n;
		tmp = atoi(buf);
		vec[n].push_back(tmp + 1);
		rvec[tmp + 1].push_back(n);
		// cout << tmp << endl;
		for (i = 0; buf[i] != '\0'; ++i) {
			if (buf[i] == ' ' || buf[i] == '\0') {
				tmp = atoi(buf + i);
				// cout << tmp << endl;
				bef = i + 1;
				vec[n].push_back(tmp + 1);
				rvec[tmp + 1].push_back(n);
			}
		}

		memset(buf, 0, sizeof(buf));
	}

	/**mark, *stac, *vis, *used, *poiWei;*/
	mark = new int[n + 10];
	used = new int[n + 10];
	vis = new int[n + 10];
	stac = new int[n + 10];
	poiWei = new int[n + 10];

	memset(mark, 0, sizeof(int)* (n + 10));
	memset(used, 0, sizeof(int)* (n + 10));
	memset(vis, 0, sizeof(int)* (n + 10));
	memset(stac, 0, sizeof(int)* (n + 10));
	memset(poiWei, 0, sizeof(int)* (n + 10));

	//第一次dfs求图的逆后序
	for (int i = 1; i <= n; i++) {
		if (!vis[i])
			dfs1(i);
	}

	t = 0;
	//第二次dfs求强连通分量，从栈顶开始遍历，向无向图那样求连通分量即可
	for (int i = n; i >= 1; i--) {
		if (!mark[stac[i]]) {
			++t;
			dfs2(stac[i], stac[i]);
		}
	}

	vector<int> resVec;
	bool flag = false;
	
	int tres = 0;

	printf("I have read the rules about plagiarism punishment\n");


	FOR(i, 1, n + 1) {
		int &tcur = mark[i];
		if (poiWei[tcur] == 0) {
			// jisuan
			tres = 0;
			used[tcur] = 1;
			dfsOld(tcur, used, tres);
			used[tcur] = 0;

			poiWei[tcur] = tres;
			if (tres > curMax) {
				curMax = tres;
				resVec.clear();
				resVec.push_back(i);
			}
			else if (tres == curMax) {
				resVec.push_back(i);
			}
		}
		else if (poiWei[tcur] == curMax) {
			resVec.push_back(i);
			continue;
		}
	}

	printf("%d\n", curMax);
	sort(resVec.begin(), resVec.end());
	FOR(i, 0, resVec.size()) {
		printf("%d ", resVec[i] - 1);
	}
	printf("\n");

	return 0;
}