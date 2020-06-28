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


/*
// 下面这个答案的方法不是从中途开始dfs, 是预处理好全部的, 然后用lower_bound去搜那个.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int sz = 0;
ll a[67000];


// 两个标志记录4和7的个数, 然后两路递归. 分成 + 4的和 + 7的.
// 预处理好先放到 a[] 里面
void dfs(int p1, int p2, ll now) {
	if (!p1 && !p2) { 
		a[++sz] = now; 
		return; 
	}
	if (p1)
		dfs(p1 - 1, p2, now * 10 + 4);
	if (p2)
		dfs(p1, p2 - 1, now * 10 + 7);
}

int main() {
	for (int i = 1; i <= 9; i++)
		dfs(i, i, 0);
	int T;
	scanf("%d", &T);
	while (T--) {
		ll n; 
		scanf("%lld", &n);
		
		// 预处理好所有数字, 然后用lower_bound去找最小的不小于X的数字.
		int pos = lower_bound(a + 1, a + sz + 1, n) - a;
		if (!a[pos])puts("44444444447777777777");
		else printf("%lld\n", a[pos]);
	}
}

*/



// dfs 没敲出来, 理解skeleton啊
// dfs 找下一个数字, 一定要敲一个半路开始dfs的.

int cmp(string a, string b) {
	if (a.length() > b.length())
		return 1;
	else if (a.length() < b.length())
		return 0;

	for (int i = 0; i < a.length(); ++i) {
		if (a[i] > b[i]) {
			return 1;
		}
		else if (a[i] < b[i])
			return 0;
	}

	return 0;
}


// 这样如果有一位是 9 就立马凉凉.

// 最主要的就是第一次的dfs路径要引对, 最重要就是前面一句话了啊, 就是第一次要引对啊.

// 从中途开始的dfs, 有点麻烦, 但是很高效!!! 自己写出来的, 真不容易, 一定要细心呀.

void dfs(int pos, string cur, int four, int seve, string &res, bool isFir, bool &flag) {
	if (flag != false)
		return;

	if (isFir == true) {
		if (res[pos] - '0' == 4 && four != 0) {
			dfs(pos + 1, cur + "4", four - 1, seve, res, isFir, flag);
		}
		if (res[pos] - '0' == 7 && seve != 0) {
			dfs(pos + 1, cur + "7", four, seve - 1, res, isFir, flag);
		}

		if (res[pos] - '0' < 4 && four != 0) {
			dfs(pos + 1, cur + "4", four - 1, seve, res, false, flag);
		}
		if (res[pos] - '0' < 7 && seve != 0) {
			dfs(pos + 1, cur + "7", four, seve - 1, res, false, flag);
		}
	}
	else {
		if (four != 0) {
			dfs(pos + 1, cur + "4", four - 1, seve, res, false, flag);
		}
		if (seve != 0) {
			dfs(pos + 1, cur + "7", four, seve - 1, res, false, flag);
		}

		if (four == 0 && seve == 0 && cmp(res, cur) == 0) {
			flag = true;
			cout << cur << endl;
		}
	}
}

/*
void dfs(int pos, string cur, int four, int seve, string res, bool &flag) {
	if (flag != false)
		return;
	if (res[pos] - '0' <= 4 && four != 0) {
		dfs(pos + 1, cur + "4", four - 1, seve, res, flag);
	}
	if (res[pos] - '0' <= 7 && seve != 0) {
		dfs(pos + 1, cur + "7", four, seve - 1, res, flag);
	}

	if (four == 0 && seve == 0 && cmp(res, cur) == 0) {
		flag = true;
		cout << cur << endl;
	}
}
*/

int main() {
	int t;
	in(t);
	while (t--) {
		string res, aisAdd, bisAdd;
		cin >> res;
		bool isFir = true, flag = false;
		int num = (res.length() + 1) / 2;

		For(i, 0, num)
			aisAdd += "4";
		For(i, 0, num)
			bisAdd += "7";

		if (cmp(res, aisAdd + bisAdd) == 0)
			cout << aisAdd + bisAdd << endl;
		else if (cmp(res, bisAdd + aisAdd) == 1)
			cout << "4"+ aisAdd + bisAdd + "7" << endl;
		else
			dfs(0, "", num, num, res, isFir, flag);
	}
	
	return 0;
}



/*


链接：https://ac.nowcoder.com/acm/contest/931/B
来源：牛客网

题目描述
期中考的时候，X 用了 10min 写完数学试卷，开始无聊地玩了起来。 突然，他开始搞起了自己的幸运数字，他规定幸运数字在十进制下只包含 4 和 7 且 4 的个数和 7 的个数一样多。他想知道最小的且不小于他数学考试分数的幸运数字是多少。

输入描述:
第一行一个整数 T，表示有 T 组数据。

接下来 T 行每行一个整数 ai 表示 X 数学考试分数。
输出描述:
T 行每行一个整数表示最小的且不小于 X 数学考试分数的幸运数字。
示例1
输入
复制
2
4500
47
输出
复制
4747
47



*/