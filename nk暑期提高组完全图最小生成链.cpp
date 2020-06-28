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


// 输出最小生成链中边权最大的边的权值.

// 称一条生成链是原图的最小生成链，当且仅当该最小生成链中边权最大的边是原图的所有生成链最大边的边权中最小的, 最小生成链的定义是依赖链中的最大边权.

// 因为是完全图, 所以其实就是两两异或之后找出前 n - 1 小的, n 是顶点数.
// 啊啊啊不会做.

int main() {
	

	return 0;
}

/*

*/