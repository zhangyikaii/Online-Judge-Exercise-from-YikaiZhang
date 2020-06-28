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
#include<bits/stdc++.h>

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



// 注意数学化简, 1 ~ 6 行, 4 ~ 6 列的子矩阵和其实就是 之前未乘的那些数 (a_1 + ... + a_6) * (b_4 + ... + b_6);

int arr[100010], brr[100010], dp[100010];
int main() {
	int n, m, res;
	in(n);
	in(m);
	for (int i = 1; i <= n; ++i) {
		in(arr[i]);
	}
	for (int i = 1; i <= m; ++i) {
		in(brr[i]);
	}

	// 怎么找 最大连续子序列? dp!
	// 如果前面的连续子序列都为负了, 那还不如重新开始, 就是从当前那个直接开始.
	dp[1] = arr[1];
	for (int i = 2; i <= n; ++i) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}

	res = dp[n];
	dp[1] = brr[1];
	for (int i = 2; i <= m; ++i) {
		dp[i] = max(dp[i - 1] + brr[i], brr[i]);
	}

	res *= dp[m];

	printf("%d\n", res);


	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read() {
	ll x=0,f=1; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())
		if(ch=='-')f=-f;
	for(;ch>='0'&&ch<='9';ch=getchar())
		x=x*10+ch-'0';
	return x*f;
}
inline void chkmin( int &a,int b ) { if(a>b) a=b; }
inline void chkmax( int &a,int b ) { if(a<b) a=b; }
#define _ read()
#define ln endl
const int N=1e6+5;
ll f[N],a[N],b[N],ans,tmp1,tmp2,tmp3,tmp4;
int n,m;
inline ll solve( ll a[],int n ) {
	ll tmp=-2e18;
	for( int i=1;i<=n;i++ )
		f[i]=max(a[i],f[i-1]+a[i]);
	for( int i=1;i<=n;i++ ) tmp=max(tmp,f[i]);
	return tmp;
}
int main() {
	n=_; m=_; ans=-2e18;
	for( int i=1;i<=n;i++ ) 
		a[i]=_;
	tmp1=solve(a,n);

	for( int i=1;i<=m;i++ ) b[i]=_; 
	tmp2=solve(b,m);

	// 对比这个答案, 自己的思路是对的, 但是就是一点细节没有注意, 因为矩阵按照我们的思路剥开来之后, 负数乘负数也可能变到很大.
	// 注意注意, 全部取负之后, 算的是最大连续子序列和的最大的 负!

	for( int i=1;i<=n;i++ ) a[i]=-a[i];
	tmp3=-solve(a,n);

	for( int i=1;i<=m;i++ ) b[i]=-b[i];
	tmp4=-solve(b,m);

	// 妙啊
	ans=max(tmp1*tmp2,ans);
	ans=max(tmp1*tmp4,ans);
	ans=max(tmp2*tmp3,ans);
	ans=max(tmp4*tmp3,ans);

	cout<<ans<<ln;
}
*/

/*

链接：https://ac.nowcoder.com/acm/contest/916/D
来源：牛客网

题目描述
出题人想造一个矩阵为难你。但是造一个n \times mn×m的矩阵是很累的，所以他钦定了两个序列A,B，规定C_{i,j}=A_i\times B_jC
i,j
​
 =A
i
​
 ×B
j
​
 。
现在你需要求出这个矩阵的最大子矩阵的和（即该子矩阵的权值和是所有子矩阵里面最大的）。
输入描述:
第一行两个数n，m。表示矩阵的规模为n \times mn×m。
第二行n个数表示A_iA
i
​

第三行m个数表示B_iB
i
​

输出描述:
一个数ANS代表该矩阵的最大子矩阵的和。
示例1
输入
复制
4 4
1 2 3 4
1 2 -3 4
输出
复制
40


*/