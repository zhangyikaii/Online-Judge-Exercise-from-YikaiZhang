#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1000010;

typedef long long ll;

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n;
int arr[110], brr[110];

int main() {
	in(n);
	for (int i = 1; i <= n; ++i) {
		in(arr[i]);
		in(brr[i]);
	}

	for (int i = 1; i <= n; ++i) {
		int tmp = arr[i] + brr[i];
		for (int k = i + 1; k <= n; ++k) {
			if (tmp == arr[k] && arr[k] + brr[k] == arr[i]) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}

	cout << "NO" << endl;
	
	return 0;
}
