#include<iostream>
#include<string>
#include<cstring>//不加会CE
using namespace std;
int n;
string s;
int main()
{
	cin >> n;
	cin >> s;

	//由于第一个为原串，所以单独输入
	for (int i = 2; i <= n; ++i) {
		string ss;
		cin >> ss;
		int x = s.find(ss[0]);//找到这个子树的根节点在原串中的位置
		s.erase(x, 1);//清除根节点
		s.insert(x, ss);//加入子树
	}
	for (int i = 0; i < s.size(); ++i)
		if (s[i] != '*') cout << s[i];//不输出空节点


	return 0;
}