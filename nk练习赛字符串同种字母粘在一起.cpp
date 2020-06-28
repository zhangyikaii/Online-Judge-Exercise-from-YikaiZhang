#include <bits/stdc++.h>
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


int used[30] = { 0 };

int main() {
	string s;
	int n;
	in(n);
	cin >> s;

	for (int i = 0; i < n; ++i) {
		if (used[s[i] - 'a'] == 0) {
			used[s[i] - 'a'] = 1;
		}
		else {
			if (s[i - 1] != s[i]) {
				printf("NO\n");
				return 0;
			}
		}
	}

	printf("YES\n");


	return 0;
}

/*

链接：https://ac.nowcoder.com/acm/contest/1080/A
来源：牛客网

题目描述
tokitsukaze有一个长度为n，只包含小写字母的字符串S。
对于每一种字母，若同种字母都连在一起，tokitsukaze会感到心情愉悦。
若tokitsukaze会感到心情愉悦，请输出"YES"，否则输出"NO"。(均不含引号。)
输入描述:
第一行输入一个正整数n，(1≤n≤100)。
接下来一行输入一个长度为n的字符串S，'a'≤S[i]≤'z'。
输出描述:
输出一行，"YES",或者"NO"。
示例1
输入
复制
1
a
输出
复制
YES
示例2
输入
复制
2
ab
输出
复制
YES
示例3
输入
复制
3
aba
输出
复制
NO


*/