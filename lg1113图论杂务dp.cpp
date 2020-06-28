//// 下面是答案:
//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//int n, l, t, ans[10005], maxans;
//int main() {
//	// 注意这个ans[] 是怎么被改的, 这就是转移.
//	scanf("%d", &n);
//	for (int i = 1; i <= n; ++i){
//		scanf("%d", &i);
//		scanf("%d", &l);
//		int tmp = 0;
//		while (scanf("%d", &t) && t)
//			tmp = max(ans[t], tmp);			// tmp此时是最大的前驱, 最晚结束的前驱的结束时间!!!
//		ans[i] = tmp + l;					// "而且任务k的前驱节点一定小于k，所以读入时顺便从它的前驱里挑一个最大的转移即可", tmp + l 是当前的dp的结束时间.
//		maxans = max(ans[i], maxans);
//	}
//	printf("%d\n", maxans);
//	return 0;
//}

#include<cstdio>
#include<memory.h>
#include<queue>
#define MAXN 10005
#define MAXM 10000005
using namespace std;

int n, id = 0;
int Y[MAXM];
int nextt[MAXM];
int head[MAXN];
int END[MAXN];//初始记录杂物开始时间，更新后记录杂物结束时间 
int T[MAXN];

// 注意这个存入度的数组!

int idu[MAXN];//拓扑存 入度  
queue<int> Q;

void ADD(int a, int b)//链式前向星 
{
	Y[++id] = b;
	nextt[id] = head[a];
	head[a] = id;
	idu[b]++;
}

void SCAN() {
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i++) {
		int a, c = 1;
		scanf("%d", &a);
		scanf("%d", &T[a]);
		scanf("%d", &c);
		while (c) {
			ADD(c, a);
			scanf("%d", &c);
		}
	}
}

//入队列前不断更新节点开始时间
//
//出队列时更新节点结束时间
//
//排序后选数组最大值输出


//拓扑排序 模板, 背一下!!!
int TP() {
	memset(END, 0, sizeof(END));
	int ans = 0;
	int i;

	// 刚开始把 度 为 0 的弄进去.
	for (i = 1; i <= n; i++) {
		if (!idu[i]) {
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		END[x] += T[x];						// 变成结束时间.
		ans = ans > END[x] ? ans : END[x];	// 更新答案.
		int i;
		// Y[i] 是邻接点, 链式前向星不要忘记了!
		for (i = head[x]; i; i = nextt[i]) {
			idu[Y[i]]--;
			END[Y[i]] = END[Y[i]] > END[x] ? END[Y[i]] : END[x];
			// 这里就是入队之前不断更新节点开始时间最大值!
			// 被更新节点开始时间为 原被更新节点开始时间与前驱节点结束时间 的较大值 
			if (!idu[Y[i]]) {
				Q.push(Y[i]);
			}
		}
	}
	return ans;
}

int main()
{
	SCAN();
	printf("%d", TP());
	return 0;
}