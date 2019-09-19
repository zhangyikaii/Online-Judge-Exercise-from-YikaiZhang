#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <functional>
#include <stack>
#include <unordered_map>

using namespace std;

#define in(x) x=read()

#define MAXN 1000000

typedef long long ll;
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int val) {
//		this->val = val;
//		this->next = NULL;
//			
//	}
//};
//
//inline int read() {
//	int X = 0, w = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X*w;
//}
//
//int n;
//bool isShuiXian(int n, int c) {
//	int ans = 0, nn = n;
//	while (n != 0) {
//		int t = n % 10, tt = n % 10;
//		int cc = c;
//		while (--cc)
//			t *= tt;
//		ans += t;
//		if (ans > nn)
//			return false;
//		n /= 10;
//	}
//	if (ans == nn)
//		return true;
//
//	return false;
//}
//
//void rotate(string &s, int l, int r) {
//	int n = r - l;
//	for (int i = 0; i < n / 2; ++i) {
//		int tmp = s[i + l];
//		s[i + l] = s[l + n - i - 1];
//		s[l + n - i - 1] = tmp;
//	}
//}
//
//string reverseWords(string &s) {
//	int curSpace = 0;
//	for (int i = s.size() - 1; i >= 0; --i) {
//		if (s[i] != ' ') {
//			s = s.substr(0, i + 1);
//			break;
//		}
//	}
//	for (int i = 0; i < s.size(); ++i) {
//		if (s[i] != ' ') {
//			s = s.substr(i, s.size());
//			break;
//		}
//	}
//
//	string ans;
//	bool flag = false;
//	for (int i = 0; i < s.size(); ++i) {
//		if (flag == false && s[i] == ' ') {
//			flag = true;
//			ans += s[i];
//		}
//		else if (flag == true && s[i] != ' ')
//			flag = false;
//
//		if (flag == false)
//			ans += s[i];
//	}
//	int iAns = ans.size();
//	for (int i = 1; i < iAns; ++i) {
//		if (ans[i] == ' ' && ans[i - 1] != ' ') {
//			rotate(ans, curSpace, i);
//		}
//		else if (ans[i] != ' ' && ans[i - 1] == ' ')
//			curSpace = i;
//	}
//	if (curSpace != 0) {
//		rotate(ans, curSpace, iAns);
//		rotate(ans, 0, iAns);
//	}
//	return ans;
//}
//
//int searchInsert(vector<int> &A, int target) {
//	// write your code here
//	if (A.empty())
//		return 0;
//	int l = 0, r = A.size() - 1, mid;
//	if (A[r] < target)
//		return r + 1;
//	else if (A[l] > target)
//		return 0;
//	while (l <= r) {
//		mid = (l + r) >> 1;
//		if (A[mid] < target && A[mid + 1] > target)
//			return mid + 1;
//		if (A[mid] > target)
//			r = mid - 1;
//		else if (A[mid] < target)
//			l = mid + 1;
//		else
//			return mid;
//	}
//
//
//}
//void Swap(vector<int> &arr, int a, int b) {
//	if (a != b) {
//		int tmp = arr[a];
//		arr[a] = arr[b];
//		arr[b] = tmp;
//	}
//}
//int deduplication(vector<int> &nums) {
//	// write your code here
//	sort(nums.begin(), nums.end());
//	int l = 0;
//	for (int i = 1; i < nums.size(); ++i) {
//		if (nums[l] != nums[i])
//			Swap(nums, ++l, i);
//	}
//
//	return l;
//}
//vector<vector<int>> multiSort(vector<vector<int>> &array) {
//	// Write your code here
//	int n = array.size();
//	for (int i = 0; i < n; ++i) {
//		int maxx = i;
//		for (int k = i + 1; k < n; ++k) {
//			if (array[maxx][1] == array[k][1] && array[maxx][0] > array[k][0])
//				maxx = k;
//			else if (array[maxx][1] < array[k][1])
//				maxx = k;
//		}
//		if (maxx != i) {
//			int at = array[maxx][0], bt = array[maxx][1];
//			array[maxx][0] = array[i][0];
//			array[maxx][1] = array[i][1];
//			array[i][0] = at;
//			array[i][1] = bt;
//		}
//	}
//
//	return array;
//}
//
//string depress(int m, int k, vector<int> &arr) {
//	// Write your code here.
//	priority_queue<int, vector<int>, greater<int>> q;
//	int ans = 0;
//	for (int i = 0; i < arr.size(); ++i) {
//		q.push(arr[i]);
//	}
//	while (k--) {
//		ans += q.top();
//		q.pop();
//	}
//	if (ans >= m)
//		return "no";
//	else
//		return "yes";
//}
//
//ListNode * insertNode(ListNode * head, int val) {
//	// write your code here
//	if (head == NULL) {
//		head = new ListNode(val);
//		return head;
//	}
//
//	if (head->val > val) {
//		ListNode *tmp = new ListNode(val);
//		tmp->next = head;
//		head = tmp;
//		return head;
//	}
//
//	ListNode *pre = head;
//
//	ListNode *i = NULL;
//	for (i = head->next; i != NULL; i = i->next) {
//		if (i->val > val) {
//			ListNode *tmp = new ListNode(val);
//			pre->next = tmp;
//			tmp->next = i;
//			return head;
//		}
//		pre = i;
//	}
//	if (i == NULL)
//		pre->next = new ListNode(val);
//	return head;
//}
//
//struct Data {
//	int x, y;
//	Data() { }
//	Data(int a, int b) : x(a), y(b) { }
//};
//
////bool used[1010][1010];
//int xw[4] = { 1, -1, 0, 0 };
//int yw[4] = { 0, 0, 1, -1 };
//bool findHer(vector<string> &maze) {
//	// Write your code here
//	queue<Data> q;
//	int ax, ay;
//	for (int i = 0; i < maze.size(); ++i) {
//		for (int k = 0; k < maze[i].size(); ++k) {
//			used[i][k] = false;
//			if (maze[i][k] == 'S') {
//				ax = i;
//				ay = k;
//			}
//		}
//	}
//
//	q.push(Data(ax, ay));
//	used[ax][ay] = true;
//	while (!q.empty()) {
//		Data t = q.front();
//		q.pop();
//		if (maze[t.x][t.y] == 'T')
//			return true;
//		for (int i = 0; i < 4; ++i) {
//			int xt = t.x + xw[i], yt = t.y + yw[i];
//			if (xt >= 0 && xt < maze.size() && yt >= 0 && yt < maze[xt].size() && maze[xt][yt] == '.' && used[xt][yt] == false) {
//				q.push(Data(xt, yt));
//				used[xt][yt] = true;
//			}
//			
//		}
//	}
//
//	return false;
//}
//
//
//bool isPrime[1010] = { 0 };
//int prime[1010] = { 0 };
//int used[20] = { 0 };
//
//// isPrime 下标是某个数 = true表示是素数 false表示不是
//// prime 按顺序存素数
//
//void init() {
//	int cnt = 1;
//	memset(isPrime, 1, sizeof(isPrime));			// 初始化认为所有数都为素数
//	isPrime[0] = isPrime[1] = 0;					// 0和1不是素数
//	for (long long i = 2; i <= 1000; i++) {
//		if (isPrime[i])
//			prime[cnt++] = i;						// 保存素数i
//		for (long long j = 1; j<cnt && prime[j] * i < 1000; j++) {
//			isPrime[prime[j] * i] = 0;				// 筛掉小于等于i的素数和i的积构成的合数 !
//		}
//	}
//}
//
//int res = 0;
//
//void dfs(int k, int cur, vector<int> &a, int curArr[], int curChoose) {
//	if (cur == k) {
//		int ans = 0;
//		for (int i = 0; i < cur; ++i) {
//			ans += curArr[i];
//			// cout << curArr[i] << " ";
//		}
//		// cout << endl;
//		if (isPrime[ans] == true) {
//			// cout << ans << "          ------------------" << endl;
//			++res;
//		}
//		return;
//	}
//
//	for (int i = curChoose + 1; i < a.size(); ++i) {
//		if (used[i] == 0) {
//			used[i] = 1;
//			curArr[cur] = a[i];
//			dfs(k, cur + 1, a, curArr, i);
//			used[i] = 0;
//		}
//	}
//}
//
//int getWays(vector<int> &a, int k) {
//	// Write your code here
//	init();
//	int curArr[30] = { 0 };
//	dfs(k, 0, a, curArr, -1);
//	return res;
//}
//
//vector<vector<int>> threeSum(vector<int> &numbers) {
//	// Write your code here
//	sort(numbers.begin(), numbers.end());
//	int n = numbers.size();
//	vector<vector<int>> res;
//	for (int i = 0; i < n; ) {
//		int l = i + 1, r = n - 1;
//		while (l < r) {
//			if (numbers[l] + numbers[r] > -numbers[i]) {
//				int tr = r;
//				while (--r >= 0 && numbers[r] == numbers[tr]);
//				if (r < 0)
//					break;
//			}
//			else if (numbers[l] + numbers[r] < -numbers[i]) {
//				int tl = l;
//				while (++l < n && numbers[l] == numbers[tl]);
//				if (l >= n)
//					break;
//			}
//			else {
//				vector<int> tmp;
//				tmp.push_back(numbers[i]);
//				tmp.push_back(numbers[l]);
//				tmp.push_back(numbers[r]);
//				res.push_back(tmp);
//				int tr = r;
//				while (--r >= 0 && numbers[r] == numbers[tr]);
//				int tl = l;
//				while (++l < n && numbers[l] == numbers[tl]);
//				if (r < 0 || l >= n)
//					break;
//			}
//		}
//
//		int tmp = i;
//		while (++i < n && numbers[i] == numbers[tmp]);
//	}
//
//	return res;
//}
//BFPRT算法
//void swap(vector<int> &nums, int i, int j) {
//	int numOfIndex = nums[i];
//	nums[i] = nums[j];
//	nums[j] = numOfIndex;
//}
//int partion(vector<int>&nums, int l, int r, int m) {
//	int s = nums[m];
//	swap(nums, l, m);
//	int j = l;
//	for (int i = l + 1; i <= r; i++) {
//		if (nums[i] < s) {
//			j++;
//			swap(nums, j, i);
//		}
//	}
//	swap(nums, j, l);
//	return j;
//}
////找一个数在nums数组中的位置
//int findId(vector<int> &nums, int l, int r, int val) {
//	for (int i = l; i <= r; i++) {
//		if (nums[i] == val)
//			return i;
//	}
//	return -1;
//}
//int findMedia(vector<int> &nums, int l, int r) {
//	if (l == r)
//		return nums[l];
//	int i = l;
//	int n;
//	for (i = l; i <= r - 5; i += 5)
//	{
//		sort(nums.begin() + l, nums.begin() + 5 + l);
//		n = i - l;
//		swap(nums, l + n / 5, i + 2);
//	}
//	int a = r - i + 1;
//	if (a>0)
//	{
//		sort(nums.begin() + i, nums.begin() + r + 1);
//		n = i - l;
//		swap(nums, l + n / 5, i + a / 2);
//	}
//	n = n / 5;
//	return findMedia(nums, l, l + n);
//}
//int bfptr(vector<int> &nums, int l, int r, int k) {
//	int n = findMedia(nums, l, r);
//	int id = findId(nums, l, r, n);
//	int i = partion(nums, l, r, id);
//
//	int m = i - l + 1;
//	if (m == k)
//		return nums[i];
//	// 说明第 k 大的在后半部分.
//	else if (m < k) {
//		return bfptr(nums, i + 1, r, k - m);
//	}
//	else {
//		return bfptr(nums, l, i - 1, k);
//	}
//}
//int findKthLargest(vector<int>& nums, int k) {
//	return bfptr(nums, 0, nums.size() - 1, nums.size() - k + 1);
//}


// 3, 2, 2, 1, 4
//void sortColors2(vector<int> &colors, int k) {
//	// write your code here
//	int size = colors.size();
//	if (size <= 0) {
//		return;
//	}
//
//	int index = 0;
//	while (index < size) {
//		int numOfIndex = colors[index] - 1;
//		if (colors[index] <= 0){
//			index++;
//		}
//		else {
//			// 如果index对应的这个数之前已经记录过, 就数目加上去=>colors[numOfIndex]--;  然后index这个位置可以用了, 不用再后面怕覆盖然后交换了, 所以就赋为 0 => colors[index] = 0;
//			if (colors[numOfIndex] <= 0) {
//				colors[numOfIndex]--;
//				colors[index] = 0;
//				index++;
//			}
//
//			// 如果这个numOfIndex这个位置还没被记录过, 就swap一下, 然后index不要动!!! 这样就保证 numOfIndex 原来位置记录的东西不会被漏掉
//			else {
//				swap(colors[index], colors[numOfIndex]);
//				colors[numOfIndex] = -1;
//			}
//		}
//	}
//
//	int i = size - 1;
//	while (k > 0) {
//		for (int j = 0; j>colors[k - 1]; j--) {
//			colors[i--] = k;
//		}
//		k--;
//	}
//}

bool judge(vector<int> &A, int m, int curMin) {
	int curAns = 0, i = 0, n = A.size();
	while (i < n && A[i] < curMin) {
		++curAns;
		++i;
	}
	for (int bef = i; bef < n; bef = i) {
		i = bef + 1;
		while (i < n && A[i] - A[bef] < curMin) {
			++curAns;
			++i;
		}
		if (curAns > m)
			return false;
	}

	if (curAns > m)
		return false;
	return true;
}
int getDistance(int n, int m, int target, vector<int> &d) {
	// Write your code here.
	d.push_back(target);
	int l = 0, r = target, mid = 0, ans = 0;

	// 二分注意点: 太小返回的都是 true, 找到最大的那个返回true的即可;
	// 注意这里是 l <= r, 然后下面是 mid + 1 和 mid - 1, 注意啦!!! 不然会有问题的
	while (l <= r) {
		mid = ((l + r) >> 1);
		if (judge(d, m, mid) == true) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return ans;
}

long long doingHomework(vector<int> &cost, vector<int> &val) {
	// Write your code here.
	vector<long long> s;
	long long res = 0;
	s.push_back(cost[0]);
	for (int i = 1; i < cost.size(); i++) {
		s.push_back(s[i - 1] + cost[i]);
	}

	for (int i = 0; i < s.size(); ++i) {
		cout << s[i] << "   ";
	}
	cout << endl;

	for (int i = 0; i < val.size(); ++i) {
		if (s[0] > val[i]) {
			continue;
		}
		int l = 0, r = s.size() - 1, curAns = 0, mid;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (s[mid] > val[i]) {
				r = mid - 1;
			}
			else {
				curAns = mid;
				l = mid + 1;
			}
		}
		cout << s[curAns] << endl;
		res += s[curAns];
	}

	return res;
}

long long MyMax(long long a, long long b) {
	return a > b ? a : b;
}

long long playGames(vector<int> &A) {
	long long max = 0;
	for (auto a : A){
		max = MyMax(a, max);
	}
	long long l = 0, r = max * 2;
	while (l<r){//cnt表式某一人完成时的游戏次数
		long long m = (l + r) / 2;
		long long cnt = 0;
		for (auto a : A) {
			cnt += MyMax(m - a, 0);
		}
		if (m>cnt){
			l = m + 1;
		}
		else{
			r = m;
		}
	}
	return MyMax(l, max);
}

int lengthOfLongestSubstring(string &s) {
	// write your code here
	int n = s.size();
	if (n <= 1)
		return n;

	// 注意啊 pre 一定是上一个相同的元素的后面一个!!! 想清楚哇
	int curMax = 0, pre = 1;
	map<char, int> m;
	for (int i = 0; i < n; ++i) {
		if (m[s[i]] == 0) {
			m[s[i]] = i + 1;
		}
		else if (m[s[i]] != 0) {
			curMax = max(curMax, i + 1 - pre);
			pre = max(pre, m[s[i]] + 1);			// 太 tm 多陷阱了, 程序lubang性很差啊啊啊
			m[s[i]] = i + 1;
		}
	}


	return max(curMax, n - pre + 1);
}

// 抓住周期的概念, 任务个数最大值count是多少, 就一定有 count - 1 个周期的 n + 1, n 是周期前的即使任务没那么多就用周期填, +1 就是冷却时间. 有多少个最大, 在count - 1 个周期之后就还有多少个单独剩下的不用冷却的, 就遍历再加
int leastInterval(string &tasks, int n) {
	// write your code here
	unordered_map<char, int> mp;
	int count = 0;              // 任务个数最大值
	for (auto e : tasks) {
		mp[e]++;
		count = max(count, mp[e]);
	}

	int ans = (count - 1) * (n + 1);
	for (auto e : mp) {
		if (e.second == count) {
			++ans;
		}
	}
	return max((int)tasks.size(), ans);
}


stack<int> stk, minstk;
// 抓住后入栈的更大的值一定不会被 min() 取到. 因为在栈上面, 比他更小的值pop出去之前他已经pop了

void push(int number) {
	// write your code here
	stk.push(number);
	if (minstk.empty() || minstk.top() >= number)
		minstk.push(number);
}

/*
* @return: An integer
*/
int pop() {
	if (minstk.top() == stk.top())
		minstk.pop();
	int tmp = stk.top();
	stk.pop();
	return tmp;
	// write your code here
}

/*
* @return: An integer
*/
int min() {
	return minstk.top();
	// write your code here
}

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//
//struct Data {
//	TreeNode *ptr;
//	int level;
//	Data() { };
//	Data(TreeNode *t, int l) : ptr(t), level(l) { }
//};
//vector<ListNode*> binaryTreeToLists(TreeNode* root) {
//	// Write your code here
//	vector<ListNode*> res;
//	if (root == NULL)
//		return res;
//	queue<Data> q;
//	q.push(Data(root, 1));
//	while (!q.empty()) {
//		Data tmp = q.front();
//		q.pop();
//		if (res.size() < tmp.level) {
//			ListNode *head = new ListNode(tmp.ptr->val);
//			res.push_back(head);
//		}
//		else {
//			ListNode *tail = res[tmp.level - 1];
//			while (tail->next != NULL)
//				tail = tail->next;
//			tail->next = new ListNode(tmp.ptr->val);
//		}
//
//		if (tmp.ptr->left != NULL)
//			q.push(Data(tmp.ptr->left, tmp.level + 1));
//		if (tmp.ptr->right != NULL)
//			q.push(Data(tmp.ptr->right, tmp.level + 1));
//	}
//
//	return res;
//}
//

struct Data {
	int s, n, m, step;
	Data() { }
	Data(int ss, int nn, int mm, int st) : s(ss), n(nn), m(mm), step(st) { }
};
int getMinTimes(int s, int n, int m) {
	// Write your code here
	if (s & 1 != 0)
		return -1;
	bool used[110][110];
	queue<Data> q;
	q.push(Data(s, n, m, 0));
	used[n][m] = true;

	while (!q.empty()) {
		Data tmp = q.front();
		q.pop();
		if ((tmp.m == tmp.n && tmp.m != 0) || (tmp.s == tmp.m && tmp.m != 0) || (tmp.s == tmp.n && tmp.n != 0))
			return tmp.step;

		if (m - tmp.m <= tmp.s && used[tmp.n][m] == false) {
			q.push(Data(tmp.s - (m - tmp.m), tmp.n, m, tmp.step + 1));
			used[tmp.n][m] = true;
		}
		else if (m - tmp.m > tmp.s && used[tmp.n][tmp.m + tmp.s] == false) {
			q.push(Data(0, tmp.n, tmp.m + tmp.s, tmp.step + 1));
			used[tmp.n][tmp.m + tmp.s] = true;
		}
		if (n - tmp.n <= tmp.s && used[n][tmp.m] == false) {
			q.push(Data(tmp.s - (n - tmp.n), n, tmp.m, tmp.step + 1));
			used[n][tmp.m] = true;
		}
		else if (n - tmp.n > tmp.s && used[tmp.n + tmp.s][tmp.m] == false) {
			q.push(Data(0, tmp.n + tmp.s, tmp.m, tmp.step + 1));
			used[tmp.n + tmp.s][tmp.m] = true;
		}

		if (s - tmp.s >= tmp.m && used[tmp.n][0] == false) {
			q.push(Data(tmp.s + tmp.m, tmp.n, 0, tmp.step + 1));
			used[tmp.n][0] = true;
		}
		else if (s - tmp.s < tmp.m && used[tmp.n][tmp.m - (s - tmp.s)] == false) {
			q.push(Data(s, tmp.n, tmp.m - (s - tmp.s), tmp.step + 1));
			used[tmp.n][tmp.m - (s - tmp.s)] = true;
		}
		if (s - tmp.s >= tmp.n && used[0][tmp.m] == false) {
			q.push(Data(tmp.s + tmp.n, 0, tmp.m, tmp.step + 1));
			used[0][tmp.m] = true;
		}
		else if (s - tmp.s < tmp.n && used[tmp.n - (s - tmp.s)][tmp.m] == false) {
			q.push(Data(s, tmp.n - (s - tmp.s), tmp.m, tmp.step + 1));
			used[tmp.n - (s - tmp.s)][tmp.m] = true;
		}

		if (m - tmp.m >= tmp.n && used[0][tmp.m + tmp.n] == false) {
			q.push(Data(tmp.s, 0, tmp.m + tmp.n, tmp.step + 1));
			used[0][tmp.m + tmp.n] = true;
		}
		else if (m - tmp.m < tmp.n && used[tmp.n - (m - tmp.m)][m] == false) {
			q.push(Data(tmp.s, tmp.n - (m - tmp.m), m, tmp.step + 1));
			used[tmp.n - (m - tmp.m)][m] = true;
		}
		if (n - tmp.n >= tmp.m && used[tmp.m + tmp.n][0] == false) {
			q.push(Data(tmp.s, tmp.m + tmp.n, 0, tmp.step + 1));
			used[tmp.m + tmp.n][0] = true;
		}
		else if (n - tmp.n < tmp.m && used[n][tmp.m - (n - tmp.n)] == false) {
			q.push(Data(tmp.s, n, tmp.m - (n - tmp.n), tmp.step + 1));
			used[n][tmp.m - (n - tmp.n)] = true;
		}
	}

	return false;
}



int reachNumber(int target) {
	// Write your code here
	int cur = 0, i, ans = 0;
	for (i = 1; i <= target; ++i) {
		if (cur + i > target)
			break;
		cur += i;
		++ans;
	}

	if (cur != target)
		ans += (target - cur) * 2;
	return ans;
}
//
//string arr[100];
//int used[100] = { 0 };
//vector<vector<string> > res;
//
//bool check(int arra[], int col, int n) {
//	for (int i = 0; i < col; ++i) {
//		if (arra[i] == col && abs(arra[i] - arra[col]) == col - i)
//			return false;
//	}
//	return true;
//}
//void dfs(int cur, int n, int arra[]) {
//	if (cur == n) {
//		vector<string> tmp;
//		for (int i = 0; i < n; ++i) {
//			tmp.push_back(arr[arra[i]]);
//		}
//		res.push_back(tmp);
//	}
//
//	for (int i = 0; i < n; ++i) {
//		if (check(arra, i, n)) {
//			arra[cur]
//			dfs(cur + 1, n, arra);
//			used[i] = 0;
//		}
//	}
//}
//
//vector<vector<string>> solveNQueens(int n) {
//	// write your code here
//	for (int i = 0; i < n; ++i) {
//		for (int k = 0; k < n; ++k) {
//			if (i == k)
//				arr[i][k] = 'Q';
//			else
//				arr[i][k] = '.';
//		}
//	}
//}

vector<vector<int> > resu;
int used[200] = { 0 };
void dfs(vector<int> &A, int k, int target, int curArr[], int cur, int curAns) {
	if (cur == k && curAns == target) {
		vector<int> tmp;
		for (int i = 0; i < k; ++i)
			tmp.push_back(curArr[i]);
		return;
	}
	else if (curAns > target)
		return;

	for (int i = 0; i < A.size(); ++i) {
		if (used[i] == 0) {

		}
	}
}
vector<vector<int>> kSumII(vector<int> &A, int k, int target) {
	// write your code here
	sort(A.begin(), A.end());
	vector<vector<int> > ans;
	if (A.size() == 0)
		return ans;
	else if (A.size() == 1) {
		if (A[0] == target) {
			vector<int> tmp;
			tmp.push_back(A[0]);
			ans.push_back(tmp);
		}
	}




	return ans;
}

// 感觉这种暴力的方法还是很不错的.
int ans[105][1005];
void append(vector<vector<int> > & A, vector<vector<int> > &B, int C) {
	for (int i = 0; i < B.size(); i++) {
		A.push_back(B[i]);
		A[A.size() - 1].push_back(C);
	}
}
vector<vector<int> > anslist[105][1005];
// ans[i][j] 表示 i 是有几个数加进来, 
vector<vector<int> > kSumII(vector<int> A, int k, int target) {
	ans[0][0] = 1;
	// 可以这样创建 vector< vector<int> >
	anslist[0][0].push_back(vector<int>());
	for (int i = 0; i < A.size(); ++i) {
		for (int j = k; j > 0; j--) {
			for (int l = target; l >= A[i]; l--) {
				ans[j][l] += ans[j - 1][l - A[i]];
				append(anslist[j][l], anslist[j - 1][l - A[i]], A[i]);
			}
		}
	}
	return anslist[k][target];
}

int main() {
	
	/*vector<int> v = { 9, 3, 3, 1, 7, 5, 8 };
	vector<int> v2 = { 17, 35, 25, 1, 1, 15, 25, 25, 5, 19 };
	vector<string> vs = { "....*", ".....", ".....", "*S**.", "T**.*"};
	stack<int> s;
	cout << doingHomework(v, v2) << endl;*/

	/*string s = "an++--viaj";
	cout << lengthOfLongestSubstring(s);
	queue<int> q;*/
	
	// sortColors2(v, 4);
	// threeSum(v);
	// cout << findHer(vs) << endl;
	

	//cout << depress(7, 3, v);
	//

	//cout << searchInsert(v, 1);
	
	
	
	return 0;
}


/*

给出2*n + 1 个的数字，除其中一个数字之外其他每个数字均出现两次，找到这个数字。



样例
给出 [1,2,2,1,3,4,3]，返回 4

挑战
一次遍历，常数级的额外空间复杂度


*/