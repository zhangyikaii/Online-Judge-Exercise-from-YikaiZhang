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


const int MAX = 1005;     // 数组最大长度
int n = 0, queenNum = 8;  // 输入的数 皇后个数
int vis[MAX] = { 0 };     // 判断是否重复的数组

int res = 0;

// 判断第i个可不可以放到pos这个位置上
bool check(int i, int pos) {
	for (int iFind = 0; iFind < pos; ++iFind) {
		if (vis[iFind] == i || abs(vis[iFind] - i) == abs(iFind - pos)) {       // 这个位置已经有取过了
			//for (int i = 0; i < 8; ++i)
			//cout << vis[i];
			//cout << endl;
			return false;
		}
	}

	return true;
}

int cou = 2;

// dfs输出
void dfs(int pos) {
	// 满足条件输出
	if (pos == queenNum) {
		// cou 计数输出多少了.
		
		if (cou >= 0) {
			--cou;
			for (int i = 0; i < queenNum; ++i)
				cout << vis[i] << " ";
			cout << endl;
		}
		++res;
		return;
	}

	for (int i = 1; i <= queenNum; ++i) {
		if (i == n)
			continue;

		if (check(i, pos)) {
			vis[pos] = i;   // 可以放
			dfs(pos + 1);   // 递归放下一个
			vis[pos] = 0;   // 回溯
		}
	}
}


int main() {
	cin >> queenNum;
	dfs(0);
	cout << res << endl;

	return 0;
}




