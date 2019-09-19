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

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

// beg: 2019年4月28日18:46:39
// end: 2019年4月28日19:06:21
int main() {
	string mapp[10][20] = {
		{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
		{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
		{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
		{ "", "M", "MM" }
	};

	int n, ia = 0;
	string arr[110];
	in(n);
	while (n != 0) {
		if (n % 10 != 0)
			arr[ia] = mapp[ia][n % 10];
		n /= 10;
		++ia;
	}

	for (int i = ia - 1; i >= 0; --i)
		cout << arr[i];
	cout << endl;


	return 0;
}


/*
链接：https://ac.nowcoder.com/acm/contest/637/A
来源：牛客网

张老师需要用数字来统计学生们的得分情况，但阿拉伯数字已经不能满足他的要求了，所以想请你帮忙将学生的成绩转换成罗马数字。
罗马数字是由七个不同的符号来表示（I，V，X，L，C，D和M），其中每个符号对应的值如下表
符号 值
I   1
V   5
X   10
L   50
C   100
D   500
M   1000
罗马数字通常从左到右从最大写到最小，表示他们的总和。但是，数字4的罗马数字表示不是IIII，而是IV，表示5-1=4。同样的，有6个应用相同原理的规则：
I可以放在V（5）和X（10）之前代表4和9。
X可以在L（50）和C（100）之前代表40和90。
C可以放在D（500）和M（1000）之前代表400和900。
现在给定一个整数，张老师请你计算出其罗马数字的表示。

输入描述:
第一行一个整数x(1<=x<=2000)
输出描述:
输出一行，表示整数x所对应的罗马数字表示


*/