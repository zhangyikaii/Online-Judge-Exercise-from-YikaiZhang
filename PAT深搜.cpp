#include <bits/stdc++.h>
using namespace std;

int n;
double jum;
double xp[10010], yp[10010];

double myabs(double a) {
	return a > 0 ? a : -a;
}

bool check(int a, int b) {
	double xg = xp[a] - xp[b], yg = yp[a] - yp[b];
	if (myabs(xg) > jum || myabs(yg) > jum)
		return false;
	return sqrt(xg * xg + yg * yg) <= jum;
}

bool isOk(int a) {
	double xans = min(myabs(xp[a] - 50), myabs(xp[a] + 50));
	if (xans <= jum)
		return true;
	double yans = min(myabs(yp[a] - 50), myabs(yp[a] + 50));
	if (yans <= jum)
		return true;
	return false;
}

void dfs(int beg, int& flag, int used[]) {
	if (flag == 1)
		return;

	for (int i = 1; i <= n; ++i) {
		if (used[i] == 0 && check(beg, i)) {
			if (isOk(i)) {
				flag = 1;
				return;
			}
			used[i] = 1;
			dfs(i, flag, used);
		}
	}
}

int main() {
	cin >> n >> jum;
	xp[1] = yp[1] = 0;
	++n;
	for (int i = 2; i <= n; ++i) {
		cin >> xp[i] >> yp[i];
	}

	int flag = 0, used[110] = { 0 };
	dfs(1, flag, used);

	if (flag == 1)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;


	return 0;
}