#define N 105
#include<cstdio>
#include<string>
#include<iostream>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
const int tab[5][5] =
{
	{ 5, -1, -2, -1, -3 },
	{ -1, 5, -3, -2, -4 },
	{ -2, -3, 5, -2, -2 },
	{ -1, -2, -2, 5, -1 },
	{ -3, -4, -2, -1, 0 }
};
int la, lb;
std::string sa, sb;
int a[N], b[N];
int dp[N][N];
int main()
{
	std::ios::sync_with_stdio(0);
	std::cin >> la >> sa >> lb >> sb;

	// 初始化为负很大的数 因为配对的权值里面有负数
	for (int i = 1; i <= la; i++) {
		for (int j = 1; j <= lb; j++)
			dp[i][j] = -2e8;
	}
	for (int i = 1; i <= la; i++) {
		if (sa[i - 1] == 'A') 
			a[i] = 0;
		if (sa[i - 1] == 'C')
			a[i] = 1;
		if (sa[i - 1] == 'G') 
			a[i] = 2;
		if (sa[i - 1] == 'T') 
			a[i] = 3;
	}
	for (int i = 1; i <= lb; i++) {
		if (sb[i - 1] == 'A') 
			b[i] = 0;
		if (sb[i - 1] == 'C') 
			b[i] = 1;
		if (sb[i - 1] == 'G')
			b[i] = 2;
		if (sb[i - 1] == 'T') 
			b[i] = 3;
	}

	// 因为当一个碱基序列为0时，就是相当于另一个碱基序列全部和空格对应
	for (int i = 1; i <= la; i++) 
		dp[i][0] = dp[i - 1][0] + tab[a[i]][4];
	for (int i = 1; i <= lb; i++) 
		dp[0][i] = dp[0][i - 1] + tab[b[i]][4];

	// 看笔记里面 四种情况dp
	for (int i = 1; i <= la; i++) {
		for (int j = 1; j <= lb; j++) {
			dp[i][j] = max(dp[i][j], dp[i][j - 1] + tab[b[j]][4]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + tab[a[i]][4]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + tab[a[i]][b[j]]);
		}
	}

	printf("%d", dp[la][lb]);
	return 0;
}

/*
两个基因的相似度的计算方法如下：

对于两个已知基因，例如 AGTGATG 和 GTTAG ，将它们的碱基互相对应。当然，中间可以加入一些空碱基 -，例如：

例如这样配对:
AGTGAT_G
_GT__TAG

那么相似度就是： (-3)+5+5+(-2)+(-3)+5+(-3)+5=9 。因为两个基因的对应方法不唯一

规定两个基因的相似度为所有对应方法中，相似度最大的那个。


输入输出格式
输入格式：

共两行。每行首先是一个整数，表示基因的长度；隔一个空格后是一个基因序列，序列中只含 A,C,G,T 四个字母。 1 ≤ 序列的长度 ≤100 。

输出格式：

仅一行，即输入基因的相似度。

输入样例#1：

7 AGTGATG
5 GTTAG

输出样例#1：

14


*/