#include <bits/stdc++.h>
using namespace std;

int arr[100010];

int main() {
	int n;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	bool flag = true;
	do {
		flag = true;

		int minn = 0x7ffffff, cur = 1;

		for (int i = 1; i <= n; ++i) {
			if (i != 1 && i != n && arr[i] == 0) {
				++cur;
				continue;
			}
			if (minn > arr[i]) {
				flag = false;
				minn = arr[i];
			}
		}

		if (flag == false) {
			for (int i = 1; i <= n; ++i) {
				arr[i] -= minn;
			}
		}
	}
	return 0;
}