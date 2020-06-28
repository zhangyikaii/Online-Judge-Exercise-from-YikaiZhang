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

#define FOR(i, s, n) for(int i = s; i < n; ++i)

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

// beg: 2019年5月1日14:12:19
// end: 2019年5月1日14:46:54

int xw[4] = { 0, 0, 1, -1 };
int yw[4] = { 1, -1, 0, 0 };
vector<vector<int> > used;

void dfs(vector<vector<char> > & board, string word, int xcur, int ycur, int wcur, bool &isOk) {
	if (wcur + 1 >= word.size()) {
		isOk = true;
		return;
	}
	if (isOk == true)
		return;

	// 判断是不是可以进行下一步都要在同一地方, 判断一次就可以了
	if (xcur >= 0 && xcur < board.size() && ycur >= 0 && ycur < board[xcur].size() && board[xcur][ycur] == word[wcur + 1] && used[xcur][ycur] == 0) {
		used[xcur][ycur] = 1;
		FOR(i, 0, 4) {
			int tx = xcur + xw[i], ty = ycur + yw[i];
			dfs(board, word, tx, ty, wcur + 1, isOk);
		}
		used[xcur][ycur] = 0;
	}
}

bool exist(vector<vector<char>>& board, string word) {
	int n = board.size();
	used.resize(n);
	FOR(i, 0, n) {
		used[i].resize(board[i].size());
	}
	FOR(i, 0, n) {
		FOR(k, 0, board[i].size()) {
			used[i][k] = 0;
		}
	}

	bool res = false;
	FOR(i, 0, n) {
		FOR(k, 0, board[i].size()) {
			if (board[i][k] == word[0]) {
				used[i][k] = 1;
				FOR(j, 0, 4) {
					int tx = i + xw[j], ty = k + yw[j];
					dfs(board, word, tx, ty, 0, res);
				}
				used[i][k] = 0;
			}
		}
	}

	return res;
}

int main() {
	vector<vector<char> > board = {
		{ 'a', 'b' }
	};

	cout << exist(board, "abc");





	return 0;
}


/*


*/