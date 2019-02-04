#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;
#define For(i, n, m) for(ll i = n;i < m; ++i)
#define ll long long

inline ll read() {
	char curNumUsed;
	ll k = 0, base = 1;
	while ((curNumUsed = getchar()) != '-' && curNumUsed != EOF&&!(curNumUsed >= '0'&&curNumUsed <= '9'));
	if (curNumUsed == EOF)exit(0);
	if (curNumUsed == '-')base = -1, curNumUsed = getchar();
	while (curNumUsed >= '0'&&curNumUsed <= '9')
	{
		k = k * 10 + (curNumUsed - '0');
		curNumUsed = getchar();
	}
	return k * base;
}

using namespace std;
int f[1001], p, res[1001], sav[1001];//乘法要开两倍长度
void result_1() {
	memset(sav, 0, sizeof(sav));
	for (register int i = 1; i <= 500; i += 1) {
		for (register int j = 1; j <= 500; j += 1)
			sav[i + j - 1] += res[i] * f[j];//先计算每一位上的值（不进位）
	}
	for (register int i = 1; i <= 500; i += 1) {
		sav[i + 1] += sav[i] / 10;//单独处理进位问题，不容易出错
		sav[i] %= 10;
	}
	memcpy(res, sav, sizeof(res));//cstring库里的赋值函数，把sav的值赋给res
}

void result_2()//只是在result_1的基础上进行了细微的修改
{
	memset(sav, 0, sizeof(sav));
	for (register int i = 1; i <= 500; i += 1) {
		for (register int j = 1; j <= 500; j += 1)
			sav[i + j - 1] += f[i] * f[j];
	}
	for (register int i = 1; i <= 500; i += 1) {
		sav[i + 1] += sav[i] / 10;
		sav[i] %= 10;
	}
	memcpy(f, sav, sizeof(f));
}
int main()
{
	scanf("%d", &p);
	printf("%d\n", (int)(log10(2)*p + 1));
	res[1] = 1;
	f[1] = 2;//高精度赋初值

	//快速幂模板
	while (p != 0) {
		if (p % 2 == 1)
			result_1();
		p /= 2;
		result_2();
	}
	res[1] -= 1;
	for (register int i = 500; i >= 1; i -= 1)//注意输出格式，50个换一行，第一个不用
	if (i != 500 && i % 50 == 0)
		printf("\n%d", res[i]);
	else 
		printf("%d", res[i]);
	return 0;
}

// 真是很烦高精度的题了!

/*
形如2^{P}-12的素数称为麦森数，这时P一定也是个素数。但反过来不一定，即如果P是个素数，2^{P}-12 不一定也是素数。

输入格式：
文件中只包含一个整数 P （1000<P<3100000）

输出格式：
第一行：十进制高精度数 2^{P}-12 的位数。

第2-11行：十进制高精度数 2^{P}-12 的最后 500 位数字。（每行输出50位，共输出10行，不足500位时高位补0）

不必验证 2^{P}-12 与 P 是否为素数。

输入:
1279

输出:
386
00000000000000000000000000000000000000000000000000
00000000000000000000000000000000000000000000000000
00000000000000104079321946643990819252403273640855
38615262247266704805319112350403608059673360298012
23944173232418484242161395428100779138356624832346
49081399066056773207629241295093892203457731833496
61583550472959420547689811211693677147548478866962
50138443826029173234888531116082853841658502825560
46662248318909188018470682222031405210266984354887
32958028878050869736186900714720710555703168729087

*/