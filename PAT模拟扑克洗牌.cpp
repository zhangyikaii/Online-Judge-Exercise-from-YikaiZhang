#include <bits/stdc++.h>
using namespace std;

int arr[110];
int seq[110];

void output(int num) {
	int div = num / 13;
	switch (div) {
	case 0: {
		cout << "S";
		break;
	}
	case 1: {
		cout << "H";
		break;
	}
	case 2: {
		cout << "C";
		break;
	}
	case 3: {
		cout << "D";
		break;
	}
	case 4: {
		cout << "J";
		break;
	}
	}

	cout << num % 13 + 1;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 54; ++i) {
		cin >> arr[i];
		seq[i] = i;
	}

	while (n--) {
		int tmp[110] = { 0 };
		for (int i = 0; i < 54; ++i)
			tmp[i] = seq[i];
		for (int i = 0; i < 54; ++i) {
			seq[arr[i] - 1] = tmp[i];
		}
	}

	for (int i = 0; i < 54; ++i) {
		output(seq[i]);
		if (i != 53)
			cout << " ";
	}
	cout << endl;


	return 0;
}