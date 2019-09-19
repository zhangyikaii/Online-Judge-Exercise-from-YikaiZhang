#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


#define in(x) x=read()

#define MAXN 1000000

typedef long long ll;

inline ll read() {
	ll X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

ll n;

string StringSort(string &s) {
	int cou[30] = { 0 }, n = s.length();
	for (int i = 0; i < n; ++i) {
		++cou[s[i] - 'a'];
	}
	string res = "";
	for (int i = 0; i < 26; ++i) {
		while (cou[i]--) {
			res += ('a' + i);
		}
	}
	return res;
}


int main() {
	ios::sync_with_stdio(false);
	in(n);

	unordered_map<string, vector<string>> ump;
	string temp, tarr;
	string *res = new string[n];
	ll iRes = 0;

	for (ll i = 0; i < n; ++i) {
		cin >> tarr;
		temp = StringSort(tarr);
		ump[temp].push_back(tarr);
	}



	for (unordered_map<string, vector<string>>::iterator i = ump.begin(); i != ump.end(); ++i) {
		if (i->second.size() > 1) {
			sort(i->second.begin(), i->second.end());
			// cout << i->second[0] << endl;
			res[iRes++] = i->second[0];
		}
	}

	sort(res, res + iRes);

	printf("wo yi yue du guan yu chao xi de shuo ming\n%lld\n", iRes);
	for (ll i = 0; i < iRes; ++i) {
		cout << res[i] << endl;
	}


	delete[] res;

	return 0;
}

/*

题目描述
请大家在做oj题之前，仔细阅读关于抄袭的说明http://www.bigoh.net/JudgeOnline/.


变位词是指由相同的字母组成的单词，如eat、tea是变位词。本次问题给出一串单词，你需要找到所有的变位词。

输入
输入由两行组成：第一行是所有单词的总数，第二行是由空格分隔的单词列表。两行末尾都有空格。

注：为防歧义，输入的单词都是小写

输出
这次需要大家先输出一个字符串，它是“我已阅读关于抄袭的说明”的汉语拼音.输出此行的提交我们将认为已经完全阅读并了解了“关于抄袭的说明”公告.

第二行是变位词组的个数，后面是所有的变位词。每个输出的变位词占一行。一组变位词只需要输出一个字典序最小的代表即可，如eat、tea中eat字典序小于tea，所以输出eat。变位词与变位词也按照字典序从小到大排列，如eat和el中eat字典序小于el所以eat在el前面。

输出的每一行最后都没有空格。

样例输入
9
a ew vc tea oe eat zoo el le
样例输出
wo yi yue du guan yu chao xi de shuo ming
2
eat
el

*/