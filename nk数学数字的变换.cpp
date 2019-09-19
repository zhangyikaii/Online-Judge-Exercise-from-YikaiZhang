#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<map>
#define INF 0xfffffff

#define CLR(a,b,Size) memset((a),(b),sizeof((a[0]))*(Size+1))
#define CPY(a,b) memcpy ((a), (b), sizeof((a)))
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

int ruleMap[15];
int used[15][15];


// 答案错误:您提交的程序没有通过所有的测试用例
// 我做的处理只有判断输入重复. 但是题目说了右边不会为0, 就不要判断第一个为0构不成数字的了.
int main() {
	string n;
	int kk, res = 1;
	int atmp, btmp;
	cin >> n;
	in(kk);

	for (int i = 0; i < 11; ++i) {
		ruleMap[i] = 1;
	}
	For(i, 0, kk) {
		in(atmp);
		in(btmp);
		if (used[atmp][btmp] == 0) {
			ruleMap[atmp]++;
			used[atmp][btmp] = 1;
		}
	}

	for (int i = 0; i < n.length(); ++i) {
		res *= (ruleMap[n[i] - '0']);
	}

	printf("%d\n", res);
	return 0;
}

/*

链接：https://ac.nowcoder.com/acm/contest/1077/C
来源：牛客网

题目描述
给出一个整数 n（n<1030) 和 k 个变换规则（k<=15）。
规则：
一位数可变换成另一个一位数：规则的右部不能为零。
例如：n=234。有规则（k＝2）：
2－> 5
3－> 6
上面的整数 234 经过变换后可能产生出的整数为（包括原数）:
234
534
264
564
共 4 种不同的产生数
问题：
给出一个整数 n 和 k 个规则。
求出：
经过任意次的变换（0次或多次），能产生出多少个不同整数。仅要求输出个数。
输入描述:
输入格式为：
n k
x1 y1
x2 y2
... ...
xn yn
输出描述:
一个整数（满足条件的个数）
示例1
输入
复制
234 2
2 5
3 6
输出
复制
4
*/

