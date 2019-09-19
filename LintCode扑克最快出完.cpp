#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
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

#include<stdio.h>
int func4(int xx,int y,int z) {
	int t = xx - y;
	t = t + (t >> 31);
	int x = (t >> 1) + y;
	if (x == z) {
		return x;
	}
	else if (x < z) {
		return func4(xx, x + 1, z) + x * 2;
	}
	else {
		return func4(x - 1, y, z) + (x >> 1);
	}
}
int main(){
		cout << func4(0x3e, 6, 62) << endl;
    return 0;
}

//typedef long long ll;
//
//#define in(x) x=read()
//
//inline int read() {
//	int X = 0, w = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X*w;
//}
//int getAns(vector<int> &cards) {
//	// Write your code here
//	int mapp[12] = { 0 }, n = cards.size(), res = 0;
//	for (int i = 0; i < n; ++i) {
//		++mapp[cards[i]];
//	}
//
//	for (int i = 1; i <= 5; ++i) {
//		bool flag = false;
//		int minn = 0x7fffff;
//		for (int k = 0; k < 5; ++k) {
//			if (mapp[i + k] == 0) {
//				flag = true;
//				break;
//			}
//			else {
//				if (minn > mapp[i + k])
//					minn = mapp[i + k];
//			}
//		}
//		if (flag == false) {
//			for (int k = 0; k < 5; ++k)
//				mapp[i + k] -= minn;
//			res += minn;
//		}
//	}
//
//	for (int i = 1; i < 10; ++i) {
//		if (mapp[i] != 0)
//			++res;
//	}
//
//	return res;
//}
//
///*
//
//*/
//int main() {
//	int a = 11;
//	a = ((a - 6) >> 1) + 5;
//	cout << a << endl;
//	return 0;
//}
