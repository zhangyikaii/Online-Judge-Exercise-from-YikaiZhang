#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define Fee(i, b, e) for(int i = (b); i <= (e); ++i)
#define Ree(i, b, e) for(int i = (b); i >= (e); --i)
	typedef long long ll;
	int deleteAndEarn(vector<int>& nums) {
		int dict[10010] = { 0 };
		int maxNum = 0;
		For(i, 0, nums.size()) {
			++dict[nums[i]];
			maxNum = max(maxNum, nums[i]);
		}

		int dp[10010] = { 0 };
		dp[1] = dict[1];
		Fee(i, 2, maxNum) {
			// 因为如果拿了当前这个数, 意味着前一个没有拿.
			dp[i] = max(dp[i - 1], dp[i - 2] + dict[i] * i);
		}

		return dp[maxNum];
	}
};

int main() {
	Solution s;
	vector<int> nums = { 2, 2, 3, 3, 3, 4 };
	cout << s.deleteAndEarn(nums) << endl;
	
	return 0;
}