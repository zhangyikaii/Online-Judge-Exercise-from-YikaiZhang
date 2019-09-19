#include <bits/stdc++.h>
using namespace std;

// lg тснЯ.
int n;
int weight[10010];
vector<int> gra[10010];
int bef[10010];

struct Node {
	int time, id;
	Node(int t, int idd) : time(t), id(idd) { }
};

void Topo() {
	queue<Node> q;
	for (int i = 1; i <= n; ++i) {
		if (bef[i] == 0)
			q.push(Node(i, 0));
	}

	while (!q.empty()) {
		Node tmp = q.front();
		q.pop();

		for (int i = 0; i < gra[tmp.id].size(); ++i) {
			q.push(Node(tmp.time, gra[tmp.id][i]))
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int num, wei, tmp;
		cin >> num;
		cin >> weight[num] >> tmp;
		while (tmp != 0) {
			gra[num].push_back(tmp);
			++bef[tmp];
			cin >> tmp;
		}
	}



	return 0;
}


