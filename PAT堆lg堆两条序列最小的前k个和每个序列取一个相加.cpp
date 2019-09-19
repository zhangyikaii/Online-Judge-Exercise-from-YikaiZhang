#include <bits/stdc++.h>
using namespace std;
#include<cstdio>  
#include<queue>   
using namespace std;
int a[100005] = {}, b[100005] = {}, to[100005] = {}, i, n;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >q;
int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]); to[i] = 1;
		// to[] 就是当前是第index个序列的第几个. 记录所有序列的push到了哪一个.
		q.push(pair<int, int>(a[1] + b[i], i));
	}
	while (n--)
	{
		printf("%d ", q.top().first);
		i = q.top().second; q.pop();
		q.push(pair<int, int>(a[++to[i]] + b[i], i));
	}
	return 0;
}


