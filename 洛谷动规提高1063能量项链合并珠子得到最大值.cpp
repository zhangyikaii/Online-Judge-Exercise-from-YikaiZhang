// 这题就很像1090合并堆消耗体力最小, 之前是用堆做的贪心, 这次就是线性的变成环形的
// 但是这个合并还有条件!!!
// 有一个环的瞄一眼就感觉是区间dp哇
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

#define in(x) x = read()

inline int read(){
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	if (f) return x;
	return 0 - x;
}

int main() {
	

	return 0;
}

/*
每个珠子有头尾数, 只有头数和尾数是一样的才可以合并, 比如珠子1 是(m, r) 珠子2 是(r, n) 合并获得 m * r * n

输入输出样例
输入样例#1：
4
2 3 5 10
输出样例#1：
710
*/