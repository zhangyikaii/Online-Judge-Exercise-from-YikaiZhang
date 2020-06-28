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

char s[20][20];
int state[11][11][5][11][11][5];

struct Data {
	int x, y;
	int dir;
	Data() { }
	Data(int d) {
		dir = d;
		// 这样按顺序, 到时候 旋转 直接取模就好.
		switch (d)
		{
		case 0:
			x = -1, y = 0;
			break;
		case 1:
			x = 0, y = 1;
			break;
		case 2:
			x = 1, y = 0;
			break;
		case 3:
			x = 0, y = -1;
			break;
		default:
			break;
		}
	}
};

/*
*...*.....
.C....*...
...*...*..
..F.......
...*......
*.....*...
...*......
.........*
...*.*....
.*.*......

*/

int main() {
	char ch;
	For(i, 0, 12)
		s[i][0] = s[i][11] = s[0][i] = s[11][i] = '*';

	For(i, 1, 11) {
		For(j, 1, 11) {
			cin >> ch;
			if (ch == 'F' || ch == 'C' || ch == '*' || ch == '.')
				s[i][j] = ch;
		}
	}
	int xf = 0, yf = 0, xc = 0, yc = 0;
	Data fdir = Data(0), cdir = Data(0);
	For(i, 1, 11) {
		For(j, 1, 11) {
			if (s[i][j] == 'F') {
				s[i][j] = '.';
				xf = i, yf = j;
			}
			else if (s[i][j] == 'C') {
				s[i][j] = '.';
				xc = i, yc = j;
			}
		}
	}

	int curTime = 0;
	while (state[xc][yc][cdir.dir][xf][yf][fdir.dir] != 1) {
		if (xc == xf && yc == yf) {
			cout << curTime << endl;
			return 0;
		}
		state[xc][yc][cdir.dir][xf][yf][fdir.dir] = 1;
		
		int xcn = xc + cdir.x, ycn = yc + cdir.y;
		int xfn = xf + fdir.x, yfn = yf + fdir.y;

		if (s[xcn][ycn] == '*')
			cdir = Data((cdir.dir + 1) % 4);
		else if (s[xcn][ycn] == '.')
			xc = xcn, yc = ycn;

		if (s[xfn][yfn] == '*')
			fdir = Data((fdir.dir + 1) % 4);
		else if (s[xfn][yfn] == '.')
			xf = xfn, yf = yfn;

		//cout << xc << " " << yc << endl;
		//cout << xf << " " << yf << endl;
		//cout << curTime << endl;
		++curTime;
	}

	cout << 0 << endl;


	return 0;
}