#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>

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

bool dp[100010] = { false };

int main() {
	string a, b;
	map<string, int> mm;
	getline(cin, a);
	getline(cin, b);

	
	int bef = 0;
	FOR(i, 0, b.size()) {
		if (b[i] == ' ') {
			mm[b.substr(bef, i - bef)] = 1;
			bef = i + 1;
		}
	}

	mm[b.substr(bef, b.size() - bef)] = 1;

	dp[0] = true;
	FOR(i, 0, a.size() + 1) {

		FOR(k, 0, i) {
			// cout << a.substr(k, i - k) << endl;

			if (dp[k] == true && mm[a.substr(k, i - k)] == 1) {
				dp[i] = true;
				break;
			}
		}
	}

	if (dp[a.size()] == true)
		printf("True\n");
	else
		printf("False\n");

	

	//int bef = 0, an = a.length();
	//FOR(i, 0, b.size()) {
	//	if (b[i] == ' ') {
	//		string t = b.substr(bef, i - bef);
	//		size_t fin = a.find(t);
	//		while (fin != string::npos) {
	//			FOR(k, 0, t.size()) {
	//				a[fin + k] = '\0';
	//			}
	//			fin = a.find(t);
	//		}
	//		bef = i + 1;
	//	}
	//}

	//string t = b.substr(bef, b.size() - bef);
	//size_t fin = a.find(t);
	//while (fin != string::npos) {
	//	FOR(k, 0, t.size()) {
	//		a[fin + k] = '\0';
	//	}
	//	fin = a.find(t);
	//}

	//bool flag = false;
	//FOR(i, 0, an) {
	//	if (a[i] != '\0')
	//		flag = true;
	//}
	//if (flag == true)
	//	printf("False\n");
	//else
	//	printf("True\n");
	return 0;
}