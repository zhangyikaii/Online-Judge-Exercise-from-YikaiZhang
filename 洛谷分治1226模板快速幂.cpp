#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
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

// 以下是纯的快速幂函数
// 把 b 分解成二进制表示, 这一位上有 1 再乘到 ans 上
int QuickPower(int a, int b)    // 是求a的b次方
{
	int ans = 1, base = a;		// ans为答案，base为a^(2^n)
	while (b > 0)				// b是一个变化的二进制数，如果还没有用完 移位移动完
	{
		// 这一位有 1 => 乘到 ans 上
		if (b & 1)				// &是位运算，b&1表示b在二进制下最后一位是不是1，如果是：
			ans *= base;		// 把ans乘上对应的a^(2^n)

		base *= base;			// base自乘，由a^(2^n)变成a^(2^(n+1)), 记住base = a^(二进制表示中每一位值) 时刻准备乘到ans上, 只要这一位有 1 即可
		b >>= 1;				// 位运算，b右移一位，如101变成10（把最右边的1移掉了），10010变成1001。现在b在二进制下最后一位是刚刚的倒数第二位。结合上面b & 1食用更佳
	}
	return ans;
}
int c;

// 以下是带取模的
int QuickPowerMod(int a, int b)   
{
	int ans = 1, base = a;		
	while (b > 0) {
		if (b & 1) {
			ans *= base;
			ans %= c;
		}

		base *= base;	
		b >>= 1;		
	}
	return ans;
}



int main() {
	int a = read(), b = read();
	c = read();

	printf("%d^%d mod %d=%d\n", a, b, c, QuickPowerMod(a, b));

	return 0;
}

/*

让计算机很快地求出a^b

暴力相乘的话，电脑要计算 b 次。用快速幂，计算次数在 log_2(b) 级别，很实用。

*/