#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;


struct Data {
	string str;
	int index;
	Data() : index(0) { }
	bool operator<(const Data &c) const {
		return this->str < c.str;
	}
};

#define in(x) x=read()

#define MAXN 1000000

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n;
Data *arr;
int minEqual, curEqual;



void ResQuickSort(int left, int right, string resArr[]) {
	int i, j;
	string temp;
	if (left > right)
		return;

	temp = resArr[left];		// 取出基准数
	i = left;
	j = right;
	// 注意把 left 和 right 临时寄放在 i j 里面, 然后要先从右边开始找
	while (i != j) {
		while (resArr[j] >= temp && i < j)		// 从右往左找到第一个更小的(应该放在左边的)
			--j;
		while (resArr[i] <= temp && i < j)		// 从左往右找到第一个更大的(应该放在右边的)
			++i;

		// 交换位置
		if (i < j) {
			string t = resArr[i];
			resArr[i] = resArr[j];
			resArr[j] = t;
		}
	}

	// 最终将基准数归位
	resArr[left] = resArr[i];         // 注意这句话!!!
	resArr[i] = temp;

	ResQuickSort(left, i - 1, resArr);			//继续处理左边的
	ResQuickSort(i + 1, right, resArr);			//继续处理右边的
}


string StringSort(string &s) {
	int cou[30] = { 0 }, nn = s.length();
	for (int i = 0; i < nn; ++i) {
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

	arr = new Data[n];
	string *tmp = new string[n];
	string *resArr = new string[n];
	int *ress = new int[n], iRes = 0;

	for (int i = 0; i < n; ++i) {
		cin >> tmp[i];
		arr[i].str = StringSort(tmp[i]);
		arr[i].index = i;
	}
	

	sort(arr, arr + n);

	/*for (int i = 0; i < n; ++i) {
		cout << rank[i] << " ";
	}
	cout << endl;

	cout << endl;*/

	curEqual = 0;
	int ti;
	for (ti = 1; ti < n; ++ti) {
		if (arr[curEqual].str == arr[ti].str)
			continue;
		else {
			if (curEqual + 1 != ti) {
				minEqual = curEqual;
				cout << tmp[arr[minEqual].index] << " ";
				for (int k = curEqual + 1; k < ti; ++k) {
					cout << tmp[arr[k].index] << " ";
					if (tmp[arr[k].index] < tmp[arr[minEqual].index]) {
						minEqual = k;
					}
				}
				ress[iRes++] = minEqual;
			}
			curEqual = ti;
		}
	}
	if (curEqual + 1 != ti) {
		minEqual = curEqual;
		for (int k = curEqual + 1; k < ti; ++k) {
			if (tmp[arr[k].index] < tmp[arr[minEqual].index]) {
				minEqual = k;
			}
		}
		ress[iRes++] = minEqual;
	}

	printf("wo yi yue du guan yu chao xi de shuo ming\n");
	cout << iRes << endl;
	for (int i = 0; i < iRes; ++i) {
		resArr[i] = tmp[arr[ress[i]].index];
	}

	/*for (int i = 0; i < iRes; ++i) {
		cout << resArr[i] << endl;
	}*/

	sort(resArr, resArr + iRes);
	for (int i = 0; i < iRes; ++i) {
		cout << resArr[i] << endl;
	}
	

	delete[] arr;
	delete[] ress;
	delete[] tmp;
	delete[] resArr;

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