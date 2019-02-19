#include<cstdio>
#include<iostream>
using namespace std;

int min(int a, int b) {
	return a > b ? b : a;
}

int f[200002], d[200002], n, minn, preFather;  // f 保存祖先节点，d 保存到其祖先节点的路径长。 

// d的初始值是到自己父亲的长度吧
// 那么想找在一开始到祖先的长度，那就是自己的d（从自己到父亲）加上父亲的d（从父亲到祖先）
int Find(int x) {
	if (f[x] != x) {						  // 查找时沿途更新祖先节点和路径长。										 
		int preFather = f[x];				  // 记录父节点（会在递归中被更新）。 
		f[x] = Find(f[x]);					  // 更新祖先节点。 往上接一层 
		d[x] += d[preFather];				  // 更新路径长（原来连在父节点上）。 这一步很关键!!!
	}

	return f[x];
}
void check(int a, int b) {
	int x = Find(a), y = Find(b);					// 查找祖先节点。 
	// 若不相连，则连接两点，更新父节点和路径长。 
	if (x != y) { 
		f[x] = y; 
		d[a] = d[b] + 1;
	}
	else 
		minn = min(minn, d[a] + d[b] + 1);			// 若已连接，则更新最小环长度。 
	return;
}
int main()
{
	int i, t;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) f[i] = i;			// 祖先节点初始化为自己，路径长为0。 
	minn = 0xfffffff;
	for (i = 1; i <= n; i++) {
		scanf("%d", &t);
		check(i, t);							// 检查当前两点是否已有边相连接。 
	}

	printf("%d", minn);

	return 0;
}