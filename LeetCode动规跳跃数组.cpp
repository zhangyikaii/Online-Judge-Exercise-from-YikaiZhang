#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

bool canJump(vector<int>& nums) {
	//int used[10005] = { 0 };
	//used[0] = 1;
	//for (int i = 0; i < nums.size(); ++i) {
	//	if (used[i] == 1) {
	//		for (int k = 1; k < nums[i]; ++k) {
	//			used[i + k] = 1;
	//		}
	//	}
	//}

	//if (used[nums.size() - 1] == 1)
	//	return true;
	//else return false;

	int maxx = 0;
	for (int i = 0; i < nums.size(); ++i) {
		if (maxx < i)
			return false;
		maxx = max(nums[i] + i, maxx);
		if (maxx >= nums.size())
			return true;
	}

	return true;
}

int main() {
	

	return 0;
}


/*
跳跃游戏: 每个点的可以跳跃的最大长度已知, 问能不能到最后一个点.

最后用贪心解的, 记录当前能到达的最大路径, 扫一遍数组, 如果下标 > 能到达的最大路径, return false.

注意一下细节, 多测再交

*/