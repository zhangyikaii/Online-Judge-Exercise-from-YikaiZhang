#include <iostream>
using namespace std;
#include <algorithm>
class TreeNode{
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val){
		this->val = val;
		this->left = this->right = NULL;
	}
};

int maxLength = 1;//最长连续序列路径的长度
pair<int, int> helper(TreeNode *root)
{
	if (!root)
		return make_pair(0, 0);
	//up表示最长升序的长度,down表示最长降序的长度
	//返回一个pair值, 注意这里同时考虑上升序列和下降序列
	int up = 1, down = 1;
	pair<int, int> left = helper(root->left);
	pair<int, int> right = helper(root->right);
	//右子树不为空,若root节点的值是左子树值+1,up值为最长递增序列长度加一
	//若root节点的值是左子树值-1,down值为最长递减序列长度加一
	if (root->left) {
		if (root->left->val == root->val + 1)
			up = max(up, left.first + 1);
		if (root->left->val == root->val - 1)
			down = max(down, left.second + 1);
	}
	//左子树不为空,若root节点的值是右子树值+1,up值为最长递增序列长度加一
	//若root节点的值是右子树值-1,down值为最长递增序列长度加一
	if (root->right) {
		if (root->right->val == root->val + 1)
			up = max(up, right.first + 1);
		if (root->right->val == root->val - 1)
			down = max(down, right.second + 1);
	}
	maxLength = max(maxLength, up + down - 1);
	return make_pair(up, down);
}


int longestConsecutive2(TreeNode * root) {
	// write your code here
	if (!root)
		return 0;
	helper(root);
	return maxLength;
}
//返回节点的<最长升序,最长降序>
