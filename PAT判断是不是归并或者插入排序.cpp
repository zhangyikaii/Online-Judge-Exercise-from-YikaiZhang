//1089
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int origin[100], current[100], t[100];
	for (int i = 0; i < n; ++i)
		scanf("%d", &origin[i]);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &t[i]);
		current[i] = t[i];
	}
	int m = 0;    //check if it is a insertion sort
	while (t[m] <= t[m + 1])
		++m;      //check the sorted element
	int temp = ++m;
	while (temp < n && t[temp] == origin[temp])
		++temp;   //check the uninserted element
	if (temp == n)
	{             //Insertion Sort
		printf("Insertion Sort\n");
		sort(origin, origin + m + 1);
	}
	else
	{             //Merge Sort
		printf("Merge Sort\n");
		int k = 1, flag = 1;
		while (flag)
		{
			flag = 0;
			//check if the origin sequence has been 
			//merged the same as current sequence
			for (int i = 0; i < n; ++i)
				if (origin[i] != current[i])
					flag = 1;
			k *= 2;
			for (int i = 0; i < n / k; ++i)
				sort(origin + i * k, origin + (i + 1) * k);
			sort(origin + (n / k) * k, origin + n);
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d%c", origin[i], " \n"[i == n - 1]);
	return 0;
}