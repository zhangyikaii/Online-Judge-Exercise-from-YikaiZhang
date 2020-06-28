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

#include<string>
#include<iostream>

using namespace std;
string a;

string ff(int arr[], int n) {
	string c;
	int b = 2, d = 0;
	for (int i = 0; i < n; i++) {
		c.push_back((d * 10 + arr[i]) / b + '0');
		d = (d * 10 + arr[i]) % b;  //模拟竖式
	}

	for (int i = 0; c[0] == '0'; i++)
		c.erase(c.begin(), c.begin() + 1);   //去0

	return c;
}
int main() {
	
	//string res;
	//int arr[100010];
	//cin >> a;

	//// 先用数组存起来
	//for (int i = 0; i < a.length(); i++)
	//	arr[i] = a[i] - '0';   //字符串转数字

	//string tmp = a;
	//do {
	//	if ((tmp[tmp.length() - 1] - '0') % 2 == 0)
	//		res.push_back('0');
	//	else
	//		res.push_back('1');
	//	
	//	tmp = ff(arr, tmp.length());
	//	for (int i = 0; i < tmp.length(); ++i)
	//		arr[i] = tmp[i] - '0';
	//} while (tmp.size() != 0);

	//for (int i = res.length() - 1; i >= 0; --i) {
	//	cout << res[i];
	//}	
	//cout << endl;
	return 0;     //完美的结束
}