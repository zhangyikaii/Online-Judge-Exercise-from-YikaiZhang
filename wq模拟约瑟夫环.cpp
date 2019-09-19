#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include<queue>
#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

#define N 1000010

typedef long long ll;

#define in(x) x=read()

ll n, m, k, tmp;
ll T[N], arr[N] = { 0 };

ll read(ll x = 0) {
	ll c, f = 1;
	for (c = getchar(); !isdigit(c); c = getchar())if (c == '-')f = -f;
	for (; isdigit(c); c = getchar())x = x * 10 + c - 48;
	return f*x;
}

ll lowbit(ll x) {
	return x&(-x);
}

void add(ll pos, ll x) {
	while (pos <= n) {
		T[pos] += x;
		pos += lowbit(x);
	}
}

int main(){
	in(n);
	for (ll i = n - 1; i >= 1; --i) {
		in(arr[i]);
		++arr[i];
		add(i, 1);
	}
	add(n, 1);

	k = 1;
	for (ll i = 1; i <= n; i++) {
		k = (k - 1 + arr[i] - 1) % (n - i + 1) + 1;			// 下一次前缀和.
		//cout << k << "  ";
		//for (int i = 1; i <= n; ++i) {
		//	cout << T[i] << "  ";
		//}
		//cout << "-----------------" << endl;
		tmp = lower_bound(T + 1, T + n, k) - T;				// 对应死了的位置.
		// cout << "k:" << k << "   tmp: " << tmp << endl;
		add(tmp, -1);										// 删了.
		// cout << tmp - 1 << "  ";
	}
	cout << tmp - 1 << endl;
	return 0;
}

//#include <cstdio>
//#include <cstdlib>
//#include <algorithm>
//#include<queue>
//#include <iostream> 
//#include <cstdio> 
//#include <algorithm> 
//#include <cstring>
//#include <map>
//#include <cmath>
//using namespace std;
//
//struct Data {
//	ll next, val;
//	Data() {}
//	Data(ll a, ll b) : next(a), val(b) { }
//};
//
//typedef long long ll;
//
//#define in(x) x=read()
//
//inline ll read() {
//	ll X = 0, w = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X*w;
//}
//
//
//ll n, head, pre, m;
//ll arr[1000010] = { 0 };
//Data list[1000010];
//
//ll main() {
//	ios::sync_with_stdio(false);
//	cin >> n;
//	for (ll i = n - 2; i >= 0; --i) {
//		cin >> arr[i];
//	}
//	for (ll i = 0; i < n - 1; ++i) {
//		list[i].next = i + 1;
//	}
//	list[n - 1].next = 0;
//
//	head = 0, pre = 0;
//	for (ll i = 0, cnt = n; i < n - 1; ++i) {
//		// --arr[i];
//		arr[i] %= cnt--;
//		while (arr[i]--) {
//			pre = head;
//			head = list[head].next;
//		}
//		// cout << head << " ";
//		list[pre].next = list[head].next;
//		head = list[head].next;
//	}
//
//	cout << head << endl;
//
//
//	
//	return 0;
//}
///*
//现在有 nnn 个人, 编号从 000 到 n−1n-1n−1, 站成一圈, 编号为 iii 的人右手边是编号为 i+1i+1i+1 的人(n−1n-1n−1 的右手边为 000). 进行一种约瑟夫环游戏的变种.
//
//游戏一共进行 n−1n-1n−1 轮, 一开始编号为 000 的人手里拿着旗子.
//
//在第 iii 轮(从 111 开始数), 手上拿着旗子的人把旗子传给他右手边的人, 一共传 w[i]w[i]w[i] 次, 传完之后拿着旗子的人退出队伍, 并把旗子传给他右手边的人.
//
//问最后剩在队伍里的人是谁.
//
//比如 n=3n=3n=3, 粗体数字代表拥有旗子, w[1]=2w[1] = 2w[1]=2, w[2]=1w[2] = 1w[2]=1.
//
//第一轮开始时状态是 0, 1, 2
//
//旗子传 222 次之后的状态是 0, 1, 2
//
//然后 222 被踢出队伍, 把旗子传给 000.
//
//第二轮开始时状态是 0, 1
//
//传 111 次之后的状态是 0, 1
//
//然后 111 被踢出.
//
//剩下的人编号为 000.
//
//输入格式
//先读入一个 n≤106n \le 10^6n≤10
//​6
//​​ .
//
//接下来 n−1n - 1n−1 个整数, 分别代表 wn−1,wn−2,⋯,w2,w1w_{n - 1}, w_{n - 2}, \cdots, w_2, w_1w
//​n−1
//​​ ,w
//​n−2
//​​ ,⋯,w
//​2
//​​ ,w
//​1
//​​ , 1≤wi≤1091 \le w_i \le 10^91≤w
//​i
//​​ ≤10
//​9
//​​ .
//
//样例
//样例输入
//3
//1 2
//样例输出
//0
//*/