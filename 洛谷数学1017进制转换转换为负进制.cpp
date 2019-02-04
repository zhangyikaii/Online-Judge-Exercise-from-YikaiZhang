#include<cstdio>
using namespace std;
int d2b(int n, int b, char c[])
{
	int i = 0, k;
	while (n != 0) {
		k = n % b;
		n /= b;
		// 负进制就在这里多加了, 这里是负进制的重点
		// 如果是负数了, 就是商加一, 余数相应扣掉除数即可
		if (k < 0) {
			k -= b; n += 1; 
		}
		// 开始转换
		if (k > 9)
			c[i] = char(k - 10 + 'A');     // 注意转为char 类型
		else 
			c[i] = char(k + '0');
		i++;
	}
	return i - 1;
}

int main()
{
	int a, n, i;
	char b[40];
	scanf("%d %d", &a, &n);
	printf("%d=", a);
	if (a == 0)
		printf("0");

	for (i = d2b(a, n, b); i >= 0; i--)
		printf("%c", b[i]);

	printf("(base%d)", n);
}
/*
转换实例:
110001=1×(−2)^5+1×(−2)^4+0×(−2)^3+0×(−2)^2+0×(−2)^1+1×(−2)^0

输入:
30000 -2

输出:
30000=11011010101110000(base-2)

-20000 -2

-20000=1111011000100000(base-2)
*/