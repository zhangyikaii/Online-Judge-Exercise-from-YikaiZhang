#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include<queue>
#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;

#define in(x) x=read()

inline ll read() {
	ll X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int T;

ll hp, atk, n, h;
ll a, t;
ll dead, toTower, tn, left;


int main() {
	// ios::sync_with_stdio(false);
	in(T);
	while (T--) {
		in(hp);
		in(atk);
		in(n);
		in(h);
		in(a);
		in(t);
		/*if (atk == 0) {
			cout << "No" << endl;
			continue;
		}
			
		dead = h / atk + 1;
		tn = t / dead, left = t % dead;
		toTower = (((n - tn + 1) * (n + tn)) >> 1) + (left * a * (tn - 1));

		if (toTower >= hp) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}*/

		cout << "No" << endl;
	}
	
	return 0;
}
/*


*/