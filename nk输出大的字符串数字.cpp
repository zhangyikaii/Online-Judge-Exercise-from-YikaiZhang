#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define in(x) x=read()
#define For(i, a, b) for(int i = a; i < b; ++i)

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}


// 这题太麻烦了! 看题解有没什么好方法...

string aa = "._....._.._....._.._.._.._.._.";
string bb = "|.|..|._|._||_||_.|_...||_||_|";
string cc = "|_|..||_.._|..|._||_|..||_|._|";

string dd = ".....__.....";
string ee = "./\.|__||\/|";
string ff = "/--\|...|..|";

string d1 = ".";
string d2 = "*";
string d3 = "*";

int main() {

	
	return 0;
}

/*

...._.._....._.._.._.._.._.._.
..|._|._||_||_.|_...||_||_||.|
..||_.._|..|._||_|..||_|._||_|



.....__.....
./\.|__||\/|
/--\|...|..|


...._..._.._.........
..|._|*._||_../\.|\/|
..||_.*._|._|/--\|..|


...._......_..__.....
..|._|*|_||_||__||\/|
..||_.*..|._||...|..|
...
..|
..|

*/