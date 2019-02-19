#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
#include <cmath>
#include <functional>

using namespace std;
long long n, m, a[100000001];

long long gcd(long long a, long long b) {
	return a == 0 ? b : gcd(b % a, a);
}

int main() {
	scanf("%lld%lld", &n, &m);
	long long p = gcd(n, m);	// 求最大公约数
	a[1] = 1;
	a[2] = 1;
	for (long long i = 3; i <= p; i++) {
			a[i] = (a[i - 1] + a[i - 2]) % 100000000;
	}
	cout << a[p] << endl;
	return 0;
}