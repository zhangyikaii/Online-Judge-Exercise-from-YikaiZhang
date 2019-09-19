#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define in(x) x=read()
#define For(i, a, b) for(int i = a; i < b; ++i)

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

int arr[1010][1010];
int rowMax[1010], linMax[1010];
int n;

int main() {
	in(n);
	for (int i = 1; i <= n; ++i) {
		int maxx = 0;
		for (int k = 1; k <= n; ++k) {
			in(arr[i][k]);
			if (arr[i][k] > maxx)
				maxx = arr[i][k];
			rowMax[i] = maxx;
		}
	}

	for (int k = 1; k <= n; ++k) {
		int maxx = 0;
		for (int i = 1; i <= n; ++i) {
			if (arr[i][k] > maxx)
				maxx = arr[i][k];
		}
		linMax[k] = maxx;
	}

	// 正视图:
	for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <= n; ++k) {
			if (linMax[k] >= n + 1 - i)
				printf("*");
			else
				printf(".");
		}
		printf("\n");
	}

	// 左视图:
	for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <= n; ++k) {
			if (rowMax[k] >= n + 1 - i)
				printf("*");
			else
				printf(".");
		}
		printf("\n");
	}

	for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <= n; ++k) {
			if (arr[i][k] != 0)
				printf("*");
			else
				printf(".");
		}
		printf("\n");
	}

	return 0;
}


/*

链接：https://ac.nowcoder.com/acm/contest/928/B
来源：牛客网

题目描述
小巫女从小就喜欢吃火龙果，她有一个梦想，就是用魔法变出许许多多美味可口的火龙果，这样她就可以天天享受火龙果的美味啦！
小巫女在学习三视图。假定每个立体图均由若干小立方体组成。
小巫女给出了一个立体图，请你尝试画出其三视图（忽略三视图的实线和虚线）。
输入描述:
第一行：一个整数n，表示三视图的长宽高（均相等）。
接下来有 n 行，每行包含用空格隔开的 n 个数字，表示俯视时，每个位置堆叠多少个立方体。
输出描述:
接下来 n 行：每行 n 个字符，表示正视图，若为’*’ 则表示该位置有正方形，若为’.’ 则表示该位置没有正方形。
接下来 n 行：每行 n 个字符，表示左视图，若为’*’ 则表示该位置有正方形，若为’.’ 则表示该位置没有正方形。
接下来 n 行：每行 n 个字符，表示俯视图，若为’*’ 则表示该位置有正方形，若为’.’ 则表示该位置没有正方形。
示例1
输入
复制
3
3 2 0
2 2 0
0 0 0
输出
复制
*..
**.
**.
*..
**.
**.
**.
**.
...


*/