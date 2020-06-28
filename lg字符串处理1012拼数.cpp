#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

#define in(x) x=read()
#define MAX 100010

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int MyMin(int a, int b) {
	return a > b ? b : a;
}

void Swap(int arr[], int i, int j) {
	if (i == j)
		return;

	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}



int n;
string arr[30];

bool cmp(string a, string b) {
	return a + b > b + a;
}

//int num[30][100];

//void Init() {
//	for (int i = 1; i <= n; ++i) {
//		int tmp = arr[i];
//		num[i][0] = 0;
//		while (tmp != 0) {
//			num[i][++num[i][0]] = tmp % 10;
//			tmp /= 10;
//		}
//	}
//}
//
//// 注意取高位数要怎么取, 这里是用先初始化提取出来了
//int cmp(int a, int b) {
//	int i = num[a][0], j = num[b][0];
//	while (i >= 0 && j >= 0) {
//		if (num[a][i] > num[b][j])
//			return 1;
//		else if (num[a][i] < num[b][j])
//			return -1;
//		--i;
//		--j;
//	}
//	if (i >= 0)
//}

int main() {
	// 注意这里部分的大小关系, 两个数, a 接在 b 前面会更大, 那就是a > b 了
	// 注意字典序可以比大小, 特指string直接比大小, 就很方便.

	in(n);
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	sort(arr + 1, arr + 1 + n, cmp);

	for (int i = 1; i <= n; ++i) {
		cout << arr[i];
	}
	cout << endl;


	
	return 0;
}

/*
题目描述
设有nn个正整数(n≤20)(n≤20)，将它们联接成一排，组成一个最大的多位整数。

例如：n=3n=3时，33个整数1313,312312,343343联接成的最大整数为：3433121334331213
又如：n=4n=4时，44个整数77,1313,44,246246联接成的最大整数为：74246137424613
输入输出格式
输入格式：
第一行，一个正整数nn。

第二行，nn个正整数。

输出格式：
一个正整数，表示最大的整数

输入输出样例
输入样例#1：
3
13 312 343
输出样例#1：
34331213

*/