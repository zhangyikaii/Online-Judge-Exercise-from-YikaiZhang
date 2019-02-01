#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
#define For(i, n, m) for(int i = n;i < m; ++i)

int a[100010], used[1010] = { 0 };
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
void write(int x) {
	if (x<0)
	{
		putchar('-');
		write(-x);
	}
	else
	{
		if (x / 10)write(x / 10);
		putchar(x % 10 + '0');
	}
}

void MyCopyQuickSort(int left, int right) {
	int i, j, temp;
	if (left > right)
		return;

	temp = a[left];		// 取出基准数
	i = left;
	j = right;
	// 注意把 left 和 right 临时寄放在 i j 里面, 然后要先从右边开始找
	while (i != j) {
		while (a[j] >= temp && i < j)		// 从右往左找到第一个更小的(应该放在左边的)
			--j;
		while (a[i] <= temp && i < j)		// 从左往右找到第一个更大的(应该放在右边的)
			++i;

		// 交换位置
		if (i < j) {
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}

	// 最终将基准数归位
	a[left] = a[i];         // 注意这句话!!!
	a[i] = temp;

	MyCopyQuickSort(left, i - 1);			//继续处理左边的
	MyCopyQuickSort(i + 1, right);			//继续处理右边的
}


int main() {
	int n = read();
	For(i, 0, n) {
		a[i] = read();
		if (used[a[i]] == 1) {
			--n;
			--i;
		}
		else {
			used[a[i]] = 1;
		}
	}

	MyCopyQuickSort(0, n - 1);

	printf("%d\n", n);
	if (n > 0)
		printf("%d", a[0]);
	For(i, 1, n) {
		printf(" %d", a[i]);
	}
	printf("\n");

	return 0;
}
