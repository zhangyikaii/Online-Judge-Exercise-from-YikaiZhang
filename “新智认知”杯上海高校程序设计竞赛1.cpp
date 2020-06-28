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


int main() {
	int n;
	in(n);
	if (n >= 3) {
		printf("BigBoLang\n");
	}
	else if (n == 2) {
		printf("YingHuaTang\n");
	}
	else if (n == 1) {
		printf("XiZhiTang\n");
	}
	else
		printf("None\n");

	return 0;
}
/*


*/