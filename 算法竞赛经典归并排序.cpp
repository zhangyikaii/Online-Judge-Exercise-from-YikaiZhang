#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
#define For(i, n, m) for(int i = n;i < m; ++i)

int a[14] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
int t[14] = { 0 };

// 好好体会
// 归并顺序就是 分两半, 然后每一半再分, 直到只有两个或三个的时候

void MergeSort(int *a, int left, int right, int *t) {
	if (right - left > 1) {
		int mid = left + (right - left) / 2;
		int tmpLeft = left, tmpMid = mid, iTarr = left;

		// 递归
		MergeSort(a, left, mid, t);
		MergeSort(a, mid, right, t);

		while (tmpLeft < mid || tmpMid < right) {
			// 左半数组复制到临时空间
			if (tmpMid >= right || (tmpLeft < mid && a[tmpLeft] <= a[tmpMid]))     // 注意这里的条件!!!
				t[iTarr++] = a[tmpLeft++];
			// 右半数组复制到临时空间
			else
				t[iTarr++] = a[tmpMid++];
		}
		// 其实只是哪个先放 哪个后放的问题? 如果比中间的大 就是后面再放, 只有全部放完了再跳出    ( 可以把递归的打注释, 然后测试 9 - 1 排列的, 然后看看下面的输出)
		/*For(i, 0, 13)
			cout << t[i] << " ";*/
		// 从辅助空间复制回A数组
		for (iTarr = left; iTarr < right; ++iTarr) {
			a[iTarr] = t[iTarr];
			cout << a[iTarr] << " ";
		}
		cout << endl;
	}
}

int main() {
	MergeSort(a, 0, 9, t);
	
	return 0;
}
