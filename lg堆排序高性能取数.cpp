//#include <iostream> 
//#include <cstdio> 
//#include <algorithm> 
//#include <cstring>
//#include <cmath>
//#include <cstdlib>
//#include <string>
//
//using namespace std;
//
//#define in(x) x=read()
//
//#define MAXN 1000000
//
//typedef long long ll;
//
//
//inline int read() {
//	int X = 0, w = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X*w;
//}
//
//int n, m, k;
//
//int main() {
//	in(n);
//	in(m);
//	in(k);
//
//	for (int i = 1; i <= n; ++i) {
//		for (int k = 1; k <= m; ++k) {
//
//		}
//	}
//	
//
//	return 0;
//}
//
//
///*
//
//题目描述
//在一个n行m列的数阵中，你须在每一行取一个数（共n个数），并将它们相加得到一个和。对于给定的数阵，请你输出和前k小的取数方法。
//
//输入输出格式
//输入格式：
//第一行，三个数n,m,k。
//
//第2~n+1行，每行m个正整数
//
//输出格式：
//一行共k个数，代表在每一行取一个数前k小的加和
//
//输入输出样例
//输入样例#1：
//3 3 2
//1 2 3
//6 3 5
//4 1 2
//输出样例#1：
//5 6
//
//
//*/