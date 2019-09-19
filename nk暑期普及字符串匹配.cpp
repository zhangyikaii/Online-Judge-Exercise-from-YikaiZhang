#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<map>
#define INF 0xfffffff

#define CLR(a,b,Size) memset((a),(b),sizeof((a[0]))*(Size+1))
#define CPY(a,b) memcpy ((a), (b), sizeof((a)))
using namespace std;
typedef long long ll;

#define in(x) x=read()

#define For(i, a, b) for(int i = a; i < b; ++i)

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

int main() {
	int n, sear;
	in(n);
	in(sear);
	string s;
	cin >> s;
	For(i, 0, sear) {
		string tmp;
		int res = 0;
		cin >> tmp;
		int ft = 0;
		for (int i = 0; i < n; ++i) {
			if (tmp[ft] == s[i]) {
				++ft;
				++res;
				if (ft >= tmp.length())
					break;
			}
		}

		printf("%d\n", res);
	}
	

	return 0;
}

/*

*/