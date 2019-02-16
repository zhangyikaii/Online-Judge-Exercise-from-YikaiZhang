#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
using namespace std;

#define in(x) x=read()

inline int read()
{
	int w = 1;
	char ch = getchar();
	
	if (ch == '0')
		w = 0;
	else {
		while (ch < '0' || ch > '9') {
			if (ch == '-')
				w = -1;
			ch = getchar();
		}
	}
	while (ch >= '0' && ch <= '9') {
		ch = getchar();
	}
	
	return w;
}

int b;

int main() {
	in(b);
	if (b > 0) {
		printf("B*C");
	}
	else if (b == 0) {
		printf("A*B B*C");
	}
	else {
		printf("A*B");
	}
	
	return 0;
}

/*

*/

