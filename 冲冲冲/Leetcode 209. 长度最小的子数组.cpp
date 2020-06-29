#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define Fee(i, b, e) for(int i = (b); i <= (e); ++i)
#define Ree(i, b, e) for(int i = (b); i >= (e); --i)

#define INF 0x7fffff

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int l = 0, r = 0;
		int sumAll = 0;
		int minLength = nums.size() + 1;
		while (l < nums.size()) {
			if (r < nums.size() && sumAll < s) {
				sumAll += nums[r++];
			}
			else {
				sumAll -= nums[l++];
			}
			if (sumAll >= s)
				minLength = min(minLength, r - l);
		}
		if (minLength == nums.size() + 1) return 0;
		return minLength;
	}
};

int main() {

	
	return 0;
}