#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<map>

using namespace std;

struct TreeNode {
	char val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(char v) : val(v) { }
};

int maxDepth(TreeNode *root) {
	if (root == NULL) {
		return 0;
	}
	int left = 0, right = 0;
	left = maxDepth(root->left);
	right = maxDepth(root->right);
	return max(left, right) + 1;
}

TreeNode* buildTreeCore(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end)
{
	if (pre_start > pre_end)
		return NULL;
	TreeNode* node = new TreeNode(preorder[pre_start]);
	node->left = NULL;
	node->right = NULL;
	if (pre_start == pre_end)
		return node;

	/*在中序中找到根的位置*/
	int len = -1;
	for (int i = in_start; i <= in_end; i++) {
		len++;
		if (inorder[i] == preorder[pre_start])
			break;
	}
	/*在中序中找到根的位置*/
	node->left = buildTreeCore(preorder, pre_start + 1, pre_start + len, inorder, in_start, in_start + len - 1);
	node->right = buildTreeCore(preorder, pre_start + len + 1, pre_end, inorder, in_start + len + 1, in_end);
	return node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	TreeNode* root = NULL;
	if (preorder.size() != inorder.size() || preorder.size() == 0 || inorder.size() == 0)
		return root;
	root = buildTreeCore(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	return root;
}

int nn;
string as, bs;
vector<int> av, bv;

int main() {
	cin >> nn >> as >> bs;

	for (int i = 0; i < as.size(); ++i) {
		av.push_back(as[i]);
	}

	for (int i = 0; i < bs.size(); ++i) {
		bv.push_back(bs[i]);
	}

	TreeNode *res = buildTree(av, bv);
	printf("%d\n", maxDepth(res));


	return 0;
}




