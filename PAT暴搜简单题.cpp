#include <bits/stdc++.h>
using namespace std;

int arr[100010];
map<int, int> m;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		m[arr[i]]++;
	}

	for (int i = 1; i <= n; ++i) {
		if (m[arr[i]] == 1) {
			cout << arr[i] << endl;
			return 0;
		}
	}

	cout << "None" << endl;


	// 好好的map不用, 真是傻了.
	//for (int i = 1; i <= n; ++i) {
	//	if (used[i] == 1)
	//		continue;
	//	int k;
	//	bool flag = false;
	//	for (k = i + 1; k <= n; ++k) {
	//		if (used[k] == 0 && arr[k] == arr[i]) {
	//			flag = true;
	//			used[k] = 1;
	//		}
	//	}
	//	if (flag == false) {
	//		cout << arr[i] << endl;
	//		return 0;
	//	}
	//}

	//cout << "None" << endl;

	return 0;
}