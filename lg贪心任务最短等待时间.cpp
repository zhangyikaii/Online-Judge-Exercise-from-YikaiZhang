#include <bits/stdc++.h>
using namespace std;

int arr[5010], brr[5010];
int asort[5010];

bool cmp(int a, int b) {
	return arr[a] > arr[b];
}


int ans = 0;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		asort[i] = i;
		cin >> arr[i] >> brr[i];
	}

	sort(asort + 1, asort + 1 + n, cmp);

	for (int i = 1; i < n; ++i) {
		int& ind = asort[i];
		if (brr[ind] < brr[asort[i + 1]])
			++ans;
	}

	cout << ans << endl;

	return 0;
}