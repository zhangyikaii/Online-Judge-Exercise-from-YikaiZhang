#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define Fee(i, b, e) for(int i = (b); i <= (e); ++i)

#define INF 0x7fffff

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
const int maxn = 10000 + 10;
int n, m, a[maxn], flagAdd = 0, flagFinish = 0;
bool curNumUsed[maxn];
void dfs(int step) {
	if (flagFinish == 1)
		return;
	// 五个数都放满了
	if (step > n) {
		++flagAdd;
		// 现在到了我们要加上的那个数的全排列的时候，我们就直接地输出，然后标记flagFinish，一直return，结束程序
		if (flagAdd == m + 1) {
			for (int j = 1; j <= n; j++)
				printf("%d ", a[j]);
			printf("\n");
			flagFinish = 1;
		}
		return;
	}
	
	// 请注意: 设定dfs起点需要在递归的for里面.
	for (int i = 1; i <= n; i++) {
		// 当还在外星人给出的排列这个阶段的时候，我们就直指外星人给出的序列中的数 
		// 这一步很关键, 就是相当于把外星人给的那个是作为dfs起点了!
		
		// 请注意: 是设置当前循环的这个值为这个, 递归还是要继续递归的, 压栈还是要继续压栈的.
		if (flagAdd == 0)
			i = a[step];
		if (curNumUsed[i] == 0) {
			curNumUsed[i] = 1;
			a[step] = i;     // 更新了!
			dfs(step + 1);
			curNumUsed[i] = 0;
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	dfs(1);
	return 0;
}

//int tmp[20], used[20], record[20];
//int n, m;
//
//void dfs(int tot, bool &flag) {
//	if (tot == n) {
//		bool isRecord = true;
//		Fee(i, 1, n) {
//			if (tmp[i] != record[i]) {
//				isRecord = false;
//				break;
//			}
//		}
//		if (isRecord == true) {
//			flag = true;
//			return;
//		}
//		Fee(i, 1, n)
//			cout << setw(5) << tmp[i];
//		cout << endl;
//		return;
//	}
//
//	if (flag == false) {
//		used[record[tot + 1]] = 1;
//		tmp[tot + 1] = record[tot + 1];
//		dfs(tot + 1, flag);
//		used[record[tot + 1]] = 0;
//	}
//	Fee(i, 1, n) {
//		if (used[i] == 0) {
//			used[i] = 1;
//			tmp[tot + 1] = i;
//			dfs(tot + 1, flag);
//			used[i] = 0;
//		}
//	}
//}
//int main() {
//	in(n), in(m);
//	Fee(i, 1, n) {
//		in(record[i]);
//	}
//
//	bool flag = false;
//	dfs(0, flag);
//	return 0;
//}