#include<bits/stdc++.h>

using namespace std;

struct node {
	int x, y, w;
}a[200002];

int f[200002];

bool cmp(node xx, node yy) {//结构体排序
	return xx.w < yy.w;
}

int find(int x) {
	if (x == f[x])
		return x;
	f[x] = find(f[x]);
	return f[x];
}

int main() {
	int n, k, m = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {

		// 并查集的初始化.
		f[i] = i;

		for (int j = 1; j <= n; j++) {
			scanf("%d", &k);
			if (j > i) {
				//读入时加一个判断就可以了，不需要读那么多
				m++;
				a[m].x = i; a[m].y = j; a[m].w = k;
			}
		}
	}
	sort(a + 1, a + m + 1, cmp);//排序
	// kruskal 刚开始简单排序就可以了.
	int ans = 0, p = 1;
	for (int i = 1; i <= m; i++) {
		if (find(a[i].x) != find(a[i].y)) {
			// 如果不在一个集合, 说明这条边可以选.
			// 这条边被选入了.
			ans += a[i].w;
			f[find(a[i].x)] = a[i].y;
			// 合并两个节点
			p++;
			if (p == n) break;
		}
	}
	cout << ans;
	return 0;
}