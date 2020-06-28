#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
#include <cmath>
#include <string>
using namespace std;

typedef long long ll;

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

struct TreeNode {
	int val;
	TreeNode *l, *r;
	TreeNode() : val(-1), l(NULL), r(NULL) { }
	TreeNode(int v, TreeNode *ll = NULL, TreeNode *rr = NULL) : val(v), l(ll), r(rr) { }
};

int valRoot = 0, n = 0;

TreeNode *constructRoot(int* preArr, int* midArr, int len){
	valRoot = preArr[0];						// 当前前序第一个结点
	TreeNode *root = new TreeNode(valRoot);
	if (len == 1 && preArr[0] == midArr[0])		// 一个结点
		return root;

	// 找到中序中位置.
	int midRoot = 0;
	for (midRoot = 0; midRoot < len; ++midRoot) {
		if (valRoot == midArr[midRoot])
			break;
	}
	if (midRoot == len)
		return NULL;

	// 左子树
	if (midRoot > 0) {
		root->l = constructRoot(preArr + 1, midArr, midRoot);
	}
	// 右子树, 注意前序序列也要分割( 和中序是一样的 )
	if (len - midRoot - 1 > 0) {
		root->r = constructRoot(preArr + midRoot + 1, midArr + midRoot + 1, len - midRoot - 1);
	}
	return root;
}

int MyMax(int a, int b) {
	return a > b ? a : b;
}

int getHeight(TreeNode *root, int &maxWeight) {
	if (root != NULL) {
		int ah = 0, bh = 0, t = 0;
		if (root->l != NULL)
			ah = getHeight(root->l, maxWeight);
		if (root->r != NULL)
			bh = getHeight(root->r, maxWeight);
		t = ah + bh;
		if (maxWeight < t)
			maxWeight = t;
		return MyMax(ah + 1, bh + 1);
	}
	return 0;
}

int main() {
	in(n);
	int *preArr = new int[n + 10], *midArr = new int[n + 10], resH = 0, resW = 0;
	if (n == 0) {
		printf("I have read the rules about plagiarism punishment\n0\n");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		in(preArr[i]);
	}
	for (int i = 0; i < n; ++i) {
		in(midArr[i]);
	}

	TreeNode * treeRoot = constructRoot(preArr, midArr, n);

	resH = getHeight(treeRoot, resW) - 1;
	printf("I have read the rules about plagiarism punishment\n%d\n%d\n", resH, resW);

	return 0;
}