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

int n, cn;

struct Level {
	int id, level;
	Level() { }
	Level(int idd, int lev) : id(idd), level(lev) { }
};

vector<int> node[105];

int res[105] = { 0 }, used[105] = { 0 };

int main() {
	in(n);
	in(cn);

	for (int i = 1; i <= cn; ++i) {
		int id = 0, k = 0;
		in(id);
		in(k);
		For(i, 0, k) {
			int tmp;
			in(tmp);
			node[id].push_back(tmp);
		}
	}

	queue<Level> q;
	q.push(Level(1, 1));
	++res[1];
	used[1] = 1;

	while (!q.empty()) {
		Level tmp = q.front();
		q.pop();

		For(i, 0, node[tmp.id].size()) {
			if (used[node[tmp.id][i]] == 0) {
				used[node[tmp.id][i]] = 1;
				q.push(Level(node[tmp.id][i], tmp.level + 1));
				++res[tmp.level + 1];
			}
		}
	}

	int ans = 0, lans = 0;
	for (int i = 1; i <= n; ++i) {
		if (ans < res[i]) {
			ans = res[i];
			lans = i;
		}
	}
	printf("%d %d\n", ans, lans);
	return 0;
}

/*

链接：https://www.nowcoder.com/questionTerminal/324faf954885435ba3b1c9bbd2a7a81e
来源：牛客网

A family hierarchy is usually presented by a pedigree tree where all the nodes on the same level belong to the same generation. Your task is to find the generation with the largest population.

输入描述:
Each input file contains one test case.  Each case starts with two positive integers N (<100) which is the total number of family members in the tree (and hence assume that all the members are numbered from 01 to N), and M (<N) which is the number of family members who have children.  Then M lines follow, each contains the information of a family member in the following format:
ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a family member, K (>0) is the number of his/her children, followed by a sequence of two-digit ID's of his/her children. For the sake of simplicity, let us fix the root ID to be 01.  All the numbers in a line are separated by a space.


输出描述:
For each test case, print in one line the largest population number and the level of the corresponding generation.  It is assumed that such a generation is unique, and the root level is defined to be 1.
示例1
输入
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18
输出
9 4



*/