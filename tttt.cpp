#include <iostream>
using namespace std;
int main() {
	
	for (int i = 0x40; i <= 0x1fc0; i += 0x40) {
		int cache_q = i;
		char string[25];
		
		itoa(cache_q, string, 2);
		printf("integer=%d string=%s\n", cache_q, string);
	}


	return 0;
}