//#include <bits/stdc++.h>
//using namespace std;
//
//int arr[100010];
//
//int main() {
//	int n;
//	cin >> n;
//	if (n == 0)
//		cout << "0" << endl;
//
//	for (int i = 0; i < n; ++i) {
//		cin >> arr[i];
//	}
//
//	int bef = 0, aft = 1;
//	while (aft < n) {
//		if (arr[bef] != aft) {
//			++ans;
//			++bef;
//		}
//		else {
//			++aft;
//		}
//	}
//
//	return 0;
//}


#include <iostream>
#include <algorithm>
#include <cmath> 
#include <string>
#include <cstring>
using namespace std;
int n, t, num;
int a[1005];
int main()
{
	while (cin >> n) {
		t = 0, num = 1005;
		for (int i = 0; i < n; i++) {
			cin >> a[i];

			// 直接在线处理, num记录bef.
			if (a[i] != num) {
				t++;
				num = a[i];
			}
		}
		cout << t << endl;
	}
	return 0;
}