// 这题解是本蒟蒻看了朱羿恺凭栏等大佬的才写出来的 主要思路差不多主要是细节的解释给我们这种蒟蒻看的


// dp f[i]为拼i所需的最少数的个数 状态转移方程：f[i]:=min(f[i],f[j-a[i]]+1), 就是没有用 a[i](前面) 和 用了a[i](后面), 边界：f[0]:=0;
// 这和背包问题很像啊啊啊

// dfs 搜索数的种数，每次取数取从上次取的数+1到之前取的数能拼到的最大+1,并通过dp求出如今所能取到得最大值

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[17], n, k, ans[17], maxn;// a[]表示这种方法的邮票，ans[]表示如今取得的解即要输出的

// 关键点:
// 1. 动规寻找最大连续数
// 2. dfs 的上界不能比 **最大连续值** + 1 还大

// 返回的是最大能拼出的钱数(总面值)
// 只是计算, 没用更改任何东西
int dp(int t, int mx) {
	int f[50000];// f[i]为拼i所需的最少数的个数
	f[0] = 0;// 边界
	for (int i = 1; i <= a[t] * n; i++)
		f[i] = 50000;// 赋初值赋一个尽可能地大就可以了

	// 每一个(i) 拿出来, 看看要不要这个
	for (int i = 1; i <= t; i++) {            // 从第一位找到目前的位数把所有已找的邮票都枚举
		// 当前如果全部用 a[t], 就可以拼出 a[t] * n 张.
		for (int j = a[i]; j <= a[t] * n; j++)   // 因为不可能找到比自己小的数，所以从自己开始找 
			f[j] = min(f[j], f[j - a[i]] + 1);    // 比较上几次已找到的最小需要位数和即将要找的相比较，取较小值 
	}
	for (int i = 1; i <= a[t] * n; i++) {
		// 如果所需最小的个数大于n就意味着这种情况不符合，但f[i-1]是符合的, 不然f[i-1]就会判断所以不符合返回i-1, 就像break 一样.
		if (f[i] > n)
			return i - 1;
	}
	return a[t] * n;	// 如果到 a[t] * n 的 f[i] 都满足意味着能取到的最大连续数就是 a[t] * n
}

// 注意 mx 作用 会不断更新的.
// 为什么全部找完: 因为多几张邮票肯定比少几张邮票可能的情况多，所以全部找完是最好的  
// mx 当前最大的能连续到的数
void dfs(int t, int mx) {
	if (t == k + 1) {	// 如果所有邮票数已经找完，那么就和 maxn比较谁更大   
		if (mx > maxn) {
			maxn = mx;
			for (int i = 1; i <= t - 1; i++)
				ans[i] = a[i];
		} // 保存所需要的邮票面值  
		return;
	}

	for (int i = a[t - 1] + 1; i <= mx + 1; i++) {  // 继续找：为了避免重复，下一张邮票要比上一张邮票大，所以上边界是a[t-1]+1，同时它不能比 **最大连续值** + 1 还大，不然最大连续值的下一个数就永远连不起来了
		// 仔细体会: 同时不能比 **最大连续值** + 1 还大，不然最大连续值的下一个数就永远连不起来了
		a[t] = i;
		int x = dp(t, mx);   // 动归寻找此时的最大连续数(总面值)
		dfs(t + 1, x);
	}
}
int main() {
	cin >> n >> k;
	dfs(1, 0);  // 先从第一张开始找，第一张前面没有数，所以所连续的最大数为 0.
	for (int i = 1; i <= k; i++)// 输出 注意打空格以及大写换行即可
		cout << ans[i] << " ";
	cout << endl;
	cout << "MAX=" << maxn << endl;
	return 0;
}

//  理解一下答案吧 Orz

// #include <iostream> 
// #include <cstdio> 
// #include <algorithm> 
// #include <cstring>
// #include <cmath>
// #include <cstdlib>
// using namespace std;
// 
// #define in(x) x=read()
// 
// inline int read() {
// 	int X = 0, w = 1;
// 	char ch = getchar();
// 	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
// 	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
// 	return X*w;
// }
// 
// int MyMin(int a, int b) {
// 	return a > b ? b : a;
// }
// 
// void Swap(int arr[], int i, int j) {
// 	if (i == j)
// 		return;
// 
// 	arr[i] = arr[i] ^ arr[j];
// 	arr[j] = arr[i] ^ arr[j];
// 	arr[i] = arr[i] ^ arr[j];
// }
// 
// int main() {
// 
// 
// 	return 0;
// }


/*

题目描述
给定一个信封，最多只允许粘贴NN张邮票，计算在给定KK（N+K≤15N+K≤15）种邮票的情况下（假定所有的邮票数量都足够），如何设计邮票的面值，能得到最大值MAXMAX，使在11至MAXMAX之间的每一个邮资值都能得到。

例如，N=3N=3，K=2K=2，如果面值分别为11分、44分，则在11分～66分之间的每一个邮资值都能得到（当然还有88分、99分和1212分）；如果面值分别为11分、33分，则在11分～77分之间的每一个邮资值都能得到。可以验证当N=3N=3，K=2K=2时，77分就是可以得到的连续的邮资最大值，所以MAX=7MAX=7，面值分别为11分、33分。

输入输出格式
输入格式：
22个整数，代表NN，KK。

输出格式：
22行。第一行若干个数字，表示选择的面值，从小到大排序。

第二行，输出“MAX=SMAX=S”，SS表示最大的面值。

输入输出样例
输入样例#1：
3 2
输出样例#1：
1 3
MAX=7

*/