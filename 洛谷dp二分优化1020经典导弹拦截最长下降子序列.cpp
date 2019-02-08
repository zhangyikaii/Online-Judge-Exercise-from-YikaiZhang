#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
using namespace std;
#define For(i, n, m) for(int i = n;i < m; ++i)

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
	return k * base;
}

int n, a[100010], B[100010], b[100010];
int f[100010], f1[100010];
int maxx = -1, maxx1 = -1;
// f[i] 表示到第 i 个时 最长不上升/上升子序列的长度

// 在arr[l...r]中二分查找插入位置, 返回的是插入后保持有序的位置, 有重复的就是插在重复后面的那一个
// r 是可以访问的下标
int insert(int arr[], int l, int r, int key) {
	int mid;
	if (arr[r] <= key)
		return r + 1;
	while (l < r) {
		mid = l + (r - l) / 2;
		if (arr[mid] <= key)
			l = mid + 1;
		else
			r = mid;
	}
	return l;
}

// insert1 会把小的那个给覆盖掉
int insert1(int arr[], int l, int r, int key) {
	int mid;
	if (arr[r] > key)
		return r + 1;
	while (l < r) {
		mid = l + (r - l) / 2;
		if (arr[mid] > key)
			l = mid + 1;
		else if (arr[mid] < key)
			r = mid;
		else
			return -1;
	}
	return l;
}

// 最长上升子序列
int LISplus(int a[], int n) {
	int i, len = 1, next;
	b[1] = a[1];

	for (i = 2; i <= n; ++i) {
		int next = insert1(b, 1, len, a[i]);
		if (next != -1)
			b[next] = a[i];
		if (len < next)
			len = next;
	}

	return len;
}

// 具体过程解释看笔记
int LIS(int A[], int n) {
	int i = 0, len = 1, next;
	B[1] = A[1];
	for (i = 2; i <= n; i++) {
		int next = insert(B, 1, len, A[i]);
		B[next] = A[i];
		if (len < next) // 如果插入在最尾巴, 长度要增加 1
			len = next;
	}
	return len;
}

int main() {
	int a[18] = { 9, 6, 5, 3, 1, 0 };
	cout << insert1(a, 0, 5, 4);
	// 没有结尾标识的输入用scanf的写法:
	int input = 1;
	while (scanf("%d", &a[input]) != EOF) {
		++input;
	}

	printf("%d\n", LIS(a, input));

	return 0;
}

/*
就是求 最长不上升子序列长度, 和 最少的不上升子序列的数目, 笔记里有详细解答

题目描述 Description
某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。

输入描述 Input Description
输入导弹依次飞来的高度（雷达给出的高度数据是不大于30000的正整数）

输出描述 Output Description

输出这套系统最多能拦截多少导弹，如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。

样例输入 Sample Input
389 207 155 300 299 170 158 65

(这里最长不上升子序列的dp数组就会是:
1   2   3   2   3   4   5   6 )

样例输出 Sample Output
6

2
*/
