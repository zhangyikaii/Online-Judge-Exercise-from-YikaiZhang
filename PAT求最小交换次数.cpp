// 注意这里环的概念, 看这里: https://blog.csdn.net/w597013296/article/details/51982225
// 在一窝里面交换, 一窝就是一个等价类, 分成不同的多个等价类.
// 最终目的是通过 0 和其他元素的交换, 把他们分成n个互不相同的等价类.

// 有些交换合并等价类, 有些是断开等价类.


#include <iostream>
using namespace std;

int search(int* p, int num)
{
	static int first = 1;
	for (int i = first; i < num; i++)
		if (p[i] != i)
			return first = i;
	return 0;
}

// 把 p[0] 和 p[n]交换.
void swap(int* p, int n)
{
	int temp = p[0];
	p[0] = p[n];
	p[n] = temp;
}

int main()
{
	int n;
	cin >> n;
	int* data = new int[n];


	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		data[temp] = i;
	}

	// data[temp] = i, 下标是输入, 赋值是 i.
	int count = 0;
	while (true)
	{
		// 下标是 0 和 data[0] 交换.
		if (data[0])
			swap(data, data[0]);
		else
		{
			temp = search(data, n);
			if (!temp) break;
			swap(data, temp);
		}
		count++;
	}
	cout << count << endl;
	delete[]data;
	return 0;
}