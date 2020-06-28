//#include <bits/stdc++.h>
//using namespace std;
//
//int a, b, c;
//
//bool isUsed(int a, int used[]) {
//	if (a >= 1000)
//		return false;
//	int x = a / 100 % 10, y = a / 10 % 10, z = a % 10;
//	if (x == 0 || y == 0 || z == 0)
//		return false;
//	if (used[x] == 1 || used[y] == 1 || used[z] == 1)
//		return false;
//	if (x == y || y == z || x == z)
//		return false;
//
//	used[x] = 1, used[y] = 1, used[z] = 1;
//
//	return true;
//}
//
//bool flag = false;
//
//int main() {
//	cin >> a >> b >> c;
//
//	for (int i = 1; i < 10; ++i) {
//		for (int k = 1; k < 10; ++k) {
//			if (i == k)
//				continue;
//			for (int j = 1; j < 10; ++j) {
//				if (j == k || j == i)
//					continue;
//				int cur = i * 100 + k * 10 + j;
//
//				if (cur * b % a != 0)
//					continue;
//				if (cur * c % a != 0)
//					continue;
//
//				int bcur = cur * b / a, ccur = cur * c / a;
//				int used[11] = { 0 };
//				if (isUsed(bcur, used) && isUsed(cur, used) && isUsed(ccur, used)) {
//					flag = true;
//					cout << cur << " " << bcur << " " << ccur << endl;
//				}
//			}
//		}
//	}
//
//	if (flag == false)
//		cout << "No!!!" << endl;
//
//	return 0;
//}


// 上面是自己写的AC了的代码

#include<bits/stdc++.h>

typedef long long ll;
// ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

using namespace std;
int a, b, c, k, st, ed, check = 1, l[10];
int main()
{
	scanf("%d%d%d", &a, &b, &c);
	k = gcd(gcd(a, b), c);
	a /= k, b /= k, c /= k;
	st = 123 / a + (123 % a > 0), ed = 987 / c;
	for (int _i = st; _i <= ed; _i++)
	{
		memset(l, 0, sizeof(l));
		int i = _i * a, j = _i * b, k = _i * c, flg = 1;
		while (i)l[i % 10]++, i /= 10;
		while (j)l[j % 10]++, j /= 10;
		while (k)l[k % 10]++, k /= 10;
		for (int _j = 1; _j <= 9; _j++)if (!l[_j])flg = 0;
		if (flg)printf("%d %d %d\n", _i * a, _i * b, _i * c), check = 0;
	}
	if (check)puts("No!!!");
	return 0;
}