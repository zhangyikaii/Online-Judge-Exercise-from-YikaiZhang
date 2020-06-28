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

int main() {

	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
#define far(i,t,n) for(int i=t;i<n;++i)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int price[20];
const int maxm=1<<15+5;
int vis[maxm];
int dp[maxm];//dp[i]表示买的书的状态为i时最多优惠的钱数
int cnt[maxm];//cnt[i]表示买书状态为i时买的书的本书，即i中1的个数

int main()
{
	int n,m;
	cin>>n>>m;
	int sum=0;
	far(i,1,n+1)
		scanf("%d",&price[i]),sum+=price[i];
	sort(price+1,price+n+1,greater<int>());
	far(i,0,m)
	{
		int state=0;
		int k;
		scanf("%d",&k);
		while(k--)
		{
			int x;
			scanf("%d",&x);
			state |= 1<<(x-1);
		}
		vis[state]=1;
	}
	int es=1<<n;
	far(i,1,es)
		cnt[i]=cnt[i&(i-1)]+1;//减掉最右边1后的状态
	far(i,1,es)
	{
		if(vis[i])
			dp[i]=max(dp[i],price[cnt[i]]);//买最贵的前cnt[i]本书，优惠第cnt[i]本
		for(int j=i;j>0;j=i&(j-1))
		{
			int x=i^j;//x为j关于i的补集
			if(vis[x])//若补集的优惠方案存在，则可以通过先到达状态j再由x到达i
				dp[i]=max(dp[i],dp[j]+price[cnt[i]]);
		}
		for(int j=0;j<n;++j)
			dp[i|(1<<j)]=max(dp[i|(1<<j)],dp[i]);
	}
	int ans=sum-dp[es-1];
	cout<<ans<<"\n";
}

*/


/*
#include<cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int f[1<<15],c[20],m,n;
int g[1<<15],sz[1<<15];
int main()
{
	cin>>n>>m;
	for(int x=1;x<=n;x++)
	{
		cin>>c[x];
	}
	sort(c+1,c+1+n);
	for(int x=1;x<=m;x++)
	{
		int s=0,k,zhi;
		cin>>k;
		for(int y=1;y<=k;y++)
		{
			cin>>zhi;
			s|=(1<<zhi-1);
		}
		g[s]=1;
	}
	for(int x=1;x<(1<<n);x++)
	{
		sz[x]=sz[(x-1)&x]+1;
	}
	for(int x=0;x<(1<<n);x++)
	{
		int s=((1<<n)-1)^x;
		for(int y=s;y;y=(y-1)&s)
		{
		if(g[y])
		{
			f[x|y]=max(f[x|y],f[x]+c[sz[x]+1]);
			}
		}
	}
	int tot=0;
	for(int x=1;x<=n;x++)
	{
		tot+=c[x];
	}
	cout<<tot-f[(1<<n)-1]<<endl;
	return 0;
}

*/

/*
链接：https://ac.nowcoder.com/acm/contest/946/B
来源：牛客网

题目描述
筱玛是一个热爱阅读的好筱玛，他最喜欢的事情就是去书店买书啦！
一天，他来到一家有nn本书的书店，筱玛十分快乐，决定把这家店里所有的书全部买下来。
正巧今天店里在搞促销活动，包含若干个促销方案。每个促销方案是由指定的若干本书构成的集合，如果购买了该方案中所有的书，那么其中最便宜的一本书将免费。但是，每本书只能用于一个促销方案。
作为店里的VIP，筱玛会得到nn个价格标签。筱玛可以给每本书挑选一个价格标签，使得每个价格标签和每本书一一对应。
筱玛想要知道，在合理利用所有促销方案的情况下，买下所有书最小要多少钱。

输入描述:
第一行两个数n,mn,m，分别表示书的本数和促销方案的种数。
第二行nn个整数，表示每个价格标签上的标注的价格。
接下来mm行，每行第一个数kk表示该促销方案包含书的数量。接下来kk个数，表示书的编号。
输出描述:
输出一行一个数，表示答案。
示例1
输入
复制
4 2
2 3 2 4
2 2 3
2 2 4
输出
复制
8

*/