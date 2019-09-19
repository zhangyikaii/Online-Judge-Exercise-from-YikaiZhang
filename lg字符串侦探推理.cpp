#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int MyMin(int a, int b) {
	return a > b ? b : a;
}

void Swap(int arr[], int i, int j) {
	if (i == j)
		return;

	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}

int m, n, p;
string str[50], say[110];
int say2Id[110] = { 0 }, say2Crimimal[50] = { 0 };
int ansArr[1000] = { 0 };

void WhoSaid() {
	for (int i = 1; i <= m; ++i) {
		for (int k = 1; k <= p; ++k) {
			if (say[k].find(str[i]) == 0)
				say2Id[k] = i;
		}
	}
}

void SaidCrimimal() {
	for (int k = 1; k <= p; ++k) {
		for (int i = 1; i <= m; ++i) {
			if (say[k].find(": " + str[i]) != string::npos) {
				say2Crimimal[say2Id[k]] = i;
				break;
			}
			else if (say[k].find(": I") != string::npos) {
				say2Crimimal[say2Id[k]] = say2Id[k];
				break;
			}
		}
	}
}

int main() {
	in(m);
	in(n);
	in(p);

	// 题目很麻烦, 还有is not之类的, 要打全匹配.

	for (int i = 1; i <= m; ++i) {
		cin >> str[i];
	}
	getline(cin, say[0]);
	for (int i = 1; i <= p; ++i) {
		getline(cin, say[i]);
	}

	WhoSaid();
	SaidCrimimal();

	// 尝试每个人是罪犯
	for (int i = 1; i <= m; ++i) {
		int lies[50] = { 0 }, k;
		for (k = 1; k <= m; ++k) {
			if (say2Crimimal[k] == 0)
				continue;

			// 说慌了.
			if ((lies[k] == 0 || lies[k] == 1) && say2Crimimal[k] != i) {
				lies[k] = 1;
			}
			// 说实话了.
			else if ((lies[k] == 0 || lies[k] == 2) && say2Crimimal[k] == i) {
				lies[k] = 2;
			}
			else
				break;
		}
		if (k <= m)
			continue;

		// 统计说谎人个数
		int ans = 0;
		for (int j = 1; j <= m; ++j) {
			if (lies[j] == 1)
				++ans;
		}
		if (ans == n) {
			ansArr[++ansArr[0]] = i;
		}
	}

	if (ansArr[0] == 1) {
		cout << str[ansArr[1]] << endl;
	}
	else if (ansArr[0] == 0) {
		printf("Impossible\n");
	}
	else {
		printf("Cannot Determine\n");
	}

	return 0;
}


/*

题目描述
明明同学最近迷上了侦探漫画《柯南》并沉醉于推理游戏之中，于是他召集了一群同学玩推理游戏。游戏的内容是这样的，明明的同学们先商量好由其中的一个人充当罪犯（在明明不知情的情况下），明明的任务就是找出这个罪犯。接着，明明逐个询问每一个同学，被询问者可能会说：



证词中出现的其他话，都不列入逻辑推理的内容。

明明所知道的是，他的同学中有NN个人始终说假话，其余的人始终说真。

现在，明明需要你帮助他从他同学的话中推断出谁是真正的凶手，请记住，凶手只有一个！

输入输出格式
输入格式：
输入由若干行组成，第一行有三个整数，M(1≤M≤20)M(1≤M≤20)、N(1≤N≤M)N(1≤N≤M)和P(1≤P≤100)P(1≤P≤100)；MM是参加游戏的明明的同学数，NN是其中始终说谎的人数，PP是证言的总数。

接下来MM行，每行是明明的一个同学的名字（英文字母组成，没有空格，全部大写）。

往后有PP行，每行开始是某个同学的名宇，紧跟着一个冒号和一个空格，后面是一句证词，符合前表中所列格式。证词每行不会超过250250个字符。

输入中不会出现连续的两个空格，而且每行开头和结尾也没有空格。

输出格式：
如果你的程序能确定谁是罪犯，则输出他的名字；如果程序判断出不止一个人可能是罪犯，则输出 "Cannot Determine"；如果程序判断出没有人可能成为罪犯，则输出 "Impossible"。

输入输出样例
输入样例#1：
3 1 5
MIKE
CHARLES
KATE
MIKE: I am guilty.
MIKE: Today is Sunday.
CHARLES: MIKE is guilty.
KATE: I am guilty.
KATE: How are you??
输出样例#1：
MIKE


*/