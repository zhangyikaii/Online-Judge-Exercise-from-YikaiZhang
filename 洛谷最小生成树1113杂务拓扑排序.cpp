#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

#define in(a) a=getin()
#define MAXN 1010
#define MAXM 100010

struct Edge {
	int to, next, w;
};

struct Data {
	int point, level;
	Data() { };
	Data(int a, int b) : point(a), level(b) { }
};
// 读入优化
int getin() {
	int x = 0;
	char ch = getchar();
	while (ch<'0' || ch>'9')
		ch = getchar();
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x;
}

int head[MAXN], n, inNum[MAXN] = { 0 }, levelWeight[MAXN] = { 0 }, maxLevelNum = 0;
Edge edge[MAXM];
int begTmp, weightTmp, toTmp, cnt = 0, begWeight = 0, ans = 0;

void add(int a, int b, int w = 0) {
	edge[++cnt].next = head[a];
	head[a] = cnt;

	edge[cnt].w = w;
	edge[cnt].to = b;
}

void updateLevel(int lev, int w) {
	// cout << lev << "*" << w << endl;
	if (levelWeight[lev] < w) {
		levelWeight[lev] = w;
	}
	if (lev > maxLevelNum)
		maxLevelNum = lev;
}

void topo() {
	queue<Data> q;
	for (int i = 1; i <= n; ++i) {
		if (inNum[i] == 0) {
			q.push(Data(i, 1));
			updateLevel(1, edge[head[i]].w);
		}
	}

	while (!q.empty()) {
		Data curDel = q.front();
		q.pop();
		cout << curDel.point << " ";
		if (curDel.point != 1)
			updateLevel(curDel.level, edge[head[curDel.point]].w);

		for (int i = head[curDel.point]; i != 0; i = edge[i].next) {
			--inNum[edge[i].to];
			if (inNum[edge[i].to] == 0) {
				q.push(Data(edge[i].to, curDel.level + 1));
			}
		}
	}
}

int main() {
	in(n);
	for (int i = 1; i <= n; ++i) {
		in(begTmp);
		in(weightTmp);

		in(toTmp);

		if (toTmp == 0)
			begWeight = weightTmp > begWeight ? weightTmp : begWeight;
		else {
			while (toTmp != 0) {
				inNum[begTmp]++;
				add(toTmp, begTmp, weightTmp);
				in(toTmp);
			}
		}
	}

	topo();

	for (int i = 1; i <= maxLevelNum; ++i)
		ans += levelWeight[i];
	
	// printf("%d\n", ans + begWeight);

	return 0;
}

/*

John的农场在给奶牛挤奶前有很多杂务要完成，每一项杂务都需要一定的时间来完成它。比如：他们要将奶牛集合起来，将他们赶进牛棚，为奶牛清洗乳房以及一些其它工作。尽早将所有杂务完成是必要的，因为这样才有更多时间挤出更多的牛奶。当然，有些杂务必须在另一些杂务完成的情况下才能进行。比如：只有将奶牛赶进牛棚才能开始为它清洗乳房，还有在未给奶牛清洗乳房之前不能挤奶。我们把这些工作称为完成本项工作的准备工作。至少有一项杂务不要求有准备工作，这个可以最早着手完成的工作，标记为杂务11。John有需要完成的nn个杂务的清单，并且这份清单是有一定顺序的，杂务k(k>1)k(k>1)的准备工作只可能在杂务11至k-1k−1中。

写一个程序从11到nn读入每个杂务的工作说明。计算出所有杂务都被完成的最短时间。当然互相没有关系的杂务可以同时工作，并且，你可以假定John的农场有足够多的工人来同时完成任意多项任务。

输入输出格式
输入格式：
第1行：一个整数nn，必须完成的杂务的数目(3≤n≤10,000)；

第22至(n+1)(n+1)行： 共有nn行，每行有一些用11个空格隔开的整数，分别表示：

* 工作序号(11至nn,在输入文件中是有序的)；

* 完成工作所需要的时间len(1≤len≤100)；

* 一些必须完成的准备工作，总数不超过100100个，由一个数字00结束。有些杂务没有需要准备的工作只描述一个单独的00，整个输入文件中不会出现多余的空格。

输出格式：
一个整数，表示完成所有杂务所需的最短时间。

输入输出样例
输入样例#1：
7
1 5 0
2 2 1 0
3 3 2 0
4 6 1 0
5 1 2 4 0
6 8 2 4 0
7 4 3 5 6 0
输出样例#1：
23

*/
