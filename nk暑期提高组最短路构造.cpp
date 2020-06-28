#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<map>
#define INF 0xfffffff

#define CLR(a,b,Size) memset((a),(b),sizeof((a[0]))*(Size+1))
#define CPY(a,b) memcpy ((a), (b), sizeof((a)))
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

int arr[50010], remain[50010] = { 0 };

struct Data {
	int from, to, weight;
	Data() : from(0), to(0), weight(0) { }
	Data(int f, int t, int w) : from(f), to(t), weight(w) { }
};

vector<Data> res;
Data curMax;

int main() {
	int n, s;
	in(n);
	in(s);
	for (int i = 1; i <= n; ++i) {
		in(arr[i]);
		remain[i] = arr[i];
		if (i != 1 && arr[i] <= s) {
			if (arr[i] > curMax.weight) {
				curMax = Data(1, i, arr[i]);
			}
			res.push_back(Data(1, i, arr[i]));
			remain[i] = 0;
		}
	}

	bool isOk = false;
	do {
		isOk = false;
		for (int i = 1; i <= n; ++i) {
			if (remain[i] != 0)
				remain[i] = arr[i] - curMax.weight;
		}

		for (int i = 1; i <= n; ++i) {
			if (remain[i] != 0 && remain[i] <= s) {
				isOk = true;
				res.push_back(Data(curMax.to, i, remain[i]));
				curMax = Data(1, i, arr[i]);
				remain[i] = 0;
			}
		}
	} while (isOk != false);

	for (int i = 1; i <= n; ++i) {
		if (remain[i] != 0) {
			printf("-1\n");
			return 0;
		}
	}

	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); ++i) {
		printf("%d %d %d\n", res[i].from, res[i].to, res[i].weight);
	}
	
	
	return 0;
}

/*

链接：https://ac.nowcoder.com/acm/contest/920/A
来源：牛客网

题目描述
大样例下载，压缩包内包含三题大样例
您有一个长度为 \mathit nn 的数组 a_ia
i
​
 。请您构造出一张 \mathit mm 条边的有向图满足 \text 11 号点到 \mathit ii 号点的最短路长度为数组中的第 \mathit ii 个数 a_ia
i
​
 ，且要求 \mathit mm 不超过 10^510
5
  且每条边的长度不超过一个给定的值 \mathit ss。
输入描述:
输入文件将会遵循以下格式：

  n \quad sns
  a_1 \quad a_2 \quad \cdots \quad a_na
1
​
 a
2
​
 ⋯a
n
​


第一行两个整数 \mathit n, sn,s (3 \le n \le 5 \times 10^4, 1 \le s \le 10^6)(3≤n≤5×10
4
 ,1≤s≤10
6
 )，表示点数和限制的边权最大值。
第二行 \mathit nn 个非负整数，第 \mathit ii 个数为 a_ia
i
​
  (0 \le a_i \le 10^9, a_1 = 0)(0≤a
i
​
 ≤10
9
 ,a
1
​
 =0)，表示点 \text 11 到点 \mathit ii 的最短距离。
输出描述:
若可以构造这样一张图，第一行输出一个数 \mathit mm，表示这张图的边数。
接下来 \mathit mm 行，每行三个正整数 \mathit u, v, wu,v,w，表示有一条从 \mathit uu 到 \mathit vv 权值为 \mathit ww 的边。

若不能构造这样一张图，只需输出 -1−1。

### 输出要求

本题可能有多种答案，我们会使用 Special Judge 来检验您的答案是否正确。

若本数据点无解并且您判断对了，会得到该测试点的满分。
若该测试点有解但您输出了 -1−1，将会判作答案错误。

如果您判断对了该测试点有解，则 Special Judge 会根据您的输出运行 Dijkstra 算法，求出 11 号点所有点的最短路。之后将得到的最短路数组与输入文件给出的数组进行比对，只要有一个同位元素不同，或者在您给出的图中有一个点不可达，则会被判作答案错误。若得到的数组一模一样，可以得到该测试点的满分。

为了防止 Special Judge 出现问题，对于输出格式，我们给出以下规定：

- 若无解，则只需输出一行一个数 -1−1。
- 否则，您输出的数必须都是正整数，且：
  - 对于输出数据中的 \mathit mm，应当满足 1 \le m \le 10^51≤m≤10
5
 。
  - 对于输出数据中所有的 \mathit ww，应当满足 1 \le w \le s1≤w≤s。
  - 对于输出数据中所有的 \mathit u, vu,v，应当满足 1 \le u, v \le n1≤u,v≤n。
  - 输出数据第一行必须是一个数 \mathit mm，之后必须刚好 \mathit mm 行，每行三个正整数 \mathit uu, \mathit vv, \mathit ww。

若您的输出不满足输出格式，可能会导致 Special Judge 出现错误判定。
示例1
输入
复制
4 5
0 4 2 9
输出
复制
4
1 2 4
1 3 2
3 2 5
2 4 5
示例2
输入
复制
4 4
0 4 2 9
输出
复制
-1

*/


// 下面是答案:
/*

#include<bits/stdc++.h>
#define N 50005
using namespace std;
int n,s,a[N],p[N];
bool cmp(int x,int y) {
	if(a[x]==a[y])return x<y;
	return a[x]<a[y];
}

// 注意: u[] 存起始顶点, v[]末尾, w[]权值.
int u[N],v[N],w[N],cnt;
void Add(int x,int y,int z){
	cnt++;
	u[cnt]=x;
	v[cnt]=y;
	w[cnt]=z;
}
int main() {
//  freopen("A.in","r",stdin);
//  freopen("A.out","w",stdout);

	scanf("%d%d",&n,&s);
	for(int i=1; i<=n; i++)scanf("%d",&a[i]);
	for(int i=1; i<=n; i++)p[i]=i;
	sort(p+1,p+n+1,cmp);
	for(int i=2,j=1; i<=n; i++) {
		while(j<i&&a[p[i]]!=a[p[j+1]])j++;
		if(a[p[i]]-a[p[j]]==0||a[p[i]]-a[p[j]]>s) {
			puts("-1");
			return 0;
		}
		Add(p[j],p[i],a[p[i]]-a[p[j]]);
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)printf("%d %d %d\n",u[i],v[i],w[i]);
	return 0;
}


*/