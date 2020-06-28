#include <bits/stdc++.h>
using namespace std;
string a, b;
int main() {
	getline(cin, a);
	getline(cin, b);

	map<char, int> m;
	for (int i = 0; i < b.size(); ++i) {
		m[b[i]] = 1;
	}

	for (int i = 0; i < a.size(); ++i) {
		if (m[a[i]] != 1)
			cout << a[i];
	}
	cout << endl;

	return 0;
}