#include <iostream>
#include <algorithm>
using namespace std;

int a[200050] = { 0 };

//void dfs(int beg, int next, int length, int &minLength, int m[]) {
//	if (next == 0 || length > minLength || m[next] == 1)
//		return;
//
//	if (next == beg) {
//		minLength = min(length, minLength);
//		return;
//	}
//
//	m[next] = 1;
//	dfs(beg, a[next], length + 1, minLength, m);
//}

// ³¬Ê±µÄ
//int main() {
//	int n = 0;
//	while (cin >> n) {
//		int minLength = 99999;
//		for (int i = 1; i <= n; ++i) {
//			cin >> a[i];
//		}
//
//		for (int i = 1; i <= n; ++i) {
//			int m[200050] = { 0 };
//			dfs(i, a[i], 1, minLength, m);
//		}
//
//		cout << minLength << endl;
//	}
//
//
//	return 0;
//}
