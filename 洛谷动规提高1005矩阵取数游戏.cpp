#include<iostream> 
#include<cstdio> 
#include<algorithm> 
#include <cstring>

#define in(x) x=read()
#define MAXN 81
#define k (m-(R-L))
#define bll int
// #define bll __int128		// __int128 比long long 还强

using namespace std;

inline int read()
{
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n, m;
int num[MAXN];
bll ans, p[MAXN], f[MAXN][MAXN];

// 记忆化搜索 
// 动规不懂怎么遍历的时候就是记忆化搜索!!!
bll dp(int L, int R) {
	// 如果答案的结点被更新了, 说明有答案了
	if (f[L][R] != -1)
		return f[L][R];
	if (R - L >= 1) 
		f[L][R] = max(num[L] * p[k] + dp(L + 1, R), dp(L, R - 1) + num[R] * p[k]);
	// 只有一个的时候
	else
		f[L][R] = num[L] * p[k];
	return f[L][R];
}

void print(bll x) {
	if (!x) return;
	if (x) print(x / 10);
	putchar(x % 10 + '0');
}

int main()
{
	in(n);
	in(m);
	p[0] = 1;

	for (int i = 1; i <= m; i++)
		p[i] = p[i - 1] << 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) 
			in(num[j]);
		memset(f, -1, sizeof(f));
		ans += dp(1, m);
	}
	if (!ans)
		printf("0");
	else 
		 print(ans);
	return 0;
}

/*
题目描述
帅帅经常跟同学玩一个矩阵取数游戏：对于一个给定的n×m的矩阵，矩阵中的每个元素a_{i,j}均为非负整数。游戏规则如下：

每次取数时须从每行各取走一个元素，共nn个。经过mm次后取完矩阵内所有元素；
每次取走的各个元素只能是该元素所在行的行首或行尾；
每次取数都有一个得分值，为每行取数的得分之和，每行取数的得分 = 被取走的元素值 × 2^i其中ii表示第ii次取数（从11开始编号）；
游戏结束总得分为mm次取数得分之和。
帅帅想请你帮忙写一个程序，对于任意矩阵，可以求出取数后的最大得分。

输入输出格式
输入格式：
输入文件包括n+1n+1行：

第11行为两个用空格隔开的整数nn和mm。

第2\backsim n+12∽n+1行为n \times mn×m矩阵，其中每行有mm个用单个空格隔开的非负整数。

输出格式：
输出文件仅包含11行，为一个整数，即输入矩阵取数后的最大得分。

输入输出样例
输入样例#1：
2 3
1 2 3
3 4 2
输出样例#1：
82
*/