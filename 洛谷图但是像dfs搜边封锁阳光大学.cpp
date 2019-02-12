#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

const double PI = 3.1415926535;

inline int read(){
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	if (f) return x;
	return 0 - x;
}

struct Data {
	int a, b;
};

int n, m, minAns = 0xfffffff;
Data arr[100010];
bool used[10010] = { false }; // 哪个点没有封锁

// dfs 搜边 很好写, 但是数据量一大就TLE
void dfs(int ans) {
	int nextFind = 1;
	for (; nextFind <= m; ++nextFind) {
		if (used[arr[nextFind].a] == false && used[arr[nextFind].b] == false)
			break;
		else if (used[arr[nextFind].a] == true && used[arr[nextFind].b] == true) {
			return;
		}  // 怎么判断不符合的时候呢
	}
	if (nextFind > m) {
		if (minAns > ans)
			minAns = ans;
		return;
	}

	used[arr[nextFind].a] = true;
	dfs(ans + 1);
	used[arr[nextFind].a] = false;

	used[arr[nextFind].b] = true;
	dfs(ans + 1);
	used[arr[nextFind].b] = false;
}

int main() {
	n = read();
	m = read();

	for (int i = 1; i <= m; ++i) {
		arr[i].a = read();
		arr[i].b = read();
	}

	dfs(0);
	if (minAns != 0xfffffff)
		printf("%d\n", minAns);
	else
		printf("Impossible\n");

	return 0;
}

/*
题目描述
曹是一只爱刷街的老曹，暑假期间，他每天都欢快地在阳光大学的校园里刷街。河蟹看到欢快的曹，感到不爽。河蟹决定封锁阳光大学，不让曹刷街。

阳光大学的校园是一张由N个点构成的无向图，N个点之间由M条道路连接。每只河蟹可以对一个点进行封锁，当某个点被封锁后，与这个点相连的道路就被封锁了，曹就无法在与这些道路上刷街了。非常悲剧的一点是，河蟹是一种不和谐的生物，当两只河蟹封锁了相邻的两个点时，他们会发生冲突。

询问：最少需要多少只河蟹，可以封锁所有道路并且不发生冲突。

输入输出格式
输入格式：
第一行：两个整数N，M

接下来M行：每行两个整数A，B，表示点A到点B之间有道路相连。

输出格式：
仅一行：如果河蟹无法封锁所有道路，则输出“Impossible”，否则输出一个整数，表示最少需要多少只河蟹。

输入输出样例
输入样例#1：
3 3
1 2
1 3
2 3
输出样例#1：
Impossible
输入样例#2：
3 2
1 2
2 3
输出样例#2：
1


*/