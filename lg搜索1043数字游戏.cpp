// #include <iostream> 
// #include <cstdio> 
// #include <algorithm> 
// #include <cstring>
// #include <cmath>
// #include <cstdlib>
// 
// using namespace std;
// 
// #define in(x) x=read()
// 
// #define MAXN 130
// 
// typedef long long ll;
// 
// inline int read() {
// 	int X = 0, w = 1;
// 	char ch = getchar();
// 	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
// 	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
// 	return X*w;
// }
// 
// int mod(int a) {
// 	while (a < 0) {
// 		a += 10;
// 	}
// 
// 	return a % 10;
// }
// 
// int MyMin(int a, int b) {
// 	return a > b ? b : a;
// 	//  下面是答案的写法, 这样避免取模为负数很不错, 就是多模一次.
// 	//  return ((a % 10) + 10) % 10;
// }
// 
// //  搜索真的差啊小鬼 好好练啊...
// // 
// // int n, m, arr[MAXN] = { 0 };
// // bool used[MAXN];
// // int maxAns = -1, minAns = 0x7ffffff;
// // 
// 
// // 
// // //  对于环上的dfs该怎么处理???
// // //  每个节点都要跑一遍
// // //  环上还是dp比较多哇
// // void dfs(int curUsedNum, int dividePart, int curAns, int pre) {
// // 	if (n - curUsedNum == m - dividePart) {
// // 		for (int i = pre; used[i] == false; ++i) {
// // 			curAns += mod(arr[i]);
// // 		}
// // 		dividePart = m;
// // 	}
// // 	//  没得分了.
// // 	else if (n - curUsedNum < m - dividePart) {
// // 		return;
// // 	}
// // 
// // 	if (dividePart == m) {
// // 		if (curAns > maxAns)
// // 			maxAns = curAns;
// // 		else if (curAns < minAns)
// // 			minAns = curAns;
// // 
// // 		return;
// // 	}
// // 	
// // 	for (int i = 1; n - (curUsedNum + i) > m - dividePart; ++i) {
// // 
// // 	}
// // }
// 
// int n, m, arr[MAXN] = { 0 };
// int dp[MAXN][MAXN];
// 
// int main() {
// 	for (int i = 0; i < MAXN; ++i) {
// 		for (int k = 0; k < MAXN; ++k) {
// 			dp[i][k] = 0x7ffffff;
// 		}
// 	}
// 	in(n);
// 	in(m);
// 
// 	for (int i = 0; i < n; ++i) {
// 		in(arr[i]);
// 		arr[i + n] = arr[i];
// 	}
// 
// 	for (int i = 0; i <= n; ++i) {
// 		dp[i][i + 1] = mod(arr[i]);
// 	}
// 
// 	//  注意区间端点问题!!! 到底是放在数字上还是放在间隔上, 这样设置中间的 j 就是端点要放在间隔上.
// 	//  这样一个环的就是复制两遍数组.
// 	for (int i = 0; i < 2 * n; ++i) {
// 		//  dp[i][i] = mod(arr[i]);
// 		for (int k = 0; k < 2 * n; ++k) {
// 			for (int j = i + 1; j < k; ++j) {
// 				int ti = i % n, tk = k % n, tj = j % n;
// 				//  printf("%d & %d = %d & %d + %d & %d\n", i % n, k % n, i % n, j % n, j % n, k % n);
// 				dp[ti][tk] = MyMin(dp[ti][tk], dp[ti][tj] + dp[tj][tk]);
// 			}
// 		}
// 	}
// 
// 	for (int i = 0; i < n; ++i) {
// 		for (int k = 0; k < n; ++k)
// 			printf("%d ", dp[i][k]);
// 		printf("\n");
// 	}
// 
// 	
// 
// 	return 0;
// }

#include<cstdio>
#include<algorithm>
#include<cstring>
#define oo 2147483647// 是个好习惯，使程序显得有条理一点 
using namespace std;
int B[101][101][11], S[101][101][11];// 区间[l,r]内分成i段的最大/小值 
int n, m;
int a[101];// a存放前缀和 
int mod(int a)// 写成函数方便一点 
{
	return ((a % 10) + 10) % 10;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		a[i + n] = a[i];
	}
	for (int i = 1; i <= 2 * n; i++)
		a[i] += a[i - 1];// 前缀和 
	for (int l = 1; l <= 2 * n; l++)
	for (int r = l; r <= 2 * n; r++)
		B[l][r][1] = S[l][r][1] = mod(a[r] - a[l - 1]);// 初始化不分段的状态 


	for (int i = 2; i <= m; i++)
	for (int l = 1; l <= 2 * n; l++)
	for (int r = l + i - 1; r <= 2 * n; r++)
		S[l][r][i] = oo;// 求最小值时记得把数组初始化为极大值 


	for (int i = 2; i <= m; i++) { // 枚举分段数
		for (int l = 1; l <= 2 * n; l++) {// 枚举左端点
			for (int r = l + i - 1; r <= 2 * n; r++) { // 枚举右端点
				for (int k = l + i - 2; k < r; k++) { // 枚举区间断点 注意范围
					// 这里又是 a[r] - a[k] 了
					S[l][r][i] = min(S[l][r][i], S[l][k][i - 1] * mod(a[r] - a[k]));
					B[l][r][i] = max(B[l][r][i], B[l][k][i - 1] * mod(a[r] - a[k]));
				}
			}
		}
	}
	int Max = 0, Min = oo;//  答案初始化 
	for (int i = 1; i <= n; i++) {
		Max = max(Max, B[i][i + n - 1][m]);		//  从前往后扫一遍 
		Min = min(Min, S[i][i + n - 1][m]);
	}
	printf("%d\n%d", Min, Max);
	return 0;
}


/*

题目描述
丁丁最近沉迷于一个数字游戏之中。这个游戏看似简单，但丁丁在研究了许多天之后却发觉原来在简单的规则下想要赢得这个游戏并不那么容易。游戏是这样的，在你面前有一圈整数（一共nn个），你要按顺序将其分为mm个部分，各部分内的数字相加，相加所得的mm个结果对1010取模后再相乘，最终得到一个数kk。游戏的要求是使你所得的k最大或者最小。

例如，对于下面这圈数字（n=4,m=2n=4,m=2）：



要求最小值时，((2-1) \bmod 10)×((4+3) \bmod 10)=1×7=7((2−1)mod10)×((4+3)mod10)=1×7=7，要求最大值时，为((2+4+3) \bmod 10)×(-1 \bmod 10)=9×9=81((2+4+3)mod10)×(−1mod10)=9×9=81。特别值得注意的是，无论是负数还是正数，对1010取模的结果均为非负值。

丁丁请你编写程序帮他赢得这个游戏。

输入输出格式
输入格式：
输入文件第一行有两个整数，n(1≤n≤50)n(1≤n≤50)和m(1≤m≤9)m(1≤m≤9)。以下nn行每行有个整数，其绝对值 \le 10^4≤10
4
，按顺序给出圈中的数字，首尾相接。

输出格式：
输出文件有22行，各包含11个非负整数。第11行是你程序得到的最小值，第22行是最大值。

输入输出样例
输入样例#1：
4 2
4
3
-1
2
输出样例#1：
7
81

*/