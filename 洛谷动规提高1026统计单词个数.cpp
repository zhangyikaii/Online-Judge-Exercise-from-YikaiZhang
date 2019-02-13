#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

#define in(x) x = read()

inline int read(){
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	if (f) return x;
	return 0 - x;
}

int p, kk, n;
string all, dic[10];
int dp[1000][50], sum[1000][1000];

// 判断是否有单词以 l 为开头
int Check(int l, int r) {
	string tmp = all.substr(l, r - l + 1);
	for (int i = 0; i < n; ++i) {
		if (tmp.find(dic[i]) == 0)
			return true;
	}
	return false;
}

int main() {
	in(p);
	in(kk);
	string inputTmp;
	for (int i = 0; i < p; ++i) {
		cin >> inputTmp;
		all += inputTmp;
	}
	in(n);
	for (int i = 0; i < n; ++i)
		cin >> dic[i];

	// 预处理 sum
	// 这个预处理方法真的精妙!!! 因为题目中说:"(每份中包含的单词可以部分重叠。当选用一个单词之后，其第一个字母不能再用。例如字符串this中可包含this和is，选用this之后就不能包含th)", 所以选择从后往前遍历, 先 sum[k][i] = sum[k + 1][i], (k是总字符串前面的i是后面的), 这个基础值用的很好! k 处Check()有了再 ++.
	// 其实这句话 就 简化为: 以总字符串中某个位开头的单词至多只有一个
	int allLength = all.length();
	// k 是前面的那个, i 是后面的那个
	for (int i = 0; i < 1000; ++i) {
		for (int k = 0; k < 1000; ++k)
			sum[i][k] = 0;
	}

	for (int i = allLength; i >= 0; --i) {
		for (int k = i; k >= 0; --k) {
			sum[k][i] = sum[k + 1][i];
			if (Check(k, i))
				++sum[k][i];
		}
	}

	// dp 预处理
	for (int i = 0; i <= 40; ++i)
		dp[0][i] = 0;
	for (int i = 0; i <= allLength; ++i)
		dp[i][0] = sum[0][i];
	for (int i = 1; i <= allLength; ++i)
		dp[i][i] = dp[i - 1][i - 1] + sum[i - 1][i - 1];

	for (int i = 0; i <= allLength; ++i) {
		// 注意 k < i 因为 划分次数 肯定是 <= (总数 - 1) 的
		for (int k = 0; k <= kk && k < i; ++k) {
			// dp 关键! 枚举之前所有的划分!
			for (int j = 0; j < i; ++j)
				dp[i][k] = max(dp[i][k], dp[j][k - 1] + sum[j + 1][i]);
		}
	}

	printf("%d\n", dp[allLength][kk]);
	
	return 0;
}

/*
题目描述
给出一个长度不超过200的由小写英文字母组成的字母串(约定;该字串以每行20个字母的方式输入，且保证每行一定为20个)。要求将此字母串分成k份，且每份中包含的单词个数加起来总数最大(每份中包含的单词可以部分重叠。当选用一个单词之后，其第一个字母不能再用。例如字符串this中可包含this和is，选用this之后就不能包含th)。

单词在给出的一个不超过6个单词的字典中。

要求输出最大的个数。

输入输出格式
输入格式：
每组的第一行有2个正整数(p,k)

pp表示字串的行数,kk表示分为kk个部分。

接下来的pp行，每行均有2020个字符。

再接下来有11个正整数ss，表示字典中单词个数。

接下来的ss行，每行均有11个单词。

输出格式：
11个整数，分别对应每组测试数据的相应结果。

输入输出样例
输入样例#1：
1 3
thisisabookyouareaoh
4
is
a
ok
sab
输出样例#1：
7

1 1
aaaaaa
1
aaa

*/