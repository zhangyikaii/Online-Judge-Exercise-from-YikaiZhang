#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<map>
#define INF 0xfffffff

#define CLR(a,b,Size) memset((a),(b),sizeof((a[0]))*(Size+1))
#define CPY(a,b) memcpy ((a), (b), sizeof((a)))
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

int horseCtrl[10][2] = {
	{-2, -1},
	{-2, 1},
	{-1, -2},
	{-1, 2},
	{1, -2},
	{1, 2},
	{2, -1},
	{2, 1},
};

int mmap[10010][10010], dp[10010][10010];


// 答案错误:您提交的程序没有通过所有的测试用例
int main() {
	int bpx, bpy, hpx, hpy;
	in(bpx);
	in(bpy);
	in(hpx);
	in(hpy);

	For(i, 0, 8) {
		int tx = hpx + horseCtrl[i][0], ty = hpy + horseCtrl[i][1];
		if (tx <= bpx && tx >= 0 && ty <= bpy && ty >= 0) {
			mmap[tx][ty] = 1;   // obstacle.
		}
	}
	
	mmap[hpx][hpy] = 1;			// 马自己的点也要.
	// dp boundary.
	for (int i = 0; i <= bpy; ++i) {
		if (mmap[0][i] != 1)
			dp[0][i] = 1;
		else
			break;
	}
	for (int i = 0; i <= bpx; ++i) {
		if (mmap[i][0] != 1)
			dp[i][0] = 1;
		else				// 注意初始化, 因为有一个障碍之后后面的都不可以了, 就都是 0.
			break;
	}

	// dp.
	for (int i = 1; i <= bpx; ++i) {
		for (int k = 1; k <= bpy; ++k) {
			if (mmap[i][k] == 1)
				dp[i][k] = 0;
			else {
				dp[i][k] = dp[i - 1][k] + dp[i][k - 1];
			}
		}
	}

	//for (int i = 0; i <= bpx; ++i) {
	//	for (int k = 0; k <= bpy; ++k) {
	//		printf("%d\t", mmap[i][k]);
	//	}
	//	printf("\n");
	//}
	//cout << endl << endl;
	//for (int i = 0; i <= bpx; ++i) {
	//	for (int k = 0; k <= bpy; ++k) {
	//		printf("%d\t", dp[i][k]);
	//	}
	//	printf("\n");
	//}

	printf("%d\n", dp[bpx][bpy]);

	return 0;
}


/*

链接：https://ac.nowcoder.com/acm/contest/1077/H
来源：牛客网

题目描述
如图，A 点有一个过河卒，需要走到目标 B 点。卒行走规则：可以向下、或者向右。同时在棋盘上的任一点有一个对方的马（如上图的C点），该马所在的点和所有跳跃一步可达的点称为对方马的控制点。例如上图 C 点上的马可以控制 9 个点（图中的P1，P2 … P8 和 C）。卒不能通过对方马的控制点。

棋盘用坐标表示，A 点（0,0）、B 点（n,m）(n,m 为不超过 20 的整数，并由键盘输入)，同样马的位置坐标是需要给出的（约定: C<>A，同时C<>B）。现在要求你计算出卒从 A 点能够到达 B 点的路径的条数。
输入描述:
输入B点的坐标（n,m）以及对方马的坐标（X,Y）{不用判错}
输出描述:
输出一个整数（路径的条数）。
示例1
输入
复制
6 6 3 2
输出
复制
17

*/