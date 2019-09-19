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


// 思路: 关键注意字符串结构: ()被删除之后, 只有)(, ((, )). 然后就对剩下的这几种进行处理.
// 注意, "()"的删除必须是递归的, 一次删干净的, 才可以用上面的那个式子. 其实是用栈最好呀!!!!! 但是下面自己用记录前一个是什么加一个标志物的方法也过了... 加油吧.

int arr[100010] = { 0 };
int main() {
	int res = 0;
	string s;
	cin >> s;

	bool flag = false;
	do {
		flag = true;
		int bef = -1;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] != '.') {
				if (s[i] == '(')
					bef = i;
				else {
					// 有记录前一个括号位置.
					if (bef != -1) {
						flag = false;
						s[bef] = '.';
						s[i] = '.';
						bef = -1;
						++res;
					}
				}
			}
		}
	} while (flag == false);
	

	int bef = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] != '.') {
			if (bef == 0) {
				bef = (s[i] == '(') ? 1 : 2;
			}
			else if ((bef == 1 && s[i] == '(') || (bef == 2 && s[i] == ')')) {
				res += 2;
				bef = 0;
			}
			else {
				res += 3;
				bef = 0;
			}
		}
	}

	printf("%d\n", res);


	return 0;
}


/*

链接：https://ac.nowcoder.com/acm/contest/926/B
来源：牛客网

题目描述
给定一个长度为\ L L (\ L L 为偶数)的字符串\ S S ，且串中只包含’(’ 和‘)’。
现在每次对该串的操作可以选择以下之一:
选择\ S S 中的一个’(’并将其替换为’)’
选择\ S S 中的一个’)’并将其替换为’(’
选择\ S S 中的一个”()”子串并将该子串从\ S S 串中移除
求至少经过多少次操作可以使得\ S S 变为空串。

输入描述:
一行一个长度为\ L L的字符串，保证\ L L为偶数，且只含’(’和‘)’。
输出描述:
一行一个整数—最小的操作次数
示例1
输入
复制
()))()
输出
复制
4
说明
可以通过\ 4 4次操作将串\ S S变为空串
\ “()))()” → “()))” → “))” → “()” → “” “()))()”→“()))”→“))”→“()”→“”
示例2
输入
复制
))((
输出
复制
4

*/