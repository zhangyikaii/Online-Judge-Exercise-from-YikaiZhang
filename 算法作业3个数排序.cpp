#include <iostream>
using namespace std;

void Swap(int arr[], int i, int j) {
	if (i == j)
		return;

	arr[i] = arr[i] ^ arr[j];				// i = i ^ j
	arr[j] = arr[i] ^ arr[j];				// j = i ^ j
	arr[i] = arr[i] ^ arr[j];				// i = i ^ j
}

void SwapCommon(int *a, int *b) {
	if (*a == *b)
		return;
	
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void Sort3Num(int *a, int *b, int *c) {
	if (*a > *b) {
		SwapCommon(a, b);
	}
	if (*a > *c) {
		SwapCommon(a, c);
	}
	if (*b > *c) {
		SwapCommon(b, c);
	}
}

int main() {
	int a = 3, b = 2, c = 1;
	Sort3Num(&a, &b, &c);

	cout << a << " " << b << " " << c << endl;

	return 0;
}