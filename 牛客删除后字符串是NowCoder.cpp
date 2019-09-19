#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
using namespace std;

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int main() {
	int n, cmpp = 0;
	string a, s("NowCoder");
	int endCmpp = s.size();
	in(n);

	while (n--) {
		cin >> a;
		int n = a.size(), i;
		cmpp = 0;

		for (i = 0; i < n; ++i) {
			if (a[i] == s[cmpp]) {
				if (cmpp == endCmpp - 1) {
					break;
				}
				++cmpp;
			}
		}

		if (i == n) {
			cout << "QIE" << endl;
		}
		else {
			cout << "QAK" << endl;
		}
	}

	return 0;
}


/*



*/