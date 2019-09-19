//#include <iostream> 
//#include <cstdio> 
//#include <algorithm> 
//#include <cstring>
//#include <cmath>
//#include <cstdlib>
//#include <string>
//using namespace std;
//
//#define in(x) x=read()
//
//inline int read() {
//	int X = 0, w = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X*w;
//}
//
//int MyMin(int a, int b) {
//	return a > b ? b : a;
//}
//
//void Swap(int arr[], int i, int j) {
//	if (i == j)
//		return;
//
//	arr[i] = arr[i] ^ arr[j];
//	arr[j] = arr[i] ^ arr[j];
//	arr[i] = arr[i] ^ arr[j];
//}
//
//
//int main() {
//
//
//	return 0;
//}


#include <iostream>
#include <algorithm>
using namespace std;

#define N 10001

struct node { 
	double x, y; 
}point[N];

int n, top = 2, st[N];//top->栈顶，st->记录凸包上点的栈。
double ans, data_x, data_y;
inline double power(double x) { return x*x; }
inline double dis(int a, int b) { return sqrt(power(point[a].x - point[b].x) + power(point[a].y - point[b].y)); }//两点间距离。

// 比较a, b 和 b, c 之间斜率
inline bool judge(int a, int b, int c) {
	return (point[a].y - point[b].y)*(point[b].x - point[c].x)>(point[a].x - point[b].x)*(point[b].y - point[c].y);//算斜率，乘在一起避免掉精
}
inline bool cmp(node a, node b){ return (a.y == b.y) ? (a.x<b.x) : (a.y<b.y); }//纵坐标小的在前，若相等，就取横坐标小的。
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf%lf", &point[i].x, &point[i].y);
	}
	sort(point + 1, point + n + 1, cmp);
	st[1] = 1, st[2] = 2;//前两点已经确定，入栈。
	for (int i = 3; i <= n; i++)//枚举其他的节点从3开始。
	{
		while (top>1 && !judge(i, st[top], st[top - 1]))top--;//后者斜率（极角）小。
		st[++top] = i;//重新入栈。
	}
	for (int i = 1; i <= top - 1; i++)ans += dis(st[i], st[i + 1]);
	top = 2;
	memset(st, 0, sizeof(st));//最好memset一下，有可能出问题。
	st[1] = 1, st[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		while (top>1 && judge(i, st[top], st[top - 1]))top--;//把！去掉就可以了。
		st[++top] = i;
	}
	for (int i = 1; i <= top - 1; i++)ans += dis(st[i], st[i + 1]);//后一边基本一样。
	printf("%.2lf", ans);
	return 0;
}


/*

题目描述
农夫约翰想要建造一个围栏用来围住他的奶牛，可是他资金匮乏。他建造的围栏必须包括他的奶牛喜欢吃草的所有地点。对于给出的这些地点的坐标，计算最短的能够围住这些点的围栏的长度。

输入输出格式
输入格式：
输入数据的第一行包括一个整数 N。N（0 <= N <= 10,000）表示农夫约翰想要围住的放牧点的数目。接下来 N 行，每行由两个实数组成，Xi 和 Yi,对应平面上的放牧点坐标（-1,000,000 <= Xi,Yi <= 1,000,000）。数字用小数表示。

输出格式：
输出必须包括一个实数，表示必须的围栏的长度。答案保留两位小数。

输入输出样例
输入样例#1：
4
4 8
4 12
5 9.3
7 8
输出样例#1：
12.00

*/