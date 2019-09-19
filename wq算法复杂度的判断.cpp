#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

#define in(x) x=read()

#define MAXN 10000000

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n, m;

int arr[110] = { 0 }, brr[110] = { 0 };
bool soh = 0, boh = 0, theta = 0, somega = 0, bomega = 0;

int main() {
	in(n);
	in(m);

	for (int i = 1; i <= n; ++i) {
		in(arr[i]);
	}
	for (int i = 1; i <= m; ++i) {
		in(brr[i]);
	}

	for (int i = n, j = m; i >= 0 && j >= 0; --i, --j) {
		if (soh == 0 && arr[i] != 0 && brr[j] == 0)
	}
	

	return 0;
}


/*
给定两个多项式 f(x)=∑i=0n−1aixif(x) = \sum_{i=0}^{n - 1} a_i x^if(x)=∑
​i=0
​n−1
​​ a
​i
​​ x
​i
​​ , g(x)=∑i=0m−1bixig(x) = \sum_{i=0}^{m - 1} b_i x^ig(x)=∑
​i=0
​m−1
​​ b
​i
​​ x
​i
​​

用 Yes 和 No 判定下面 555 个问题:

f(x)=o(g(x))f(x) = \omicron (g(x))f(x)=o(g(x))
f(x)=O(g(x))f(x) = O (g(x))f(x)=O(g(x))
f(x)=Θ(g(x))f(x) = \Theta (g(x))f(x)=Θ(g(x))
f(x)=Ω(g(x))f(x) = \Omega (g(x))f(x)=Ω(g(x))
f(x)=ω(g(x))f(x) = \omega (g(x)) f(x)=ω(g(x))
输入格式
读入 1≤n,m≤1001 \le n, m \le 1001≤n,m≤100.

接下来读入 nnn 个非负整数 a0,a1,⋯,an−1a_0, a_1, \cdots, a_{n - 1}a
​0
​​ ,a
​1
​​ ,⋯,a
​n−1
​​

接下来读入 mmm 个非负整数b0,b1,⋯,bm−1b_0, b_1, \cdots, b_{m - 1}b
​0
​​ ,b
​1
​​ ,⋯,b
​m−1
​​

保证 ai,bia_i, b_ia
​i
​​ ,b
​i
​​  都在 int 范围内, 且 f(x),g(x)f(x), g(x)f(x),g(x) 不恒等于 000.

样例
样例输入 1
4 4
0 0 1 1
1 0 0 1
样例输出 1
No
Yes
Yes
Yes
No
*/
