#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

typedef long long ll;

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

string luckyNumber(string &n) {
	// Write your code here.
	string res;
	int num = n.size(), l = num / 2, r = num / 2;
	bool flag = false;
	if (n.size() <= 0)
		return res;
	if (n[0] > '5' || (num & 1) == 1) {
		int endd = l + 1;
		string a(endd, '3'), b(endd, '5');

		return a + b;
	}
	int i = 0;
	for (; i < num; ++i) {
		if (r > 0 && n[i] == '5')
			res += "5";
		else if (l > 0 && n[i] == '3') {
			string a(l - 1, '3'), b(r, '5'), t = res + "3" + b + a;
			if (t < n) {
				--r;
				res += "5";
			}
			else {
				--l;
				res += "3";
			}
		}
		else if (n[i] < '3') {
			string a(l, '3'), b(r, '5');
			return res + a + b;
		}
		else if (n[i] < '5' && n[i] > '3') {
			string a(l, '3'), b(r - 1, '5');
			return res + "5" + a + b;
		}
	}

	return res;
}

int main() {
	string n;
	cin >> n;
	cout << luckyNumber(n);


	return 0;
}