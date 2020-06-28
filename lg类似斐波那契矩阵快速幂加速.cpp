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

#define FOR(i, s, n) for(ll i = s; i < n; ++i)

typedef long long ll;

inline ll read() {
	ll X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

const ll mod = 1000000007;

// ll res[5][5], arr[5][5];		// 二维数组不好传参! 就定义一个结构体吧..

struct Data {
	ll arra[5][5];
	Data() {
		FOR(i, 0, 5) {
			FOR(k, 0, 5) {
				arra[i][k] = 0;
			}
		}
	}
};


// 注意循环的 k , 矩阵乘法返回相乘的结果吧, 结果和计算分开来比较好弄.
Data mul(Data &res, Data &arr) {
	Data ret;
	FOR(i, 0, 3) {
		FOR(j, 0, 3) {
			FOR(k, 0, 3) {
				ret.arra[i][j] = ret.arra[i][j] % mod + (res.arra[i][k] % mod) * (arr.arra[k][j] % mod);
			}
		}
	}

	return ret;
}

Data quick(const Data ma, ll mi) {
	Data tmp = ma, res;
	FOR(i, 0, 3) {
		res.arra[i][i] = 1;
	}
	while (mi != 0) {
		if ((mi & 1) == 1) {
			res = mul(res, tmp);
		}

		tmp = mul(tmp, tmp);
		mi >>= 1;
	}

	return res;	
}

int main() {
	ios::sync_with_stdio(false);
	ll T, n;
	cin >> T;

	Data ini;
	ini.arra[0][0] = 1;
	ini.arra[0][1] = 1;
	ini.arra[1][2] = 1;
	ini.arra[2][0] = 1;
	while (T--) {
		cin >> n;
		if (n == 1 || n == 2 || n == 3)
			cout << "1" << endl;
		else {
			Data ress = quick(ini, n - 3);
			cout << ((ress.arra[0][0] + ress.arra[1][0]) % mod + ress.arra[2][0] % mod) % mod << endl;
		}
	}


	return 0;
}


/*

题目描述
a[1]=a[2]=a[3]=1

a[x]=a[x-3]+a[x-1] (x>3)

求a数列的第n项对1000000007（10^9+7）取余的值。

输入输出格式
输入格式：
第一行一个整数T，表示询问个数。

以下T行，每行一个正整数n。

输出格式：
每行输出一个非负整数表示答案。

输入输出样例
输入样例#1：
3
6
8
10
输出样例#1：
4
9
19
*/


/*

*/