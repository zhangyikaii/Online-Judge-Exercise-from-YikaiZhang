#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Node {
	Node* left, * right;
	int val, high;
	Node(int v) : left(NULL), right(NULL), high(1), val(v) { }
};

int getHigh(Node* root) {
	int a = 0, b = 0;
	if (root->left != NULL)
		a = root->left->high;
	if (root->right != NULL)
		b = root->right->high;

	return a > b ? a + 1 : b + 1;
}

void R(Node*& root) {
	Node* tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	root->high = getHigh(root);
	tmp->high = getHigh(tmp);
	root = tmp;
}

void L(Node*& root) {
	Node* tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	root->high = getHigh(root);
	tmp->high = getHigh(tmp);
	root = tmp;
}

// 敲到这里, 下面没抄, AVL是个很难啃的东西.

void insert(node*& root, int val)
{
	if (root == NULL)
	{
		root = new node(val);
		return;
	}

	if (val < root->val)
	{
		insert(root->left, val);
		root->high = gethigh(root);
		int a = root->left == NULL ? 0 : root->left->high;
		int b = root->right == NULL ? 0 : root->right->high;
		if (a - b == 2)
		{
			int c = root->left->left == NULL ? 0 : root->left->left->high;
			int d = root->left->right == NULL ? 0 : root->left->right->high;
			if (c - d == 1)
			{
				R(root);
			}
			else if (c - d == -1)
			{
				L(root->left);
				R(root);
			}
		}
	}
	else
	{
		insert(root->right, val);
		root->high = gethigh(root);
		int a = root->left == NULL ? 0 : root->left->high;
		int b = root->right == NULL ? 0 : root->right->high;
		if (a - b == -2)
		{
			int c = root->right->right == NULL ? 0 : root->right->right->high;
			int d = root->right->left == NULL ? 0 : root->right->left->high;
			if (c - d == 1)
			{
				L(root);
			}
			else if (c - d == -1)
			{
				R(root->right);
				L(root);
			}
		}
	}
}

int main()
{
	int n, tem;
	scanf("%d", &n);
	node* Tree = NULL;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &tem);
		insert(Tree, tem);
	}
	printf("%d\n", Tree->val);
	return 0;
}