#include <iostream>
#include <algorithm>
using namespace std;

struct Data {
	int a;
	bool operator < (const Data t) const {
		return this->a > t.a;
	}
};
int main() {
	Data arr[30];
	for (int i = 1; i <= 20; ++i) {
		arr[i].a = 100 - i;
	}

	sort(arr + 1, arr + 1 + 20);

	for (int i = 1; i <= 20; ++i) {
		cout << arr[i].a << " ";
	}


}