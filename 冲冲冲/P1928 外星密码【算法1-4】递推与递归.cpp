#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define Fee(i, b, e) for(int i = (b); i <= (e); ++i)
#define Ree(i, b, e) for(int i = (b); i >= (e); --i)

#define INF 0x7fffff

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

//string deco(string s) {
//	int beg = s.find_first_of("["), aft = s.find_last_of("]");
//	if (beg == -1 && aft == -1)
//		return s;
//	string cur = s.substr(beg + 1, aft - beg - 1);
//	if 
//	return cur;
//}

// 看到题解巨简单, 瞬间GG, 好好学习一下题解:

string solve()
{
	int n;
	string s = "", s1;
	char c;
	while (cin >> c)//一直读入字符，直到Ctrl+z
	{
		if (c == '[') {
			cin >> n;// 读入D, 把流读入看成一个整体的过程, 读数字也是很顺畅.
			s1 = solve();//读入X // 非常关键, 牛! 递归的魅力.
			while (n--) s += s1;// 重复D次X
			// 注：上面不能写成while (n--) s+=solve();
		}
		else {
			if (c == ']') return s;//返回X
			else s += c;//如果不是'['和']'，那就是X的一个字符，所以加进X
		}
	}
}
int main() {
	cout << solve();
	return 0;
}