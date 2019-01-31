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

#define MAX 40

int main() {
	int T, M, v[10010], t[10010];
	int f[100010] = { 0 };
	
	T = read();
	M = read();

	for (int i = 1; i <= M; ++i) {
		t[i] = read();
		v[i] = read();
	}

	int maxx = 0;
	for (int i = 1; i <= M; ++i) {
		for (int k = t[i]; k <= T; ++k) {
			f[k] = MyMax(f[k], f[k - t[i]] + v[i]);
			maxx = MyMax(maxx, f[k]);
		}
	}

	cout << maxx << endl;
	
	// 总结: 药可以无穷采的 就是物品可以有无穷多个, 这是完全背包问题, 不如背住模板吧.
	// 就是相比原来有限的 压缩一维数组存的那种 从前往后遍历即可

	return 0;
}


/*
“孩子，这个山洞里有一些不同种类的草药，采每一种都需要一些时间，每一种也有它自身的价值。我会给你一段时间，在这段时间里，你可以采到一些草药。如果你是一个聪明的孩子，你应该可以让采到的草药的总价值最大。”

如果你是LiYuxiang，你能完成这个任务吗？

此题和原题的不同点：
此题和原题的不同点：
此题和原题的不同点：!!!

1.每种草药可以无限制地疯狂采摘。

2.药的种类眼花缭乱，采药时间好长好长啊！师傅等得菊花都谢了！

输入输出格式
输入格式：
输入第一行有两个整数T（1 <= T <= 100000）和M（1 <= M <= 10000），用一个空格隔开，T代表总共能够用来采药的时间，M代表山洞里的草药的数目。接下来的M行每行包括两个在1到10000之间（包括1和10000）的整数，分别表示采摘某种草药的时间和这种草药的价值。

输出格式：
输出一行，这一行只包含一个整数，表示在规定的时间内，可以采到的草药的最大总价值。
输入:
70 3
71 100
69 1
1 2

输出:
140
*/