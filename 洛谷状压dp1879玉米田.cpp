#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
#define in(a) a=read()
#define N 1005
#define mod 10007

using namespace std;
const int M = 1e9;
int m, n, f[13][4096], F[13], field[13][13];
// max state: (11111111111)2 = (4095)10
bool state[4096];
int main()
{
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++)
			cin >> field[i][j];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++)
			F[i] = (F[i] << 1) + field[i][j];						// 把可不可以放草地的标志转化为每行二进制表示
	}

	// F[i]: state on line i
	int MAXSTATE = 1 << n;
	for (int i = 0; i < MAXSTATE; i++)
		state[i] = ((i & (i << 1)) == 0) && ((i & (i >> 1)) == 0);	// 存了所有状态是否满足1不相邻条件
	f[0][0] = 1;

	// f[i][j] 表示: 在第 i 行, 放 j 状态的方案数		// 动规!!! 所以这是最优子结构, 就是第 i 行之前也算的所有结果
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < MAXSTATE; j++) {
			// 在第 i 行, 如果当前状态 j(01序列) 1. 满足1不相邻, 2. 满足不在不能种草的地方, 这个只是本行需要满足的条件.
			if (state[j] && ((j & F[i]) == j)) {
				// 找上一行所有可以满足下一行的状态, 开始推了
				for (int k = 0; k < MAXSTATE; k++) {
					if ((k & j) == 0) {
						f[i][j] = (f[i][j] + f[i - 1][k]) % M;
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < MAXSTATE; i++)
		ans += f[m][i], ans %= M;
	cout << ans << endl;
	return 0;
}


//
//struct Data {
//	int arr[13];
//	Data() {
//		for (int i = 0; i < 13; ++i)
//			arr[i] = 0;
//	}
//};
//
//inline int read() {
//	int X = 0, w = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X*w;
//}
//
//// 主要问题: 给定一行的确定选择, 比如010100, 可以确定在这种选择下的下一行选择个数.
//int m, n, canDo[15][15];
//
//int main() {
//	in(m);
//	in(n);
//
//	for (int i = 1; i <= m; ++i) {
//		for (int k = 1; k <= n; ++k) {
//			in(canDo[i][k]);
//		}
//	}
//
//
//
//
//	return 0;
//}

/*
农场主John新买了一块长方形的新牧场，这块牧场被划分成M行N列(1 ≤ M ≤ 12; 1 ≤ N ≤ 12)，每一格都是一块正方形的土地。John打算在牧场上的某几格里种上美味的草，供他的奶牛们享用。

遗憾的是，有些土地相当贫瘠，不能用来种草。并且，奶牛们喜欢独占一块草地的感觉，于是John不会选择两块相邻的土地，也就是说，没有哪两块草地有公共边。

John想知道，如果不考虑草地的总块数，那么，一共有多少种种植方案可供他选择？（当然，把新牧场完全荒废也是一种方案）

输入输出格式
输入格式：
第一行：两个整数M和N，用空格隔开。

第2到第M+1行：每行包含N个用空格隔开的整数，描述了每块土地的状态。第i+1行描述了第i行的土地，所有整数均为0或1，是1的话，表示这块土地足够肥沃，0则表示这块土地不适合种草。

输出格式：
一个整数，即牧场分配总方案数除以100,000,000的余数。

输入输出样例
输入样例#1：
2 3
1 1 1
0 1 0
输出样例#1：
9


*/