#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <sstream>
// 用一下sstream里面的sscanf可以帮助简化代码。

// sscanf(ch + 2, "%llu", &tmp);		// 下面的 1LL 表示是 long long类型的 1.
//从字符串的第二位开始读，把后面的所有数字转换为一个unsigned long long类型变量
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (!isdigit(ch)){ if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)){ x = x * 10 + ch - 48; ch = getchar(); }
	return x*f;
}

long long l, r;

int t;

int main()
{
	/*freopen("testdata.in", "r", stdin);
	freopen("testdata.out", "w", stdout);*/
	cin >> l >> r >> t;
	while (t--)
	{
		char ch[1000005];//输入文件不超过128kb所以开大点……当然不用开这么大了
		cin >> (ch + 1);
		int len = strlen(ch + 1);
		if (ch[1] == '-')//若为负号开头，如果只有一个负号则不合法，如果为-0也不合法
		{
			if (ch[2] == '0' || len == 1)
			{
				puts("1");
				continue;
			}
		}
		if (ch[1] == '0' && len != 1)//如果是00或者类似的格式不合法
		{
			puts("1");
			continue;
		}
		if (ch[1] == '-' && len>20)//如果是一个-很大的数字，那么直接判断不合法即可。
		{
			puts("2");
			continue;
		}
		if (ch[1] != '-' && len>19)//如果是一个正的很大的数字，也可以直接判断不合法
		{
			puts("2");
			continue;
		}
		//上面两个操作是为了确保我们的数字可以在ull之内的范围再进行下述操作，会方便许多。
		unsigned long long tmp = 0;
		long long x = 0;
		if (ch[1] == '-')
		{
			// sscanf(ch + 2, "%llu", &tmp);		// 1LL 表示是 long long类型的 1.
			sscanf(ch + 2, "%llu", &tmp);	//从字符串的第二位开始读，把后面的所有数字转换为一个unsigned long long类型变量tmp后再进行处理。
			if (tmp>(1LL << 63))
			{
				puts("2");
				continue;
			}
			x = -tmp;
		}
		else
		{
			sscanf(ch + 1, "%llu", &tmp);
			if (tmp >= (1LL << 63))
			{
				puts("2");
				continue;
			}
			x = tmp;
		}
		puts(x >= l && x <= r ? "0" : "2");
	}
	return 0;
}
//#include <iostream> 
//#include <cstdio> 
//#include <algorithm> 
//#include <cstring>
//#include <cmath>
//using namespace std;
//
//#define in(x) x=read()
//
//#define MAXN 500
//
//inline long long read() {
//	long long X = 0, w = 1;
//	char ch = getchar();
//	while (ch < '0' || ch > '9') {
//		if (ch == '-')
//			w = -1;
//		ch = getchar();
//	}
//	while (ch >= '0' && ch <= '9')
//		X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//
//	return X*w;
//}
//
//
//
//// 溢出控制真不好搞
//// 是溢出那边的问题吗? wuwuwu
//
//int solve(long long &x) {
//	x = 0;						// 注意啊 初始化啊啊啊
//	long long w = 1;
//	int isFir = 0, digit = 0, ret = -1;
//	char ch = getchar();
//	if ((ch < '0' || ch > '9') && ch == '-') {
//		w = -1;
//		ch = getchar();
//	}
//
//	while (ch >= '0' && ch <= '9') {
//		if (ret == -1) {
//			if (++digit >= 20)
//				ret = 2;
//
//			// -0 不可以
//			if (ch == '0' && isFir == 0 && w == -1)
//				ret = 0;
//
//			// 第一个为0, 还要判断第二个
//			if (ch == '0' && isFir == 0) {
//				isFir = 1;
//			}
//			// 第一个为非0, 可以了
//			else if (ch != '0' && isFir == 0)
//				isFir = 2;
//
//			// 第二个为非0, 可以了
//			else if (ch != '0' && isFir == 1)
//				isFir = 2;
//			// 第二个还是0, 不可以
//			else if (ch == '0' && isFir == 1)
//				ret = 0;
//		}
//
//		// 注意即使判断出来是什么之后也要全部读完
//		x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
//	}
//
//	if (ret == -1)
//		return 1;
//
//	return ret;
//}
//
//long long n, l, r, input;
//
//int main() {
//	in(l);
//	in(r);
//	in(n);
//	while (n--) {
//		int isNum = solve(input);
//		if (isNum == 1 && input <= r && input >= l)
//			printf("0\n");
//		else if (isNum == 2 || (isNum == 1 && !(input <= r && input >= l)))
//			printf("2\n");
//		else if (isNum == 0)
//			printf("1\n");
//		
//		// cout << endl;
//	}
//	
//	
//	return 0;
//}
//
///*
//题目描述
//有些时候需要解决这样一类问题：判断一个数 xx 是否合法。
//
//xx 合法当且仅当其满足如下条件：
//
//xx 格式合法，一个格式合法的整数要么是 00，要么由一个可选的负号，一个 11 到 99 之间的数字，和若干个 00 到 99 之间的数字顺序连接而成。
//xx 在区间 [l,r][l,r] 范围内（即 l \le x \le rl≤x≤r）。
//你需要实现这样一个校验器，对于给定的 l, rl,r，多次判断 xx 是否合法。
//
//输入输出格式
//输入格式：
//第一行三个整数 l,r,Tl,r,T，表示校验器的校验区间为 [l,r][l,r]，以及需要校验的 xx 的个数。
//
//接下来 TT 行，每行一个 xx，表示要校验的数，保证 xx 长度至少为 11 且仅由 '0'~'9' 及 '-' 构成，且 '-' 只会出现在第一个字符。
//
//输出格式：
//输出共 TT 行，每行一个整数，表示每个 xx 的校验结果。
//
//校验结果规定如下：00 表示 xx 合法；11 表示 xx 格式不合法；22 表示 xx 格式合法且不在 [l,r][l,r] 区间内。
//
//输入输出样例
//输入样例#1：
//-3 3 4
//0
//00
//-0
//100000000000000000000
//输出样例#1：
//0
//1
//1
//2
//
//
//*/