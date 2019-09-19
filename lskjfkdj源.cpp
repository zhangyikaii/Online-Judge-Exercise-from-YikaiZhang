#include <iostream>
using namespace std;

char buffer[10010] = "";
char * inttohex(int aa) {
	itoa(aa, buffer, 16);
	return (buffer);
}

int main() {
	for (int i = 0; i < 256; ++i) {
		cout << "@" << inttohex(i) << " 00" << endl;
	}

	return 0;
}