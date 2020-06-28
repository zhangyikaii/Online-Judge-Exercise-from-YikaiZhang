#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
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

	int gcd(int a, int b) {
		return a == 0 ? b : gcd(b % a, a);
	}

	vector<int> fraction(vector<int>& cont) {
		// 迭代计算 a + b/c 的最简结果:
		int len = cont.size();
		
		// 注意边界条件:
		if (len == 1) {
			vector<int> tmp = { cont[0], 1 };
			return tmp;
		}
		else if (len == 0) {
			return vector<int>();
		}

		// 初始化abc:
		int a = cont[len - 2], b = 1, c = cont[len - 1];
		len -= 2;
		while (len >= 0) {
			a = cont[len--];
			// 开始计算 a + b/c 最简结果, 放在b/c:
			b = a * c + b;
			int bcGcd = gcd(b, c);
			b /= bcGcd, c /= bcGcd;

			if (b < 0)
				b = -b, c = -c;

			// cout << b << " " << c << endl;
			// 计算 1 / (b/c)
			int tmp = b;
			b = c;
			c = tmp;
		}
		
		// 因为迭代内的结果被翻过来了, 所以再翻一次.
		vector<int> tmp = { c, b };
		return tmp;
	}
};
int main() {
	Solution s;
	vector<int> vec = { 3, 2, 0, 2 };
	vec = s.fraction(vec);

	for (auto i : vec)
		cout << i << endl;

	return 0;
}