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
	return k*base;
}

string s[40];
// 预处理肯定要考虑!!! 用yc[i][j]来存储 第i个单词 后连接 第j个单词 的 最小重叠部分
int yc[40][40], n;

// 预处理: 用yc[i][j]来存储 第i个单词 后连接 第j个单词 的 最小重叠部分
void init() {
	For(i, 0, n) {
		For(k, i, n) {
			int a = s[i].length(), b = s[k].length();
			// 判断 s[k] 可不可以接到 s[i] 中 
			int ji;
			for (ji = a - 1; i == 0 ? ji >= 0 : ji > 0; --ji) {
				if (s[k][0] == s[i][ji]) {
					int tk = 1, ti = ji + 1;
					while (ti < a && tk < b && s[k][tk] == s[i][ti]) {
						++ti;
						++tk;
					}
					if (ti == a && tk != b) {
						yc[i][k] = tk;
						break;
					}
				}
			}
			if (ji == 0 && i != 0)
				yc[i][k] = 0;
				
			int jk;
			for (jk = b - 1; k == 0 ? jk >= 0 : jk > 0; --jk) {
				if (s[i][0] == s[k][jk]) {
					int ti = 1, tk = jk + 1;
					while (tk < b && ti < a && s[k][tk] == s[i][ti]) {
						++ti;
						++tk;
					}
					if (tk == b && ti != a) {
						yc[k][i] = ti;
						break;
					}
				}
			}
			if (jk == 0 && k != 0)
				yc[k][i] = 0;
		}
	}
}

int used[30] = { 0 };
int maxx = -1;
void dfs(int index, int curNum) {
	bool isProce = false;
	For(i, 0, n) {
		if (yc[index][i] != 0 && used[i] < 2) {
			isProce = true;
			++used[i];
			dfs(i, curNum + s[i].length() - yc[index][i]);
			--used[i];
		}
	}
	if (isProce == false && maxx < curNum) {
		maxx = curNum;
	}
}


int main() {
	n = read() + 1;
	For(i, 1, n) {
		cin >> s[i];
	}

	cin >> s[0];

	init();

	dfs(0, s[0].length());

	cout << maxx << endl;

	// 总结: 注意注意看清题目!!! 还是有点可惜的呀没有一遍AC, 题目 1. 最后给的是开头字母, 2. 可以自己连接自己
	// 不要想当然!!!

	return 0;
}

/*

两个单词合并时，合并部分取的是最小重叠部分   注意是最小!!!

相邻的两部分不能存在包含关系  比如 at 和 atide 就不能相连

每个单词最多出现两次.


输入:
5
at
touch
cheat
choose
tact
a

输出:
23

连成的龙是:   atoucheatactactouchoose

*/