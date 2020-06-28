#include <bits/stdc++.h>
using namespace std;

/*
3 2
R1 S1
S0 R0
R1 S1
R0 S0
R1 R1 R1 R1 S1 S1 S1 S1
S0 S0 S0 S0 R0 R0 R0 R0


2 3
R1 S1
R2 S0 R0 S2
S1 R1
R1
R2 S0 R0
S1 R1

*/

int main() {
	int n, m;
	cin >> n >> m;

	getchar();
	while (n--) {
		queue<int> q[10010];
		int waitFlag[10010] = { 0 };

		for (int k = 1; k <= m; ++k) {
			string tmp;
			getline(cin, tmp);
			for (int j = 0; j < tmp.size();) {
				int spa = tmp.find(' ', j);
				if (spa == string::npos) {
					spa = tmp.size();
				}
				//cout << tmp.substr(j + 1, spa - j - 1) << endl;
				//cout << atoi(tmp.substr(j + 1, spa - j - 1).c_str()) << endl;
				if (tmp[j] == 'S') {
					q[k].push(atoi(tmp.substr(j + 1, spa - 1 - j).c_str()) + 1);
				}
				else
					q[k].push(-atoi(tmp.substr(j + 1, spa - 1 - j).c_str()) - 1);
				j = spa + 1;
			}
		}

		bool isCha = false;
		// 遍历所有进程.
		while (isCha == false) {
			isCha = true;
			for (int i = 1; i <= m; ++i) {
				if (!q[i].empty()) {
					int tmp = q[i].front();
					if (tmp > 0/* && waitFlag[tmp] == 0*/) {
						isCha = false;
						waitFlag[tmp] = i;
						q[i].pop();
					}
					else if (tmp < 0 && waitFlag[i] == -tmp) {
						isCha = false;
						waitFlag[-tmp] = 0;
						q[i].pop();
					}
				}
			}
		}

		bool ans = false;
		for (int i = 1; i <= m; ++i) {
			if (!q[i].empty()) {
				ans = true;
				break;
			}
		}
		if (ans == false)
			cout << "0" << endl;
		else
			cout << "1" << endl;
	}

	return 0;
}