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

string s[100010];
map<string, int> mapp;


// 哈希, 自己做的:
// 注意: 之前先O(n)扫一遍全部存下来, 一次性处理完一对的, 就是mapp = 0.
// 这种配对的匹配, DNA匹配都可以用这样hash的思路做.

string Switch(string a) {
	for (int i = 0; i < a.length(); ++i) {
		switch (a[i]) {
		case 'A':
			a[i] = 'T';
			break;

		case 'T':
			a[i] = 'A';
			break;
		case 'C':
			a[i] = 'G';
			break;
		case 'G':
			a[i] = 'C';
			break;

		default:
			break;
		}
	}

	return a;
}

int main() {
	int n;
	in(n);

	int ans = 0;
	string tmp;
	For(i, 0, n) {
		cin >> s[i];
		++mapp[s[i]];
	}

	For(i, 0, n) {
		tmp = Switch(s[i]);
		// cout << tmp << "  " << min(mapp[tmp], mapp[s[i]]) << endl;
		ans += min(mapp[tmp], mapp[s[i]]); // 注意是有限拿走式的匹配.
		mapp[s[i]] = 0;
	}

	printf("%d\n", ans);
	

	return 0;
}


/*

链接：https://ac.nowcoder.com/acm/contest/931/A
来源：牛客网

题目描述
DNA序列里只有ACGT四种字母，A和T对应，C和G对应。
俩序列完全对应，就是指它们每一位上的字母一一对应。比如ACG和TGC完全对应
求最多能选出多少对完全对应的DNA序列。（当然一个序列最多被选一次）
输入描述:
第一行一个整数n表示有多少序列。
接下来n行，每行一个长度\leq 20≤20的只包含ACGT的字符串，表示序列。

输出描述:
一个整数，表示最多能选出多少对完全对应的。
示例1
输入
复制
4
ATCG
TAGC
TAGG
ACG
输出
复制
1
说明
ATCG和TAGC完全对应。
示例2
输入
复制
20
CG
C
C
C
A
AG
G
A
CG
A
TA
CA
G
A
GC
TT
GT
GA
CA
G
输出
复制
5



*/