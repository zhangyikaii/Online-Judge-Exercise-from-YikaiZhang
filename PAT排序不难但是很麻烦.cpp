#include <bits/stdc++.h>
using namespace std;

int fen[10];

struct Node {
	int gett[10];
	int pasNum, scor;
	int id;
	Node() : pasNum(0), scor(0) {
		for (int i = 0; i < 10; ++i) {
			gett[i] = -1;
		}
	}
};

Node per[100010];

bool cmp(Node a, Node b) {
	if (a.scor == b.scor) {
		if (a.pasNum == b.pasNum)
			return a.id < b.id;
		return a.pasNum > b.pasNum;
	}
	return a.scor > b.scor;
}

int main() {
	int n, p, m, tmp, qId, qFen;
	cin >> n >> p >> m;
	
	for (int i = 1; i <= p; ++i) {
		cin >> fen[i];
	}

	for (int i = 1; i <= m; ++i) {
		cin >> tmp >> qId >> qFen;
		if (qFen == -1) {
			per[tmp].gett[qId] = 0;
			continue;
		}
		if (qFen == fen[qId]) {
			++per[tmp].pasNum;
			per[tmp].gett[qId] = qFen;
		}
		else if (per[tmp].gett[qId] < qFen)
			per[tmp].gett[qId] = qFen;
	}

	for (int i = 1; i <= n; ++i) {
		per[i].id = i;
		int sum = 0;
		for (int k = 1; k <= p; ++k) {
			if (per[i].gett[k] > 0)
				sum += per[i].gett[k];
		}
		per[i].scor = sum;
	}

	sort(per + 1, per + 1 + n, cmp);

	int bef = 0x7fffff, curRank = 0, realRank = 0;
	for (int i = 1; i <= n; ++i) {
		if (per[i].scor != 0) {
			++realRank;
			if (per[i].scor < bef) {
				bef = per[i].scor;
				curRank = realRank;
			}

			printf("%d %05d %d", curRank, per[i].id, per[i].scor);
			for (int k = 1; k <= p; ++k) {
				if (per[i].gett[k] == -1)
					printf(" -");
				else
					printf(" %d", per[i].gett[k]);
			}
			printf("\n");
		}
	}





	return 0;
}