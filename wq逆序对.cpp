#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

#define in(x) x=read()
#define xw x+xway[i]
#define yw y+yway[i]

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int MyMin(int a, int b) {
	return a > b ? b : a;
}

void Swap(int arr[], int i, int j) {
	if (i == j)
		return;

	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}

const int maxn = 5e5 + 10;

int mergeResTmp[maxn] = { 0 }, iResTmp = 0;			// 暂时存放归并结果.
long long ans = 0;
int a[maxn];
void MergeSort(int l, int r) {
	// 终止条件
	if (l >= r)
		return;

	int mid = (l + r) / 2;

	// 先递归!
	MergeSort(l, mid);
	MergeSort(mid + 1, r);

	// 开始归并
	//for (int i = l; i <= r; ++i)
	//	printf("%d ", a[i]);
	//printf("\n");

	int i = l, j = mid + 1;
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
	for (int t = l; t <= r; ++t)
		a[t] = mergeResTmp[t];
}

int n;

int main() {
	in(n);
	for (int i = 1; i <= n; ++i) {
		in(a[i]);
	}

	MergeSort(1, n);

	printf("%lld\n", ans);


	return 0;
}


/*
题目描述
给定数组A1,⋯,AnA_1, \cdots, A_nA
​1
​​ ,⋯,A
​n
​​ 。

定义逆序对为(i,j)(i, j)(i,j)，满足1≤i<j≤n,Ai>Aj1 \leq i \lt j \leq n, A_i \gt A_j1≤i<j≤n,A
​i
​​ >A
​j
​​ 。

求出逆序对的个数。

输入格式
第一行一个数nnn。

第二行有nnn个数A1,⋯,AnA_1, \cdots, A_nA
​1
​​ ,⋯,A
​n
​​ 。

输出格式
输出一个数，表示逆序对的个数

样例
Input
2
2 1
Output
1

*/
