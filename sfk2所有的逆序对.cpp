#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

#define in(x) x=read()

#define MAXN 1000000

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n;
int iQui, jQui, tQui, iResTmp;
ll ans = 0;

bool cmp(int a, int b, char **arr) {
	for (int i = 0; i < 10; ++i) {
		if (arr[a][i] > arr[b][i])
			return true;
		else if (arr[a][i] < arr[b][i])
			return false;
	}

	return true;
}

void Swap(int arr[], int i, int j) {
	if (i == j)
		return;

	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}

void MyQuickSort(int left, int right, int rank[], char **arr) {
	if (left > right)
		return;

	tQui = rank[left];		// 取出基准数
	iQui = left;
	jQui = right;
	// 注意把 left 和 right 临时寄放在 iQui jQui 里面, 然后要先从右边开始找
	while (iQui != jQui) {
		while (cmp(rank[jQui], tQui, arr) && iQui < jQui)		// 从右往左找到第一个更小的(应该放在左边的)
			--jQui;
		while (cmp(tQui, rank[iQui], arr) && iQui < jQui)		// 从左往右找到第一个更大的(应该放在右边的)
			++iQui;

		// 交换位置
		if (iQui < jQui) {
			Swap(rank, iQui, jQui);
		}
	}

	// 最终将基准数归位
	rank[left] = rank[iQui];         // 注意这句话!!!
	rank[iQui] = tQui;

	MyQuickSort(left, iQui - 1, rank, arr);				//继续处理左边的
	MyQuickSort(iQui + 1, right, rank, arr);				//继续处理右边的
}


void MergeSort(int l, int r, int rank[], int mergeResTmp[]) {
	// 终止条件
	if (l >= r)
		return;

	int mid = (l + r) / 2;

	// 先递归!
	MergeSort(l, mid, rank, mergeResTmp);
	MergeSort(mid + 1, r, rank, mergeResTmp);
	
	// 开始归并
	//for (int i = l; i <= r; ++i)
	//	printf("%d ", rank[i]);
	//printf("\n");

	for (int i = l; i < r; ++i) {
		cout << rank[i] << " ";
	}
	int i = l, j = mid + 1;
	iResTmp = l - 1;						// 注意这里是中间那一部分处理!
	while (i <= mid && j <= r) {
		if (rank[i] <= rank[j]) {
			mergeResTmp[++iResTmp] = rank[i++];
		}
		else {
			mergeResTmp[++iResTmp] = rank[j++];
			ans += (mid - i + 1);				// 注意这里 ans 的处理, 归并第二个的时候, 前面的全部都更小, 都是逆序对
		}
	}

	// 剩余数组弄回去
	while (i <= mid)
		mergeResTmp[++iResTmp] = rank[i++];
	while (j <= r)
		mergeResTmp[++iResTmp] = rank[j++];

	// 中间那一部分放回去, 所以是从 l 开始到 r.
	for (int t = l; t <= r; ++t)
		rank[t] = mergeResTmp[t];
}


int main() {
	in(n);

	char **arr = new char*[n];
	int *rank = new int[n], *mergeResTmp = new int[n];

	for (int i = 0; i < n; ++i) {
		arr[i] = new char[12];
	}


	for (int i = 0; i < n; ++i) {
		scanf("%s", arr[i]);
		rank[i] = i;
	}
	
	MyQuickSort(0, n - 1, rank, arr);
	MergeSort(0, n - 1, rank, mergeResTmp);
	
	
	printf("wo yi yue du guan yu chao xi de shuo ming\n%lld\n", ans);

	for (int i = 0; i < n; ++i) {
		delete []arr[i];
	}
	delete[] rank;
	delete[] mergeResTmp;

	return 0;
}

/*

给出一个字符串数组，如果（按照字典序）一个大的字符串在比它小的字符串前面我们称这两个字符串组成一个“逆序对”。你需要找到所有的逆序对的个数。

输入
第一行是数组大小，第二行是以空格分隔的字符串数组.

注：预先知道每个字符串的长度都是 10.

输出
所有的逆序对个数. 这次需要大家先输出一个字符串，它是“我已阅读关于抄袭的说明”的汉语拼音.输出此行的提交我们将认为已经完全阅读并了解了“关于抄袭的说明”公告.

注意：结果比较大，请用 long 类型保存.

样例输入
3
aaaaaaaaaa cccccccccc bbbbbbbbbb
样例输出
wo yi yue du guan yu chao xi de shuo ming
1


*/