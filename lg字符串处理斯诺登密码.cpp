#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

#define FOR(k, b, s) for(int k = b; k < s; ++k)

string cmpp[50] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty",  "first", "second", "third" };

string cmpa[5] = { "a", "both", "another" };

int res[10010] = { 0 };
int main() {
	string a;
	int beg = -1;
	getline(cin, a);

	FOR(i, 0, a.size()) {
		if (i == 0) {
			beg = 0;
		}
		else if (a[i] == ' ') {
			beg = i + 1;
		}

		if (beg != -1) {
			int j;
			for (j = 1; j <= 20; ++j) {
				if (a.find(cmpp[j], beg) == beg) {
					res[++res[0]] = j;
					break;
				}
			}
		}

		beg = -1;
	}
	
	FOR(i, 1, res[0] + 1)
		cout << res[i] << " ";

	return 0;
}


/*




*/