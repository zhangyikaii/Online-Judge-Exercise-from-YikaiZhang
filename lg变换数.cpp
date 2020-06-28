//#include <bits/stdc++.h>
//using namespace std;
//
//// 注意到每一位都不影响, 用set去重, 算出每一位可以变换的个数就可以了.
//set<int> ma[12];
//
//void dfs(int used[], int self, int des) {
//	for (set<int>::iterator iter = ma[des].begin(); iter != ma[des].end(); ++iter) {
//		if (used[*iter] == 0) {
//			used[*iter] = 1;
//			ma[self].insert(*iter);
//			dfs(used, self, *iter);
//		}
//	}
//}
//int main() {
//	string n;
//	int num;
//	cin >> n >> num;
//
//	for (int i = 1; i <= num; ++i) {
//		int a, b;
//		cin >> a >> b;
//
//		ma[a].insert(b);
//	}
//
//	for (int i = 0; i <= 9; ++i) {
//		int used[15] = { 0 };
//		for (set<int>::iterator iter = ma[i].begin(); iter != ma[i].end(); ++iter) {
//			used[*iter] = 1;
//			dfs(used, i, *iter);
//		}
//		ma[i].insert(i);
//	}
//
//	long long res = 1;
//	for (int i = 0; i < n.size(); ++i) {
//		res *= (long long)ma[n[i] - '0'].size();
//	}
//
//	printf("%lld\n", res);
//
//	
//
//	return 0;
//}

// 自己写的没有高精 wa了一个点

#include <iostream>
#include <string>
using namespace std;
string str;
int k, vis[10][10], f[10], num[101];

inline void floyd() {  //弗洛伊德
	for (int k = 0; k <= 9; k++)
		for (int i = 0; i <= 9; i++)
			for (int j = 0; j <= 9; j++)
				vis[i][j] = vis[i][j] || (vis[i][k] && vis[k][j]);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> str >> k;
	while (k--) {
		int a, b;
		cin >> a >> b;
		vis[a][b] = true;  //a可以变成b
	}
	// 有一条变换规则, 就是a -> b之间有一条通路.

	for (int i = 0; i <= 9; i++)
		vis[i][i] = true;  //自己可以变成自己, 自己连自己有一条通路.

	floyd();
	for (int i = 0; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
			if (vis[i][j]) f[i]++;  //求出i可以变成多少种数字
	int len = 2; num[1] = 1;
	for (int i = 0; i < (int)str.length(); i++) {  //高精度
		for (int j = 1; j <= 100; j++) num[j] *= f[str[i] - '0'];
		for (int j = 1; j <= 100; j++)
			if (num[j] >= 10) {  //进位
				num[j + 1] += num[j] / 10;
				num[j] %= 10;
			}
		while (num[len]) len++;  //求出长度
	}
	for (int i = len - 1; i >= 1; i--) cout << num[i];  //输出
	return 0;
}