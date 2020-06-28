#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

// vis数组可以拿来传参
// vis数组记录的是位置, 这个位置有没访问过.
void permuteUniqueDFS(vector<int> &nums, vector<int> &visited, vector<int> &resVec, vector<vector<int> > &res) {
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

vector<vector<int>> permuteUnique(vector<int> &nums) {
	// write your code here
	vector<vector<int> > res;
	vector<int> resVec;
	vector<int> visited(nums.size(), 0);
	sort(nums.begin(), nums.end());
	permuteUniqueDFS(nums, visited, resVec, res);
	return res;
}
