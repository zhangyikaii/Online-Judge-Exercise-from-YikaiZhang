#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 110;

struct node {
	int data;
	int lchild, rchild;
} Node[maxn];

struct Node {
	int data;
	int lchild, rchild;
};

// 树直接在运行之前开好就可以了, 不要用动态的.


int n, in[maxn], num = 0;

void inOrder(int root) {
	if (root == -1) {
		return;
	}
	inOrder(Node[root].lchild);
	Node[root].data = in[num++];				// 记录中序遍历.
	inOrder(Node[root].rchild);
}

// 完全不难.

void BFS(int root) {
	queue<int> q;
	q.push(root);
	num = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		printf("%d", Node[now].data);
		num++;
		if (num < n)
			printf(" ");
		if (Node[now].lchild != -1)
			q.push(Node[now].lchild);
		if (Node[now].rchild != -1)
			q.push(Node[now].rchild);
	}
}

int main() {
	int lchild, rchild;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &lchild, &rchild);
		Node[i].lchild = lchild;
		Node[i].rchild = rchild;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	sort(in, in + n);
	inOrder(0);
	BFS(0);
	return 0;
}