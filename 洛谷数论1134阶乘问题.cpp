#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

#define in(a) a=read()

inline long long read() {
	long long X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

long long n, aLast, ans = 1;

long long getLast(long long a) {
	while (a % 10 == 0)
		a /= 10;
	return a % 10;
}

int main() {
	in(n);

	// 每次取一位的方法是错误的!!! 
	// 14 != 87178291200。到这里我们的程序依然正确。result存贮的是2。
	// 15 != 1307674368000。然而，2 * 15 = 30，去0后是3而非正确的8。
	// 事实上，我们存贮的应是12, 12 * 15 = 180，去0后是18，个位是正确的8。

	for (long long i = 2; i <= n; ++i) {
		aLast = getLast(i);
		ans = getLast(ans * aLast);
	}

	printf("%lld\n", ans);
	
	return 0;
}


/*


*/



