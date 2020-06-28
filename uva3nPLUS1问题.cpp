#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>

using namespace std;


#define in(x) x=read()

#define MAXN 1000000

typedef long long ll;

inline ll read() {
	ll X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

ll arr[1000010] = { 0 };
int res[10000];
int n;

int main() {
	int i, j;
	while (cin >> i >> j) {
		int iRes = 0, maxx = 0;
		for (int k = i; k <= j; ++k) {
			/*if (k == 1) {
				maxx = 1;
				continue;
			}*/
			int t = k, cnt = 1;
			res[iRes] = t;
			while (t != 1) {
				if (arr[res[iRes]] != 0) {
					cnt = arr[res[iRes]];
					break;
				}
				res[++iRes] = ((t | 0x1) == 1) ? (t * 3 + 1) : (t >> 1);
				t = res[iRes];
			}

			for (int j = iRes; j >= 0; --j) {
				arr[res[j]] = cnt++;
			}
			maxx = max(maxx, cnt);
		}

		cout << i << " " << j << " " << maxx << endl;
	}
	
	return 0;
}

/*

*/