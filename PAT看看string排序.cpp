#include <bits/stdc++.h>
using namespace std;

int main() {
	// string 自带天然字典比大小.
	string arr[10] = {
		"alsdkfjs",
		"jgfklglk",
		"azaaaaaaaaaaaa",
		"cccccccc",
		"dddddddd"
	};

	sort(arr, arr + 5);

	for (int i = 0; i < 5; ++i) {
		cout << arr[i] << endl;
	}
}