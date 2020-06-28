#include<iostream>
#include<cstdio>
#include <algorithm>
#include <string.h>
#define maxn 1000
using namespace std;
int n, m, f[maxn][maxn], head[maxn], cnt;

// 熟悉的链式前向星
/*
不妨设f[now][j][k]表示以now为根节点的子树, 考虑前j个节点选k门课的方案数, 前j个结点选k门课的方案数.

因为1号节点是根节点,显然递推起点f[now][1][1]=val[now]

这样很容易得到状态转移方程

注意这里是 son, 就是选了
f[now][j][k]=max(f[now][j-1][k],f[son][所有节点数][l]+f[now][j-1][k-l]);
然后我们观察等式两边的特点, 哪些是我们已知的?

在对now求解前

我们至少已经处理完了前面的子树, 至少已经处理完了前面的子树. 

所以f[son][所有节点数][l]是可以直接用的

然后 在处理第j个节点前

前j-1个节点是我们已经处理过的

所以f[now][j-1][k]和f[now][j-1][k-l]也不用考虑循环顺序问题

但是问题来了, 这样开三维数组不会炸空间吗

也许本题不会

但是我们可以很显然的发现

空间是可以优化的

只要稍稍改变循环顺序即可

我要用到j-1的内容

都是满足l<k的

所以倒着循环k

这样就可以使我们在一个数组中当前值和上面我们用到的值完全不影响

就酱~
*/
struct edge {
	int to, pre;
}e[maxn];
inline int in() {
	char a = getchar();
	while (a<'0' || a>'9')
	{
		a = getchar();
	}
	int t = 0;
	while (a >= '0'&&a <= '9')
	{
		t = (t << 1) + (t << 3) + a - '0';
		a = getchar();
	}
	return t;
}
void add(int from, int to) {
	e[++cnt].pre = head[from];
	e[cnt].to = to;
	head[from] = cnt;
}
void dp(int now) {
	//    f[now][0]=0;
	// 遍历周围的
	for (int i = head[now]; i; i = e[i].pre) {
		int go = e[i].to;
		//dfs
		dp(go);

		// 注意这里的dp顺序
		for (int j = m + 1; j >= 1; j--) {
			for (int k = 0; k<j; k++) {
				// go 是儿子结点
				f[now][j] = max(f[now][j], f[go][k] + f[now][j - k]);
			}
		}
	}
}

int main() {
	
	n = in(), m = in();
	for (int i = 1; i <= n; i++) {
		int fa = in();
		f[i][1] = in();
		add(fa, i);
	}
	dp(0);
	printf("%d\n", f[0][m + 1]);
	return 0;
}