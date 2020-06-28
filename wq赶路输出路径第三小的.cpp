#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

#define in(x) x=read()

#define MAXN 1000000

typedef long long ll;

inline ll read() {
	ll X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}
ll MyAbs(ll a) {
	return a > 0 ? a : -a;
}

ll ax, bx, ay, by;

int main() {
	in(ax);
	in(ay);
	in(bx);
	in(by);

	ll xgap = MyAbs(ax - bx), ygap = MyAbs(ay - by);

	if (xgap == 1 && ygap == 1) {
		printf("4\n");
	}
	else if (xgap == 0 || ygap == 0) {
		ll tmp = xgap == 0 ? ygap : xgap;
		printf("%lld\n", tmp + 2);
	}
	else if (xgap == 0 && ygap == 0)
		printf("0\n");
	else {
		printf("%lld\n", xgap + ygap);
	}

	return 0;
}


/*

在无穷大二维平面上有两个整点A(a,b)A(a, b)A(a,b)和B(x,y)B(x, y)B(x,y)。

现在AceSrc需要从AAA点赶往BBB点。他每一步可以向平行于坐标轴的四个方向之一前进1单位的距离，这一步可以用"上下左右"来表示。

显然，AceSrc从AAA赶往BBB的方案可以用"上下左右"组成的字符串表示。

由于AceSrc特别的牛逼，他对自己的要求也非常的严格。他要求自己不能经过一个点两次，还要求所选方案的步数是所有不同的方案中第三小的。

现在AceSrc很好奇他需要走多少步才能从AAA走到BBB，你能帮帮他吗？

HINT

两种方案不同，当且仅当他们表示出来的字符串不同。

输入格式
输入有两行，每行两个数字。

第一行两个数字a,ba, ba,b为点AAA的坐标。

第二行两个数字x,yx, yx,y为点BBB的坐标。

保证AAA和BBB不是同一个点。

输出格式
输出一行，表示AceSrc需要走的步数。

样例
Input
1 100
2 500
Output
401
数据范围与提示
−2×109≤a,b,x,y≤2×109-2 \times 10^9 \leq a, b, x, y \leq 2 \times 10^9−2×10
​9
​​ ≤a,b,x,y≤2×10
​9
​​

*/