#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int MyMin(int a, int b) {
	return a > b ? b : a;
}

void Swap(int arr[], int i, int j) {
	if (i == j)
		return;

	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}

int main() {
	char arr[300] = "";
	int stac[300] = { 0 };
	int iStac = 0;
	cin >> arr;

	for (int i = 0; arr[i] != '@'; ++i) {
		if (arr[i] == '(')
			stac[++iStac] = 1;
		else if (arr[i] == ')' && stac[iStac] == 1)
			--iStac;
		else if (arr[i] == ')' && stac[iStac] != 1) {
			printf("NO\n");
			return 0;
		}	
	}
	
	if (iStac == 0)
		printf("YES\n");
	else
		printf("NO\n");
	
	return 0;
}


/*

*/