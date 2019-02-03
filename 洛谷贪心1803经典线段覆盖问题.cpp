#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;
#define For(i, n, m) for(int i = n;i < m; ++i)

struct Data {
	int beg, end;
	bool operator >(Data a) {
		if (a.end == this->end) {
			return this->beg > a.beg;
		}
		return this->end > a.end;
	}

	bool operator <(Data a) {
		if (a.end == this->end) {
			return this->beg < a.beg;
		}
		return this->end < a.end;
	}
};

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

Data arr[1000010];

// 线段覆盖贪心问题!!!
// 按照结束时间从小到大排序!!! 理解一下, 其实不难, 次排序为开始时间
int main() {
	int n = read();
	For(i, 0, n) {
		arr[i].beg = read();
		arr[i].end = read();
	}

	sort(arr, arr + n);

	int curBef = 0, res = 1;
	For(i, 1, n) {
		if (arr[i].beg >= arr[curBef].end) {
			++res;
			curBef = i;
		}
	}

	cout << res << endl;

	return 0;
}

/*
输入格式：
第一行是一个整数n ，接下来n行每行是2个整数ai,bi(ai<bi)，表示比赛开始、结束的时间。

输出格式：
一个整数最多参加的比赛数目。

3
0 2
2 4
1 3
2
*/