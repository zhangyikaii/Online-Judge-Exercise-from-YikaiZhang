#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val, l, r;
	Node() : val(0), l(-1), r(-1) { }
	Node(int v, int ll, int rr) : val(v), l(ll), r(rr) { }
};

Node nod[1010];

int arr[1010];

int arrTot = 0;

void inOrder(int cur) {
	if (nod[cur].l != -1)
		inOrder(nod[cur].l);
	nod[cur].val = arr[++arrTot];
	if (nod[cur].r != -1)
		inOrder(nod[cur].r);
}

int main() {
	int n;
	cin >> n;

	for (int i = 1, cur = 1; i <= n; i *= 2) {
		for (int k = i; k < 2 * i; ++k, ++cur) {
			if (2 * cur <= n)
				nod[cur].l = 2 * cur;
			if (2 * cur + 1 <= n) {
				nod[cur].r = 2 * cur + 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	sort(arr + 1, arr + 1 + n);

	inOrder(1);

	for (int i = 1; i <= n; ++i) {
		if (i != 1)
			cout << " ";
		cout << nod[i].val;
	}

	cout << endl;

	return 0;
}