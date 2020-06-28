// 纯sort过不了
#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
using namespace std;

struct Data {
	int id, w, score;
	bool operator<(Data t) {
		if (t.score == score) {
			return t.id > id;
		}

		return t.score < score;
	}
};

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

Data arr[100010], tmp[100010];
int win[100010] = { 0 }, lose[100010] = { 0 };
int i_tmp = 1, iWin = 1, iLose = 1;
int n, r, q;

// 注意归并的格式. 很简单很典型, 分成的两个序列要有序.
// 可以用归并, 关键就在每轮之后, 赢的人就是原来序列抽出来的( 两个两个比赛 ), 肯定是有序的
// 必须要借一个 tmp[]
void merge() {
	int i = 1, j = 1;
	i_tmp = 1;
	// 这里是不是取到最后一个一定要记清
	while (i < iWin && j < iLose) {
		// 这什么鬼重载, 你自己想清楚来!!!
		if (arr[win[i]] < arr[lose[j]])
			tmp[i_tmp++] = arr[win[i++]];

		else
			tmp[i_tmp++] = arr[lose[j++]];
	}

	while (i < iWin)
		tmp[i_tmp++] = arr[win[i++]];
	while (j < iLose)
		tmp[i_tmp++] = arr[lose[j++]];

	/*if (i_tmp != n + 1)
		cout << "error" << endl;*/

	for (int i = 1; i <= n; ++i)
		arr[i] = tmp[i];
	/*int end1 = n / 2, end2 = n;
	int i = 1, j = end1 + 1;

	while (i <= end1 && j <= end2) {
		if (arr[i] < arr[j])
			tmp[i_tmp++] = arr[j++];
		else
			tmp[i_tmp++] = arr[i++];
	}

	while (i <= end1)
		tmp[i_tmp++] = arr[i++];
	while (j <= end2)
		tmp[i_tmp++] = arr[j++];

	for (int i = 1; i <= n; ++i)
		arr[i] = tmp[i];*/					// 注意是有序归并
}


int main() {
	// freopen("testdata (1).in", "r", stdin);
	in(n);
	n *= 2;
	in(r);
	in(q);

	for (int i = 1; i <= n; ++i) {
		arr[i].id = i;
		in(arr[i].score);
	}
	for (int i = 1; i <= n; ++i) {
		in(arr[i].w);
	}

	sort(arr + 1, arr + n + 1);

	while (r--) {
		/*for (int i = 1; i <= n; ++i)
			cout << arr[i].id << " ";
		cout << endl;*/
		iWin = 1;
		iLose = 1;
		for (int i = 1; i <= n; i += 2) {
			if (arr[i].w > arr[i + 1].w) {
				arr[i].score++;
				win[iWin++] = i;
				lose[iLose++] = i + 1;
			}
			else {
				arr[i + 1].score++;
				win[iWin++] = i + 1;
				lose[iLose++] = i;
			}
		}

		merge();
	}


	printf("%d\n", arr[q].id);


	return 0;
}

//#include <algorithm>
//using namespace std;
//
//int n, r, q;
//int a[200100], win[200100], lose[200100];			// win[] 当前赢的人的序号.
//int s[200100], w[200100];
//
//bool cmp(int x, int y) {
//	if (s[x] == s[y])   return x<y;
//	return s[x]>s[y];
//}
//void merge() {
//	int i, j;
//	i = j = 1, a[0] = 0;
//	// win[0] 是当前存了几个, win[win[0]] 就是最后一个.
//	// 同理 a[0] 也有相同的意思.
//	while (i <= win[0] && j <= lose[0]) {
//		if (cmp(win[i], lose[j]))
//			a[++a[0]] = win[i++];
//		else
//			a[++a[0]] = lose[j++];
//	}
//
//	// 归并完还有没有的, 继续弄进去.
//	while (i <= win[0])
//		a[++a[0]] = win[i++];
//	while (j <= lose[0])
//		a[++a[0]] = lose[j++];
//}
//int main() {
//	cin >> n >> r >> q; n *= 2;
//	for (int i = 1; i <= n; i++)
//		a[i] = i;
//	for (int i = 1; i <= n; i++)
//		cin >> s[i];
//	for (int i = 1; i <= n; i++)
//		cin >> w[i];
//
//	sort(a + 1, a + n + 1, cmp);
//
//	// r 轮比赛.
//	for (int i = 1; i <= r; i++) {
//		win[0] = lose[0] = 0;			// win[0] 就像 i_win 就是记录当前到了哪里的那个标志
//		for (int j = 1; j <= n; j += 2) {
//			if (w[a[j]] > w[a[j + 1]]) {
//				s[a[j]]++;
//				win[++win[0]] = a[j];
//				lose[++lose[0]] = a[j + 1];
//			}
//			else {
//				s[a[j + 1]]++;
//				win[++win[0]] = a[j + 1];
//				lose[++lose[0]] = a[j];
//			}
//			merge();						// 排序
//		}
//	}
//	cout << a[q];
//	return 0;
//}

/*

题目背景
在双人对决的竞技性比赛，如乒乓球、羽毛球、国际象棋中，最常见的赛制是淘汰赛和循环赛。前者的特点是比赛场数少，每场都紧张刺激，但偶然性较高。后者的特点是较为公平，偶然性较低，但比赛过程往往十分冗长。

本题中介绍的瑞士轮赛制，因最早使用于18951895年在瑞士举办的国际象棋比赛而得名。它可以看作是淘汰赛与循环赛的折中，既保证了比赛的稳定性，又能使赛程不至于过长。

题目描述
2 \times N2×N 名编号为 1\sim 2N1∼2N 的选手共进行R 轮比赛。每轮比赛开始前，以及所有比赛结束后，都会按照总分从高到低对选手进行一次排名。选手的总分为第一轮开始前的初始分数加上已参加过的所有比赛的得分和。总分相同的，约定编号较小的选手排名靠前。

每轮比赛的对阵安排与该轮比赛开始前的排名有关：第11 名和第22 名、第 33 名和第 44名、……、第2K - 1 2K−1名和第 2K2K名、…… 、第2N - 1 2N−1名和第2N2N名，各进行一场比赛。每场比赛胜者得1 1分，负者得 0 0分。也就是说除了首轮以外，其它轮比赛的安排均不能事先确定，而是要取决于选手在之前比赛中的表现。

现给定每个选手的初始分数及其实力值，试计算在R 轮比赛过后，排名第 QQ 的选手编号是多少。我们假设选手的实力值两两不同，且每场比赛中实力值较高的总能获胜。

输入输出格式
输入格式：
第一行是三个正整数N,R ,QN,R,Q,每两个数之间用一个空格隔开，表示有 2 \times N 2×N名选手、RR 轮比赛，以及我们关心的名次 QQ。

第二行是2 \times N2×N 个非负整数s_1, s_2, …, s_{2N}s
1
​	 ,s
2
​	 ,…,s
2N
​	 ，每两个数之间用一个空格隔开，其中 s_i s
i
​	 表示编号为ii 的选手的初始分数。 第三行是2 \times N2×N 个正整数w_1 , w_2 , …, w_{2N}w
1
​	 ,w
2
​	 ,…,w
2N
​	 ，每两个数之间用一个空格隔开，其中 w_iw
i
​	  表示编号为ii 的选手的实力值。

输出格式：
一个整数，即RR 轮比赛结束后，排名第 QQ 的选手的编号。

输入输出样例
输入样例#1：
2 4 2
7 6 6 7
10 5 20 15
输出样例#1：
1


*/