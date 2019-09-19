#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
using namespace std;

// 十分不理解为什么第二次写的dfs会超, 没有更优化的了..
#define in(x) x=read()

#define MAXN 500

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

#include <stdio.h>
int n, sum;
int visited[13] = { 0 }; // 防止重复
int ans[13];	// 放置答案
int pc[12];		// 构造所有 i C n-1
int dfs(int, int, int); // 写函数原型是好习惯！
int main(void){
	int i;
	scanf("%d%d", &n, &sum);
	//下面开始构造杨辉三角(即组合数表)
	pc[0] = pc[n - 1] = 1; // 杨辉三角性质,两边都是1
	if (n>1)
	for (i = 1; i * 2 < n; i++)
		pc[i] = pc[n - 1 - i] = (n - i) * pc[i - 1] / i; //利用杨辉三角对称性和组合数公式计算
	if (dfs(0, -1, 0)) //-1仅起占位符作用
	for (i = 1; i <= n; i++)
		printf("%d ", ans[i]); //输出答案
	return 0;
}
int dfs(int i, int num, int v){ //参数说明:i表示正在搜索第i个数(从1开始),num表示第i个数是num,v表示前i个数的“和”为v
	//返回值说明:返回0表示不行(不可能)，返回1表示找到了可行解
	int j; //循环变量
	if (v > sum) // 已经超了!
		return 0; // 不可能
	if (i == n) { // 枚举到了最后一个,判断一下是否是可行解
		if (v == sum){
			ans[i] = num; //放置解
			return 1;
		}
		else
			return 0;
	}
	visited[num] = 1;
	for (j = 1; j <= n; j++){
		if (!visited[j] && dfs(i + 1, j, v + pc[i] * j)){//v+pc[i]*j表示前(i+1)个数的“和”
			//已经找到了可行的解
			ans[i] = num;
			return 1;
		}
	}
	visited[num] = 0;//一定记得复位
	return 0;//执行到这里一定是没有找到解
}

// 
//// 看了题解自己用杨辉三角做
// 但是还是超时了两个点
//
//int c[MAXN + 10][MAXN + 10], n, sum;
//bool flag = false;
//int cur[MAXN + 10] = { 0 };
//bool used[MAXN + 10] = { false };
//
//
//// 组合数模板一定要背啊!!!
//void Init() {
//	c[0][0] = 1;
//	c[1][0] = 1;
//	c[1][1] = 1;
//	c[0][1] = 1;
//	// 用高中那个递推式
//	for (int i = 2; i < MAXN; ++i) {
//		c[i][0] = 1;
//		for (int k = 1; k <= i; ++k) {
//			c[i][k] = (c[i - 1][k] + c[i - 1][k - 1]);
//		}
//	}
//}
//
//
//// 记住这样子的全排列到 11 个速度就很慢了
//void dfs(int level) {
//	if (flag == true) {
//		return;
//	}
//	if (level == n + 1) {
//		/*for (int i = 1; i <= n; ++i) {
//			printf("%d ", cur[i]);
//		}
//		printf("\n");*/
//		// 判断会不会等于sum
//		int ans = 0;
//		for (int i = 1; i <= n; ++i) {
//			ans += c[n - 1][i - 1] * cur[i];
//		}
//		// printf("%d\n", ans);
//		if (ans == sum) {
//			printf("%d", cur[1]);
//			for (int i = 2; i <= n; ++i) {
//				printf(" %d", cur[i]);
//			}
//			printf("\n");
//			flag = true;
//		}
//		return;						// dfs不敢错, 这里一定要记得return
//	}
//
//	// 看清题目, 这里讲的就是 1 ~ n 的排列!!!
//	for (int i = 1; i <= n; ++i) {
//		if (used[i] == false) {
//			used[i] = true;
//			cur[level] = i;
//			dfs(level + 1);
//			used[i] = false;
//		}
//	}
//}
//
//int main() {
//	Init();
//	in(n);
//	in(sum);
//
//	dfs(1);
//
//	return 0;
//}
//


// dfs超时, 而且关键错误是每一行的字典序最小不一定是最上面的字典序最小.
//int n, sum;
//bool flag = false;
//
//int ans[2000][2000] = { 0 };
//
//void dfs(int level, int bef[]) {
//	if (flag == true)
//		return;
//	if (level == n) {
//		for (int i = 1; i <= level; ++i) {
//			printf("%d ", bef[i]);
//		}
//		flag = true;
//		return;
//	}
//	for (int i = 1; i < bef[1]; ++i) {
//		int tmpBef[15];
//		bool tmpFlag = false, used[12500] = { false };
//		tmpBef[1] = i;
//		used[i] = true;
//		// 每一层的字典序最小, 不一定是最上层的字典序最小!!!!!!! 所以这里错了!
//		for (int k = 2; k <= level + 1; ++k) {
//			tmpBef[k] = bef[k - 1] - tmpBef[k - 1];
//			if (tmpBef[k] <= 0 || used[tmpBef[k]] == true) {
//				tmpFlag = true;
//				break;
//			}
//			else
//				used[tmpBef[k]] = true;
//		}
//		if (tmpFlag != true)
//			dfs(level + 1, tmpBef);
//	}
//}
//
//int main() {
//	in(n);
//	in(sum);
//
//	int bef[15] = { 0, sum };
//	dfs(1, bef);
//
//	return 0;
//}

/*
有这么一个游戏：

写出一个11至NN的排列a_i，然后每次将相邻两个数相加，构成新的序列，再对新序列进行这样的操作，显然每次构成的序列都比上一次的序列长度少11，直到只剩下一个数字位置。下面是一个例子：

3,1,2,4

4,3,6

7,9

16

最后得到1616这样一个数字。

现在想要倒着玩这样一个游戏，如果知道NN，知道最后得到的数字的大小sumsum，请你求出最初序列a_ia
i
​	 ，为11至NN的一个排列。若答案有多种可能，则输出字典序最小的那一个。

[color=red]管理员注：本题描述有误，这里字典序指的是1,2,3,4,5,6,7,8,9,10,11,12而不是1,10,11,12,2,3,4,5,6,7,8,9

输入输出格式
输入格式：
两个正整数n,sumn,sum。

输出格式：
输出包括11行，为字典序最小的那个答案。

当无解的时候，请什么也不输出。（好奇葩啊）

*/