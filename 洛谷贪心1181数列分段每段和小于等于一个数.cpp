#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
#define For(i, n, m) for(int i = n;i < m; ++i)

inline int read() {
	char s;
	int k = 0, base = 1;
	while ((s = getchar()) != '-' && s != EOF&&!(s >= '0'&&s <= '9'));
	if (s == EOF)exit(0);
	if (s == '-')base = -1, s = getchar();
	while (s >= '0'&&s <= '9')
	{
		k = k * 10 + (s - '0');
		s = getchar();
	}
	return k*base;
}

int main() {
	int n = read(), m = read();
	int tmp, cur = 0, res = 0;
	For(i, 0, n) {
		tmp = read();
		// 还可以继续分段
		// 仔细啊啊啊 注意分段时候刚好等于 m, 这一个数是要算在这一段里面的; 如果大于 m, 这一个数是要算在下一段里面的!!!
		if (tmp + cur <= m) {
			cur += tmp;
		}
		else {
			++res;
			cur = tmp;
		}
	}

	++res;       // 所有情况都是留下符合条件的一段, (要么等于m, 要么小于m)          

	cout << res << endl;

	return 0;
}

/*
例如有 3 种果子，数目依次为 1 ， 2 ， 9 。可以先将 1 、 2 堆合并，新堆数目为 3 ，耗费体力为 3 。接着，将新堆与原先的第三堆合并，又得到新的堆，数目为 12 ，耗费体力为 12 。所以多多总共耗费体力 = 3+12=15 。可以证明 15 为最小的体力耗费值。

其实是堆排序的一道题, 注意注意每时每刻都是取最小的那两个堆, 只取最小/大而不管其他的, 就用堆做!!!
*/

// 1 2 3 4
// (1 + 2) + (1 + 2 + 3) + (1234)
