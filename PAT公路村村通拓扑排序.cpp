#include<stdio.h>
#define num 100
#include<queue>
using namespace std;

//节点个数，边数
int N, M;
//bool isin[num];
//入度，出度，每个节点需要花费时间，节点之间关系矩阵
int indgree[num];
int outdegree[num];
int cost[num];
int info[num][num];
//初始化，
void init() {
	int i, j;
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			info[i][j] = -1;
		}
		indgree[i] = 0;
		outdegree[i] = 0;
		cost[i] = 0;
	}
}
//求最大值
int max(int x, int y) {
	return x > y ? x : y;
}
//主方法
int solve() {
	int n = 0;
	int i, front;
	queue<int> Q;
	for (i = 0; i < N; i++) {
		if (indgree[i] == 0) {
			//入度为0的节点入队。
			Q.push(i);
			//让其不再是0，否则会影响后面的入队
			indgree[i]--;
		}
	}
	//Q不空则循环，
	while (!Q.empty()) {
		front = Q.front();
		Q.pop();
		n++;//记录现在有多少节点出队
		//出队的都是可以抹掉的节点
		for (i = 0; i < N; i++) {
			if (info[front][i] >= 0) {//如果要抹掉的节点与某个节点有一条有向边，
				//该边入度减一，计算该边的cost
				indgree[i]--;

				// topo还是原来的拓扑, 只是在其中插入了计算.
				cost[i] = max(cost[i], cost[front] + info[front][i]);
			}
		}
		//重新寻找需要入队的
		for (i = 0; i < N; i++) {
			if (indgree[i] == 0) {
				Q.push(i);
				indgree[i]--;
			}
		}
	}
	//如果删掉N个边说明没有环，注意cost[front]不是最终结果
	if (n == N)
		return cost[front];
	//否则
	return -1;
}

int main() {
	int file = 0;
	FILE* fp;
	init();
	int i, temp1, temp2, temp3;
	if (file) {

		fp = fopen("1.txt", "r");
		if (fp == NULL) {
			puts("ERROR!");
		}
		fscanf(fp, "%d%d", &N, &M);
		for (i = 0; i < M; i++) {
			fscanf(fp, "%d%d%d", &temp1, &temp2, &temp3);
			info[temp1][temp2] = temp3;
			indgree[temp2]++;
			outdegree[temp1]++;
			//printf("%d,%d,%d\n",temp1,temp2,info[temp1][temp2]);
		}
	}
	else {
		scanf("%d%d", &N, &M);
		for (i = 0; i < M; i++) {
			scanf("%d%d%d", &temp1, &temp2, &temp3);
			info[temp1][temp2] = temp3;
			indgree[temp2]++;
			outdegree[temp1]++;
		}
	}
	int res;
	res = solve();
	if (res == -1) {
		puts("Impossible");
	}
	else {
		for (i = 0; i < N; i++) {
			if (outdegree[i] == 0)
				//可能有多个终点，需要找到耗时最多的那个
				res = max(cost[i], res);
		}
		printf("%d\n", res);
	}

	return 0;
}
