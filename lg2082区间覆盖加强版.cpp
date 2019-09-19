#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;
typedef long long ll;

struct Data {
	ll a, b;
};

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int MyMin(int a, int b) {
	return a > b ? b : a;
}

void Swap(int arr[], int i, int j) {
	if (i == j)
		return;

	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}

const int MAXN = 1e5 + 5;

Data arr[MAXN]; 
int n;


bool cmp(Data x, Data y) {
	if (x.a == y.a)
		return x.b < y.b;
	return x.a < y.a;
}

int main() {
	in(n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &arr[i].a);
		scanf("%lld", &arr[i].b);
	}

	sort(arr + 1, arr + 1 + n, cmp);

	ll curBeg = arr[1].a, curEnd = arr[1].b, ans = 0;

	for (int i = 2; i <= n; ++i) {
		if (arr[i].a > curEnd) {
			ans += (curEnd - curBeg + 1);
			curBeg = arr[i].a;
			curEnd = arr[i].b;
		}
		else {
			// 注意注意这里的限制, 只有r更大了才更新!!!
			if (arr[i].b > curEnd)
				curEnd = arr[i].b;
		}
	}
	ans += (curEnd - curBeg + 1);

	printf("%lld\n", ans);

	
	return 0;
}


/*

题目描述
已知有N个区间，每个区间的范围是[si,ti]，请求出区间覆盖后的总长。

输入输出格式
输入格式：
N s1 t1 s2 t2 …… sn tn

输出格式：
共一行，一个正整数，为覆盖后的区间总长。

*/