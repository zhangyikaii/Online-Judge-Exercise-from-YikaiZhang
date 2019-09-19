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


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int weight, inda, rank, indb;
};


// 这题就是注意这样子分组晋级的, 有一轮一轮这样的可以用队列做.

// 按照题目所给的顺序输出.
bool cmp1(node a, node b) {
	return a.indb < b.indb;
}
int main() {
	int n, g, num;
	scanf("%d%d", &n, &g);

	// 像数组一样处理vector.
	vector<int> v(n);
	vector<node> w(n);

	// v[i] 是初始weight
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	// inda 是输入顺序下的, indb 是初始随机的顺序.
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		w[i].weight = v[num];		// tmd 谁知道原来输入的权重不是对应顺序的权重........
		w[i].inda = i;
		w[i].indb = num;
	}

	// 所有入队
	queue<node> q;
	for (int i = 0; i < n; i++)
		q.push(w[i]);

	// 当栈不空时
	while (!q.empty()) {
		int sz = q.size();
		// 看看要不要退出
		if (sz == 1) {
			node temp = q.front();
			w[temp.inda].rank = 1;
			break;
		}
		int group = sz / g;
		if (sz % g != 0)
			group += 1;
		node maxnode;
		int maxn = -1, cnt = 0;
		// 遍历整个队列.
		for (int i = 0; i < sz; i++) {
			node temp = q.front();
			// 因为队列不是传的引用, 所以要记录一个inda也就是原来数组里面的index来改原来的信息.
			w[temp.inda].rank = group + 1;
			q.pop();
			cnt++;
			if (temp.weight > maxn) {
				maxn = temp.weight;
				maxnode = temp;
			}

			// 可以提取一个组里面最大的那个了. 注意 || i = sz - 1.
			// 就把此次晋级的放入队列.
			if (cnt == g || i == sz - 1) {
				cnt = 0;
				maxn = -1;
				q.push(maxnode);
			}
		}
	}

	sort(w.begin(), w.end(), cmp1);
	for (int i = 0; i < n; i++) {
		if (i != 0)
			printf(" ");
		printf("%d", w[i].rank);
	}
	return 0;
}

/*



*/