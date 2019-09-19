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

int main() {
	int k, n, *arr, mid, midPos;
	in(n);
	arr = new int[n + 10];
	for (int i = 1; i <= n; ++i)
		scanf("%d", &arr[i]);

	in(k);

	// 尺取法可以做? 因为有序

	int bef = 1, aft = n;
	while (bef < aft) {
		if (arr[bef] + arr[aft] < k)
			++bef;
		else if (arr[bef] + arr[aft] > k)
			--aft;
		else {
			printf("%d %d\n", arr[bef], arr[aft]);
			++bef;
			--aft;
		}
	}

	delete[] arr;

	return 0;
}


/*

题目描述
给定一个 int 数组 arr，元素按照升序排列且各不相同。另外有一个目标数 c，请你找出 arr 中所有的数对 a, b，使得 a + b = c。
输入
输入为三行，第一行为 arr 的元素个数，第二行为 arr，元素以空格分隔，第三行为目标数 c。
输出
所有符合条件的数对 a, b。a 和 b 以空格分开，每个数对占据一行。每行中 a < b，所有数对以它的第一个数（也就是 a 的值）升序排列。
样例输入
9
-2 0 1 2 3 5 6 8 10
8
样例输出
-2 10
0 8
2 6
3 5

*/