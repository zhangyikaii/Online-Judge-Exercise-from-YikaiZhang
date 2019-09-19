#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(int i = s; i < n; ++i)

#define MAXN 1000010

#define FLAG 9999999

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}
//
//int *arr;
//int ans[5] = { 0 };
//int main() {
//	int n;
//	in(n);
//	arr = new int[n + 10];
//	FOR(i, 0, n) {
//		in(arr[i]);
//	}
//
//	sort(arr, arr + n);
//	int cnt = 0, cur = FLAG;
//	bool isFir = false;
//	do {
//		cnt = 0;
//		FOR(i, 0, n) {
//			if (arr[i] != FLAG && cur != arr[i]) {
//				cur = arr[i];
//				if (cnt < 2)
//					ans[cnt] = arr[i];
//				arr[i] = FLAG;
//				++cnt;
//			}
//		}
//		cur = FLAG;
//	} while (cnt > 2);
//	
//	printf("%d %d\n", ans[0], ans[1]);
//	return 0;
//}

struct Data {
	int fir, sec;
	Data() : fir(FLAG), sec(0) { }
};

Data arr[5];
void decc() {
	while (arr[0].sec != 0 && arr[1].sec != 0 && arr[2].sec != 0) {
		--arr[0].sec;
		--arr[1].sec;
		--arr[2].sec;
	}

	FOR(i, 0, 3) {
		if (arr[i].sec <= 0) {
			arr[i].sec = 0;
			arr[i].fir = FLAG;
		}
	}	
}

void addd(int a) {
	FOR(i, 0, 3) {
		if (arr[i].fir == a) {
			++arr[i].sec;
			return;
		}
	}
	FOR(i, 0, 3) {
		if (arr[i].fir == FLAG) {
			arr[i].fir = a;
			arr[i].sec = 1;
			return;
		}
	}
}
int main() {
	int n, tmp = 0, cnt = 0;
	int ans[5] = { 0 };
	in(n);
	FOR(i, 0, n) {
		in(tmp);
		addd(tmp);
		decc();
	}

	FOR(i, 0, 3) {
		if (arr[i].fir != FLAG)
			ans[++ans[0]] = i;
	}

	if (arr[ans[1]].fir > arr[ans[2]].fir) {
		int temp = ans[1];
		ans[1] = ans[2];
		ans[2] = temp;
	}

	printf("%d %d\n", arr[ans[1]].fir, arr[ans[2]].fir);

	return 0;
}