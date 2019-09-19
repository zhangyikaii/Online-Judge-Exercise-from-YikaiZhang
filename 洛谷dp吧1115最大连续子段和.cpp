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

int n, arr[200010];
int preMin[200010] = { 0 }, preSum[200010] = { 0 }, ans[200010];		// ans[i] 表示当前以第 i 个结尾的最大连续子段和...
int curMinPre, maxAns = -0x6fffffff;

int MyMin(int a, int b) {
	return a > b ? b : a;
}

int main() {
	// freopen("testdata.in", "r", stdin);
	in(n);
	for (int i = 1; i <= n; ++i) {
		in(arr[i]);
		preSum[i] = preSum[i - 1] + arr[i];		// 前缀和的记忆化处理方法
	}

	preMin[1] = MyMin(0, preSum[1]);			// 注意为了包含第一个, 一定要考虑, 如果第一个为正!!!
	for (int i = 2; i <= n; ++i) {
		preMin[i] = MyMin(preSum[i], preMin[i - 1]);
	}

	ans[1] = preSum[1];
	for (int i = 2; i <= n; ++i) {
		ans[i] = preSum[i] - preMin[i - 1];
	}

	for (int i = 1; i <= n; ++i) {
		if (ans[i] > maxAns)
			maxAns = ans[i];
	}

	printf("%d\n", maxAns);

	return 0;
}


/*

题目描述
给出一段序列，选出其中连续且非空的一段使得这段和最大。

输入输出格式
输入格式：
第一行是一个正整数NN，表示了序列的长度。

第二行包含NN个绝对值不大于1000010000的整数A_iA
i
​	 ，描述了这段序列。

输出格式：
一个整数，为最大的子段和是多少。子段的最小长度为11。

输入输出样例
输入样例#1：
7
2 -4 3 -1 2 -4 3
输出样例#1：
4


*/