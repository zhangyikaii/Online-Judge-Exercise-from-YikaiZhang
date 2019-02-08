// 这题也是抄答案的 理解在笔记里 很不错的模板
#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f
int stone[105];
int dpmin[205][205];// 最小
int dpmax[205][205];// 最大
int sum[205];		// 前缀和 方便求一段的和
int main()
{
	int n;
	scanf("%d", &n);
	memset(sum, 0, sizeof(sum));
	memset(dpmin, INF, sizeof(dpmin));
	memset(dpmax, -1, sizeof(dpmax));
	for (int i = 1; i <= n; i++){
		scanf("%d", &stone[i]);
		sum[i] = sum[i - 1] + stone[i];
		dpmin[i][i] = 0;
		dpmax[i][i] = 0;
	}
	for (int i = 1; i <= n; i++){
		sum[i + n] = sum[i + n - 1] + stone[i];//展开的n后面的n-1~1重量
		dpmin[i + n][i + n] = 0;
		dpmax[i + n][i + n] = 0;
	}
	
	// 最外层循环 枚举分割的区间长度 因为合并不可能合并两圈, 所以长度还是最大n
	for (int len = 1; len <= n; len++) {
		// 接下来起点枚举最大到2*n-1, ends<=2*n-1, 因为要考虑成环, 相当于复制一次链
		for (int j = 1; j + len <= 2 * n; j++) {
			int ends = j + len - 1;
			// 最后枚举分割终点
			for (int i = j; i < ends; i++){	// 注意！i<ends！！！因为i=ends时，dp[ends+1][ends]是不成立的！
				// cout << len << " " << j << " " << i << endl;
				dpmin[j][ends] = min(dpmin[j][ends], dpmin[j][i] + dpmin[i + 1][ends] + sum[ends] - sum[j - 1]);
				dpmax[j][ends] = max(dpmax[j][ends], dpmax[j][i] + dpmax[i + 1][ends] + sum[ends] - sum[j - 1]);
			}
		}
	}
	int ansmin = 0xfffffff;
	int ansmax = -1;
	for (int i = 1; i <= n; i++){
		ansmin = min(ansmin, dpmin[i][i + n - 1]);//找1~n,2~n~1,3~n~2....的合并n个堆的中最大和最小的值
		ansmax = max(ansmax, dpmax[i][i + n - 1]);
	}
	cout << ansmin << endl;
	cout << ansmax << endl;
	return 0;
}

/*
题目描述
在一个圆形操场的四周摆放N堆石子,现要将石子有次序地合并成一堆.规定每次只能选相邻的2堆合并成新的一堆，并将新的一堆的石子数，记为该次合并的得分。

试设计出1个算法,计算出将N堆石子合并成1堆的最小得分和最大得分.

输入输出格式
输入格式：
数据的第1行试正整数N,1≤N≤100,表示有N堆石子.第2行有N个数,分别表示每堆石子的个数.

输出格式：
输出共2行,第1行为最小得分,第2行为最大得分.

*/
