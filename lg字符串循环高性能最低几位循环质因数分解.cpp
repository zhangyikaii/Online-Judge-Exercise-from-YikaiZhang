#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

#define in(x) x=read()
#define MAX 100010

bool isPrime[MAX + 10] = { 0 };
int prime[MAX + 10] = { 0 };
int cnt = 1;


struct Data {
	int x, y;
	Data() : x(0), y(0) { }
};

// isPrime 下标是某个数 = true表示是素数 false表示不是
// prime 按顺序存素数

void init() {
	// memset(isPrime, 1, sizeof(isPrime));			// 初始化认为所有数都为素数
	for (int i = 0; i < 10020; ++i)
		isPrime[i] = true;
	isPrime[0] = isPrime[1] = 0;					// 0和1不是素数
	for (int i = 2; i <= MAX; i++) {
		if (isPrime[i])
			prime[cnt++] = i;						// 保存素数i
		for (long long j = 1; j < cnt && prime[j] * i < MAX; j++) {
			isPrime[prime[j] * i] = 0;				// 筛掉小于等于i的素数和i的积构成的合数 !
		}
	}
}

//void initCopy() {
//	// 初始化都是素数, 挖掉 0 和 1.
//	for (int i = 2; i < MAX; ++i)
//		isPrime[i] = 1;
//	//开始筛:
//	for (int i = 2; i < MAX; ++i) {
//		// 遇到一个素数.
//		if (isPrime[i] == 1)
//			prime[cnt++] = i;
//		// 是 遍历prime[], i 倍的 prime[](已知的)素数开始筛其他的了.
//		for (int j = 1; j < cnt && prime[j] * i < MAX; ++j) {
//			isPrime[prime[j] * i] = 0;
//		}
//	}
//}


inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
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

int n, m1, m2, arr[50010] = { 0 };
Data input[100];
Data tmp[100];


// 质因数分解, res[0].x 记录有多少个质因数, 这种方法看起来不错
void resolve(Data res[], int a) {
	int iPrime = 1;
	// a 没有分解完 和 已知的素数没有被除完.
	while (a != 1 && iPrime < cnt) {
		int cnt = 0;
		// 来的这个素数使劲除.
		while (a % prime[iPrime] == 0) {
			a /= prime[iPrime];
			++cnt;
		}
		// 记录这个素数. 注意还要记录幂次
		if (cnt != 0) {
			res[++res[0].x].x = prime[iPrime];
			res[res[0].x].y = cnt;
		}
		++iPrime;
	}
}

int main() {
	// freopen("ttt.in", "r", stdin);
	init();
	// 大数相除, 去想质因数分解
	// 大数相除, 去想质因数分解!!!
	in(n);
	in(m1);
	in(m2);
	for (int i = 1; i <= n; ++i) {
		in(arr[i]);
	}

	if (m1 == 1) {
		printf("0\n");
		return 0;
	}
	resolve(input, m1);

	for (int i = 1; i <= input[0].x; ++i) {
		input[i].y *= m2;
	}

	int ans = 0x7ffffff;
	for (int i = 1; i <= n; ++i) {
		tmp[0].x = 0;
		resolve(tmp, arr[i]);

		int curMax = 1;
		bool flag = false;
		// 瓶子
		for (int j = 1; j <= input[0].x; ++j) {
			bool isOk = false;
			// 细胞
			for (int k = 1; k <= tmp[0].x; ++k) {
				if (input[j].x == tmp[k].x) {
					isOk = true;
					int tmpAns = input[j].y / tmp[k].y;
					if (input[j].y % tmp[k].y != 0)
						++tmpAns;

					if (curMax < tmpAns)
						curMax = tmpAns;
				}
			}
			// 在这里卡了好久!!!!! 所以最好第一次写的时候就要想好, 怎么样才是要 -1 的, 很关键! 先理解题意!!!
			// 有一个细胞不可以没有关系, 所有不可以才是输出 -1;
			if (isOk == false) {
				flag = true;
			}
		}

		if (ans > curMax && flag == false)
			ans = curMax;
	}

	if (ans == 0x7ffffff)
		printf("-1\n");
	else
		printf("%d\n", ans);

	return 0;
}

// 24 68 76 32

/*

题目描述
HanksHanks 博士是 BTBT (Bio-TechBio−Tech，生物技术) 领域的知名专家。现在，他正在为一个细胞实验做准备工作：培养细胞样本。

HanksHanks 博士手里现在有 N N种细胞，编号从 1-N1−N，一个第 i i种细胞经过 11 秒钟可以分裂为S_iS
i
​	 个同种细胞（S_iS
i
​	 为正整数）。现在他需要选取某种细胞的一个放进培养皿，让其自由分裂，进行培养。一段时间以后，再把培养皿中的所有细胞平均分入 M M个试管，形成 M M份样本，用于实验。HanksHanks 博士的试管数 M M很大，普通的计算机的基本数据类型无法存储这样大的M M值，但万幸的是，MM 总可以表示为 m_1m
1
​	 的 m_2m
2
​	 次方，即M = m_1^{m_2}M=m
1
m
2
​
​	 ，其中 m_1,m_2m
1
​	 ,m
2
​	 均为基本数据类型可以存储的正整数。

注意，整个实验过程中不允许分割单个细胞，比如某个时刻若培养皿中有 4 4个细胞，

Hanks Hanks博士可以把它们分入 22 个试管，每试管内 22 个，然后开始实验。但如果培养皿中有 55个细胞，博士就无法将它们均分入 22 个试管。此时，博士就只能等待一段时间，让细胞们继续分裂，使得其个数可以均分，或是干脆改换另一种细胞培养。

为了能让实验尽早开始，Hanks Hanks博士在选定一种细胞开始培养后，总是在得到的细胞“刚好可以平均分入 M M个试管”时停止细胞培养并开始实验。现在博士希望知道，选择哪种细胞培养，可以使得实验的开始时间最早。

输入输出格式
输入格式：
第一行,有一个正整数 NN，代表细胞种数。

第二行,有两个正整数 m_1,m_2m
1
​	 ,m
2
​	 ，以一个空格隔开，即表示试管的总数 M = m_1^{m_2}M=m
1
m
2
​
​	 .

第三行有 N 个正整数，第 i 个数 Si表示第 i 种细胞经过 1 秒钟可以分裂成同种细胞的个数。

输出格式：
一个整数，表示从开始培养细胞到实验能够开始所经过的最少时间（单位为秒）。

如果无论HanksHanks博士选择哪种细胞都不能满足要求，则输出整数-1−1。

输入输出样例
输入样例#1：
1
2 1
3
输出样例#1：
-1
输入样例#2：
2
24 1
30 12
输出样例#2：
2


*/