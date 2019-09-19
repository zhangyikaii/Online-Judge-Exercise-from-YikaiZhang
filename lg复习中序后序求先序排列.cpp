// 这么短的代码真的6.
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

// BADC
// BDCA
void beford(string in, string after) {
	if (in.size() > 0) {
		char ch = after[after.size() - 1];
		cout << ch;//找根输出, 后序最后一个是根.
		// 每次输出根就可以了, 递归左右子树.
		int k = in.find(ch);
		beford(in.substr(0, k), after.substr(0, k));
		beford(in.substr(k + 1), after.substr(k, in.size() - k - 1));//递归左右子树；
	}
}
int main() {
	string inord, aftord;
	cin >> inord; 
	cin >> aftord;//读入
	beford(inord, aftord); 
	cout << endl;
	return 0;
}