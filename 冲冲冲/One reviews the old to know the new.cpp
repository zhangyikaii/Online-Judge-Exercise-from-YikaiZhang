#include <bits/stdc++.h>
using namespace std;

// One reviews the old to know the new
class Solution {
public:
	/**
	 * @param n: An integer
	 * @param nums: An array
	 * @return: the Kth largest element
	 */
	////////////////////////////REVIEW///////////////////////////////////////////////////
	int reviewPartion(int l, int r, int m, vector<int>& nums) {
		int guard = nums[m]; // 以此为依据.
		swap(nums, l, m); // 放到第一个.
		int j = l;
		// for-loop 把比guard更小的都放到前面.
		for (int i = l + 1; i <= r; ++i) {
			if (nums[i] < guard) {
				++j;
				swap(nums, j, i);
			}
		}
		swap(nums, j, l); // 把guard放到中间.
		return j; // 返回idx.
	}

	// ??? 以下似乎是算法导论里面那个找中位数的算法:
	int findMedia(vector<int>& nums, int l, int r) {
		if (l == r)
			return nums[l];
		int i = l;
		int n;
		for (i = l; i <= r - 5; i += 5)
		{
			sort(nums.begin() + l, nums.begin() + 5 + l);
			n = i - l;
			swap(nums, l + n / 5, i + 2);
		}
		int a = r - i + 1;
		if (a > 0)
		{
			sort(nums.begin() + i, nums.begin() + r + 1);
			n = i - l;
			swap(nums, l + n / 5, i + a / 2);
		}
		n = n / 5;
		return findMedia(nums, l, l + n);
	}
	////////////////////////////REVIEW///////////////////////////////////////////////////

	void swap(vector<int>& nums, int i, int j) {
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}

	int partion(vector<int>& nums, int l, int r, int m) {
		int s = nums[m];
		swap(nums, l, m);
		int j = l;
		for (int i = l + 1; i <= r; i++) {
			if (nums[i] < s) {
				j++;
				swap(nums, j, i);
			}
		}
		swap(nums, j, l);
		return j;
	}

	//找一个数在nums数组中的位置
	int findId(vector<int>& nums, int l, int r, int val) {
		for (int i = l; i <= r; i++) {
			if (nums[i] == val)
				return i;
		}
		return -1;
	}
	int findMedia(vector<int>& nums, int l, int r) {
		if (l == r)
			return nums[l];
		int i = l;
		int n;
		for (i = l; i <= r - 5; i += 5)
		{
			sort(nums.begin() + l, nums.begin() + 5 + l);
			n = i - l;
			swap(nums, l + n / 5, i + 2);
		}
		int a = r - i + 1;
		if (a > 0)
		{
			sort(nums.begin() + i, nums.begin() + r + 1);
			n = i - l;
			swap(nums, l + n / 5, i + a / 2);
		}
		n = n / 5;
		return findMedia(nums, l, l + n);
	}
	int bfptr(vector<int>& nums, int l, int r, int k) {
		int n = findMedia(nums, l, r);
		int id = findId(nums, l, r, n);
		int i = partion(nums, l, r, id);

		int m = i - l + 1;
		if (m == k)
			return nums[i];
		// 说明第 k 大的在后半部分.
		else if (m < k) {
			return bfptr(nums, i + 1, r, k - m);
		}
		else {
			return bfptr(nums, l, i - 1, k);
		}
	}

	int kthLargestElement(int n, vector<int>& nums) {
		return bfptr(nums, 0, nums.size() - 1, nums.size() - n + 1);
	}

};


// 8. Rotate String
// 逆序全部, 逆序前offset个, 逆序后n - offset个.
class Solution {
public:
	/**
	 * @param str: An array of char
	 * @param offset: An integer
	 * @return: nothing
	 */

	void rotate(int i, int n, string& str) {
		char tmp = str[i];
		str[i] = str[n - 1 - i];
		str[n - 1 - i] = tmp;
	}
	void rotateString(string& str, int offset) {
		// write your code here
		int n = str.size();
		if (n <= 1)
			return;
		offset %= n;
		for (int i = 0; i < n / 2; ++i) {
			rotate(i, n, str);
		}

		for (int i = 0; i < offset / 2; ++i) {
			rotate(i, offset, str);
		}

		int nn = n - offset;
		for (int i = offset, k = 0; k < (n - offset) / 2; ++k) {
			char tmp = str[i + k];
			str[i + k] = str[i + nn - 1 - k];
			str[i + nn - 1 - k] = tmp;
		}
	}
};




// 16. Permutations II

class Solution {
public:
	/*
	 * @param :  A list of integers
	 * @return: A list of unique permutations
	 */

	// dfs需要的终止长度, 需要全排列的数组, 记录visit的一个数组, 中间结果的一个数组.
	void reviewDFS(vector<int>& nums, vector<int>& visited, vector<int>& resVec) {
		// 终止判断...

		// else:
		// 这里不能继续DFS的条件:
		// 1. ??? 没看懂, 复习luogu火星文.
	}

	 // vis数组可以拿来传参
	 // vis数组记录的是位置, 这个位置有没访问过.
	void permuteUniqueDFS(vector<int>& nums, vector<int>& visited, vector<int>& resVec, vector<vector<int> >& res) {
		if (resVec.size() == nums.size())		// 排完了.
			res.push_back(resVec);
		else {
			for (int i = 0; i < nums.size(); ++i) {
				if (visited[i] == 0) {
					// 不访问: 如果和前面数字相同 而且! 前面数字没有访问过.
					// 因为如果这样再访问的话, 等等会访问到前面元素, 就重复了.
					// 主要变化就在这里, 还有vis[] 记录的是下标, 其他都一样的.
					if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0)
						continue;
					visited[i] = 1;
					resVec.push_back(nums[i]);
					permuteUniqueDFS(nums, visited, resVec, res);
					resVec.pop_back();				// 注意回溯临时的res数组.
					visited[i] = 0;
				}
			}
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		// write your code here
		vector<vector<int> > res;
		vector<int> resVec;
		vector<int> visited(nums.size(), 0);
		sort(nums.begin(), nums.end());
		permuteUniqueDFS(nums, visited, resVec, res);
		return res;
	}

};



// 33. N-Queens

class Solution {
public:
	/*
	 * @param n: The number of queens
	 * @return: All distinct solutions
	 */

	vector<vector<string> > solveNQueens(int n) {
		// write your code here
		vector<vector<string> > result;
		if (n <= 0) {
			return result;
		}
		vector<int> cols;
		search(n, cols, result);
		return result;
	}

	void search(int n, vector<int>& cols, vector<vector<string> >& result) {
		if (cols.size() == n) {
			result.push_back(drawResult(cols, n));
			return;
		}

		// Review Notes: 遍历每一行的状态即放在哪个位置.
		for (int col = 0; col < n; col++) {
			// Review Notes: 如果不满足条件就跳.
			if (!isValid(cols, col)) {
				continue;
			}
			cols.push_back(col);
			search(n, cols, result);
			cols.pop_back();
		}
	}
	bool isValid(vector<int>& cols, int col) {
		int row = cols.size();
		for (int i = 0; i < row; ++i) {
			if (cols[i] == col) {
				return false;
			}
			if (i - cols[i] == row - col) {
				return false;
			}
			if (i + cols[i] == row + col) {
				return false;
			}
		}
		return true;
	}

	// 返回值的写一个函数.
	vector<string> drawResult(vector<int>& cols, int n) {
		vector<string> result;
		for (int i = 0; i < cols.size(); ++i) {
			// 注意这个string 的初始化.
			string temp(n, '.');
			temp[cols[i]] = 'Q';
			result.push_back(temp);
		}
		return result;
	}
};

// 60. Search Insert Position

class Solution {
public:
	/**
	 * @param A: an integer sorted array
	 * @param target: an integer to be inserted
	 * @return: An integer
	 */
	int searchInsert(vector<int>& A, int target) {
		// write your code here
		if (A.empty())
			return 0;
		int l = 0, r = A.size() - 1, mid;
		if (A[r] < target)
			return r + 1;
		else if (A[l] > target)
			return 0;

		// RN: 外层while带等号.
		while (l <= r) {
			mid = (l + r) >> 1;

			// RN: 跳出限制卡死.
			if (A[mid] < target && A[mid + 1] > target)
				return mid + 1;

			// 不满足时都是 - 1 and + 1.
			if (A[mid] > target)
				r = mid - 1;
			else if (A[mid] < target)
				l = mid + 1;
			else
				return mid;
		}
	}
};

// 69. Binary Tree Level Order Traversal

// Definition of TreeNode:
class TreeNode {
public:
	int val;
	TreeNode* left, * right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

class Solution {
public:
	/**
	 * @param root: A Tree
	 * @return: Level order a list of lists of integer
	 */
	struct Data {
		TreeNode* ptr;
		int level;
		Data() { };
		Data(TreeNode* t, int l) : ptr(t), level(l) { }
	};
	vector<vector<int>> levelOrder(TreeNode* root) {
		// Write your code here
		vector<vector<int>> res;
		if (root == NULL)
			return res;

		// RN: 队列基本使用方法.
		queue<Data> RNq;
		// push root 层次是1.
		RNq.push(Data(root, 1));
		while (!RNq.empty()) {
			Data tmp = RNq.front();
			RNq.pop();

			// do ..

			// 满足一定条件则 push 新的.
		}



		queue<Data> q;
		q.push(Data(root, 1));
		while (!q.empty()) {
			Data tmp = q.front();
			q.pop();
			if (res.size() < tmp.level) {
				vector<int> tmpVec;
				tmpVec.push_back(tmp.ptr->val);
				res.push_back(tmpVec);
			}
			else {
				res[tmp.level - 1].push_back(tmp.ptr->val);
			}

			if (tmp.ptr->left != NULL)
				q.push(Data(tmp.ptr->left, tmp.level + 1));
			if (tmp.ptr->right != NULL)
				q.push(Data(tmp.ptr->right, tmp.level + 1));
		}

		return res;
	}
};

// 82. Single Number
// 找到一个只出现一次的数字.

class Solution {
public:
	/**
	 * @param A: An integer array
	 * @return: An integer
	 */
	int singleNumber(vector<int>& A) {
		// write your code here
		int ans = A[0];
		for (int i = 1; i < A.size(); ++i) {
			ans ^= A[i];
		}
		return ans;
	}
};

// 97. Maximum Depth of Binary Tree

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
	/**
	 * @param root: The root of binary tree.
	 * @return: An integer
	 */
	int maxDepth(TreeNode* root) {
		// write your code here
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL) {
			return 1;
		}

		return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
	}
};



// 二叉树的直径:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int getHeight(TreeNode* root, int& maxWeight) {
		if (root != NULL) {
			int ah = 0, bh = 0, t = 0;
			if (root->left != NULL)
				ah = getHeight(root->left, maxWeight);
			if (root->right != NULL)
				bh = getHeight(root->right, maxWeight);
			t = ah + bh;
			if (maxWeight < t)
				maxWeight = t;
			return max(ah + 1, bh + 1);
		}
		return 0;
	}
	int diameterOfBinaryTree(TreeNode* root) {
		int t = 0;
		getHeight(root, t);
		return t;
	}
};


// 二叉树的所有路径:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:


	void doit(TreeNode* root, vector<string>& vec, string ss) {
		ss += to_string(root->val) + "->";

		// 到了叶子节点 就终止.
		if (root->left == NULL && root->right == NULL && !ss.empty()) {
			ss = ss.substr(0, ss.length() - 2);
			// cout << ss << endl;
			vec.push_back(ss);
		}

		if (root->left != NULL)
			doit(root->left, vec, ss);

		if (root->right != NULL)
			doit(root->right, vec, ss);
	}


	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> vec;

		if (root == NULL)
			return vec;

		doit(root, vec, "");
		return vec;
	}
};


// 二叉树的层平均值:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

	vector<double> averageOfLevels(TreeNode* root) {
		double arr[2005][2];
		for (int i = 0; i < 2005; ++i) {
			for (int k = 0; k < 2; ++k)
				arr[i][k] = 0;
		}

		queue<pair<TreeNode*, int>> que;
		vector<double> res;
		que.push(make_pair(root, 0));
		double sum = 0;

		// 这里有一点广搜的味道了
		while (!que.empty()) {
			TreeNode* tmp = que.front().first;
			int tmpn = que.front().second;
			que.pop();

			if (tmp != NULL) {
				sum += tmp->val;
				que.push(make_pair(tmp->left, tmpn + 1));
				que.push(make_pair(tmp->right, tmpn + 1));

				// 难点在每层多少的计数！
				// 层次遍历的同时记录每层有多少个以及每层的总和.
				arr[tmpn][0]++;
				arr[tmpn][1] += tmp->val;
			}
		}

		for (int i = 0; arr[i][0] != 0; ++i) {
			res.push_back(arr[i][1] / arr[i][0]);
		}

		return res;
	}
};


// 二叉树的坡度:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	// 这是递归计算总和的函数, 递归计算一棵树总和.
	int countChild(TreeNode* node) {
		if (node == NULL)
			return 0;
		return node->val + countChild(node->left) + countChild(node->right);
	}

	// 关键在下面的简洁的return
	int findTilt(TreeNode* root) {
		if (root == nullptr)
			return 0;

		// 返回 根节点的坡度 加上 左孩子坡度右孩子坡度 这是算的时候不是从头开始，是从最下面开始 然后就是一层层返回就是总的了
		// 返回的是要利用前面的加和 就是一定要 return 本函数 + ...
		// 树形, return 递归函数 + 附属值.. 递归看成计算好的.
		return abs(countChild(root->left) - countChild(root->right)) + findTilt(root->left) + findTilt(root->right);
	}

};


// 合并二叉树:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
	{
		// 如果是空针就不用加了
		if (t1 == NULL)
			return t2;
		if (t2 == NULL)
			return t1;

		// 全部都加到一棵树上去
		// 注意在merge的时候 子树是如何被执行的.
		t1->val += t2->val;
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);
		return t1;
	}

};

// 翻转二叉树:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

	void exchange(TreeNode* root) {
		TreeNode* node = root;
		// 交换左右结点.
		if (node != NULL) {
			TreeNode* temp = node->left;
			node->left = node->right;
			node->right = temp;
		}
		/*cout << "---:";
		if (node->left != NULL)
			cout << node->left->val << "   ";
		if (node->right != NULL)
			cout << node->right->val;
		cout << endl;*/
	}

	// 这个递归很不好理解啊
	// 但是实际上还是最低下的先交换
	// 注意函数invertTree返回的时候 继续往下做的时候 是在最底下为空的时候 就是root == NULL 的时候
	TreeNode* invertTree(TreeNode* root) {
		TreeNode* node = root;
		if (root == NULL) {
			return root;
		}

		// 这个就是先处理递归, 再处理自己的.
		// 因为递归处理是要从最底层的开始翻转, 然后往上翻转上来, 所以最上层的要最后来做.
		invertTree(node->left);//翻转左子树
		invertTree(node->right);//翻转右子树
		exchange(node);//交换左子节点与右子节点
		return root;
	}

};


// 对称二叉树:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool compRoot(TreeNode* l, TreeNode* r) {
		// 前面要把NULL的判断好.
		if (l == NULL)
			return (r == NULL);

		if (r == NULL)
			return false;

		if (r->val != l->val)
			return false;

		// 注意对称的比较, 是l->left 和 r->right比较 然后 l->right, r->left 的比较.
		return (compRoot(l->left, r->right) && compRoot(l->right, r->left));
	}

	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;

		return compRoot(root->left, root->right);
	}

};




// K个一组翻转链表
// 注意核心思路以及操作:


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == NULL || head->next == NULL || k == 1)
			return head;
		int num = 0;
		for (ListNode* t = head; t != NULL; t = t->next, ++num);
		ListNode* tHead = head, * tTail = head->next, * reaHead = head, * coneHead = head;
		for (int j = 0; j < num / k; ++j) {
			for (int i = 0; i < k - 1; ++i) {
				/*if (tTail->next == NULL) {    // 这里本来想整除的时候就可以直接跳出 但是后面想一想没有必要
					tTail->next = reaHead;
					tHead->next = NULL;

					reaHead = tTail;

					tTail = NULL;
					break;
				}*/
				tHead->next = tTail->next;
				tTail->next = reaHead;
				reaHead = tTail;
				if (coneHead != head)
					coneHead->next = reaHead;
				tTail = tHead->next;
			}
			if (coneHead == head)
				head = reaHead;
			if (j == num / k - 1)
				break;
			coneHead = tHead;
			tHead = tTail;
			tTail = tTail->next;
			reaHead = tHead;
		}
		// 剩下的翻转过来
		/*if (tTail != NULL) {
			while (tTail != NULL) {
				tHead->next = tTail->next;
				tTail->next = reaHead;
				reaHead = tTail;
				tTail = tHead->next;
			}
		}*/

		return head;
	}

};


