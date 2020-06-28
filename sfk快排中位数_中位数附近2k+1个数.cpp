#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

#define in(x) x=read()

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


// 利用快排, 每次都是把基准元素归到正确的位置, 这个函数是获取第一个元素位置, arr[]: 1 ~ n.
// 这个函数是做了一轮而已.
int GetRank(int arr[], int n) {
	int pivot = arr[1], l = 1, r = n;
	
	while (l < r) {
		while (l < r && arr[r] >= pivot)		// 放到第一个小于pivot的
			--r;
		arr[l] = arr[r];

		while (l < r && arr[l] <= pivot)		// 放到第一个大于pivot的
			++l;
		arr[r] = arr[l];
	}
	arr[l] = pivot;					// 不要忘了放回去

	return l;
}

int GetPosVal(int arr[], int n, int pos) {
	int tmp = GetRank(arr, n);		// 第一个数在第几个, 并把它放到正确位置

	if (tmp == pos)
		return arr[pos];
	else if (tmp < pos)				// 找到的更小, 说明在pos在找到的那个后面
		return GetPosVal(arr + tmp, n - tmp, pos - tmp);
	// 注意这里 tmp - 1, 因为在 tmp 的前面, 这是只有 tmp - 1 个数的 ( 数组以 1 开头! )
	else
		return GetPosVal(arr, tmp - 1, pos);
}



int main() {
	int k, n, *arr, mid, midPos;
	in(k);
	in(n);
	arr = new int[n + 10];
	for (int i = 1; i <= n; ++i)
		scanf("%d", &arr[i]);

	// 写完发现其实只要保证 pivot == 中位数值 的那趟快排已经做完了就可以了, 因为这趟做完之后前面都是小于pivot的, 后面都是大于pivot的, 然后再选择排序一下就可以了

	midPos = (n + 1) / 2;
	mid = GetPosVal(arr, n, midPos);

	for (int i = midPos - 1; i >= midPos - k; --i) {
		// 找到前半部分前 k 个大的
		int maxx = i;
		for (int j = i - 1; j >= 1; --j) {
			if (arr[j] > arr[maxx])
				maxx = j;
		}
		Swap(arr, i, maxx);
	}
	
	for (int i = midPos + 1; i <= midPos + k; ++i) {
		int minn = i;
		// 注意这里是选择排序找到后半部分前 k 个小的
		for (int j = i + 1; j <= n; ++j) {
			if (arr[j] < arr[minn])
				minn = j;
		}
		if (minn != i)
			Swap(arr, minn, i);
	}

	printf("%d", arr[midPos - k]);
	for (int i = midPos - k + 1; i <= midPos + k; ++i)
		printf(" %d", arr[i]);
	printf("\n");

	delete[] arr;

	return 0;
}


/*

题目描述
给出一串整型数 a1,a2,...,an 以及一个较小的常数 k，找出这串数的中位数 m 和最接近 m 的小于等于 m 的 k 个数，以及最接近 m 的大于等于 m 的 k 个数。将这 2k+1 个数按升序排序后输出。


中位数定义：如果数串的大小是偶数 2j，中位数是从小到大排列的第 j 个数；如果数串的大小是奇数 2j+1，中位数是从小到大排列的第 j+1 个数。

输入
第一行是 k 的值和数串的长度 n。

第二行是以空格隔开的 n 个整型数，最后一个数后面有空格。

输出
按升序排列的 2k+1 个数，以空格分开，最后一个数后面没有空格。结果可能出现重复的数。
样例输入
2 10
7 2 5 7 2 10 7 7 13 15
样例输出
5 7 7 7 7


*/