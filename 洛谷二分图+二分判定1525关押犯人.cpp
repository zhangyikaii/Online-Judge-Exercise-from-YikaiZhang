#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7;
inline int read() {
	int p = 0, f = 1; char c = getchar();
	while (c<'0' || c>'9'){ if (c == '-')f = -1; c = getchar(); }
	while (c >= '0'&&c <= '9'){ p = p * 10 + c - '0'; c = getchar(); }
	return f*p;
}
struct Edge
{
	int from, to, w;
}edge[200019];

int n, m, L, R, cnt, head[200019];

// 这种存两次的像有向边的方法! from 连接的是边, to连接的是点
void AddEdge(int x, int y, int W) {
	cnt++;
	edge[cnt].from = head[x];
	head[x] = cnt;				// 存着这个点连接的边的编号, 下一次另一条边(含有这个点的)进来可以连接上这条边
	edge[cnt].to = y;
	edge[cnt].w = W;
}

// 判断以mid为仇恨值是否能形成二分图 
bool Judge(int mid) {
	queue <int> q;
	int color[20009] = { 0 };
	// 以下是染色法判断二分图 
	for (int i = 1; i <= n; i++) {
		if (!color[i]) {
			q.push(i);
			color[i] = 1;
			while (!q.empty()) {
				int x = q.front();
				q.pop();

				// 遍历 x 的所有邻接点, edge[i].to就是了, 是通过遍历边来的(用i), 看染色情况
				for (int i = head[x]; i != 0; i = edge[i].from) {
					if (edge[i].w >= mid) {
						// 没染过色 
						if (!color[edge[i].to]) {
							// 入队
							q.push(edge[i].to);
							// 染成相反的颜色
							if (color[x] == 1)
								color[edge[i].to] = 2;
							else
								color[edge[i].to] = 1;
						}
						else if (color[edge[i].to] == color[x])
							return false;
						//如果出现矛盾直接返回(不为二分图) 
					}
				}
			}
		}
	}
	return true;// 正常结束，证明是二分图
}
int main() {
	n = read(), m = read();
	// 加边（无向图）
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read(), w = read();
		R = max(R, w);//二分右端点 
		AddEdge(x, y, w);
		AddEdge(y, x, w);
	}
	R++;// 别忘了加1（右端点R），左端点L开始为0
	while (R > L + 1)// 开始二分判断二分图(答案单调) 
	{
		int mid = (L + R) >> 1;
		if (Judge(mid))
			// 染色法判断二分图如果可行就缩小范围 
			R = mid;
		else 
			L = mid;
	}
	printf("%d", L);//最后左端点即为答案
	return 0;
}
/*
题目描述</h2>
$S $城现有两座监狱，一共关押着$N $名罪犯，编号分别为$1-N$。他们之间的关系自然也极不和谐。很多罪犯之间甚至积怨已久，如果客观条件具备则随时可能爆发冲突。我们用“怨气值”（一个正整数值）来表示某两名罪犯之间的仇恨程度，怨气值越大，则这两名罪犯之间的积怨越多。如果两名怨气值为$c$ 的罪犯被关押在同一监狱，他们俩之间会发生摩擦，并造成影响力为$c $的冲突事件。
每年年末，警察局会将本年内监狱中的所有冲突事件按影响力从大到小排成一个列表，然后上报到S 城Z 市长那里。公务繁忙的Z 市长只会去看列表中的第一个事件的影响力，如果影响很坏，他就会考虑撤换警察局长。
在详细考察了$N$ 名罪犯间的矛盾关系后，警察局长觉得压力巨大。他准备将罪犯们在两座监狱内重新分配，以求产生的冲突事件影响力都较小，从而保住自己的乌纱帽。假设只要处于同一监狱内的某两个罪犯间有仇恨，那么他们一定会在每年的某个时候发生摩擦。
那么，应如何分配罪犯，才能使Z 市长看到的那个冲突事件的影响力最小？这个最小值是多少？
输入输出格式
输入格式：
每行中两个数之间用一个空格隔开。第一行为两个正整数$N,M$，分别表示罪犯的数目以及存在仇恨的罪犯对数。接下来的$M$行每行为三个正整数$a_j,b_j,c_j$，表示$a_j$ 号和$b_j $号罪犯之间存在仇恨，其怨气值为$c_j$。数据保证$1&lt;aj≤bj≤N ,0 &lt; cj≤ 1,000,000,000$，且每对罪犯组合只出现一次。


题面大意:（人性翻译）
给你m对矛盾关系,每对关系分别涉及到x，y两人,矛盾值为w

请你判断分配x和y到两个集合中，能否避免冲突

如能避免请输出0，如果冲突不可避免，请输出最小的矛盾值

以上是本人自己的“翻译”理解，接下来请看算法分析

输入输出样例
输入样例#1：
4 6
1 4 2534
2 3 3512
1 2 28351
1 3 6618
2 4 1805
3 4 12884

输出样例#1：
3512
*/