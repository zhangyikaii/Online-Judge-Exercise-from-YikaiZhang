#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<map>
#define INF 0xfffffff
#define mod 1000000007
#define CLR(a,b,Size) memset((a),(b),sizeof((a[0]))*(Size+1))
#define CPY(a,b) memcpy ((a), (b), sizeof((a)))
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define MAXN 2010

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n, m, kk, t;
int dp[MAXN + 10][MAXN + 10], c[MAXN + 10][MAXN + 10];

int gcd(int a, int b) {
	return a == 0 ? b : gcd(b % a, a);
}

void Init() {
	c[0][0] = 1;
	c[1][0] = 1;
	c[1][1] = 1;
	c[0][1] = 1;
	for (int i = 2; i < MAXN; ++i) {
		c[i][0] = 1;
		for (int k = 1; k <= i; ++k) {
			c[i][k] = (c[i - 1][k] + c[i - 1][k - 1]) % kk;
		}
	}

	for (int i = 2; i <= MAXN; ++i) {
		for (int k = 1; k <= i; ++k) {
			dp[i][k] = dp[i - 1][k] + dp[i][k - 1] - dp[i - 1][k - 1];
			if (c[i][k] == 0)
				++dp[i][k];
		}
		dp[i][i + 1] = dp[i][i];    // 为了接下来内层for中, k == i 的时候?
	}
}



int main() {
	in(t);
	in(kk);
	Init();
	for (int i = 0; i < t; ++i) {
		in(n);
		in(m);
		if (m > n)
			m = n;
		printf("%d\n", dp[n][m]);
	}

	return 0;
}

/*
C n 取 m, 有多少对 (n, m) 对于所有的 i 属于[0, n] j 属于 [0, min(i, m)] 有多少对 (i,j) 使 C i 取 j 是k 的倍数.

输入输出格式
输入格式：
第一行有两个整数 t,kt,k，其中 tt 代表该测试点总共有多少组测试数据，kk 的意义见问题描述。

接下来 tt 行每行两个整数 n,mn,m，其中 n,mn,m 的意义见问题描述。

输入输出样例
输入样例#1：
1 2
3 3
输出样例#1：
1

输入样例#2：
2 5
4 5
6 7
输出样例#2：
0
7

*/