#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

#define For(i, n, m) for(int i = n;i < m; ++i)

inline int read(){
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	if (f) return x;
	return 0 - x;
}

int n, m, a[66], nextArr[66], cnt, sum, len;

bool used[66], ok; //used数组即优化5的vis数组，记录每根木棍是否用过；ok记录是否已找到答案。 
bool cmp(int a, int b) {
	return a > b;
}

// k 为正在拼的木棍的编号, 就像递归的组号/层数，last 为正在拼的木棍的前一节编号，rest 为该木棍还未拼的长度
void dfs(int k, int last, int rest) {
	int i;

	// 未拼的长度为0，说明这根原始长棍拼完了，准备拼下一个
	// 这是搜索的开头, 拼的第一根木棍
	if (!rest) { 
		if (k == m) { ok = 1; return; } //优化6，全部拼完并符合要求，找到答案，直接返回 

		// 找一个还没用的最长的木棍打头即可。反正要想全都拼接成功，每根木棍都得用上 
		for (i = 1; i <= cnt; i++) {
			if (!used[i]) 
				break;
		}

		used[i] = 1;
		dfs(k + 1, i, len - a[i]);			// 这里选了第一根木棍, 所以是 len - a[i]
		used[i] = 0;

		if (ok) return; //优化6，找到答案就退出 
	}

	else {
		// 优化4，二分找第一个 木棍长度不大于未拼长度 rest 的位置 
		int l = last + 1, r = cnt, mid;
		while (l < r) {
			mid = (l + r) >> 1;
			if (a[mid] <= rest)
				r = mid;
			else
				l = mid + 1;
		}

		for (i = l; i <= cnt; i++) {
			if (!used[i]) { //优化5，判断木棍是否用过 
				used[i] = 1;
				dfs(k, i, rest - a[i]);
				used[i] = 0;

				if (ok) return; //优化6，找到答案就退出 

				// 优化7: 如果当前长棍剩余的未拼长度等于当前木棍的长度或原始长度，继续拼下去时却失败了，就直接回溯并改之前拼的木棍
				if (rest == a[i] || rest == len)
					return;
				i = nextArr[i]; //优化3 

				if (i == cnt)
					return;
			}
		}
	}
}
int main(){
	n = read();
	int d;
	for (int i = 1; i <= n; i++){
		d = read();
		if (d > 50) 
			continue;
		a[++cnt] = d;
		sum += d;
	}

	sort(a + 1, a + cnt + 1, cmp); //优化1，木棍按长度从大到小排序 
	
	//优化3，预处理nextArr数组, 保证遍历不到重复的, 有点像并查集的作用, 这个方法很不错
	nextArr[cnt] = cnt;
	for (int i = cnt - 1; i>0; i--) {
		if (a[i] == a[i + 1]) 
			nextArr[i] = nextArr[i + 1];
		else 
			nextArr[i] = i;
	}

	// 总的搜索开始, 确定遍历每一组的len
	for (len = a[1]; len <= sum / 2; len++) { //枚举原始长度 
		if (sum%len != 0) 
			continue; //如果不能拼出整数根 就跳过 

		m = sum / len; //优化6中的那个计算 
		ok = 0;

		used[1] = 1;
		dfs(1, 1, len - a[1]);
		used[1] = 0;

		if (ok){ printf("%d\n", len); return 0; } //优化6，输出答案，退出
	}
	printf("%d\n", sum); return 0;
}