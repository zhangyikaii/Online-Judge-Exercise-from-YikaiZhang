#include <iostream>
#include <cstdio>
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

int MyMax(int a, int b) {
	return (a > b) ? a : b;
}

#define MAX 1010

// 很典型的dp了
// f[i][k] 表示前 i 个药品, 花了 k 时间(可以有休息, k时间不是全部在采药), 采药的总价值 f[i][k].
int main() {
	int T, M, v[MAX], t[MAX];
	int f[MAX][MAX];
	for (int i = 0; i < MAX; ++i) {
		f[0][i] = 0;
	}
	T = read();
	M = read();

	for (int i = 1; i <= M; ++i) {
		t[i] = read();
		v[i] = read();
	}

	// 二维dp特有的问题 必须注意 一维dp巧妙地直接覆盖了!!!
	// 注意! 下面这个是不行的! 因为 当k < t[i]时 (钱(时间)不够的时候) 第 i 个直接就不能买了 所以就是 f[i][k] = f[i - 1][k]
	/*
	for (int i = 1; i <= M; ++i) {
		// 遍历第 i 个要不要的所有方案
		for (int k = T; k >= t[i]; --k) {
			f[i][k] = MyMax(f[i - 1][k], f[i - 1][k - t[i]] + v[i]);
		}
	}
	*/

	for (int i = 1; i <= M; ++i) {
		// 遍历第 i 个要不要的所有方案
		for (int k = T; k >= t[i]; --k) {
			f[i][k] = MyMax(f[i - 1][k], f[i - 1][k - t[i]] + v[i]);
		}
		for (int k = t[i] - 1; k >= 0; --k) {
			f[i][k] = f[i - 1][k];
		}
	}

	cout << f[M][T] << endl;

	// 总结: 这样求总价值的题目 就和金明那题一个样, 注意区分求方案数的dp(1164 小A点菜) 就是要 += 去处理.

	return 0;
}


/*
孩子，这个山洞里有一些不同的草药，采每一株都需要一些时间，每一株也有它自身的价值。我会给你一段时间，在这段时间里，你可以采到一些草药。如果你是一个聪明的孩子，你应该可以让采到的草药的总价值最大。

如果你是辰辰，你能完成这个任务吗？

输入输出格式
输入格式：
第一行有22个整数 T (1 ≤ T ≤ 1000)和 M (1 ≤ M ≤ 100)，用一个空格隔开，T代表总共能够用来采药的时间，M代表山洞里的草药的数目。
接下来的 M 行每行包括两个在 1 到 100 之间（包括 1 和 100）的整数，分别表示采摘某株草药的时间和这株草药的价值。

输出格式：
1个整数，表示在规定的时间内可以采到的草药的最大总价值。
*/