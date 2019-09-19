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


/*
int arr[10010] = { 0 }, brr[10010] = { 0 };

int sum[10010], mul[2000010];
int sumn = 0, muln = 0;
int main() {
	int n, m;
	int maxn, maxm;

	in(n);
	For(i, 0, n) {
		int ind, num; 
		in(num);
		in(ind);
		ind += 1000;

		maxn = max(ind, maxn);
		arr[ind] = num;
	}

	in(m);
	For(i, 0, m) {
		int ind, num;
		in(num);
		in(ind);
		ind += 1000;

		maxm = max(ind, maxm);
		brr[ind] = num;
	}

	++maxn;
	++maxm;
	For(i, 0, maxn) {
		For(k, 0, maxm) {
			mul[i + k] += arr[i] * brr[k];
		}
	}

	For(i, 0, max(maxn, maxm)) {
		sum[i] = arr[i] + brr[i];
		if (sum[i] != 0)
			++sumn;
	}

	bool isFir = true;
	for (int i = maxn + maxm; i >= 0; --i) {
		if (mul[i] != 0) {
			if (isFir == true) {
				printf("%d %d", mul[i], i - 1000);
				isFir = false;
			}
			else {
				printf(" %d %d", mul[i], i - 1000);
			}
		}
	}

	printf("\n");
	isFir = true;
	for (int i = max(maxn, maxm); i >= 0; --i) {
		if (sum[i] != 0) {
			if (isFir == true) {
				printf("%d %d", sum[i], i - 1000);
				isFir = false;
			}
			else {
				printf(" %d %d", sum[i], i - 1000);
			}
		}
	}
	printf("\n");
	
	return 0;
}

*/


// 写的什么垃圾... 认真一点啊...

struct Data {
	int ind, num;
	Data() { }
	Data(int indd, int numm) : ind(indd), num(numm) { }
};

vector<Data> arr, brr;
vector<Data> sumr;
map<int, int> mapp;
int main() {
	int n, m;

	in(n);
	For(i, 0, n) {
		Data tmp;
		in(tmp.num);
		in(tmp.ind);
		
		arr.push_back(tmp);
	}

	in(m);
	For(i, 0, m) {
		Data tmp;
		in(tmp.num);
		in(tmp.ind);

		brr.push_back(tmp);
	}

	// sum
	int ia = 0, ib = 0;
	while (ia < arr.size() && ib < brr.size()) {
		if (arr[ia].ind == brr[ib].ind) {
			if (arr[ia].num + brr[ib].num != 0)
				sumr.push_back(Data(arr[ia].ind, arr[ia].num + brr[ib].num));
			++ia, ++ib;
		}
		else if (arr[ia].ind > brr[ib].ind) {
			sumr.push_back(arr[ia]);
			++ia;
		}
		else {
			sumr.push_back(brr[ib]);
			++ib;
		}
	}
	while (ia < arr.size()) {
		sumr.push_back(arr[ia]);
		++ia;
	}

	while (ib < brr.size()) {
		sumr.push_back(brr[ib]);
		++ib;
	}

	// mul
	For(i, 0, arr.size()) {
		For(k, 0, brr.size()) {
			mapp[arr[i].ind + brr[k].ind] += arr[i].num * brr[k].num;
		}
	}

	bool isFir = true;

	if (mapp.empty()) {
		printf("0 0\n");
	}
	else {
		for (int i = arr[0].ind + brr[0].ind; i >= arr[arr.size() - 1].ind + brr[brr.size() - 1].ind; --i) {
			if (mapp[i] != 0) {
				if (isFir == true) {
					isFir = false;
					printf("%d %d", mapp[i], i);
				}
				else
					printf(" %d %d", mapp[i], i);
			}
		}

		printf("\n");
	}

	if (sumr.size() == 0)
		printf("0 0\n");
	else {
		isFir = true;
		For(i, 0, sumr.size()) {
			if (isFir == true) {
				isFir = false;
				printf("%d %d", sumr[i].num, sumr[i].ind);
			}
			else
				printf(" %d %d", sumr[i].num, sumr[i].ind);
		}
		printf("\n");
	}

	



	return 0;
}
// 两个坑点:
// 零多项式输出 0 0;
// 相加时合并同类项可能为0;
/*
题目描述:

设计函数分别求两个一元多项式的乘积与和。

输入格式:
输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式:
输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

输入样例:
4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
输出样例:
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0

*/