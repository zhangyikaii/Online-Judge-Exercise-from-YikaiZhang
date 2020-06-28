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

int arr[320][320], used[320][320];
int xway[5] = { 1, -1, 0, 0 };
int yway[5] = { 0, 0, 1, -1 };
int m;

int a, b, c;

struct Data {
	int x, y;
	int tim;
	Data(int xx, int yy, int tt) : x(xx), y(yy), tim(tt) { }
};

/*

1 0 0 1 0 0 0 0
0 1 0 0 0 0 0 0
0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
*/

int main() {
	in(m);
	For(i, 0, m) {
		in(a), in(b), in(c);
		if (arr[a][b] == 0 || arr[a][b] > c)
			arr[a][b] = c == 0 ? 1 : c;
		For(i, 0, 4) {
			int nx = a + xway[i], ny = b + yway[i];
			if (nx >= 0 && ny >= 0 && (arr[nx][ny] == 0 || arr[nx][ny] > c))
				arr[nx][ny] = c == 0 ? 1 : c;
		}
	}

	if (arr[0][0] == 0) {
		cout << 0 << endl;
		return 0;
	}

	//For(i, 0, 10) {
	//	For(j, 0, 10) {
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	queue<Data> q;
	q.push(Data(0, 0, 0));
	used[0][0] = 1;
	while (!q.empty()) {
		Data cur = q.front();
		q.pop();
		
		For(i, 0, 4) {
			int nx = cur.x + xway[i], ny = cur.y + yway[i], ntim = cur.tim + 1;
			if (nx >= 0 && nx <= 300 && ny >= 0 && ny <= 300) {
				if (used[nx][ny] == 1)
					continue;
				if (arr[nx][ny] == 0) {
					cout << cur.tim + 1 << endl;
					// cout << nx << " " << ny << endl;
					return 0;
				}
				else if (arr[nx][ny] > ntim) {
					q.push(Data(nx, ny, ntim));
					used[nx][ny] = 1;
				}
			}
		}
	}

	cout << -1 << endl;

	
	return 0;
}