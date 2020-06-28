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

const int maxn = 105;
int cnt = 0;
/*
中序遍历的顺序即为序列从小到大的顺序，因此中序遍历的时候顺便赋值，
最后层次遍历输出即可。
*/

// 二叉树数组建法.
struct Node {
	int val;
	int left;
	int right;
}node[maxn];


// 中序遍历.
void dfs(int i, int a[]) {
	if (i == -1)
		return;
	dfs(node[i].left, a);
	node[i].val = a[cnt];			// 中序遍历访问的时候放节点.
	++cnt;
	dfs(node[i].right, a);
}

int main() {
	int n, l, r;
	int a[maxn];
	scanf("%d", &n);

	// 关键就是数组建树, 其他一点儿不难.
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &l, &r);
		node[i].left = l;
		node[i].right = r;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	// 需要填入的数从小到大排序.
	sort(a, a + n);

	dfs(0, a);


	// 层次遍历, 直接放节点.
	queue<Node> q;
	q.push(node[0]);

	bool first = true;
	while (!q.empty()) {
		Node tmp = q.front();
		q.pop();
		if (first) {
			printf("%d", tmp.val);
			first = false;
		}
		else {
			printf(" %d", tmp.val);
		}
		if (tmp.left != -1)
			q.push(node[tmp.left]);
		if (tmp.right != -1)
			q.push(node[tmp.right]);
	}

	return 0;
}


/*
题目描述
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
Given the structure of a binary tree and a sequence of distinct integer keys, there is only one way to fill these keys into the tree so that the resulting tree satisfies the definition of a BST.  You are supposed to output the level order traversal sequence of that tree.  The sample is illustrated by Figure 1 and 2.





输入描述:
Each input file contains one test case.  For each case, the first line gives a positive integer N (<=100) which is the total number of nodes in the tree.  The next N lines each contains the left and the right children of a node in the format "left_index right_index", provided that the nodes are numbered from 0 to N-1, and 0 is always the root.  If one child is missing, then -1 will represent the NULL child pointer.  Finally N distinct integer keys are given in the last line.



输出描述:
For each test case, print in one line the level order traversal sequence of that tree.  All the numbers must be separated by a space, with no extra space at the end of the line.


输入例子:
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42

输出例子:
58 25 82 11 38 67 45 73 42
*/