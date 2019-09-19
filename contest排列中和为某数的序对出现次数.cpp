#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
using namespace std;

#define in(x) x=read()

#define FOR(i, n) for(int i = 0; i < n; ++i)

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

// beg: 2019年4月28日19:09:46
// end: 2019年4月28日19:40:18

int n, k, arr[100010] = { 0 }, mapp[100010] = { 0 };
ll res = 0;

int main() {
	in(n);
	in(k);
	FOR(i, n) {
		in(arr[i]);
	}

	FOR(i, n) {
		mapp[arr[i]]++;
	}

	FOR(i, n) {
		if (mapp[arr[i]] != 0) {
			if (arr[i] == k - arr[i]) {
				res += mapp[arr[i]] * (mapp[arr[i]] - 1) / 2;
			}
			else {
				res += mapp[arr[i]] * mapp[k - arr[i]];
			}
			mapp[arr[i]] = 0;
		}
	}

	cout << res << endl;

	return 0;
}


/*

链接：https://ac.nowcoder.com/acm/contest/637/B
来源：牛客网

题目描述
在张老师的学生中，每一名同学都有一个能力值。现在张老师想挑选一个两人小组，他有个奇怪的要求，
需要这两名同学的能力值加起来和张老师一个期望的值一样，现在请你帮忙计算他有多少种挑选学生组成小组的方式，注意不同学生能力值可能相同。
输入描述:
第一行一个整数n(2<=n<=100000)和一个整数t(1<=t<=100000), 表示张老师学生的个数和他期望的值，
接下来一行有n个非负整数，第i个非负整数表示第i名学生的能力值，其中每名学生的能力值都不会超过t。
输出描述:
输出一行，表示张老师能挑选出的小组的方案数
示例1
输入
复制
4 5
2 3 3 2
输出
复制
4
说明
可以选择的方式有(1,2),(1,3),(2,4),(3,4)共4种
示例2
输入
复制
5 4
2 2 2 2 2
输出
复制
10

*/