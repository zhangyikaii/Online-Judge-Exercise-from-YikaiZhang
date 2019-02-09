#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
/*****/
#define For(i, n, m) for(int i = n;i < m; ++i)

inline int read() {
	char s;
	int k = 0, base = 1;
	while ((s = getchar()) != '-' && s != EOF&&!(s >= '0'&&s <= '9'));
	if (s == EOF)exit(0);
	if (s == '-')base = -1, s = getchar();
	while (s >= '0'&&s <= '9')
	{
		k = k * 10 + (s - '0');
		s = getchar();
	}
	return k * base;
}

#define MAX 40000

int n, arr[40010];		// arr[i] 存有看出去的第 i 层正方形每边能看到的个数


// 耶耶耶这是爽爽地AC的一道题
int main() {
	// 预处理, 计算arr[]
	for (int i = 3; i <= MAX; ++i) {
		arr[i] = i - 2;
	}
	for (int i = 3; i <= MAX; ++i) {
		int tmp = i - 1;
		for (int k = i + tmp; k <= MAX; k += tmp)
			arr[k] -= arr[i];			// 当前行有arr[i]个, 就挡住了后面的 每 +(i - 1) 行的arr[i]个
	}

	n = read();

	if (n == 2)
		printf("3\n");
	else if (n < 2)
		printf("0\n");
	else {
		int sum = 0;
		for (int i = 3; i <= n; ++i)
			sum += arr[i];
		printf("%d\n", 2 * sum + 3);
	}


	return 0;
}

/*
作为体育委员，C君负责这次运动会仪仗队的训练。仪仗队是由学生组成的N * N的方阵，为了保证队伍在行进中整齐划一，C君会跟在仪仗队的左后方，根据其视线所及的学生人数来判断队伍是否整齐(如下图)。  现在，C君希望你告诉他队伍整齐时能看到的学生人数。

输入:
4

输出:
9
*/