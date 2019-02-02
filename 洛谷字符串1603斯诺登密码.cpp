#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
#define For(i, n, m) for(int i = n;i < m; ++i)

char dic[27][20] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "a", "both", "another", "first", "second", "third" };
int di[30] = { 0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 00, 21, 44, 69, 96, 25, 56, 89, 24, 61, 0, 1, 4, 1, 1, 4, 9 };

inline int read() {
	char s;
	int k = 0, base = 1;
	while ((s = getchar()) != '-' && s != EOF&&!(s >= '0'&&s <= '9'));
	if (s == EOF)exit(0);
	if (s == '-')base = -1, s = getchar();
	while (s >= '0'&&s <= '9')
	{
		k = k * 10 + (s - '0');
		s = getchar();
	}
	return k*base;
}

int main() {
	char a[60] = "";
	int data[10] = { 0 }, iData = 0;
	For(i, 0, 6) {
		scanf("%s", a);
		For(i, 0, 27) {
			if (!strcmp(a, dic[i])) {
				data[iData++] = di[i];
				break;
			}
		}
	}
	if (iData == 0)
		cout << 0 << endl;
	else {
		sort(data, data + iData);

		bool isFir = true;
		For(i, 0, iData) {
			if (isFir == true) {
				if (data[i] != 0) {
					printf("%d", data[i]);
					isFir = false;
				}
			}
			else {
				printf("%.2d", data[i]);
			}
		}

		if (isFir == true) {
			cout << "0" << endl;
		}
		else {
			printf("\n");
		}
	}


	return 0;
}

/*
找出句子中所有用英文表示的数字(≤20)，列举在下：

正规：one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty

非正规：a both another first second third

（2）将这些数字平方后%100，如00,05,11,19,86,99。

（3）把这些两位数按数位排成一行，组成一个新数，如果开头为0，就去0。

（4）找出所有排列方法中最小的一个数，即为密码。


Black Obama is two five zero .

425
*/
