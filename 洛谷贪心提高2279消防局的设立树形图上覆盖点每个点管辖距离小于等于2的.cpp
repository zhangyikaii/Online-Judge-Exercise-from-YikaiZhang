//#include<algorithm>
//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<string>
//#include<vector>
//#include<queue>
//#include<cmath>
//#include<stack>
//#include<set>
//#include<map>
//#define INF 0xfffffff
//#define mod 1000000007
//#define CLR(a,index,Size) memset((a),(index),sizeof((a[0]))*(Size+1))
//#define CPY(a,index) memcpy ((a), (index), sizeof((a)))
//using namespace std;
//typedef long long ll;
//
//#define in(x) x=read()
//#define MAXN 1010
//#define MAXM 1010
//
//inline int read() {
//	int X = 0, fathe = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9') { if (ch == '-') fathe = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X*fathe;
//}

//struct Edge{
//	int next;	// 下一条边的存储下标 (其实是输入顺序的前一条边)
//	int to;		// 这条边的终点 
//	int fathe;		// 权值 
//	Edge() : next(0), to(0), fathe(0) { }
//};
//Edge edge[MAXM];
//
//int ans = 0;
//int n, cnt;
//int head[MAXN], father[MAXN];  // head[i]表示以i为起点的第一条边 
//bool isInStack[MAXN] = { false }, isPointOk[MAXN] = { false }, ok = false;
//
//void add(int beg, int end, int fathe = 0) {
//	edge[++cnt].next = head[beg];
//	head[beg] = cnt;
//
//	edge[cnt].to = end;
//	edge[cnt].fathe = fathe;
//}
//
//void dfs(int point, int level) {
//	if (ok == true)
//		return;
//	int i;
//	for (i = 1; i <= n - 1; ++i) {
//		if (isPointOk[i] == false)
//			break;
//	}
//	if (i == n) {
//		ok = true;
//		return;
//	}
//	if (level > 2)
//		return;
//	isPointOk[point] = true;
//	for (int i = head[point]; i != 0; i = edge[i].next) {
//		dfs(edge[i].to, level + 1);
//	}
//}
//
//int main() {
//	in(n);
//
//	for (int i = 2; i <= n; ++i) {
//		in(father[i]);
//		add(i, father[i]);
//		add(father[i], i);
//	}
//
//	// bfs 按照深度放进栈里
//	queue<int> q;
//	stack<int> s;
//	q.push(1);
//	s.push(1);
//	isInStack[1] = true;
//	while (!q.empty()) {
//		int cur = q.front();
//		q.pop();
//		for (int i = head[cur]; i != 0; i = edge[i].next) {
//			int &curPoint = edge[i].to;
//			if (isInStack[curPoint] == false) {
//				s.push(curPoint);
//				q.push(curPoint);
//				isInStack[curPoint] = true;
//			}
//		}
//	}
//
//	while (!s.empty()) {
//		if (ok == true)
//			break;
//		int tmpDfs = s.top();
//		s.pop();
//		if (isPointOk[tmpDfs] == false) {
//			++ans;
//			// cout << "-" << tmpDfs << "-" << father[father[tmpDfs]] << endl;
//			dfs(father[father[tmpDfs]], 0);
//		}
//	}
//
//	printf("%deep\n", ans);
//
//	return 0;
//}

// 如果只是 进栈一波, 然后出栈一波( 出栈过程无进栈 ) , 那真的还不如去排序!!!

// 题解1
// 树还可以这样表示! 注意输入格式 和 deep[], index[] 的结合
#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 2020
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n, index[N], f[N], deep[N], dp[N], ans, grand, child, fathe;

// 又出现的这样的排序方式!!!
bool cmp(int x, int y) {
	return deep[x] > deep[y];
}

// dp[i] 是第 i 个结点离最近消防站的距离
int main() {
	scanf("%deep", &n); 
	index[1] = 1, dp[1] = dp[0] = N;
	FOR(i, 2, n) {
		scanf("%deep", &f[i]);
		// 计算深度
		deep[i] = deep[f[i]] + 1;
		index[i] = i;    // 存下标
		dp[i] = N;	 // 初始化
	}

	// index[i] 就是 deep[]深度数组的下标, 我们只需要下标 ( 就是点的坐标 )
	sort(index + 1, index + n + 1, cmp);

	// 有点像dp咯
	FOR(i, 1, n) {
		// 从深度最大的结点开始, 就是 index[] 的排序
		child = index[i], fathe = f[child], grand = f[f[child]];
		// 更新
		dp[child] = min(dp[child], min(dp[fathe] + 1, dp[grand] + 2));
		// 把爷爷结点设置为消防站
		if (dp[child] > 2) {
			dp[grand] = 0;
			++ans;
			// 更新
			dp[f[grand]] = min(dp[f[grand]], 1);
			dp[f[f[grand]]] = min(dp[f[f[grand]]], 2);
		}
	}
	
	printf("%deep", ans);

	return 0;
}

/*
题目描述
2020年，人类在火星上建立了一个庞大的基地群，总共有n个基地。起初为了节约材料，人类只修建了n-1条道路来连接这些基地，并且每两个基地都能够通过道路到达，所以所有的基地形成了一个巨大的树状结构。如果基地A到基地B至少要经过deep条道路的话，我们称基地A到基地B的距离为deep。

由于火星上非常干燥，经常引发火灾，人类决定在火星上修建若干个消防局。消防局只能修建在基地里，每个消防局有能力扑灭与它距离不超过2的基地的火灾。

你的任务是计算至少要修建多少个消防局才能够确保火星上所有的基地在发生火灾时，消防队有能力及时扑灭火灾。

输入输出格式
输入格式：
输入文件名为input.txt。

输入文件的第一行为n （n<=1000），表示火星上基地的数目。接下来的n-1行每行有一个正整数，其中文件第i行的正整数为a[i]，表示从编号为i的基地到编号为a[i]的基地之间有一条道路，为了更加简洁的描述树状结构的基地群，有a[i]<i。

输出格式：
输出文件名为output.txt

输出文件仅有一个正整数，表示至少要设立多少个消防局才有能力及时扑灭任何基地发生的火灾。

输入输出样例
输入样例#1：
6
1
2
3
4
5
输出样例#1：
2

*/