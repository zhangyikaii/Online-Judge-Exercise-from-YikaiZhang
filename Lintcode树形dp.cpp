#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



// 赖皮递归真的牛
class Solution {
private:
	// 传引用!
	void visit(TreeNode* root, int &rob, int &not_rob) {
		rob = not_rob = 0;
		if (root == NULL)
			return;

		int left_rob, left_not_rob, right_rob, right_not_rob;
		// dfs
		visit(root->left, left_rob, left_not_rob);
		visit(root->right, right_rob, right_not_rob);

		// 注意下面关键的 + root->val!
		rob = left_not_rob + right_not_rob + root->val;
		not_rob = max(left_rob, left_not_rob) + max(right_rob, right_not_rob);
	}
public:
	/**
	* @param root: The root of binary tree.
	* @return: The maximum amount of money you can rob tonight
	*/
	int houseRobber3(TreeNode* root) {
		// write your code here
		int rob, not_rob;
		visit(root, rob, not_rob);
		return max(rob, not_rob);
	}
};