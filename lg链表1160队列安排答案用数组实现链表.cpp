#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

#define in(x) x=read()
#define MAX 100010

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n, list[100050][2];				// list[i][0] 表示第 i 个人左边, list[i][1] 表示右边

// AC 了 !!!!!!!
// 用数组实现双向链表, 用于id不是很大( maxId 数组存得下的时候 ), 很好用!!!!!!!
int main() {
	for (int i = 0; i < 100050; ++i) {
		list[i][0] = list[i][1] = 0;
	}
	in(n);
	int head = 1;
	for (int i = 2; i <= n; ++i) {
		int insed = read();				// i 插到 insed
		int flag = read();

		// 右边或者左边没有人的情况, NULL都不用考虑, 因为赋值会解决一切
		if (flag == 0) {
			list[list[insed][0]][1] = i;			// insed原来左边人的右边 = i
			list[i][0] = list[insed][0];			// i 的左边 = insed原来左边人
			list[i][1] = insed;						// i 的右边 = insed
			list[insed][0] = i;						// insed 的左边 = i
			// 特殊情况, 插到head 的左边
			if (head == insed)
				head = i;
		}
		else if (flag == 1) {
			list[list[insed][1]][0] = i;
			list[i][1] = list[insed][1];
			list[i][0] = insed;
			list[insed][1] = i;
		}
	}

	int del = read();
	for (int i = 1; i <= del; ++i) {
		int id = read();
		// 尾
		if (list[id][1] == 0 && list[id][0] != 0) {
			list[list[id][0]][1] = 0;
			list[id][0] = 0;
		}
		else if (id == head) {
			head = list[id][1];
			list[id][1] = 0;
		}
		else if (list[id][1] != 0 && list[id][0] != 0) {
			list[list[id][0]][1] = list[id][1];
			list[list[id][1]][0] = list[id][0];
			list[id][0] = 0;
			list[id][1] = 0;
		}
	}

	for (int i = head; i != 0; i = list[i][1])
		printf("%d ", i);

	return 0;
}

/*

题目描述
一个学校里老师要将班上NN个同学排成一列，同学被编号为1\sim N1∼N，他采取如下的方法：

先将11号同学安排进队列，这时队列中只有他一个人；

2-N2−N号同学依次入列，编号为i的同学入列方式为：老师指定编号为i的同学站在编号为1\sim (i -1)1∼(i−1)中某位同学（即之前已经入列的同学）的左边或右边；

从队列中去掉M(M<N)M(M<N)个同学，其他同学位置顺序不变。

在所有同学按照上述方法队列排列完毕后，老师想知道从左到右所有同学的编号。

输入输出格式
输入格式：
第11行为一个正整数NN，表示了有NN个同学。

第2-N2−N行，第ii行包含两个整数k,pk,p，其中kk为小于ii的正整数，pp为00或者11。若pp为00，则表示将ii号同学插入到kk号同学的左边，pp为11则表示插入到右边。

第N+1N+1行为一个正整数MM，表示去掉的同学数目。

接下来MM行，每行一个正整数xx，表示将xx号同学从队列中移去，如果xx号同学已经不在队列中则忽略这一条指令。

输出格式：
11行，包含最多NN个空格隔开的正整数，表示了队列从左到右所有同学的编号，行末换行且无空格。

输入输出样例
输入样例#1：
4
1 0
2 1
1 0
2
3
3
输出样例#1：
2 4 1


*/


// 以下是答案, 用数组实现双向链表, 很不错, 我来模仿一个单向链表

////  用数组实现链表??? 好像很不错
//#include<cstdio>
//#include<cstring>
//int a[100010][3], n, m;
////  a[i][2]表示学号为i的同学右边同学的学号
////  a[i][3]表示学号为i的同学左边同学的学号
//int main()
//{
//	scanf("%d", &n);
//	int head = 1;
//	memset(a, 0, sizeof(a));
//	a[1][1] = 1;
//	for (int i = 2; i <= n; i++)
//	{
//		int x, y; scanf("%d %d", &x, &y);
//
//		a[i][1] = i;
//		// 插入左边
//		if (y == 0) {
//			a[a[x][3]][2] = i; 
//			a[i][2] = x;
//			a[i][3] = a[x][3]; 
//			a[x][3] = i;
//			if (x == head) 
//				head = i;
//			// 比较麻烦，要改链表
//		}
//		else
//			// 插入右边
//		{
//			a[i][2] = a[x][2]; 
//			a[a[x][2]][3] = i;
//			a[x][2] = i;
//			a[i][3] = x;
//		}
//	}
//	scanf("%d", &m);
//	for (int i = 1; i <= m; i++)
//	{
//		int x; scanf("%d", &x);
//		// 该同学还在 
//		if (a[x][1] != 0) {
//			a[x][1] = 0;
//			// 踢掉……(好可怜) 
//			a[a[x][3]][2] = a[x][2];
//			a[a[x][2]][3] = a[x][3];
//			n--;
//			if (x == head) 
//				head = a[x][3];
//		}
//	}
//	int i = 1, x = head;
//	while (i <= n)
//	{
//		printf("%d ", a[x][1]);
//		x = a[x][2]; i++;
//	}
//	return 0;
//}


// -------------------------------------------------------------------------------------------

//  链表做了超时了.......
// #include <iostream> 
// #include <cstdio> 
// #include <algorithm> 
// #include <cstring>
// #include <cmath>
// #include <cstdlib>
// #include <string>
// using namespace std;
// 
// #define in(x) x=read()
// #define MAX 100010
// 
// struct list {
// 	int data;
// 	bool isOut;
// 	list *next;
// 	list() : data(0), next(NULL), isOut(false) { }
// 	list(int a) : data(a), next(NULL), isOut(false) { }
// };
// 
// inline int read() {
// 	int X = 0, w = 1;
// 	char ch = getchar();
// 	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
// 	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
// 	return X*w;
// }
// 
// int MyMin(int a, int b) {
// 	return a > b ? b : a;
// }
// 
// void Swap(int arr[], int i, int head) {
// 	if (i == head)
// 		return;
// 
// 	arr[i] = arr[i] ^ arr[head];
// 	arr[head] = arr[i] ^ arr[head];
// 	arr[i] = arr[i] ^ arr[head];
// }
// 
// int n;
// 
// int main() {
// 	in(n);
// 	list *head = new list(1);
// 	for (int k = 2; k <= n; ++k) {
// 		int i = read(), way = read();
// 		list *pre = NULL, *pFind = NULL;
// 		if (way == 0) {
// 			//  插入在左边 ( 前面 ), 有特殊情况在第一个的
// 			for (pFind = head; pFind != NULL && pFind->data != i; pFind = pFind->next) {
// 				pre = pFind;
// 			}
// 			if (pre != NULL) {
// 				pre->next = new list(k);
// 				pre->next->next = pFind;
// 			}
// 			else {
// 				list *tmp = new list(k);
// 				tmp->next = head;
// 				head = tmp;
// 			}
// 		}
// 
// 		else {
// 			//  插入在后面, 有特殊情况 在最后一个的
// 			for (pFind = head; pFind != NULL && pFind->data != i; pFind = pFind->next);
// 			if (pFind->next == NULL) {
// 				pFind->next = new list(k);
// 			}
// 			else {
// 				list *tmp = pFind->next;
// 				pFind->next = new list(k);
// 				pFind->next->next = tmp;
// 			}
// 		}
// 
// 		/*for (list *tmp = head; tmp != NULL; tmp = tmp->next) {
// 			cout << tmp->data << endl;
// 		}
// 
// 		cout << "=========\n";*/
// 	}
// 	in(n);
// 	for (int i = 1; i <= n; ++i) {
// 		int del = read();
// 		for (list *tmp = head; tmp != NULL; tmp = tmp->next) {
// 			if (tmp->data == del)
// 				tmp->isOut = true;
// 		}
// 	}
// 
// 	bool isFir = true;
// 	for (list *tmp = head; tmp != NULL; tmp = tmp->next) {
// 		if (tmp->isOut == false) {
// 			if (isFir == true)
// 				isFir = false;
// 			else
// 				printf(" ");
// 			printf("%d", tmp->data);
// 		}
// 	}
// 
// 	printf("\n");
// 
// 	return 0;
// }

/*


*/