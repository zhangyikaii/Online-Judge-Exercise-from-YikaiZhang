#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

#define in(x) x=read()

#define MAXN 1000000

typedef long long ll;


inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n;

int main() {
	in(n);
	int aGap = n, iStep;
	bool isZero = false;
	for (iStep = 0; aGap > 3 || isZero != false; ++iStep) {
		printf("Step %d:", iStep);
		for (int k = 1; k <= aGap; ++k)
			printf("1");
		if (isZero != false)
			printf("00");
		for (int j = 1; j <= aGap; ++j)
			printf("2");
		if (isZero == false)
			printf("00");
		for (int t = 1; t <= n - aGap; ++t)
			printf("12");
		if (isZero == false)
			--aGap;
		
		isZero = isZero == false ? true : false;
		printf("\n");
	}

	string a = "1112122002", b = "1002122112", c = "1212120012", d = "0012121212";
	printf("Step %d:", iStep++);
	cout << a;
	for (int i = 1; i <= n - aGap; ++i)
		printf("12");
	printf("\n");

	printf("Step %d:", iStep++);
	cout << b;
	for (int i = 1; i <= n - aGap; ++i)
		printf("12");
	printf("\n");

	printf("Step %d:", iStep++);
	cout << c;
	for (int i = 1; i <= n - aGap; ++i)
		printf("12");
	printf("\n");

	printf("Step %d:", iStep++);
	cout << d;
	for (int i = 1; i <= n - aGap; ++i)
		printf("12");
	printf("\n");
	printf("%d\n", iStep - 1);


	return 0;
}


/*


*/