#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

// 看到题目发现是 double 的题, 就要一直记住用double!!!, double的不会画整个图, 但是会算面积, 注意一定全上double!!! 可以看错误列表 -> 警告

const double PI = 3.1415926535;

inline int read(){
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	if (f) return x;
	return 0 - x;
}
// dfs 不一定是所有都要打地图的

double min(double a, double b) {
	return a > b ? b : a;
}

double n, ax, ay, bx, by, minn = 0xfffffff, allArea;
double xarr[2010], yarr[2010], usedArr[2010] = { 0 }, r[2010] = { 0 };

double Distant(int a, int b) {
	return sqrt((xarr[a] - xarr[b]) * (xarr[a] - xarr[b]) + (yarr[a] - yarr[b]) * (yarr[a] - yarr[b]));
}

double GetR(int who) {
	double ans = 0xfffffff;
	// 先不能碰到其他油滴
	for (int i = 1; i <= n; ++i) {
		if (i != who && r[i] != 0) {
			double dis = Distant(who, i);
			// 在其他油滴里面
			if (dis < r[i])
				return 0;

			if (ans > dis - r[i])
				ans = dis - r[i];
		}
	}

	// 再不能碰到边界
	double minx = min(abs(xarr[who] - ax), abs(xarr[who] - bx)), miny = min(abs(yarr[who] - ay), abs(yarr[who] - by));
	ans = min(min(minx, miny), ans);
	return ans;
}

void dfs(int num, double used) {
	if (num == n) {
		double tmp = allArea - used;
		if (minn > tmp)
			minn = tmp;
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (usedArr[i] == 0) {
			r[i] = GetR(i);
			usedArr[i] = 1;
			dfs(num + 1, used + PI * r[i] * r[i]);
			usedArr[i] = 0;
		}
	}
}


int main() {
	n = read();
	scanf("%lf%lf%lf%lf", &ax, &ay, &bx, &by);

	allArea = abs((bx - ax) * (by - ay));

	for (int i = 1; i <= n; ++i) {
		scanf("%lf%lf", &xarr[i], &yarr[i]);
	}

	dfs(0, 0);
	printf("%d\n", (int)(minn + 0.5));


	return 0;
}

/*
在一个长方形框子里，最多有N（0≤N≤6）个相异的点，在其中任何一个点上放一个很小的油滴，那么这个油滴会一直扩展，直到接触到其他油滴或者框子的边界。必须等一个油滴扩展完毕才能放置下一个油滴。那么应该按照怎样的顺序在这N个点上放置油滴，才能使放置完毕后所有油滴占据的总体积最大呢？（不同的油滴不会相互融合）

注：圆的面积公式V=pi*r*r，其中r为圆的半径。

输入输出格式
输入格式：
第1行一个整数N。

第2行为长方形边框一个顶点及其对角顶点的坐标，x,y,x’,y’。

接下去N行，每行两个整数xi,yi，表示盒子的N个点的坐标。

以上所有的数据都在[-1000，1000]内。

输出格式：
一行，一个整数，长方形盒子剩余的最小空间（结果四舍五入输出）

输入输出样例
输入样例#1：
2
20 0 10 10
13 3
17 7


输出样例#1：
50


*/