#include <bits/stdc++.h>
using namespace std;

// 先 a 后 b 的顺序不能变.

// 判断的是 b == 0;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int main() {


	return 0;
}