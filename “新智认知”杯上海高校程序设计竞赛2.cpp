#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include<queue>
#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
#include <cmath>
#include <string>
using namespace std;

typedef long long ll;

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

char arr[30];
int rankk[30] = { 0 };
string a[1010], b[1010];

int main() {
	int n, aa, bb, flag, ia, ib;
	in(n);

	for (int i = 1; i <= 26; ++i) {
		cin >> arr[i];
		rankk[arr[i] - 'a'] = i;
	}
	
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		flag = 0;
		aa = a[i].length(), bb = b[i].length();
		for (ia = 0, ib = 0; ia < aa && ib < bb; ++ia, ++ib) {
			if (rankk[a[i][ia] - 'a'] > rankk[b[i][ib] - 'a']) {
				flag = 1;
				break;
			}
			else if (rankk[a[i][ia] - 'a'] < rankk[b[i][ib] - 'a']) {
				flag = 2;
				break;
			}
		}
		if (flag == 0) {
			if (ia == aa && ib == bb) {
				cout << "=" << endl;
			}
			else if (ia == aa && ib != bb) {
				cout << "<" << endl;
			}
			else if (ia != aa && ib == bb) {
				cout << ">" << endl;
			}
		}
		else if (flag == 1) {
			cout << ">" << endl;
		}
		else if (flag == 2) {
			cout << "<" << endl;
		}
	}

	return 0;
}
/*


*/