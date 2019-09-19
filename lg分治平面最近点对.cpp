#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

#define in(x) x=read()

#define MAXN 1000000

typedef long long ll;

struct Data {
	double x, y;
};


inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 1000001;
const int INF = 2 << 20;
int n, temp[maxn];
struct Point
{
	double x, y;
}S[maxn];

bool cmp(const Point &a, const Point&b)
{
	if (a.x == b.x)
		return a.y<b.y;
	else
		return a.x<b.x;
}

bool cmps(const int &a, const int &b)
{
	return S[a].y<S[b].y;
}

double min(double a, double b)
{
	return a<b ? a : b;
}

double dist(int i, int j)
{
	double x = (S[i].x - S[j].x)*(S[i].x - S[j].x);
	double y = (S[i].y - S[j].y)*(S[i].y - S[j].y);
	return sqrt(x + y);
}

double merge(int left, int right)
{
	double d = INF;
	if (left == right)
		return d;
	if (left + 1 == right)
		return dist(left, right);
	int mid = left + right >> 1;
	double d1 = merge(left, mid);
	double d2 = merge(mid + 1, right);
	d = min(d1, d2);
	int i, j, k = 0;
	// 和中间线距离小于d的选出来
	for (i = left; i <= right; i++) {
		if (fabs(S[mid].x - S[i].x) <= d)
			temp[k++] = i;
	}
	// 然后按照 y 排序.
	sort(temp, temp + k, cmps);
	for (i = 0; i < k; ++i) {
		for (j = i + 1; j < k && S[temp[j]].y - S[temp[i]].y < d; j++) {
			double d3 = dist(temp[i], temp[j]);
			if (d>d3)
				d = d3;
		}
	}
	return d;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
		scanf("%lf%lf", &S[i].x, &S[i].y);
	sort(S, S + n, cmp);
	return !printf("%.4lf\n", merge(0, n - 1));
}


//
//int n;
//Data arr[200010];
//int tmp[200010];
//
//
//double MyMin(double a, double b) {
//	return a > b ? b : a;
//}
//
//bool cmp(Data a, Data b) {
//	return a.x > b.x;
//}
//
//// 像这样点之间距离的问题, dis能预处理的要预处理 ( 这里并不可以 )
//double GetDis(int a, int b) {
//	return sqrt((arr[a].x - arr[b].x) * (arr[a].x - arr[b].x) + (arr[a].y - arr[b].y) * (arr[a].y - arr[b].y));
//}
//
//double MyFabs(double a) {
//	return a > 0 ? a : -a;
//}
//
//bool cmp0(int a, int b) {
//	return arr[a].y > arr[b].y;
//}
//
//// 数据太大, 记忆化搜索也用不上
//double Recur(int l, int r) {
//	if (l + 1 == r)
//		return GetDis(l, r);
//	else if (l + 2 == r)
//		return MyMin(GetDis(l, l + 2), MyMin(GetDis(l, l + 1), GetDis(l + 1, l + 2)));
//
//	int mid = (l + r) >> 2;
//	double curMin = MyMin(Recur(l, mid), Recur(mid + 1, r));
//	int iTmp = 0;
//
//	for (int i = 1; i <= n; ++i) {
//		if (i != mid && curMin > arr[i].x - arr[mid].x) {
//			tmp[++iTmp] = i;
//		}
//	}
//
//	sort(tmp + 1, tmp + 1 + iTmp, cmp0);
//
//	for (int i = 1; i <= iTmp; ++i) {
//		for (int k = 1; k <= iTmp; ++k) {
//
//		}
//	}
//
//
//
//}
//int main() {
//	int n;
//	for (int i = 1; i <= n; ++i) {
//		scanf("%lf", &arr[i]);
//	}
//
//	sort(arr + 1, arr + 1 + n, cmp);
//
//
//
//
//	
//	return 0;
//}
//
//int n;
//Data arr[200010];
//int tmp[200010];
//
//
//double MyMin(double a, double b) {
//	return a > b ? b : a;
//}
//
//bool cmp(Data a, Data b) {
//	return a.x > b.x;
//}
//
//// 像这样点之间距离的问题, dis能预处理的要预处理 ( 这里并不可以 )
//double GetDis(int a, int b) {
//	return sqrt((arr[a].x - arr[b].x) * (arr[a].x - arr[b].x) + (arr[a].y - arr[b].y) * (arr[a].y - arr[b].y));
//}
//
//double MyFabs(double a) {
//	return a > 0 ? a : -a;
//}
//
//bool cmp0(int a, int b) {
//	return arr[a].y > arr[b].y;
//}
//
//// 数据太大, 记忆化搜索也用不上
//double Recur(int l, int r) {
//	if (l + 1 == r)
//		return GetDis(l, r);
//	else if (l + 2 == r)
//		return MyMin(GetDis(l, l + 2), MyMin(GetDis(l, l + 1), GetDis(l + 1, l + 2)));
//
//	int mid = (l + r) >> 2;
//	double curMin = MyMin(Recur(l, mid), Recur(mid + 1, r));
//	int iTmp = 0;
//
//	for (int i = 1; i <= n; ++i) {
//		if (i != mid && curMin > arr[i].x - arr[mid].x) {
//			tmp[++iTmp] = i;
//		}
//	}
//
//	sort(tmp + 1, tmp + 1 + iTmp, cmp0);
//
//	for (int i = 1; i <= iTmp; ++i) {
//		for (int k = 1; k <= iTmp; ++k) {
//
//		}
//	}
//
//
//
//}
//int main() {
//	int n;
//	for (int i = 1; i <= n; ++i) {
//		scanf("%lf", &arr[i]);
//	}
//
//	sort(arr + 1, arr + 1 + n, cmp);
//
//
//
//
//	
//	return 0;
//}


/*


*/