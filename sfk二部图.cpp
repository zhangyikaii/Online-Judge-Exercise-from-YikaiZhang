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
#include <sstream>

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

//struct Edge {
//	int next, to;
//};
//
//struct Data {
//	vector<int> vd;
//};

// Edge edge[1000010];
//int cnt = 0;
//int head[100010];
// int matc[1010] = { 0 }, dfn[1000010];

vector<vector<int> > vec;
vector<int> colo;
//vector<int> ress;
// ¡¥ Ω«∞œÚ–«¥ÊÕº.
//void add(int x, int y) {
//	edge[++cnt].next = y;
//	edge[cnt].to = head[x];
//	head[x] = cnt;
//}

//bool dfs(int visi, int u) {
//	for (int i = 0; i < vec[u].vd.size(); ++i) {
//		int &neigh = vec[u].vd[i];
//		if (dfn[neigh] != visi) {
//			dfn[neigh] = visi;
//			if (matc[neigh] == 0 || dfs(visi, matc[neigh]) != false) {
//				matc[neigh] = u;
//				return true;
//			}
//		}
//	}
//
//	return false;
//}



void dfsInit(int u) {
	int nxtColor = (colo[u] == 1) ? 2 : 1;
	for (int i = 0; i < vec[u].size(); ++i) {
		int neigh = vec[u][i];
		if (colo[neigh] == 0) {
			// cout << u - 1 << "   " << neigh - 1 << endl;
			colo[neigh] = nxtColor;
			dfsInit(neigh);
		}
	}
}


//
//void pushh(int n) {
//	Data tmp;
//	while (vec.size() < n + 1)
//		vec.push_back(tmp);
//}
//
//void pushb(int u, int n) {
//	while (vec[u].vd.size() < n + 1) {
//		vec[u].vd.push_back(0);
//	}
//}

int MyMax(int a, int b) {
	return a > b ? b : a;
}


int main() {
	// ios::sync_with_stdio(false);

	string s;
	vector<int> tmpp;
	int tmp;
	int npoint = 0;
	int beg = 0;
	vec.push_back(tmpp);
	while (getline(cin, s)) {
		++npoint;
		vec.push_back(tmpp);

		istringstream iss(s);
		iss >> beg;
		++beg;
		while (iss >> tmp) {
			vec[beg].push_back(tmp + 1);
		}

		//beg = s[0] - '0' + 1;
		//FOR(i, 1, s.size()) {
		//	if (s[i] >= '0' && s[i] <= '9') {
		//		int tmp = s[i] - '0' + 1;
		//		vec[beg].push_back(tmp);
		//	}
		//}
	}

	// vec.resize(npoint + 1);
	colo.resize(npoint + 1);
	FOR(i, 0, npoint + 1)
		colo[i] = 0;

	colo[1] = 1;
	dfsInit(1);

	cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
	for (int i = 1; i <= npoint; ++i) {
		if (colo[i] == 1)
			cout << i - 1 << endl;
	}

	return 0;
}