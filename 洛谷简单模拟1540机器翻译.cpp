#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

inline int read(){
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}

#define MAX 40

int main() {
	int m, n;
	m = read();
	n = read();
	int input;
	int used[1010] = { false }, res = 0;
	queue<int> q;

	for (int i = 0; i < n; ++i) {
		input = read();
		if (used[input] == false && q.size() < m) {
			used[input] = true;
			q.push(input);
		}
		else if (used[input] == false && q.size() == m) {
			used[input] = true;
			used[q.front()] = false;
			q.pop();
			q.push(input);
		}
		else if (used[input] == true) {
			++res;
		}
	}

	cout << n - res << endl;
	
	return 0;
}


/*
整个查字典过程如下：每行表示一个单词的翻译，冒号前为本次翻译后的内存状况：

空：内存初始状态为空。

1． 1：查找单词1并调入内存。

2． 12：查找单词2并调入内存。

3． 12：在内存中找到单词1。

4． 125：查找单词5并调入内存。

5． 254：查找单词4并调入内存替代单词1。

6． 254：在内存中找到单词4。

7． 541：查找单词1并调入内存替代单词2。

共计查了5次词典。
*/