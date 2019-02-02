#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;
#define For(i, n, m) for(int i = n;i < m; ++i)

// -------------------以下是答案 有加高精度模板!!!
int now[20010], sum[20010], ans[20010], add[20010];
struct Node {
	int a;
	int b;
	long long a_b;
}node[1010];

int read() {
	int ans = 0, flag = 1;
	char ch = getchar();
	while ((ch>'9' || ch<'0') && ch != '-') ch = getchar();
	if (ch == '-') flag = -1, ch = getchar();
	while (ch >= '0' && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
	return ans*flag;
}
void times(int x) {
	memset(add, 0, sizeof(add));
	for (int i = 1; i <= ans[0]; i++) {
		ans[i] = ans[i] * x;
		add[i + 1] += ans[i] / 10;
		ans[i] %= 10;
	}
	for (int i = 1; i <= ans[0] + 4; i++) {
		ans[i] += add[i];
		if (ans[i] >= 10) {
			ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
		}
		if (ans[i] != 0) {
			ans[0] = max(ans[0], i);
		}
	}
	return;
}
int divition(int x) {
	memset(add, 0, sizeof(add));
	int q = 0;
	for (int i = ans[0]; i >= 1; i--) {
		q *= 10;
		q += ans[i];
		add[i] = q / x;
		if (add[0] == 0 && add[i] != 0) {
			add[0] = i;
		}
		q %= x;
	}
	return 0;
}
bool compare() {
	if (sum[0] == add[0]) {
		for (int i = add[0]; i >= 1; i--) {
			if (add[i]>sum[i]) return 1;
			if (add[i]<sum[i]) return 0;
		}
	}
	if (add[0]>sum[0]) return 1;
	if (add[0]<sum[0]) return 0;
}
void cp() {
	memset(sum, 0, sizeof(sum));
	for (int i = add[0]; i >= 0; i--) {
		sum[i] = add[i];
	}
	return;
}
bool cmp(Node a, Node b) {
	return a.a_b<b.a_b;
}
int main() {
	int n = read();
	for (int i = 0; i <= n; i++) {
		node[i].a = read(), node[i].b = read();
		node[i].a_b = node[i].a * node[i].b;
	}

	sort(node + 1, node + n + 1, cmp);

	// 主要是下面计算的时候要高精度
	ans[0] = 1, ans[1] = 1;
	for (int i = 1; i <= n; i++) {
		times(node[i - 1].a);
		divition(node[i].b);         // 计算出一个人的
		// 取最大值
		if (compare()) {
			cp();
		}
	}
	for (int i = sum[0]; i >= 1; i--)
		printf("%d", sum[i]);
	return 0;
}










// 下面是我没有考虑高精度的答案   long double 都是没用的
/*
struct Data {
	int l, r;
	long double sum;
	bool operator >(Data a) {
		return sum > a.sum;
	}

	bool operator <(Data a) {
		return sum < a.sum;
	}

};

inline int read() {
	char s;
	int k = 0, base = 1;
	while ((s = getchar()) != '-' && s != EOF&&!(s >= '0'&&s <= '9'));
	if (s == EOF)exit(0);
	if (s == '-')base = -1, s = getchar();
	while (s >= '0'&&s <= '9')
	{
		k = k * 10 + (s - '0');
		s = getchar();
	}
	return k*base;
}

// 这题完全搞错了, 证明的东西要去试一下, 
/////////////////////////////// 有大数相乘一定要记得高精度!!!!!!!

int main() {
	int n = read();
	int l = read(), r = read(), maxx = -1;
	Data arr[1010];
	For(i, 0, n) {
		arr[i].l = read();
		arr[i].r = read();
		arr[i].sum = l * r;
	}

	sort(arr, arr + n);

	For(i, 0, n) {
		long double curLeft = l;
		For(k, 0, i) {
			curLeft *= arr[k].l;
		}
		curLeft = floor(curLeft / arr[i].r);
		maxx = maxx > curLeft ? maxx : curLeft;
	}

	cout << maxx << endl;

	return 0;
}

*/

/*
让这 n 位大臣排成一排，国王站在队伍的最前面。排好队后，所有的大臣都会获得国王奖赏的若干金币，每位大臣获得的金币数分别是：排在该大臣前面的所有人的左手上的数的乘积除以他自己右手上的数，然后向下取整得到的结果。

国王不希望某一个大臣获得特别多的奖赏，所以他想请你帮他重新安排一下队伍的顺序，使得获得奖赏最多的大臣，所获奖赏尽可能的少。注意，国王的位置始终在队伍的最前面。


// 第一个是国王

3
1 1
2 3
7 4
4 6

2

*/