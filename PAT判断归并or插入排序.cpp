#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

#define in(x) x=read()
#define xw x+xway[i]
#define yw y+yway[i]

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

int MyMin(int a, int b) {
	return a > b ? b : a;
}

void Swap(int arr[], int i, int j) {
	if (i == j)
		return;

	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}


// 抄一遍吧..

const int maxn = 5e5 + 10;

int mergeResTmp[maxn] = { 0 }, iResTmp = 0;			// 暂时存放归并结果.
long long ans = 0;
int a[maxn];
void MergeSort(int l, int r) {
	// 终止条件
	if (l >= r)
		return;

	int mid = (l + r) / 2;

	// 先递归!
	MergeSort(l, mid);
	MergeSort(mid + 1, r);

	// 开始归并
	//for (int i = l; i <= r; ++i)
	//	printf("%d ", a[i]);
	//printf("\n");

	int i = l, j = mid + 1;
	iResTmp = l - 1;						// 注意这里是中间那一部分处理!
	while (i <= mid && j <= r) {
		if (a[i] <= a[j]) {
			mergeResTmp[++iResTmp] = a[i++];
		}
		else {
			mergeResTmp[++iResTmp] = a[j++];
			ans += mid - i + 1;				// 注意这里 ans 的处理, 归并第二个的时候, 前面的全部都更小, 都是逆序对
		}
	}

	// 剩余数组弄回去
	while (i <= mid)
		mergeResTmp[++iResTmp] = a[i++];
	while (j <= r)
		mergeResTmp[++iResTmp] = a[j++];

	// 中间那一部分放回去, 所以是从 l 开始到 r.
	for (int t = l; t <= r; ++t)
		a[t] = mergeResTmp[t];
}

int n;

int main() {
	in(n);
	for (int i = 1; i <= n; ++i) {
		in(a[i]);
	}

	MergeSort(1, n);

	printf("%lld\n", ans);


	return 0;
}
//
//
//
//// 以下是答案, 看一遍自己写.
//using namespace std;
//const int maxn = 5e5 + 10;
//int n, a[maxn], r[maxn];
//long long ans = 0;
//void mergesort(int s, int t)
//{
//	int i, j, k, m;
//	if (s == t) return;
//	m = (s + t) / 2; //取中点
//	mergesort(s, m); //递归左区间
//	mergesort(m + 1, t); //递归右区间
//	i = s, j = m + 1, k = s;
//	//二路归并（升序）过程
//	while (i <= m && j <= t) {
//		if (a[i] <= a[j]) {
//			r[k] = a[i]; i++; k++;
//		}
//		else {
//			r[k] = a[j]; j++; k++;
//			ans += m - i + 1;				// 注意这里 ans 的处理
//		}
//	} //将序列中剩余的元素接入r数组
//	while (i <= m) { 
//		r[k] = a[i]; 
//		i++;
//		k++;
//	}
//	while (j <= t) { r[k] = a[j]; j++; k++; }
//	for (int i = s; i <= t; i++) a[i] = r[i]; //数组赋回
//}
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
//	mergesort(1, n); //归并求解逆序对
//	printf("%lld\n", ans); //别忘了long long
//	return 0;
//}
//


/*

题目描述
破解了符文之语，小FF开启了通往地下的道路。当他走到最底层时，发现正前方有一扇巨石门，门上雕刻着一幅古代人进行某种活动的图案。而石门上方用古代文写着“神的殿堂”。小FF猜想里面应该就有王室的遗产了。但现在的问题是如何打开这扇门……

仔细研究后，他发现门上的图案大概是说：古代人认为只有智者才是最容易接近神明的。而最聪明的人往往通过一种仪式选拔出来。仪式大概是指，即将隐退的智者为他的候选人写下一串无序的数字，并让他们进行一种操作，即交换序列中相邻的两个元素。而用最少的交换次数使原序列变成不下降序列的人即是下一任智者。

小FF发现门上同样有着n个数字。于是他认为打开这扇门的秘诀就是找到让这个序列变成不下降序列所需要的最小次数。但小FF不会……只好又找到了你，并答应事成之后与你三七分……

输入输出格式
输入格式：
第一行为一个整数n，表示序列长度

第二行为n个整数，表示序列中每个元素。

输出格式：
一个整数ans，即最少操作次数。

输入输出样例
输入样例#1：
4
2 8 0 3
输出样例#1：
3

*/
