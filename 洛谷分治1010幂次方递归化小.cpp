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
	return k * base;
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

bool isFir = true;

/*
// 以下答案牛逼!!!
// 其实就是分清楚 1的时候不是2(1), 
string run(int x, int i = 0, string s = string("")){
	if (x == 0)
		return string("0");
	do {
		if (x & 1)
			s = (i == 1 ? "2" : "2(" + run(i) + ")") + (s == "" ? "" : "+") + s;
		// 拼接字符串，应题意，要把低次方接在后面, 所以一直都是往前拼东西.
	} while (++i, x >>= 1);	// 每次向右移位
	return s;
}

int main(){
	int x; 
	cin >> x;
	cout << run(x) << endl;
}
*/

// 关键就是把加号放在哪里!!!
void Out(int a) {
	if (a == 0) {
		if (isFir == true)
			isFir = false;
		printf("0");
	}
	else if (a == 1) {
		if (isFir == true)
			isFir = false;
	}
	else if (a == 2) {
		if (isFir == true)
			isFir = false;
		printf("2");
	}

	else {
		int arr[30], ia = 0;
		while (a > 0) {
			if (a & 1)
				arr[ia] = 1;
			else
				arr[ia] = 0;
			++ia;
			a >>= 1;
		}

		isFir = true;
		// 抓住递归子结构, 不断替换掉的是哪一个!
		for (int k = ia - 1; k >= 0; --k) {
			if (arr[k] == 1 && isFir == true) {
				if (k != 1) {
					printf("2(");
					Out(k);
					printf(")");
				}
				else {
					if (isFir == true)
						isFir = false;
					printf("2");
				}
			}
			else if (arr[k] == 1 && isFir == false) {
				printf("+");
				if (k != 1) {
					printf("2(");
					Out(k);
					printf(")");
				}
				else {
					if (isFir == true)
						isFir = false;
					printf("2");
				}
			}
		}
	}
}

int main() {
	int a = read();
	if (a == 1)
		cout << "1" << endl;
	Out(a);

	printf("\n");

	return 0;
}

/*
输入:
137

输出:
2(2(2)+2+2(0))+2(2+2(0))+2(0)

输入:
1315

输出:
2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
*/