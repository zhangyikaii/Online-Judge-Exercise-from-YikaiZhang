#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <iostream>
using namespace std;
// 树状数组要捡起来了!

const double pi = acos(-1.0);
double eps = 0.00000001;
vector<int> dis;
int tm[100010];
int sum[100010];
int tree[100010];
int n, k;
int lowbit(int x) {
	return x&-x;
}
void add(int x, int value) {
	for (int i = x; i <= n; i = i + lowbit(i)) {
		tree[i] += value;
	}
}
int get(int x) {
	int sum = 0;
	for (int i = x; i; i -= lowbit(i)) {
		sum += tree[i];
	}
	return sum;
}

// 求多少个子序列的和严格大于mid
// 用树状数组优化, 有点像逆序对的, 不过这里是求顺序对! 原理一样, 那个第几大的数组改成第几小的就可以了
int check(int mid) {
	int i, ret = 0;
	memset(tree, 0, sizeof(tree));
	for (i = 1; i <= n; i++) {
		int x = sum[i] - mid;  // sum[i]-sum[j]>mid, => sum[i]-mid>sum[j],对应s[j+1]...s[i]
		int it = lower_bound(dis.begin(), dis.end(), x) - dis.begin();	// 找到离散化数组中对应>=x的下标, 就是这个x在第几小: 在 第 it 小.

		ret += get(it);		// 求得 j 的个数, 算在 x 前面比 x 小的个数
		if (x > 0)			// 前缀和 = 子段和的情况
			ret++;
		it = lower_bound(dis.begin(), dis.end(), sum[i]) - dis.begin();
		cout << it << "   -----" << endl;
		add(it + 1, 1);		// 插入第几小进树状数组
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);

	int i, j;
	cin >> n >> k;

	for (i = 1; i <= n; i++)
		cin >> tm[i];

	dis.clear();
	for (i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + tm[i];
		dis.push_back(sum[i]);
	}

	sort(dis.begin(), dis.end());

	dis.erase(unique(dis.begin(), dis.end()), dis.end());		//去重

	int maxx = 100010;
	int minn = -100010;
	int l = minn, r = maxx;

	int ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid) >= k)
			l = mid + 1;
		else
			r = mid - 1, ans = mid;
	}

	/*sum[0] = 0;
	for (int i = 0; i <= n; ++i) {
		for (int k = i + 1; k <= n; ++k) {
			int tmp = sum[k] - sum[i];
			if (ans == tmp) {
				cout << i + 1 << " " << k << endl;
				return 0;
			}
		}
	}*/

	return 0;

}