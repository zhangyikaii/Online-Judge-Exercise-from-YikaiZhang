#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
	int i, k;
	double d;
	int ans = 0;
	for(k = 3702; k <= 10000 && ans < 10000; ++k) {
		ans = 0;
		for (i = 1; i <= k; i++)
			ans += log10(i);
		printf("%d\n", (int)ans + 1);
	}
	cout << "---" << k << endl;
	return 0;

}