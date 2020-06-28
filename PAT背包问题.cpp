#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define in(x) x=read()
#define For(i, a, b) for(int i = a; i < b; ++i)

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}


#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define MAXTOTAL	10001
#define MAXAMOUNT	101

int f[MAXTOTAL][MAXAMOUNT];			//f[n][m]表示前 n 个数(前n个硬币)中得出的最接近 m 的值 注意这里是最接近m的值, 就是如果等于目标值就说明是OK的.
bool has[MAXTOTAL][MAXAMOUNT];		//has[n][m]表示前 n 个数中得出最接近 m 的值时是否用到c[n]
int* c = NULL;						// 放置硬币面值的数组.

int calcClosestSum(int n, int m) {
	memset(f, 0, sizeof(int) * MAXTOTAL * MAXAMOUNT);
	memset(has, false, sizeof(bool) * MAXTOTAL * MAXAMOUNT);
	int i, j;
	int sec; // 表示放入c[i]后的值
	for (i = 1; i < n + 1; i++) {
		for (j = 1; j <= m; j++) {
			if (j - c[i] < 0)
				sec = 0; // 如果不满足小于等于j，则说明放入后是非法值，可以设其为0，表示面值无效。
			else
				sec = f[i - 1][j - c[i]] + c[i]; // 正常情况下计算放入c[i]的值。
			if (f[i - 1][j] > sec) {
				f[i][j] = f[i - 1][j];
			}
			else {
				f[i][j] = sec;
				has[i][j] = true;		//用到c[i]了 设has[i][j]为true 当前 前i个, 放置总面值j情况下这个i有没有选择.
			}
		}
	}
	return f[n][m];
}

// has[][] 就是判断用了什么元素的数组
bool cmp(const int& A, const int& B) {
	return A > B;
}

int main() {
	int n, m;
	cin >> n >> m;

	c = new int[n + 1];
	memset(c, 0, sizeof(int) * (n + 1));

	int i;
	for (i = 0; i < n; i++) {
		cin >> c[i + 1];
	}
	sort(&c[1], &c[n + 1], cmp);		//从大到小排序

	int res = calcClosestSum(n, m);

	// 背包问题记录选择的是哪个就是这种方法: has[] 路由表.
	if (res == m) {		// 有解
		vector<int> v;
		while (m) {
			while (!has[n][m])
				n--;
			v.push_back(c[n]);
			m = m - c[n];
			// 有点像路由表, 当前这个用了, 数组的后面就要减一个 c[当前] 去寻找下一个
			n--;
		}
		for (i = 0; i < v.size() - 1; i++)
			cout << v[i] << ' ';
		cout << v[i] << endl;
	}
	else						//无解
		cout << "No Solution" << endl;

	return 0;
}

//int n, des;
//
//int arr[100010], dp[100010];
//
//// 背包问题, 难在输出最小序列!
//
//int main() {
//	in(n);
//	in(des);
//
//	for (int i = 1; i <= n; ++i) {
//		in(arr[i]);
//	}
//
//	sort(arr + 1, arr + 1 + n);
//
//
//	return 0;
//}

/*

Find More Coins (30)
时间限制 1000 ms 内存限制 65536 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述
Eva loves to collect coins from all over the universe, including some other planets like Mars.  One day she visited a universal shopping mall which could accept all kinds of coins as payments.  However, there was a special requirement of the payment: for each bill, she must pay the exact amount.  Since she has as many as 104 coins with her, she definitely needs your help.  You are supposed to tell her, for any given amount of money, whether or not she can find some coins to pay for it.

输入描述:
Each input file contains one test case.  For each case, the first line contains 2 positive numbers: N (<=104, the total number of coins) and M(<=102, the amount of money Eva has to pay).  The second line contains N face values of the coins, which are all positive numbers.  All the numbers in a line are separated by a space.


输出描述:
For each test case, print in one line the face values V1 <= V2 <= ... <= Vk such that V1 + V2 + ... + Vk = M.  All the numbers must be separated by a space, and there must be no extra space at the end of the line.  If such a solution is not unique, output the smallest sequence.  If there is no solution, output "No Solution" instead.
Note: sequence {A[1], A[2], ...} is said to be "smaller" than sequence  {B[1], B[2], ...} if there exists k >= 1 such that A[i]=B[i] for all i < k, and A[k] < B[k].

输入例子:
8 9
5 9 8 7 2 3 4 1

输出例子:
1 3 5




*/