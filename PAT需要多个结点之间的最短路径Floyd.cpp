#include<iostream> 
#define MaxSize 100 //最多顶点数 
#define INF 65535  //int的最大值 
using namespace std;

struct MGraph {
	int n;
	int m;
	int s[MaxSize][MaxSize];
};
MGraph g;


void FindAnimal() {
	//Floyd算法，三重循环 建立任意两点的最短距离矩阵 
	for (int k = 0; k < g.n; k++) {
		for (int i = 0; i < g.n; i++) {
			for (int j = 0; j < g.n; j++) {
				// (i != k) && (j != i) 为何不分别为循环 i 和 j 的条件 ==> 不能，若作为 for 循环条件，一旦不满足，就终止循环了，后面符合条件的也不执行了
				//放在 if 里，符合就执行，不符合就跳过执行下个 

				// 记住是 k: 先中间点, 再 i, j.
				if ((i != k) && (j != i) && (g.s[i][k] + g.s[k][j] < g.s[i][j])) {
					g.s[i][j] = g.s[i][k] + g.s[k][j];
				}
			}
		}
	}

	int animal;
	//从最长距离中找最短距离 
	int MinDist = INF;
	for (int i = 0; i < g.n; i++) {
		//找最长距离 
		int MaxDist = 0;
		for (int j = 0; j < g.n; j++) {
			if ((i != j) && (g.s[i][j] > MaxDist)) { //i!=j去掉主对角线元，因为主对角线元肯定是INF
				MaxDist = g.s[i][j];
				//cout<<"("<<i<<","<<j<<")="<<g.s[i][j]<<" ";			
			}
		}

		if (MaxDist == INF) {//不是一整个连通集，而是多个分的连通集，即：有i无法变出的动物 
			cout << "0" << endl;
			return;//直接退出 
		}
		if (MaxDist < MinDist) {
			MinDist = MaxDist;
			animal = i + 1;//i+1是因为动物下边从1开始 
		}
	}
	cout << animal << " " << MinDist << endl;
}


int main()
{
	//freopen("input.txt","r",stdin);
	int n, m, i, j, v1, v2, weight;
	cin >> n >> m;
	g.n = n;
	g.m = m;
	//1初始化邻接矩阵 
	for (i = 0; i < g.n; i++) {
		for (j = 0; j < g.n; j++) {
			g.s[i][j] = INF;
		}
	}
	//2插入边
	while (g.m--) {
		cin >> v1 >> v2 >> weight;
		--v1; --v2;//动物从1开始，图从0开始
		g.s[v1][v2] = weight;
		g.s[v2][v1] = weight;
	}


	//3.找最长距离中的最短距离对应的点及这个最短距离
	FindAnimal();

	return 0;
}


