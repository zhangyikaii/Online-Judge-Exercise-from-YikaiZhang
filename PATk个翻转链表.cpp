#include <bits/stdc++.h>
using namespace std;

struct node {
	int ind, val, next;
	node() { }
	node(int indd, int vall, int nextt) : ind(indd), val(vall), next(nextt) { }
};

int head, n, m;

node arr[100010];

int main() {
	cin >> head >> n >> m;
	if (m == 0)
		++m;

	for (int i = 0; i < n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		arr[a].ind = a;
		arr[a].next = c;
		arr[a].val = b;
	}

	int cur = m;
	vector<int> v;
	bool flag = false;
	for (int i = head; i != -1; i = arr[i].next) {
		v.push_back(arr[i].ind);

		--cur;
		if (cur == 0) {
			// do
			for (int i = v.size() - 1; i >= 0; --i) {
				flag = true;
				if (i == v.size() - 1)
					printf("%05d %d", arr[v[i]].ind, arr[v[i]].val);
				else
					printf(" %05d\n%05d %d", arr[v[i]].ind, arr[v[i]].ind, arr[v[i]].val);
			}
			v.clear();
		}
	}

	if (!v.empty()) {
		for (int i = 0; i < v.size(); ++i) {
			if (i == 0 && flag != true)
				printf("%05d %d", arr[v[i]].ind, arr[v[i]].val);
			else
				printf(" %05d\n%05d %d", arr[v[i]].ind, arr[v[i]].ind, arr[v[i]].val);
		}
	}

	printf(" -1\n");


	return 0;
}

/*
1.next = 2.next
2.next = 1

1.next = 3.next
3.next = 2

3 2 1 4 5 6 7 8 9


00100 6 1
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

*/