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

int arr[30] = { 0 };
int main() {
	int n;
	string s;
	in(n);
	cin >> s;
	for (int i = 0; i < s.length(); ++i) {
		arr[s[i] - 'a']++;
	}

	printf("%d", arr[0]);
	for (int i = 1; i < 26; ++i) {
		printf(" %d", arr[i]);
	}
	printf("\n");

	return 0;
}

/*

*/