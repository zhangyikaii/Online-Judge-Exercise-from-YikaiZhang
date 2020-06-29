#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>

class Solution {
public:
	int maxChoosableInteger, desiredTotal;
	std::unordered_map<unsigned long long, bool> mp;

	// 当前这个状态下, 能否稳赢. total_sum记录当前的和, bitset记录那些数已经被选择过了
	bool dfs(int total_sum, std::bitset<25> bs) {
		// 递归的边界
		if (total_sum >= desiredTotal)
			return true;
		// 记忆化
		if (mp.find(bs.to_ullong()) != mp.end()) return mp[bs.to_ullong()];

		bool ret = true;
		// 假设当前状态是A
		// 这里就是上文说的, 枚举B走的所以情况的(用一个for), 只有循环里B都不能稳赢, A才能稳赢. 
		for (int i = 1; i <= maxChoosableInteger; ++i) {
			if (bs[i]) continue;
			std::bitset<25> bs_tmp = bs;
			bs_tmp[i] = 1;
			// 这里就是枚举B 
			if (dfs(total_sum + i, bs_tmp)) {
				ret = false;
				break;
			}
		}
		return mp[bs.to_ullong()] = ret;
	}

	bool canIWin(int a_, int b_) {
		maxChoosableInteger = a_;
		desiredTotal = b_;
		// 所有数加起来都小于desiredTotal, 则稳输
		if ((maxChoosableInteger + 1) * maxChoosableInteger * 0.5 < desiredTotal)
			return false;
		for (int i = 1; i <= maxChoosableInteger; ++i) {
			bitset<25> bs;
			bs[i] = 1;
			if (dfs(i, bs)) return true;
		}
		return false;
	}
};

int main() {
	Solution s;
	vector<int> nums = { 2, 2, 3, 3, 3, 4 };
	cout << s.deleteAndEarn(nums) << endl;

	return 0;
}