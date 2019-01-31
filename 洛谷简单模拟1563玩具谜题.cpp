#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;

struct Person
{
	char name[11];
	long long id;
};

inline long long read(){
	long long s = 0, w = 1;
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

#define MAX 100010
#define MAXtest 30
int main() {
	long n = 0, m = 0;
	Person p[MAX];
	n = read();
	m = read();

	for (long long i = 0; i < n; ++i) {
		p[i].id = read();
		gets(p[i].name);
	}

	long long a = 0, b = 0;
	long long cur = 0;
	for (long long i = 0; i < m; ++i) {
		a = read();
		b = read();
		// 左数 就是 减
		if (!(a ^ p[cur].id)) {
			cur = (cur + n - b) % n;
		}
		else {
			cur = (cur + b) % n;
		}
	}

	cout << p[cur].name << endl;

	return 0;
}

/*

输入的第一行包含两个正整数 n,m，表示玩具小人的个数和指令的条数。

接下来 n 行，每行包含一个整数和一个字符串，以逆时针为顺序给出每个玩具小人的朝向和职业。其中 0 表示朝向圈内，1 表示朝向圈外。 保证不会出现其他的数。字符串长度不超过 10 且仅由小写字母构成，字符串不为空，并且字符串两两不同。整数和字符串之间用一个空格隔开。

输出格式：
输出一个字符串，表示从第一个读入的小人开始，依次数完 m 条指令后到达的小人的职业


输入:
7 3
0 singer
0 reader
0 mengbier
1 thinker
1 archer
0 writer
1 mogician
0 3
1 1
0 2

输出:
writer

*/