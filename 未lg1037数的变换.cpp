//#include <iostream> 
//#include <cstdio> 
//#include <algorithm> 
//#include <cstring>
//#include <cmath>
//#include <cstdlib>
//#include <string>
//
//// 思路就是找出所有变换方案, 有间接变换的, 然后按照规律乘上去, 写高精.
//
//using namespace std;
//
//#define in(x) x=read()
//
//#define MAXN 1000
//
//typedef long long ll;
//
//inline int read() {
//	int X = 0, w = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X*w;
//}
//
//string str;
//int k, a, b, ans = 1;
//int arr[MAXN][MAXN];
//
//int main() {
//	for (int i = 0; i < MAXN; ++i) {
//		for (int k = 0; k < MAXN; ++k) {
//			arr[i][k] = 0;
//		}
//	}
//
//	cin >> str;
//	in(k);
//
//	for (int i = 1; i <= k; ++i) {
//		in(a);
//		in(b);
//		arr[a][b] = 1;
//	}
//
//	for (int i = 1; i < 9; ++i) {
//		for (int j = 1; j <= 9; ++j) {
//			for (int k = i + 1; k < j; ++k) {
//				arr[i][j] = arr[i][j] || (arr[i][k] == 1 && arr[k][j] == 1);
//			}
//		}
//	}
//
//	// 简单的高精加法乘法要熟练一点
//
//	printf("%d\n", ans);
//
//	return 0;
//}
//
//
///*
//题目描述
//给出一个整数n(n<10^{30})n(n<10
//30
//)和 k k个变换规则(k \le 15)(k≤15)。
//
//规则：
//
//一位数可变换成另一个一位数：
//
//规则的右部不能为零。
//
//例如：n=234n=234。有规则（k=2k=2）：
//
//22－>55
//33－>66
//上面的整数234234经过变换后可能产生出的整数为（包括原数）:
//
//234234
//534534
//264264
//564564
//共44 种不同的产生数
//
//问题：
//
//给出一个整数 nn 和 kk 个规则。
//
//求出：
//
//经过任意次的变换（00次或多次），能产生出多少个不同整数。
//
//仅要求输出个数。
//
//输入输出格式
//输入格式：
//键盘输入，格式为：
//
//n knk
//x_1 y_1x
//1
//​	 y
//1
//​
//x_2 y_2x
//2
//​	 y
//2
//​
//... ...
//
//x_n y_nx
//n
//​	 y
//n
//​
//输出格式：
//屏幕输出，格式为：
//
//11个整数（满足条件的个数）：
//
//输入输出样例
//输入样例#1：
//234 2
//2 5
//3 6
//输出样例#1：
//4
//
//*/