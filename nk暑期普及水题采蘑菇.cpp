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

int arr[100010];

// 注意水题是因为每次增加蘑菇的操作只能用一次.

int main() {
	int n, maxx = -1, res = 0;
	in(n);

	For(i, 0, n) {
		in(arr[i]);

		if ((arr[i] & 0x1) == 1) {
			if (maxx < arr[i])
				maxx = arr[i];
		}
		else {
			res += arr[i];
		}
	}
	res += maxx + 1;

	printf("%d\n", res);


	return 0;
}


/*
链接：https://ac.nowcoder.com/acm/contest/926/A
来源：牛客网

题目描述
cdd正在魔法森林里采蘑菇。

在这片森林中有\ n n个蘑菇采集点，其中第\ i i个采集点有\ a_{i} a
i
​
 个蘑菇。
cdd初始没有蘑菇，他将会按编号从小到大的顺序经过这\ n n个采集点。当他经过某个采集点时:
如果他当前所拥有的蘑菇数量与该采集点的蘑菇数量之和为偶数，他将得到该采集点的所有蘑菇.
如果为奇数，他会忽略该采集点。
现在cdd可以在采蘑菇前使用一次魔法任选一个采集点并使其蘑菇数量增加1，当然也可以不使用。问在最优策略下cdd最多能获得多少蘑菇？
请注意使用魔法增加的一个蘑菇如果被cdd获得那么也算在答案内。
输入描述:
第一行一个整数\ n n，采集点的数量。

第二行\ n n个整数—其中第\ i i个整数代表第\ i i个采集点的蘑菇数量。

输出描述:
一行一个整数—在最优策略下cdd能获得的最大蘑菇数量。
示例1
输入
复制
3
2 2 2
输出
复制
6
说明
不使用魔法可以得到最大数量(2+2+2)。
示例2
输入
复制
2
1 1
输出
复制
2
说明
对任意一个采集点使用魔法可以得到最大数量(0+2或2+0)。



*/