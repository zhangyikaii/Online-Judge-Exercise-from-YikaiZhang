#include <bits/stdc++.h>
using namespace std;

int arr[100010];
map<int, int> ma;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		ma[arr[i]]++;
	}

	sort(arr + 1, arr + 1 + n);
	for (int i = 1; i <= n; ++i) {
		if (arr[i] * 2 != m && ma[m - arr[i]] != 0) {
			cout << min(m - arr[i], arr[i]) << " " << max(m - arr[i], arr[i]) << endl;
			return 0;
		}
		else if (arr[i] * 2 == m && ma[arr[i]] >= 2) {
			cout << arr[i] << " " << arr[i] << endl;
			return 0;
		}
	}

	cout << "No Solution" << endl;

	return 0;
}