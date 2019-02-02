#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;
#define For(i, n, m) for(int i = n;i < m; ++i)

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

struct Data
{
	string dat;
	int id;
};

int cmp(Data &a, Data &b) {
	if (a.dat.size() > b.dat.size())
		return 1;
	else if (a.dat.size() < b.dat.size())
		return -1;
	else {
		int tmpNum = a.dat.size();
		For(i, 0, tmpNum) {
			if (a.dat[i] > b.dat[i])
				return 1;
			else if (a.dat[i] < b.dat[i])
				return -1;
		}
		return 0;
	}
}

void MergeSort(Data *a, int left, int right, Data *t) {
	if (right - left > 1) {
		int mid = left + (right - left) / 2;
		int tmpLeft = left, tmpMid = mid, iTarr = left;

		// 递归
		MergeSort(a, left, mid, t);
		MergeSort(a, mid, right, t);

		while (tmpLeft < mid || tmpMid < right) {
			// 左半数组复制到临时空间
			if (tmpMid >= right || (tmpLeft < mid && cmp(a[tmpLeft], a[tmpMid]) >= 0))    // 注意这里的条件!!!
				t[iTarr++] = a[tmpLeft++];
			// 右半数组复制到临时空间
			else
				t[iTarr++] = a[tmpMid++];
		}
		/*For(i, left, right)
			cout << t[i].dat << " ";
		cout << endl;*/

		// 从辅助空间复制回A数组
		for (iTarr = left; iTarr < right; ++iTarr) {
			a[iTarr] = t[iTarr];
		}
	}
}

int main() {
	int n = read();
	Data arr[20], tmp[20];
	For(i, 0, n) {
		cin >> arr[i].dat;
		arr[i].id = i;
	}

	MergeSort(arr, 0, n, tmp);

	printf("%d\n", arr[0].id + 1);
	cout << arr[0].dat << endl;


	return 0;
}

/*
6
1
3
2
6
5
4
*/
