#include <bits/stdc++.h>
using namespace std;

string words[110], sen;

int ans = 0;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> words[i];
	}
	
	getchar();
	getline(cin, sen);
	int tmp = sen.find('.'), bef = 0;
	while (tmp != string::npos) {
		string sub = sen.substr(bef, tmp - bef);
		// cout << sub << endl;
		for (int i = 1; i <= n; ++i) {
			if (sub.find(words[i]) != string::npos)
				++ans;
		}

		sen[tmp] = ' ';
		bef = tmp + 1;
		tmp = sen.find('.', bef);
	}

	cout << ans << endl;

	return 0;
}