#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 10;

int a[N][N], ans[N][N], vis[3][N][N], b[82], maxn, flag;

struct Row {
	int h, zero_cnt;
}row[N];

// 排序规则:按照行的0的个数从小到大
// 先搜索0个数比较少的
int cmp(Row row1, Row row2) {
	return row1.zero_cnt < row2.zero_cnt;
}

// 获取x，y在哪一个小九宫格子中, 数独的那九个小九宫格子中
int getGrid(int x, int y) {
	if (x >= 1 && x <= 3) {
		if (y >= 1 && y <= 3)  return 1;
		else if (y >= 4 && y <= 6) return 2;
		else    return 3;
	}
	if (x >= 4 && x <= 6) {
		if (y >= 1 && y <= 3)  return 4;
		else if (y >= 4 && y <= 6) return 5;
		else    return 6;
	}
	if (x >= 7 && x <= 9) {
		if (y >= 1 && y <= 3)  return 7;
		else if (y >= 4 && y <= 6) return 8;
		else    return 9;
	}
}

// 获取x，y位置对应的分数
int getScore(int x, int y) {
	if (x == 1 || y == 1 || x == 9 || y == 9)   return 6;
	else if (x == 2 || y == 2 || x == 8 || y == 8)     return 7;
	else if (x == 3 || y == 3 || x == 7 || y == 7)   return 8;
	else if (x == 4 || y == 4 || x == 6 || y == 6)   return 9;
	else    return 10;
}

// 计算当前组合按照规则计算出来的结果
int cal() {
	int sum = 0;
	for (int i = 1; i <= 9; i++)
	for (int j = 1; j <= 9; j++)
		sum += ans[i][j] * getScore(i, j);
	return sum;
}
void dfs(int xh) {        // xh:b数组的序号
	if (xh == 82) {
		flag = 1;
		maxn = max(maxn, cal());
		return;
	}
	int x = b[xh] / 9 + 1;    // 现在这个序号对应的是第x行，第y列
	int y = b[xh] % 9;
	if (y == 0)
		x = b[xh] / 9, y = 9;
	if (!a[x][y]) {       // 如果当前这个格子是0，才需要填
		for (int j = 1; j <= 9; j++) {  // 判断1-9能不能用
			int g = getGrid(x, y);
			if (!vis[0][x][j] && !vis[1][y][j] && !vis[2][g][j]) {
				ans[x][y] = j;
				vis[0][x][j] = 1, vis[1][y][j] = 1, vis[2][g][j] = 1;
				dfs(xh + 1);
				vis[0][x][j] = 0, vis[1][y][j] = 0, vis[2][g][j] = 0;
			}
		}
	}
	else
		dfs(xh + 1);
}
void init() {
	for (int i = 1; i <= 9; i++) {
		int cnt = 0;                  // cnt:记录该行0的个数
		for (int j = 1; j <= 9; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0)
				cnt++;
			else {
				int v = a[i][j];
				int g = getGrid(i, j);
				ans[i][j] = v;       // 已经填好的数，将它保留，并且行/列/小方格均不可使用
				vis[0][i][v] = 1, vis[1][j][v] = 1, vis[2][g][v] = 1;
			}
		}
		row[i].h = i, row[i].zero_cnt = cnt;   // 记录每一行有几个0
	}
	sort(row + 1, row + 1 + 9, cmp);              // 优先安排0少的行
	int num = 0;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			int x = row[i].h, y = j;
			num++;
			b[num] = (x - 1) * 9 + y;           // 存储待搜索格子的优先顺序
		}
	}
}
int main() {
	init();
	dfs(1);
	if (flag)
		cout << maxn << endl;
	else
		cout << -1 << endl;
	return 0;
}