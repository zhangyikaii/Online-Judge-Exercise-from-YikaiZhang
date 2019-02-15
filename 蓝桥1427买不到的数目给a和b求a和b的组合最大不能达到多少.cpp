#include<iostream> 
#include<cstdio> 
#include<algorithm> 
#include <cstring>
using namespace std;

#define in(x) x=read()

inline int read()
{
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}
int n, m;

int gcd(int a, int b) {
	return a == 0 ? b : gcd(b % a, a); 
}

int main() {
	std::ios::sync_with_stdio(0);
	while (cin >> n && cin >> m) {
		printf("%d\n", n * m - n - m);
	}
	
	return 0;
}

/*
小明开了一家糖果店。他别出心裁：把水果糖包成4颗一包和7颗一包的两种。糖果不能拆包卖。
小朋友来买糖的时候，他就用这两种包装来组合。当然有些糖果数目是无法组合出来的，比如要买  10  颗糖。
你可以用计算机测试一下，在这种包装情况下，最大不能买到的数量是17。大于17的任何数字都可以用4和7组合出来。
本题的要求就是在已知两个包装的数量时，求最大不能组合出的数字。

输入:
4 7

输出:
17

*/