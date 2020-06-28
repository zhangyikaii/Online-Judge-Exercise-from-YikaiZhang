#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define INF 0x7fffff

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

string a, b;

// compare比较函数：相等返回0，大于返回1，小于返回-1
int compare(string str1, string str2) {
	// 请记住string的compare不能处理长度更长带来的数字更大.
	if (str1.length() > str2.length())
		return 1;
	else if (str1.length() < str2.length())
		return -1;
	else
		return str1.compare(str2);
}

string add(string str1, string str2) {
	string str;
	int len1 = str1.length();
	int len2 = str2.length();
	// 前面补0，弄成长度相同
	if (len1 < len2) {
		for (int i = 1; i <= len2 - len1; i++)
			str1 = "0" + str1;
	}
	else {
		for (int i = 1; i <= len1 - len2; i++)
			str2 = "0" + str2;
	}
	len1 = str1.length();
	int cf = 0; // ICS既视感.
	int temp;
	for (int i = len1 - 1; i >= 0; i--) {
		temp = str1[i] - '0' + str2[i] - '0' + cf;
		cf = temp / 10; // 进位
		temp %= 10;
		str = char(temp + '0') + str; // 计算结果.
	}
	if (cf != 0)
		str = char(cf + '0') + str;
	return str;
}

int main() {
	cin >> a >> b;
	cout << add(a, b) << endl;

	return 0;
}