#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(int i = s; i < n; ++i)

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

// beg: 2019年5月3日21:12:56
// end: 

int arr[5050] = { 0 };
int main() {
	string a;
	vector<int> v;
	cin >> a;

	int n = a.size();
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 'A') {
			v.push_back(i);
			arr[i] = arr[i - 1];
			continue;
		}
		
		if (i != 0 && a[i] == 'Q') {
			arr[i] = arr[i - 1] + 1;
		}
		else if (i == 0 && a[i] == 'Q')
			arr[i] = 1;
		else {
			arr[i] = arr[i - 1];
		}
	}

	int nn = v.size();
	FOR(i, 0, nn) {
		if (v[i] > 1 && v[i] < n - 1)
			res += (ll)(arr[v[i] - 2] * (arr[n - 1] - arr[v[i] + 1]));
	}

	cout << res << endl;

	return 0;
}


/*

链接：https://ac.nowcoder.com/acm/contest/847/A
来源：牛客网

给定一个只包含大写字母的长度为

N
N的字符串

S
S,求

S
S中不含相邻字符且长度为

3
3的"QAQ"子序列个数。
即:
设字符串

S
S的第

i
i个字符为

S
i
Si,求满足下列条件的

<
x
,
y
,
z
>
<x,y,z>三元组个数。

1
≤
x
,
y
,
z
≤
N
1≤x,y,z≤N

x
<
y
−
1
x<y−1

y
<
z
−
1
y<z−1

S
x
=
Sx='Q',

S
y
=
Sy='A',

S
z
=
Sz='Q'

输入描述:
输入仅一行一个字符串

S
S,字符串的长度

N
N满足

(
1
≤
N
≤
5000
)
(1≤N≤5000)。

N
N不会在输入中给出。
保证

S
S中只包含大写字母。
输出描述:
输出一行一个整数--满足条件的三元组个数。
示例1
输入
复制
QQAQQ
输出
复制
1
说明
满足条件的三元组只有一个:

<
1
,
3
,
5
>
<1,3,5>
示例2
输入
复制
QAQAQ
输出
复制
0
示例3
输入
复制
QQHAHAQQAQ
输出
复制
10

*/