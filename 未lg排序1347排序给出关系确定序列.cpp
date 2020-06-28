#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

#define in(x) x=read()

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

int n, m;
int sol[110] = { 0 };
string arr[110];

int main() {
	in(n);
	in(m);
	for (int i = 1; i <= m; ++i) {
		getline(cin, arr[i]);
		int fir = arr[i][0] - 'A', sec = arr[i][2] - 'A';
		if (arr[i][1] == '<') {
			
		}
	}

	return 0;
}


/*

题目描述
一个不同的值的升序排序数列指的是一个从左到右元素依次增大的序列，例如，一个有序的数列A,B,C,D 表示A<B,B<C,C<D。在这道题中，我们将给你一系列形如A<B的关系，并要求你判断是否能够根据这些关系确定这个数列的顺序。

输入输出格式
输入格式：
第一行有两个整数n,m，n表示需要排序的元素数量，2<=n<=26，第1到n个元素将用大写的A,B,C,D....表示。m表示将给出的形如A<B的关系的数量。

接下来有m行，每行有3个字符，分别为一个大写字母，一个<符号，一个大写字母，表示两个元素之间的关系。

输出格式：
若根据前x个关系即可确定这n个元素的顺序yyy..y（如ABC），输出

Sorted sequence determined after xxx relations: yyy...y.

若根据前x个关系即发现存在矛盾（如A<B,B<C,C<A），输出

Inconsistency found after 2 relations.

若根据这m个关系无法确定这n个元素的顺序，输出

Sorted sequence cannot be determined.

（提示：确定n个元素的顺序后即可结束程序，可以不用考虑确定顺序之后出现矛盾的情况）

输入输出样例
输入样例#1：
4 6
A<B
A<C
B<C
C<D
B<D
A<B
输出样例#1：
Sorted sequence determined after 4 relations: ABCD.
输入样例#2：
3 2
A<B
B<A
输出样例#2：
Inconsistency found after 2 relations.
输入样例#3：
26 1
A<Z
输出样例#3：
Sorted sequence cannot be determined.


*/