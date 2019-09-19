#include <bits/stdc++.h>
using namespace std;

struct Node {
	int id, val;
	Node() { }
	Node(int ii, int vv) : id(ii), val(vv) { }
};

vector<Node> gra[1010];

int nHous, mGas, kRoad, dServ;

int chang(string a) {
	if (a[0] == 'G') {
		string tmp = a.substr(1, a.size() - 1);
		return atoi(tmp.c_str()) + nHous;
	}

	return atoi(a.c_str());
}

int main() {
	// 动态开一个领接矩阵.
	int N = 1000, M = 1000;
	vector<vector<int> > dist(N + M + 1, vector<int>(N + M + 1, INT_MAX / 2));

	string at, bt;
	int tmpInt;
	cin >> nHous >> mGas >> kRoad >> dServ;


	for (int i = 1; i <= kRoad; ++i) {
		cin >> at >> bt >> tmpInt;
		int ach = chang(at), bch = chang(bt);
		gra[ach].push_back(Node(bch, tmpInt));
		gra[bch].push_back(Node(ach, tmpInt));
	}
	
	for (int i = nHous + 1; i <= nHous + mGas; ++i) {
		queue<Node> q;
		q.push(Node(i, 0));
		
	}

	return 0;
}