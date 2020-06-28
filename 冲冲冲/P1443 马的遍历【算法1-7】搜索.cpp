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

int xway[10] = { -1, -1, 1, 1, 2, 2, -2, -2 };
int yway[10] = { 2, -2, 2, -2, 1, -1, 1, -1 };

int n, m;
int x, y;
int arr[410][410];

struct Data {
	int x, y;
	int d;
	Data() { }
	Data(int x, int y, int d) : x(x), y(y), d(d) { }
};
int main() {
	in(n), in(m);
	in(x), in(y);

	queue<Data> q;
	q.push(Data(x, y, 0));

	while (!q.empty()) {
		Data cur = q.front();
		q.pop();

		For(i, 0, 8) {
			int nx = cur.x + xway[i], ny = cur.y + yway[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && arr[nx][ny] == 0) {
				arr[nx][ny] = cur.d + 1;
				q.push(Data(nx, ny, cur.d + 1));
			}
		}
	}

	Fee(i, 1, n) {
		Fee(j, 1, m) {
			if (i == x && j == y)
				printf("%-5d", 0);
			else if (arr[i][j] == 0)
				printf("%-5d", -1);
			else
				printf("%-5d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}