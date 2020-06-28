#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<map>
#define INF 0xfffffff

#define CLR(a,b,Size) memset((a),(b),sizeof((a[0]))*(Size+1))
#define CPY(a,b) memcpy ((a), (b), sizeof((a)))
using namespace std;
typedef long long ll;

#define in(x) x=read()

#define For(i, a, b) for(int i = a; i < b; ++i)

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

string name[15];
map<string, int> res;

int main() {
	int n;
	in(n);

	For(i, 0, n) {
		cin >> name[i];
		res[name[i]] = 0;
	}

	For(i, 0, n) {
		string tName;
		cin >> tName;
		int monTmp, monNum;
		in(monTmp);
		in(monNum);
		if (monNum != 0) {
			int sen = monTmp / monNum;
			res[tName] -= (sen * monNum);
			For(k, 0, monNum) {
				string ttName;
				cin >> ttName;
				res[ttName] += sen;
			}
		}
	}

	For(i, 0, n) {
		cout << name[i] << " " << res[name[i]] << endl;;
	}
	
	return 0;
}

/*

题目描述
对于一群（NP个）要互送礼物的朋友，GY要确定每个人送出的钱比收到的多多少。在这一个问题中，每个人都准备了一些钱来送礼物，而这些钱将会被平均分给那些将收到他的礼物的人。然而，在任何一群朋友中，有些人将送出较多的礼物(可能是因为有较多的朋友)，有些人有准备了较多的钱。给出一群朋友，没有人的名字会长于 14 字符，给出每个人将花在送礼上的钱，和将收到他的礼物的人的列表，请确定每个人收到的比送出的钱多的数目。

输入格式
第 1 行: 人数NP,2<= NP<=10

第 2 行 到 第NP+1 行:这NP个在组里人的名字一个名字一行

第NP＋2到最后：

这里的I段内容是这样组织的：

第一行是将会送出礼物人的名字。

第二行包含二个数字:第一个是原有的钱的数目（在0到2000的范围里），第二个 NGi 是将收到这个人礼物的人的个数 如果 NGi 是非零的, 在下面 NGi 行列出礼物的接受者的名字，一个名字一行。

输出格式
输出共 NP NP 行，每行输出一个人的名字和该人收到的钱比送出的钱多的数目。名字的顺序应该与输入第 2 2 行至 NP+1 NP+1 行的顺序相同。

送出的钱永远是整数，即假设送礼人一次向 m m 人送出 n n 元，每个人应该得到 \lfloor n/m \rfloor ⌊n/m⌋ 元。剩余未送出的钱应返还给送礼者。

输入输出样例
输入 #1 复制
5
dave
laura
owen
vick
amr
dave
200 3
laura
owen
vick
owen
500 1
dave
amr
150 2
vick
owen
laura
0 2
amr
vick
vick
0 0
输出 #1 复制
dave 302
laura 66
owen -359
vick 141
amr -150





*/