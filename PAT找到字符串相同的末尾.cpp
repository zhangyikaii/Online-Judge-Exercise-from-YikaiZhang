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

string arr[110];
int leng[110];
int main() {
	int n, minn = 0x7fffff;
	in(n);

	For(i, 0, n) {
		getline(cin, arr[i]);
		leng[i] = arr[i].length() - 1;
		minn = min(minn, leng[i]);
	}

	int i = 0;
	for (i = 0; i <= minn; ++i) {
		char base = arr[0][leng[0] - i];
		bool flag = true;
		For(k, 1, n) {
			if (base != arr[k][leng[k] - i]) {
				flag = false;
				break;
			}
		}
		if (flag == false)
			break;
	}

	if (i != 0)
		cout << arr[0].substr(leng[0] - i + 1, i) << endl;
	else
		cout << "nai" << endl;

	return 0;
}

/*


Kuchiguse (20)
时间限制 1000 ms 内存限制 65536 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述
The Japanese language is notorious for its sentence ending particles. Personal preference of such particles can be considered as a reflection of the speaker's personality. Such a preference is called "Kuchiguse" and is often exaggerated artistically in Anime and Manga. For example, the artificial sentence ending particle "nyan~" is often used as a stereotype for characters with a cat-like personality:
Itai nyan~ (It hurts, nyan~)
Ninjin wa iyada nyan~ (I hate carrots, nyan~)
Now given a few lines spoken by the same character, can you find her Kuchiguse?

输入描述:
Each input file contains one test case.  For each case, the first line is an integer N (2<=N<=100). Following are N file lines of 0~256 (inclusive) characters in length, each representing a character's spoken line. The spoken lines are case sensitive.


输出描述:
For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix of all N lines. If there is no such suffix, write "nai".

输入例子:
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~

输出例子:
nyan~


注意有效的时间.

正确的时间花在正确的事情上, 正确的方法家家相似, 错误的方法各有不同, 找努力的小伙伴一起前行, 圆梦.

概念知识点的理解落实到做题上, 笔头上的功夫一定要有.

“在努力中淬炼人格,在辛劳中塑造尊严,在奋斗中超越自我,绽放青春的光芒,照亮通往未来的道路！”

花里胡哨的东西很多, 不要乱搞.
*/