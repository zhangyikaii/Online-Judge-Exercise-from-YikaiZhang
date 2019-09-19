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

int n, d;
int res = 0;
// 这么大的范围估计要在线算法.

int myabs(int a) {
	return a > 0 ? a : -a;
}

int main() {
	in(n);
	in(d);
	int tmp = 0, bef = 0;
	For(i, 0, n) {
		in(tmp);
		if (i != 0) {
			res = (res + myabs(tmp - bef)) % d;
		}
		bef = tmp;
	}

	printf("%d\n", res);

	return 0;
}

/*

链接：https://ac.nowcoder.com/acm/contest/934/A
来源：牛客网

输入描述:
第一行，两个数，n,d
第二行，n个数，第i个数代表a_i

输出描述:
一行，一个数，表示\sum\limits_{i=2}^n |a_i-a_{i-1}|最小值

示例1
输入
复制
4 3
1 7 8 1
输出
复制
2


*/