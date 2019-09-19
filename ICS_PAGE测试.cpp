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
#define mod 1000000007
#define CLR(a,b,Size) memset((a),(b),sizeof((a[0]))*(Size+1))
#define CPY(a,b) memcpy ((a), (b), sizeof((a)))
using namespace std;
typedef long long ll;

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

void pri(int a, int b) {
	cout << a << "  ---  " << b << endl;
}

int main() {
	freopen("out.txt", "w", stdout);
	int pframe_idx = 0, pdir_idx = 0, ptable = 0;
	for (pdir_idx = 0; pdir_idx < 32; pdir_idx++) {
		// pdir[pdir_idx].val = make_pde(ptable);
		pri(pdir_idx, ptable);
		// pdir[pdir_idx + KOFFSET / PT_SIZE].val = make_pde(ptable);
		pri(pdir_idx + 768, ptable);
		cout << "d -------------------------------------- " << endl << endl;
		for (int ptable_idx = 0; ptable_idx < 1024; ptable_idx++) {
			// ptable->val = make_pte(pframe_idx << 12);
			pri(ptable, (pframe_idx << 12));
			pframe_idx++;
			ptable++;
		}
		cout << "u -------------------------------------- " << endl << endl;
	}


	return 0;
}