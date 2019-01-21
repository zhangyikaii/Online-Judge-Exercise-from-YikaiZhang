#include <iostream>
using namespace std;

inline int read(){
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}

#define MAX 110

int n, m, a[MAX], f[MAX][10010];
int f1[10010] = { 0 };


int main() {
	n = read();
	m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	// 正好买一件（边界条件）
	f1[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; --j) {
			f1[j] += f1[j];					// # 不买第 i 件菜品#（这里指的是当前已经花了 j 元 如果 j < a[i] 当然不可能是买了第 i 件菜品
			if (j >= a[i])
				f1[j] += f1[j - a[i]];		// # 买了第 i 件菜品# 也就是说 f[j - a[i]] 表示的方案：就是前 i 件菜品花了 j - a[i] 元，加上买的第 i 件 的这样的方案
		}
	}
	cout << f1[m] << endl;
	return 0;
}