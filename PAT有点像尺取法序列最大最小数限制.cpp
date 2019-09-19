#include <bits/stdc++.h>
using namespace std;

int n, arr[100010];
int lim;

int main() {
	cin >> n >> lim;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	sort(arr + 1, arr + 1 + n);

	int ar = 0, br = n, res = (ar + br) >> 2;
	int ans = 0;
	while (ar <= br) {
		res = (ar + br) >> 1;
		// cout << res << endl;
		int bef = 1, aft = n - res;
		while (aft <= n) {
			if (arr[bef] * lim >= arr[aft]) {
				ans = n - res;
				br = res - 1;
				break;
			}
			++bef, ++aft;
		}

		if (br != res - 1)
			ar = res + 1;
	}

	cout << ans << endl;
	return 0;
}