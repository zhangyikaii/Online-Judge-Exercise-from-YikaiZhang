#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>


using namespace std;

// 不可运行.
int main() {
	int n;
	scanf("%d ", &n); // 读入数据个数，注意%d 后面的空格，它吞掉匹配参数后面的任何空字符
	int *arr = (int *)malloc(sizeof(int)* n); // 创建动态数组
	for (int i = 0; i < n && scanf("%d ", arr + i) > 0; i++); // 读入n 个数，这里 i < n 正好读到 n 个数据也不会引起越界

	for (int i = 0; i < n && cin >> arr[i]; i++); // C++ 使用cin 读入数据



	int a;
	vector<int> input;
	while (cin >> a)
		input.push_back(a);

	return 0;
}