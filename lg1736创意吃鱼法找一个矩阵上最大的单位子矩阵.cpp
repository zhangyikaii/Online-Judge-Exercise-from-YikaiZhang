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
//#include <queue>
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
//int arr[3000][3000], res[3000][3000];
//int ans = 0;
//
//int main() {
//	FOR(i, 0, 3000) {
//		FOR(k, 0, 3000)
//			res[i][k] = -1;
//	}
//	int n, m;
//	in(n), in(m);
//	FOR(i, 0, n) {
//		FOR(k, 0, m) {
//			in(arr[i][k]);
//		}
//	}
//
//	FOR(i, 0, m) {
//		if (arr[0][i] == 1)
//			res[0][i] = i;
//	}
//
//	FOR(i, 1, n) {
//		FOR(k, 0, m) {
//			if (k == 0) {
//				if (arr[i][k] == 1)
//					res[i][k] = 0;
//				continue;
//			}
//			if (arr[i - 1][k] == 0 && arr[i][k - 1] == 0 && arr[i][k] == 1) {
//				if (res[i - 1][k - 1] == -1)
//					res[i][k] = k;
//				else {
//					res[i][k] = res[i - 1][k - 1];
//					ans = max(ans, k - res[i - 1][k - 1] + 1);
//				}
//			}
//			else if (arr[i][k] == 1 && !(arr[i - 1][k] == 0 && arr[i][k - 1] == 0)) {
//				res[i][k] = k;
//			}
//		}
//	}
//
//	/*cout << endl;
//
//	FOR(i, 0, n) {
//		FOR(k, 0, m)
//			cout << res[i][k] << " ";
//		cout << endl;
//	}*/
//
//	cout << ans << endl;
//	
//	return 0;
//}
//
//


// 下面是答案
// 注意对角线左右都可以呀..
//
//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//#include<cstring>
//using namespace std;
//#define N 2510
//int dp[N][N], sum[N][N];  //sum表示从(1,1)到(i,j)的元素和
//bool map[N][N];
//int maxx = 0;
//
//// 二维前缀和.
//int getsum(int i, int j, int x, int y) {
//	return sum[x][y] - sum[x][j - 1] - sum[i - 1][y] + sum[i - 1][j - 1];  //二维前缀和的精华操作，表示对角线从(i,j)到(x,y)的子矩阵的元素和
//}
//int read() {
//	int ans = 0, f = 1;
//	char ch = getchar();
//	while (!isdigit(ch)) {
//		if (ch == '-') f = -1;
//		ch = getchar();
//	}
//	while (isdigit(ch)) {
//		ans = ans * 10 + ch - '0';
//		ch = getchar();
//	}
//	return f*ans;
//}
//
//// 二维前缀和 => 数组从1 开始读!!!
//int main() {
//	int i, j, n = read(), m = read();
//	for (i = 1; i <= n; i++) {
//		int num = 0;
//		for (j = 1; j <= m; j++) {
//			map[i][j] = read();
//			num += map[i][j];
//			sum[i][j] = sum[i - 1][j] + num;  //初始化二维前缀和 注意这样初始化还行, 有一个num记录当前行前面的数和.
//		}
//	}
//	//左对角线操作
//	// 二维前缀和 + 二分 这个已经是套路了..
//	for (i = 1; i <= n; i++) {
//		for (j = 1; j <= m; j++) {
//			// 如果这个位置 == 1.
//			if (map[i][j]) {
//				dp[i][j] = 1; // 初始化为1，在这里没什么意义，但在下面求右对角线时是必要的
//				if (dp[i - 1][j - 1]) {
//					int num = dp[i - 1][j - 1];
//					int l = 0, r = num, ans = 0;
//					//以下即为二分查找，功能就是找出符合条件的最长对角线长度
//					while (l <= r) {
//						int mid = l + r >> 1;
//						if (getsum(i - mid, j - mid, i, j) == mid + 1) ans = mid, l = mid + 1;
//						else r = mid - 1;
//					}
//					dp[i][j] = max(dp[i][j], ans + 1);
//				}
//				maxx = max(maxx, dp[i][j]);
//			}
//		}
//	}
//	// 右对角线长度
//	for (i = 1; i <= n; i++)
//	for (j = 1; j <= m; j++)
//	if (map[i][j]) {
//		dp[i][j] = 1;
//		if (dp[i - 1][j + 1]) {
//			int num = dp[i - 1][j + 1];
//			int l = 0, r = num, ans = 0;
//			while (l <= r) {
//				int mid = l + r >> 1;
//				if (getsum(i - mid, j, i, j + mid) == mid + 1) ans = mid, l = mid + 1; //注意getsum()内填入的顺序，我一开始就被坑了
//				else r = mid - 1;
//			}
//			dp[i][j] = max(dp[i][j], ans + 1);
//		}
//		maxx = max(maxx, dp[i][j]);
//	}
//	printf("%d\n", maxx);
//	return 0;
//}


// 最后一个dp的思路, 非常不错, 这就很像我的思路, 但是为什么我不行呢.. 就是因为没有s1[]和s2[] 这两个数组, 使每次
// 100
// 010
// 101
// 这个例子就会出错


#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
typedef long long ll;
using namespace std;
int n, m, ans;
int a[2509][2509], f[2509][2509], s1[2509][2509], s2[2509][2509];//s1为横向，s2为纵向 
int main()
{
	cin >> n >> m;
	//第一遍左上——右下 
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	{
		scanf("%d", &a[i][j]);
		if (!a[i][j])
		{
			s1[i][j] = s1[i][j - 1] + 1;
			s2[i][j] = s2[i - 1][j] + 1;
		}
		if (a[i][j])
			f[i][j] = min(f[i - 1][j - 1], min(s1[i][j - 1], s2[i - 1][j])) + 1;
		ans = max(ans, f[i][j]);
	}
	//第二遍右上——左下 
	memset(f, 0, sizeof(f));
	memset(s1, 0, sizeof(s1));//数组置0 
	memset(s2, 0, sizeof(s2));
	for (int i = 1; i <= n; i++)
	for (int j = m; j >= 1; j--)
	{
		if (!a[i][j])
		{
			s1[i][j] = s1[i][j + 1] + 1;
			s2[i][j] = s2[i - 1][j] + 1;
		}
		if (a[i][j])
			f[i][j] = min(f[i - 1][j + 1], min(s1[i][j + 1], s2[i - 1][j])) + 1;
		ans = max(ans, f[i][j]);
	}
	cout << ans << endl;
	return 0;
}