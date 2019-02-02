#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
#define For(i, n, m) for(int i = n;i < m; ++i)

struct Score {
	int sco;
	int id;
	bool operator<(Score a) {
		if (a.sco == this->sco)
			return this->id < a.id;
		return this->sco > a.sco;
	}

	bool operator<=(Score a) {
		if (a.sco == this->sco)
			return this->id <= a.id;
		return this->sco >= a.sco;
	}
};

inline int read() {
	char s;
	int k = 0, base = 1;
	while ((s = getchar()) != '-'&&s != EOF&&!(s >= '0'&&s <= '9'));
	if (s == EOF)exit(0);
	if (s == '-')base = -1, s = getchar();
	while (s >= '0'&&s <= '9')
	{
		k = k * 10 + (s - '0');
		s = getchar();
	}
	return k*base;
}

void MergeSort(Score *a, int left, int right, Score *t) {
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
		// 从辅助空间复制回A数组
		for (iTarr = left; iTarr < right; ++iTarr) {
			a[iTarr] = t[iTarr];
		}
	}
}

int main() {
	int n = read(), m = read();
	int endd = floor(m * 1.5), iOut = 0;
	Score arr[5010], tmp[5010];
	For(i, 0, n) {
		arr[i].id = read();
		arr[i].sco = read();
	}

	MergeSort(arr, 0, n, tmp);

	for (iOut = 0; iOut < endd; ++iOut) {
		if (iOut + 1 != n && iOut + 1 == endd && arr[iOut].sco == arr[endd].sco)
			++endd;
	}

	printf("%d %d\n", arr[endd - 1].sco, endd);
	
	for (int i = 0; i < endd; ++i)
		printf("%d %d\n", arr[i].id, arr[i].sco);
	
	


	return 0;
}
