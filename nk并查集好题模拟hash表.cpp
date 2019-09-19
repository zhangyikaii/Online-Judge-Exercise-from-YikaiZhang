#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define in(x) x=read()
#define For(i, a, b) for(int i = a; i < b; ++i)

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

// 下面是答案:
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int fa[1000005];
// 递归找 这是并查集的节奏啊
int find(int x) { 
	return x == fa[x] ? x : fa[x] = find(fa[x]); 
}

int a[1000005];
int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i <= n + 1; ++i)
		fa[i] = i;



	// 记住记住 在过程中每一个并查集, 每一个堆, 都是根节点是空位!
	for (int i = 1; i <= n; ++i) {
		int tmp;
		cin >> tmp;
		int x = find(tmp % n + 1);	// 找到输入的插入位置.

		// 找到最后了.
		if (x == n + 1) {
			x = find(1);
		}

		// 维护, 把下一次这样找下去的, 父亲结点, 改到后面一个.
		// 所以比如x位置, 有冲突的时候就是从x, x + 1, x + 2 开始一个链(并查集), 再次访问x的时候就通过上面的找来找到链状补位之后的空位. 如果找到了n就从1开始.

		// 记住下面这样是改了x的父母.
		// 如果x + 1也被占用, 不影响, 因为每次插入这样处理之后都可以保证多颗树连一个父节点也可以, 反正父节点就是空位, 总是有这个空位.
		fa[x] = find(x + 1);
		a[x] = tmp;
	}
	for (int i = 1; i <= n; ++i)
		cout << a[i] << " "; 
	cout << endl;

	return 0;
}


// 本来想打暴力, 算了绝对超.

/*
int arr[1000010] = { 0 };

int main() {
	int n;
	in(n);

	For(i, 0, n) {
		int ins;
		in(ins);

		ins = ins % n;
		if(arr[ins] == )
	}
	
	return 0;
}

*/

/*



链接：https://ac.nowcoder.com/acm/contest/1080/B
来源：牛客网

题目描述
tokitsukaze有n个数，需要按顺序把他们插入哈希表中，哈希表的位置为0到n-1。
插入的规则是：
刚开始哈希表是空的。
对于一个数x，在哈希表中，如果(x mod n)的位置是空的，就把x放在(x mod n)的位置上。如果不是空的，就从(x mod n)往右开始找到第一个空的位置插入。若一直到n-1都不是空的，就从位置0开始继续往右找第一个空的位置插入。
因为哈希表总共有n个空位，需要插入n个数，所以每个数都能被插入。
现在tokitsukaze想知道把这n个数按顺序插入哈希表后，哈希表中的每个位置分别对应的是哪个数。
输入描述:
第一行包含一个正整数n(1≤n≤10^6)。
第二行包含n个非负整数x(0≤x≤10^9)，这些数按从左到右的顺序依次插入哈希表。
输出描述:
输出一行，n个数，第i个数表示哈希表中位置为i所对应的数。(0≤i≤n-1)
示例1
输入
复制
4
1 2 6 5
输出
复制
5 1 2 6
说明
插入1时，1 mod 4=1，是空的，在位置1插入。
插入2时，2 mod 4=2，是空的，在位置2插入。
插入6时，6 mod 4=2，不是空的，找到下一个空的位置为3，所以在位置3插入。
插入5时，5 mod 4=1，不是空的，找到下一个空的位置为0，所以在位置0插入。
示例2
输入
复制
4
3 0 7 11
输出
复制
0 7 11 3
说明
插入3时，3 mod 4=3，是空的，在位置3插入。
插入0时，0 mod 4=0，是空的，在位置0插入。
插入7时，7 mod 4=3，不是空的，找到下一个空的位置为1，所以在位置1插入。
插入11时，11 mod 4=3，不是空的，找到下一个空的位置为2，所以在位置2插入。





*/