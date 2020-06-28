#include <bits/stdc++.h>
using namespace std;

struct Node {
	int id, bef;
};

Node arr[100010];

bool cmp(Node a, Node b) {
	return a.id < b.id;
}
int main() {
	int n, head;
	cin >> n >> head;

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i].bef >> arr[i].id;
		int tmp;
		cin >> tmp;
	}

	sort(arr + 1, arr + 1 + n, cmp);

	for (int i = 1; i <= n; ++i) {
		if (i == 1) {
			printf("%05d %d", arr[i].bef, arr[i].id);
		}
		else {
			printf(" %05d\n%05d %d", arr[i].bef, arr[i].bef, arr[i].id);
		}
	}
	printf(" -1\n");

	return 0;
}