#include <bits/stdc++.h>
using namespace std;

int arr[100010], sum[100010];

int myabs(int a) {
	return a > 0 ? a : -a;
}

int main() {
	int n, all = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
		all += arr[i];
	}

	// 1 2 3 4 1 2 3 4
	//  5 4 1 2 5 4 1 2
	//  5 9 10 12



	// 注意: 求环上的长度, 可以用环总长减当前长度.
	int q;
	cin >> q;
	while (q--) {
		int aa, bb;
		cin >> aa >> bb;
		--aa, --bb;
		cout << min(myabs(sum[aa] - sum[bb]), all - myabs(sum[aa] - sum[bb])) << endl;
	}

	return 0;
}