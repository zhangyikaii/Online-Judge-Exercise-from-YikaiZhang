// 给 存货数量, 月饼价格和最大市场需求, 求最大利润.

#include <bits/stdc++.h>
using namespace std;

double arr[1010], one[1010], per[1010];

int ind[1010];

bool cmp(int a, int b) {
	return per[a] > per[b];
}

int main() {
	int n;
	double lim;
	double res = 0;
	cin >> n >> lim;

	for (int i = 0; i < n; ++i) {
		ind[i] = i;
		cin >> arr[i];
	}

	for (int i = 0; i < n; ++i) {
		cin >> one[i];
		per[i] = one[i] / arr[i];
	}

	sort(ind, ind + n, cmp);

	for (int i = 0; i < n; ++i) {
		int& cur = ind[i];
		if (lim < arr[cur]) {
			res += lim * per[cur];
			break;
		}
		else {
			// 如果不使用one[], 直接计算per, 这里再乘一次有精度损失, 会wa.
			res += one[cur];
			lim -= arr[cur];
		}
	}

	printf("%.2f\n", res);

	return 0;
}