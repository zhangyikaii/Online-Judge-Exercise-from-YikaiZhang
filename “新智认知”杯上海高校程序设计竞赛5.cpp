#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
#include <cmath>
#include <string>
using namespace std;

typedef long long ll;

#define in(x) x=read()

inline ll read() {
	ll X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

#define maxn 10010

ll mergeResTmp[maxn] = { 0 }, iResTmp = 0;			// 暂时存放归并结果.
ll arr[maxn], brr[maxn];
void MergeSort(ll l, ll r, ll a[], ll &ans) {
	// 终止条件
	if (l >= r)
		return;

	ll mid = (l + r) / 2;

	// 先递归!
	MergeSort(l, mid, a, ans);
	MergeSort(mid + 1, r, a, ans);

	// 开始归并
	//for (ll i = l; i <= r; ++i)
	//	prllf("%d ", a[i]);
	//prllf("\n");

	ll i = l, j = mid + 1;
	iResTmp = l - 1;						// 注意这里是中间那一部分处理!
	while (i <= mid && j <= r) {
		if (a[i] <= a[j]) {
			mergeResTmp[++iResTmp] = a[i++];
		}
		else {
			mergeResTmp[++iResTmp] = a[j++];
			ans += mid - i + 1;				// 注意这里 ans 的处理, 归并第二个的时候, 前面的全部都更小, 都是逆序对
		}
	}

	// 剩余数组弄回去
	while (i <= mid)
		mergeResTmp[++iResTmp] = a[i++];
	while (j <= r)
		mergeResTmp[++iResTmp] = a[j++];

	// 中间那一部分放回去, 所以是从 l 开始到 r.
	for (ll t = l; t <= r; ++t)
		a[t] = mergeResTmp[t];
}

ll MyMin(ll a, ll b) {
	return a > b ? b : a;
}
ll n;
ll ans1 = 0, ans2 = 0, as1, as2;

int main() {
	ios::sync_with_stdio(false);

	in(n);
	for (ll i = 1; i <= n; ++i) {
		in(arr[i]);
	}

	for (ll i = 1; i <= n; ++i) {
		in(brr[i]);
	}

	MergeSort(1, n, arr, ans1);
	MergeSort(1, n, brr, ans2);

	as1 = n * (n - 1) / 2 - ans1;
	as2 = n * (n - 1) / 2 - ans2;

	cout << MyMin(as1 + ans2, as2 + ans1) << endl;

	return 0;
}

/*


*/