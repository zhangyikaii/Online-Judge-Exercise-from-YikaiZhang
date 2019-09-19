#include <bits/stdc++.h>
using namespace std;

int arr[1010][1010];
map<int, int> ma;
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		for (int k = 0; k < n; ++k) {
			cin >> arr[i][k];
			ma[arr[i][k]]++;
		}
	}

	int maxFir = 0, maxSec = 0;
	for (map<int, int>::iterator iter = ma.begin(); iter != ma.end(); ++iter) {
		if (iter->second > maxSec) {
			maxSec = iter->second;
			maxFir = iter->first;
		}
	}

	cout << maxFir << endl;

	return 0;
}