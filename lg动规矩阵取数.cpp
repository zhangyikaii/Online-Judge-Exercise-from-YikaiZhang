//#include <iostream> 
//#include <cstdio> 
//#include <algorithm> 
//#include <cstring>
//#include <cmath>
//#include <cstdlib>
//#include <string>
//#include <string.h>
//#include <vector>
//#include <set>
//
//using namespace std;
//
//#define in(x) x=read()
//
//#define FOR(i, s, n) for(int i = s; i < n; ++i)
//
//typedef long long ll;
//
//inline int read() {
//	int X = 0, w = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X*w;
//}
//
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//struct point
//{
//	int x, y, data;//记录每个点的位置和数值
//}p[100];
//int n, m, map[11][11], f[11][11];
//int main()
//{
//	int i, ii, j, jj, l;
//	scanf("%d", &n);
//	while (1)
//	{
//		int a, b, c;
//		scanf("%d%d%d", &a, &b, &c);
//		if (!a&&!b&&!c)
//			break;
//		p[++m].x = a;
//		p[m].y = b;
//		p[m].data = c;
//	}
//	for (i = 1; i <= m; i++)
//		map[p[i].x][p[i].y] = p[i].data;
//	for (l = 2; l <= n * 2; l++) {
//		//每个点最少横着竖着都走一格，最多都走n格就到终点
//		for (i = l - 1; i >= 1; i--) {
//			//和前面说的一样，倒着做
//			for (ii = l - 1; ii >= 1; ii--) {
//				j = l - i; jj = l - ii;//i+j=ii+jj=l
//				f[i][ii] = max(max(f[i][ii], f[i - 1][ii - 1]), max(f[i - 1][ii], f[i][ii - 1])) + map[i][j];
//				//重点说明一下吧，这里省略了很多。如果i不减1，意思就是j-1，因为上一个阶段就是l-1嘛。如果ii-1，意思就是说jj不减1。
//				f[i][ii] += map[ii][jj] * (i != ii);
//				//如果i==ii，其实就是(i==ii&&j==jj)，因为和都是l嘛。如果走过一遍，第二遍走得到的值就是0（题目上说的）。
//			}
//		}
//	}
//	printf("%d\n", f[n][n]);
//	//输出意思是在路径长度为2*n的阶段，两遍都走到(n,n)的最优值。因为在这里(j=2*n-i=n,jj=2*n-ii=n),所以走到的就是(n,n)的位置
//	return 0;
//}
//
//
////
////int arr[110][110];
////int res[110][110];
////int way[110][110];
////
////int main() {
////	int n;
////	in(n);
////
////	FOR(i, 0, n + 1) {
////		FOR(j, 0, n + 1) {
////			arr[i][j] = 0;
////			res[i][j] = 0;
////			way[i][j] = 0;
////		}
////	}
////
////	int a, b, c;
////	while (true) {
////		in(a), in(b), in(c);
////		if (a == 0 && b == 0 && c == 0)
////			break;
////		arr[a][b] = c;
////	}
////
////	for (int i = 1; i <= n; ++i) {
////		for (int j = 1; j <= n; ++j) {
////			res[i][j] = arr[i][j] + max(res[i - 1][j], res[i][j - 1]);
////			if (arr[i - 1][j] > arr[i][j - 1]) {
////				way[i][j] = -1;
////			}
////			else
////				way[i][j] = -2;
////		}
////	}
////
////	cout << res[n][n] << endl;
////	
////	return 0;
////}


#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int f[12][12][12][12], a[12][12], n, x, y, z;
int main() {
	cin >> n >> x >> y >> z;
	while (x != 0 || y != 0 || z != 0){
		a[x][y] = z;
		cin >> x >> y >> z;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			for (int k = 1; k <= n; k++){
				for (int l = 1; l <= n; l++){
					f[i][j][k][l] = max(max(f[i - 1][j][k - 1][l], f[i - 1][j][k][l - 1]), max(f[i][j - 1][k - 1][l], f[i][j - 1][k][l - 1])) + a[i][j] + a[k][l];
					// 注意注意这里, 因为到了同一个位置只能取一次, 所以要加回去.
					if (i == k&&l == j)f[i][j][k][l] -= a[i][j];
				}
			}
		}
	}
	cout << f[n][n][n][n];
	return 0;
}