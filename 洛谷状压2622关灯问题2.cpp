#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;

// 不难

int read() {
	int f = 1, x = 0;
	char ss = getchar();
	while (ss<'0' || ss>'9'){ if (ss == '-')f = -1; ss = getchar(); }
	while (ss >= '0'&&ss <= '9'){ x = x * 10 + ss - '0'; ss = getchar(); }
	return f*x;
}

void print(int x) {
	if (x<0){ putchar('-'); x = -x; }
	if (x>9)print(x / 10);
	putchar(x % 10 + '0');
}

int n, m;
int a[110][1010];
struct node{ 
	int s, step;
	node() {}
	node(int ss, int stt) : s(ss), step(stt) { }
};// s存储状态，step存储当前步数
bool vis[1000010];

int spfa() {
	int ss;
	queue<node> q;
	q.push(node((1 << n) - 1, 0 ));
	vis[(1 << n) - 1] = true;// 全开为初始状态(题意)，二进制为n个1，十进制如代码

	while (!q.empty()) {
		node u = q.front();
		q.pop();
		// 全部关掉了:
		if (u.s == 0) {
			return u.step;
		}// 若状态为0，则返回当前步数

		// 一次按开关操作, 按这m个按钮.
		// 每个开关按下后什么变化都要试一下
		for (int i = 1; i <= m; i++) {
			ss = u.s;
			// 由于开关对所有灯都影响，所以每个灯都遍历, 遍历二进制上的每一位
			for (int j = 1; j <= n; j++) {
				if (a[i][j] == 1 && (ss & (1 << j - 1)))
					ss ^= (1 << j - 1);
				else if (a[i][j] == -1 && !(ss & (1 << j - 1)))
					ss |= (1 << j - 1);
			}
			// 若该状态未访问，就加入队列
			if (!vis[ss]) {
				q.push(node(ss, u.step + 1));
				vis[ss] = true;
			}
		}
	}
	return -1;
}

int main()
{
	n = read(); m = read();
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
		a[i][j] = read();// 保存每个开关操作对灯的影响

	print(spfa());
	return 0;
}

/*
// 灯是只有一排的, 但是不同开关按下之后对他们的效果不同.
题目描述
现有n盏灯，以及m个按钮。每个按钮可以同时控制这n盏灯——按下了第i个按钮，对于所有的灯都有一个效果。按下i按钮对于第j盏灯，是下面3中效果之一：如果a[i][j]为1，那么当这盏灯开了的时候，把它关上，否则不管；如果为-1的话，如果这盏灯是关的，那么把它打开，否则也不管；如果是0，无论这灯是否开，都不管。

现在这些灯都是开的，给出所有开关对所有灯的控制效果，求问最少要按几下按钮才能全部关掉。

输入输出格式
输入格式：
前两行两个数，n m

接下来m行，每行n个数,a[i][j]表示第i个开关对第j个灯的效果。

输出格式：
一个整数，表示最少按按钮次数。如果没有任何办法使其全部关闭，输出-1

输入输出样例
输入样例#1：
3
2
1 0 1
-1 1 0
输出样例#1：
2
*/