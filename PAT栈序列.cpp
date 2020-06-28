#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, n, k;
	cin >> m >> n >> k;

	int stand[10010] = { 0 };
	for (int i = 0; i < n + 5; ++i)
		stand[i] = i;

	while (k--) {
		int curStan = 1;
		int arr[10010] = { 0 };
		stack<int> st;
		bool flag = false;

		for (int i = 0; i < n; ++i) {
			cin >> arr[i];

			if (flag == false) {
				while (st.empty() || st.top() != arr[i]) {
					st.push(stand[curStan++]);
					if (st.size() > m) {
						flag = true;
						break;
					}
				}
				if (flag == false)
					st.pop();
			}
		}

		if (flag == false && st.empty()) {
			printf("YES\n");
		}
		else
			printf("NO\n");
	}

	return 0;
}