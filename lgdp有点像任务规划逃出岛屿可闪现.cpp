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

// 思路: 看成离散的秒, 运动过程其实就是每秒选择 17m/s 的 或者 60m/s 的.
int tr = 0;
int m, s, t;
int dp[300010] = { 0 };

int main() {
	in(m);
	in(s);
	in(t);
	// 注意走路的时候也可回蓝.

	// 答案的方法: 闪现的耗蓝要和跑步一同计算十分麻烦, 于是把它们分开算：
	// 先处理全部使用一种策略的, 比如闪现的
	// 在这全部使用一种策略的dp基础上, 再dp一遍看看在哪些节点使用17m/s的更快.
	// 局部快就是全局快

	// dp[i]表示时刻i能走多远

	for (int i = 1; i <= t; ++i) {
		if (m >= 10) {
			m -= 10;
			dp[i] = dp[i - 1] + 60;
		}
		else {
			m += 4;
			dp[i] = dp[i - 1];
		}
	}

	for (int i = 1; i <= t; ++i) {
		dp[i] = max(dp[i], dp[i - 1] + 17);
		if (dp[i] >= s) {
			printf("Yes\n%d\n", i);
			return 0;
		}
	}

	printf("No\n%d\n", dp[t]);

	return 0;
}

/*

#include <cstdio>
#include <algorithm>
using namespace std;
int dp[300001];
int main(){
	int m,s,t;
	scanf("%d%d%d",&m,&s,&t);
	for(int i=1;i<=t;i++){//处理闪烁法术
		if(m>=10)dp[i]=dp[i-1]+60,m-=10;//如果能用，就用
		else dp[i]=dp[i-1],m+=4;//否则休息
	}
	for(int i=1;i<=t;i++){dp[i]=max(dp[i],dp[i-1]+17);//处理跑步，dp[i]为使用法术和跑步的最大值（最优）
	if(dp[i]>=s){printf("Yes\n%d",i);return 0;}//如果超过了距离s，就成功了，输出yes
	}printf("No\n%d",dp[t]);//没成功，输出no
	return 0;
}
*/

/*


*/