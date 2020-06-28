#include <bits/stdc++.h>
using namespace std;


// 下面是数位DP解法..

#include<iostream>
#include<vector>
using namespace std;
int main() {
	long long int n, sum = 0;
	cin >> n;
	int a[100010] = { 0 };
	// vector<int> a(n+1, 0);

	// 遍历小于n的所有数.
	// 这种方法就是把小于n的所有数的1的个数算出来.
	// 因为增长长的是个位, 所以就是每次判断个位.
	for (int i = 1; i <= n; i++) {
		// 有一个递推的关系.
		// 如果个位为0, 这个位就没有作用了, 所以1的出现次数就和 i / 10 一样.
		// 注意下面这个很关键.
		if (i % 10 == 0)
			a[i] = a[i / 10];
		// 加一次, 因为 == i 的时候多了一次.
		else if (i % 10 == 1)
			a[i] = a[i - 1] + 1;
		// 因为变成2了, 所以应该和a[i - 2] 一样, 就是a[i - 1] - 1.
		else if (i % 10 == 2)
			a[i] = a[i - 1] - 1;
		else
			a[i] = a[i - 1];
		sum += a[i];
	}
	cout << sum << endl;


	return 0;
}


//
//// 这题直接看答案了...
//// 下面是据说比较通用的一个方法, 每一位扫, 分成当前位的左右两边.
//#include <iostream>
//using namespace std;
//int main() {
//	int n, left = 0, right = 0, a = 1, now = 1, ans = 0;
//	scanf("%d", &n);
//	while (n / a) {
//		// 
//		// 比如 a == 1000, n = 1234567
//		// left = 123, now = 4, right = 567.
//		// 分成三个部分, 其实就是中间那个部分就是一位的.
//
//		left = n / (a * 10), now = n / a % 10, right = n % a;
//		// cout << left << " " << now << " " << right << endl;
//
//		// 这三种情况下三种公式还是蛮神奇的哈.
//		if (now == 0)
//			ans += left * a;
//		else if (now == 1)
//			ans += left * a + right + 1;
//		else
//			ans += (left + 1) * a;
//
//		a = a * 10;
//	}
//	printf("%d", ans);
//	return 0;
//}

//int main() {
//	string N;
//	cin >> N;
//
//
//
//
//	return 0;
//}