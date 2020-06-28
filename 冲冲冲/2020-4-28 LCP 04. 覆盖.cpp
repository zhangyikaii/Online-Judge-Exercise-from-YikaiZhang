#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define INF 0x7fffff

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

class Solution {
#define For(i, b, e) for(int i = (b); i < (e); ++i)

	struct Data	{
		int x, y;
		Data() : x(0), y(0) { }
		Data(int xx, int yy) : x(xx), y(yy) { }

		bool operator<(const Data a) const {
			if (this->y == a.y)
				return this->x < a.x;
			return this->y < a.y;
		}
	};
public:
	int domino(int n, int m, vector<vector<int>>& broken) {
		map<Data, bool> ma;
		for (auto i : broken) {
			ma[Data(i[0], i[1])] = true;
		}

		int dp[280][70];
		For(i, 0, 280) {
			For(j, 0, 70)
				dp[i][j] = 0;
		}

		int maxState = 0x1 << m;
		int bef = (0x1 << (m - 1)), mask = bef | 0x1;
		For(i, 1, n) {
			For(j, 0, m) {
				int pos = i * m + j;
				
				For(cur, 0, maxState) {
					// 根据当前dp[cur][i * m + j]更新dp[next(由cur生成)][i * m + j + 1].
					// 要注意边界的情况, 就比如那m个元素刚好就是一行的时候. 也就是上面pos的j为零:
					if (ma[Data(i, j)] != true && j == 0) {
						if ((cur & bef) == bef)
							dp[(cur << 1) | 0x1][pos + 1] = max(dp[cur][pos], dp[(cur << 1) | 0x1][pos + 1]);
						else
							dp[(cur << 1) | 0x1][pos + 1] = max(dp[cur][pos] + 1, dp[(cur << 1) | 0x1][pos + 1]);
					}
					// 不能放的情况:
					if (ma[Data(i, j)] == true || (cur & mask) == mask) {
						// 左移, 低位补1, 占住位置就是不放.
						int curNext = (cur << 1) | (0x1);
						dp[curNext][pos + 1] = max(dp[cur][pos], dp[curNext][pos + 1]);
						continue;
					}

					// 如果可以横放:
					if ((cur & 0x1) != 0x1 && (cur & bef) == bef) {
						int curNext = (cur << 1) | (0x3);
						dp[curNext][pos + 1] = max(dp[cur][pos] + 1, dp[curNext][pos + 1]);
					}
					// 可以竖着放:
					else if ((cur & 0x1) == 0x1 && (cur & bef) != bef) {
						int curNext = (cur << 1) | (0x1);
						dp[curNext][pos + 1] = max(dp[cur][pos] + 1, dp[curNext][pos + 1]);
					}
					else {
						// 既可以竖着也可以横着放:
						int vertiNext = (cur << 1) | (0x1), acrossNext = (cur << 1) | (0x3);
						dp[vertiNext][pos + 1] = max(dp[cur][pos] + 1, dp[vertiNext][pos + 1]);
						dp[acrossNext][pos + 1] = max(dp[cur][pos] + 1, dp[acrossNext][pos + 1]);
					}
				}
			}
		}

		cout << dp[6][3] << endl;
		cout << dp[5][4] << endl;
		cout << dp[3][5] << endl;
		cout << dp[7][6] << endl;
		int ret = 0;
		For(cur, 0, maxState) {
			ret = max(ret, dp[cur][m * n]);
		}
		return ret;
	}
};

int main() {
	Solution s;
	vector<vector<int> > obs = { { 1, 0 }, { 1, 1 } };
	//vector<vector<int> >obs = {
	//	{7, 7}, {0, 5}, {2, 7}, {8, 6}, {8, 7}, {6, 5}, {4, 4}, {0, 3}, {3, 6}
	//};
	// vector<vector<int> > obs = { {6, 7}, {1, 7}, {0, 1}, {2, 9}, {5, 5}, {4, 1}, {4, 8} };
	//vector<vector<int> > obs = {
	//	{4, 2}
	//};

	cout << s.domino(2, 3, obs) << endl;
	return 0;
}