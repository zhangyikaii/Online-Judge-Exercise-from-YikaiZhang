#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
using namespace std;

const int maxn = 100000 + 5;

// 如何找环, 判断进入环???
// 这个解法很特殊, 遇到这种出度为1 的题目才比较好用
int n;
int nxt[maxn];
int color[maxn];	// 颜色: 此节点第一次被访问时，这条访问他的路径是由那个节点发出的（起点）。
int sucdfn[maxn];	// 入环时间戳: 这条路径什么时候会进入环中，同样是为之后服务的一个属性, 入环时间戳只要记录为那个交点的时间戳即可
int dfn[maxn];		// 时间戳: 此节点第一次被访问时，他到发出这条路径的起点的距离（发出节点的 dfn = 0，第二个被访问的节点的 dfn = 1，第三个 dfn = 2 ......）
int minc[maxn];		// 环的大小: 每条路径最终都会进入环中，或者起点本身就在环中，我们记录下这个环的大小为之后服务

void Init()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) 
		cin >> nxt[i];
	memset(color, 0, sizeof(color));
	memset(dfn, 0, sizeof(dfn));
	memset(minc, 0, sizeof(minc));
}

void Solve() {
	for (int cow = 1; cow <= n; ++cow) {
		for (int i = cow, cnt = 0;; i = nxt[i], ++cnt) {
			// 如果没有访问过这个结点 标记为此奶牛经过的
			if (!color[i]) {
				color[i] = cow;
				dfn[i] = cnt;
			}
			// dfn 是上一次经过这个结点的时间, 所以 cnt - dfn[i] 就是环的大小
			else if (color[i] == cow) {
				minc[cow] = cnt - dfn[i];
				sucdfn[cow] = dfn[i];
				cout << cnt << endl;
				break;
			}
			// 进入了上一头牛进过的地方( 不一定是环 ), 这里很关键!!!
			// 如果走到了之前走过的节点，那么新的路径必然进入之前路径的环中，直接把这个环的大小要过来就行了。入环时间戳则分两种情况：
			// i.如果这个节点不在环中，“原路径的入环时间戳 - 原路径中此节点的时间戳 + 新路径当前时间”　即为新路径的入环时间戳;
			// ii.而如果这个节点在环中，直接就是新路径当前时间。
			// iii.判断方法则是 “原路径的入环时间戳 - 原路径中此节点的时间戳” 是否大于 0，综合起来就是：“max(原路径的入环时间戳 - 原路径中此节点的时间戳, 0) + 新路径当前时间”
			else {
				minc[cow] = minc[color[i]];
				sucdfn[cow] = cnt + max(sucdfn[color[i]] - dfn[i], 0);
				cout << sucdfn[cow] + minc[cow] << endl;
				break;
			}
		}
	}
}

int main()
{
	Init();
	Solve();
	return 0;
}

//// 超时了 呜呜呜
//
//#define in(x) x=read()
//
//struct Edge {
//	int next;	// 边
//	int to;		// 点
//	Edge() : next(0), to(0) { }
//};
//
//inline int read()
//{
//	int X = 0, w = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X*w;
//}
//
//int n, head[100010], cnt = 0, a[100010];
//Edge edge[200010];
//void add(int a, int b) {
//	edge[++cnt].next = head[a];
//	head[a] = cnt;
//
//	edge[cnt].to = b;
//}
//
//int main() {
//	// freopen("testdata (1).in", "r", stdin);
//	in(n);
//	for (int i = 1; i <= n; ++i) {
//		in(a[i]);
//		add(i, a[i]);
//	}
//
//	for (int i = 1; i <= n; ++i) {
//		int curPoint = i, ans = 0;
//		int *m = new int[100010];
//		for (int i = 0; i <= 100000; ++i)
//			m[i] = 0;
//		do {
//			m[curPoint] = 1;
//			curPoint = edge[head[curPoint]].to;
//			++ans;
//		} while (m[curPoint] == 0);
//		if (i != n)
//			printf("%d\n", ans);
//		else
//			printf("%d", ans);
//		delete[]m;
//	}
//
//	return 0;
//}

/*
每年，在威斯康星州，奶牛们都会穿上衣服，收集农夫约翰在N(1<=N<=100，000)个牛棚隔间中留下的糖果，以此来庆祝美国秋天的万圣节。

由于牛棚不太大，FJ通过指定奶牛必须遵循的穿越路线来确保奶牛的乐趣。为了实现这个让奶牛在牛棚里来回穿梭的方案，FJ在第i号隔间上张贴了一个“下一个隔间”Next_i(1<=Next_i<=N)，告诉奶牛要去的下一个隔间；这样，为了收集它们的糖果，奶牛就会在牛棚里来回穿梭了。

FJ命令奶牛i应该从i号隔间开始收集糖果。如果一只奶牛回到某一个她已经去过的隔间，她就会停止收集糖果。

在被迫停止收集糖果之前，计算一下每头奶牛要前往的隔间数（包含起点）。

输入格式
第1行 整数n。

第2行到n+1行 每行包含一个整数 next_i 。

输出格式
n行，第i行包含一个整数，表示第i只奶牛要前往的隔间数。

样例解释
有4个隔间

隔间1要求牛到隔间1

隔间2要求牛到隔间3

隔间3要求牛到隔间2

隔间4要求牛到隔间3

牛1，从1号隔间出发，总共访问1个隔间；

牛2，从2号隔间出发，然后到三号隔间，然后到2号隔间，终止，总共访问2个隔间；

牛3，从3号隔间出发，然后到2号隔间，然后到3号隔间，终止，总共访问2个隔间；

牛4，从4号隔间出发，然后到3号隔间，然后到2号隔间，然后到3号隔间，终止，总共访问3个隔间。

输入输出样例
输入样例#1：
4
1
3
2
3
输出样例#1：
1
2
2
3

*/

