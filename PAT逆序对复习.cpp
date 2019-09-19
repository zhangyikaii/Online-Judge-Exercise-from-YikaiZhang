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

// 碰到一道逆序对的裸题.

// luogu 归并求还是最稳的呀:

#include<cstdio>
#define ll long long 
using namespace std;
const int maxn = 5e5 + 5;
//下面就是 归并排序求逆序对 的过程==
int a[maxn], tmp[maxn], n;
ll ans = 0;//ans作为全局变量，记录逆序对的数量； 
void msort(int s, int t) {
	if (s == t) 
		return;
	int mid = s + t >> 1;
	
	msort(s, mid); 
	msort(mid + 1, t);//→→→→→→→递归的体现
	
	int i = s, j = mid + 1, k = s;

	// i, j 是两个指针, 把数组分成两半的两个指针.
	// 下面是两部分归并过程.
	while (i <= mid && j <= t) {
		if (a[i] <= a[j]) 
			tmp[k++] = a[i++];//先赋值再+1 
		else {
			tmp[k++] = a[j++];
			// 最关键的就是下面这一句.
			// ans += (ll)mid - i + 1
			// ans += (ll)mid - i + 1;
			ans += (ll)mid - i + 1;//可以理解为上面的数学归纳吧qaq；
		}
	}
	while (i <= mid) {
		tmp[k] = a[i];
		k++, i++;
	}
	while (j <= t) {
		tmp[k] = a[j];
		k++, j++;
	}

	for (int i = s; i <= t; i++)
		a[i] = tmp[i];//复制回a数组中 
}


inline int read() {//快读
	char ch = getchar();
	int x = 0, f = 1;
	while (ch<'0' || ch>'9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
	return x * f;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) a[i] = read();
	msort(1, n);//从1到n将a数组排序;
	printf("%lld\n", ans);
	return 0;
}

// 记住最关键的那一句 ans += (ll)mid - i + 1;

int main() {
	


	return 0;
}

/*




*/