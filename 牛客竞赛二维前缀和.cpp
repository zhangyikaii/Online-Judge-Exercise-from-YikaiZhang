#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(int i = s; i <= n; ++i)

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n, m;
ll L, R;

ll a[1010], b[1010];
ll c[1010][1010];

ll q[1010][1010];


ll tmp = 0;
int res = 0;

int main() {
	for (int i = 0; i < 1010; ++i) {
		for (int k = 0; k < 1010; ++k) {
			q[i][k] = 0;
		}
	}
	ios::sync_with_stdio(false);
	cin >> n >> m >> L >> R;
	FOR(i, 1, n) {
		cin >> a[i];
	}
	FOR(i, 1, m) {
		cin >> b[i];
	}

	FOR(i, 1, n) {
		FOR(k, 1, m) {
			c[i][k] = a[i] * b[k];
		}
	}

	q[1][1] = c[1][1];
	FOR(i, 2, n) {
		q[i][1] = c[i][1] + q[i - 1][1];
	}
	FOR(k, 2, m) {
		q[1][k] = c[1][k] + q[1][k - 1];
	}
	FOR(i, 2, n) {
		FOR(k, 2, m) {
			q[i][k] = c[i][k] + q[i - 1][k] + q[i][k - 1] - q[i - 1][k - 1];
		}
	}

	FOR(bi, 0, n - 1) {
		FOR(bk, 0, m - 1) {
			FOR(ei, bi + 1, n) {
				FOR(ek, bk + 1, m) {
					tmp = q[ei][ek] - (q[ei][bk] + q[bi][ek] - q[bi][bk]);
					cout << bi << " " << bk << " " << ei << " " << ek << "   " << tmp << endl;
					if (tmp <= R && tmp >= L) {
						// cout << bi << " " << bk << " " << ei << " " << ek << "   " << tmp << endl;
						++res;
					}
				}
			}
		}
	}

	printf("%d\n", res);
	

	return 0;
}


/*

3 3 6 10
3 2 3
2 3 1


链接：https://ac.nowcoder.com/acm/contest/894/B
来源：牛客网

题目描述
华华用数组a和数组b合成了矩阵c。其中a数组长度为n，b数组长度为m，c是n行m列的矩阵，且c[i][j]=a[i]*b[j]。定义矩阵的权值为矩阵中所有元素的和。然后他想把矩阵送给奕奕。然而他怕奕奕不喜欢。若矩阵的权值小于L,奕奕会讨厌它，因为奕奕不喜欢太小的数字。若矩阵的权值大于R，奕奕会生气因为奕奕不认识比R大的数字。所以奕奕只喜欢权值大于等于L并且小于等于R的矩阵。还好华华学过acm，他马上想到可以送奕奕一个子矩阵，并且他立马写程序从c矩阵中找出了所有奕奕喜欢的子矩阵。你只需要帮他算算这样的子矩阵有多少个即可。
输入描述:
第一行输入n,m,L,R。
第二行n个数表示a数组
第三行m个数表示b数组
1<=n,m<=1000,1<=L<=R<=1e18
1<=a[i],b[i]<=1e6
输出描述:
输出一个数表示子矩阵的个数
示例1
输入
复制
3 3 3 8
3 2 3
2 3 1
输出
复制
10

*/