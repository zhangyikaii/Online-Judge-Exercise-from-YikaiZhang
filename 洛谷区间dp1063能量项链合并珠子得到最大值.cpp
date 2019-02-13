// 有一个环的瞄一眼就感觉是区间dp哇
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

#define in(x) x = read()

inline int read(){
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	if (f) return x;
	return 0 - x;
}

int n, pearl[300], dp[300][300], maxn = -1;

int main() {
	in(n);
	for (int i = 1; i <= n; i++) {
		in(pearl[i]); 
		pearl[i + n] = pearl[i];
	}

	// 背住模板: 先确定len, 然后遍历每一个 beg 开始点( 总链中的所有可能开始点 ), 结束点由 beg 和 len 确定了, 遍历beg end 之间的分割点, 对每一个这样的分割区间进行处理.
	// len: 划分的两段区间的总长度
	for (int len = 1; len <= n; ++len) {
		// beg: 总区间开始点
		for (int beg = 1; beg + len <= 2 * n; ++beg) {
			// tmpEnd: 总区间结束点, par: 分割点
			int tmpEnd = beg + len - 1;
			for (int par = beg; par < tmpEnd; ++par) {
				// cout << beg << " " << par << " " << tmpEnd << endl;
				dp[beg][tmpEnd] = max(dp[beg][tmpEnd], dp[beg][par] + dp[par + 1][tmpEnd] + pearl[beg] * pearl[par + 1] * pearl[tmpEnd + 1]);
			}
			if (dp[beg][tmpEnd] > maxn)
				maxn = dp[beg][tmpEnd];
		}
	}

	printf("%d\n", maxn);
	return 0;
}

/*
每个珠子有头尾数, 只有头数和尾数是一样的才可以合并, 比如珠子1 是(m, r) 珠子2 是(r, n) 合并获得 m * r * n

输入输出样例
输入样例#1：
4
2 3 5 10
输出样例#1：
710
*/