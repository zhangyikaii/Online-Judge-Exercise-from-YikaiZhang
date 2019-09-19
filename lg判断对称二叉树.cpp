//#include <bits/stdc++.h>
//using namespace std;
//
//struct Node {
//	int l, r;
//};
//
//int val[100010];
//
//Node arr[100010];
//
//// 怎么传递给上层结点?
//int check(int left, int right) {
//	if (left == -1 && right == -1)
//		return 1;
//
//	if (val[left] == val[right])
//}
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; ++i) {
//		cin >> val[i];
//	}
//	for (int i = 1; i <= n; ++i) {
//		cin >> arr[i].l >> arr[i].r;
//	}
//
//
//	return 0;
//}

#include <bits/stdc++.h>
#define ll long long

const int maxn = 2000000;

using namespace std;

ll a[maxn], l[maxn], r[maxn];

ll ans, N;
/*
a数组存节点数值，l[i]表示编号为i的节点的左孩子的编号，
r[i]表示编号为i的节点的右孩子的编号
*/
bool f;  //全局变量f判断是否为对称二叉子树


// 这个其实就是单独写一个计算树节点个数的递归函数.
inline ll cnt(ll x) //计算以x为根节点的对称二叉子树的节点数  *递归
{
	ll sum = 0;
	if (l[x] != -1) sum += cnt(l[x]);
	if (r[x] != -1) sum += cnt(r[x]);
	return sum + 1;  //别忘了根节点
}


// 设置全局标志位判断是不是对称.
void work(ll xx, ll yy)  //判断对称二叉子树的函数   *递归
{
	if (xx == -1 && yy == -1)
		return;  //如果已经到底了，结束
	if (xx == -1 || yy == -1 || a[xx] != a[yy]) { f = 0; return; } //不对称
	work(l[xx], r[yy]);
	work(r[xx], l[yy]); //这里代码后插图另作解释qwq
}

int main()
{
	cin >> N;//读入n

	for (int i = 1; i <= N; ++i)  //读入每个节点的值
		scanf("%lld", &a[i]);

	for (int i = 1; i <= N; ++i)   //读入每个节点的左右孩子节点编号
		scanf("%lld%lld", &l[i], &r[i]);

	ans = 1;      //至少有一个对称（一个节点）

	for (int i = 1; i <= N; ++i)  //枚举对称二叉子树的根节点
		if (l[i] != -1 && r[i] != -1 && a[l[i]] == a[r[i]])  //这里可以过滤掉很多不必要的枚举
		{
			f = true;     //先默认为是对称二叉子树

			work(l[i], r[i]);      //开始递归判断

			if (f == true) 
				ans = max(ans, cnt(i));  //如果是对称二叉子树就可以计算节点取最大值了
		}

	printf("%lld\n", ans);

	return 0;
}