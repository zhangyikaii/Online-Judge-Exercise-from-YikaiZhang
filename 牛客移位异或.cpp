#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(int i = s; i < n; ++i)

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int MyAbs(int a, int b) {
	if (a - b < 0)
		return b - a;
	return a - b;
}
//
//string s;
//
//string preZero(int a) {
//	string t;
//	while (a--) {
//		t += "0";
//	}
//
//	return t;
//}

using namespace std;
int n, m;
string s, ans;
int main()
{
	cin >> n >> m >> s;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (i - m >= 0)
			sum ^= (ans[i - m] - '0');
		int a = s[i] - '0';
		cout << "a, i: " << a << " " << i << endl;
		cout << "sum: " << sum << endl;
		ans += (sum ^ a + '0');
		sum = a;
	}
	cout << ans << endl;
	return 0;
}

//int main() {
//	
//	int n, m;
//	in(n);
//	in(m);
//	cin >> s;
//
//	string res = s + preZero(m - 1);
//
//	for (int i = 1; i < m; ++i) {
//		int aft = m - 1 - i;
//		cout << res << endl;
//		string tmp = preZero(i) + s + preZero(aft);
//		cout << tmp << endl;
//
//		for (int i = 0; i < res.size(); ++i) {
//			res[i] = ((res[i] - '0') ^ (tmp[i] - '0')) + '0';
//		}
//		cout << res << endl;
//		cout << endl;
//	}
//
//	cout << res << endl;
//
//
//	return 0;
//}

#include <unordered_map>

using namespace std;
unordered_map<string, string>M;
string t, tt;
int n, m, o, i;
string findd(string x) {
	return (x == M[x]) ? x : M[x] = findd(M[x]);
}
string find(string x){ return x == M[x] ? x : M[x] = find(M[x]); }
int main() {
	cin >> n >> m;
	for (i = 0; i<n; i++)cin >> t, M[t] = t;			// 甚至不用转数字, 直接字符串编码.
	for (i = 0; i<m; i++)
		// 如果不是, 就把tt的祖先接到t的祖先那里.
		cin >> o >> t >> tt, o == 1 ? (M[find(tt)] = find(t), 0) : (puts(find(t) == find(tt) ? "1" : "0"));
}


using namespace std;
typedef long long ll;
ll h[200005], y[200005], dp[1000505] = { 0 };
int main(){
	int n, m;		// 高度绝对值小于等于m的柱子上.
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) 
		scanf("%lld%lld", &h[i], &y[i]);

	ll ans = 0;
	// 这个for的顺序保证了 只能往右跳的性质.
	for (int i = 1; i <= n; i++) {
		int l = max(1LL, h[i] - m), r = h[i] + m;			// l ~ r 是可能的下一个的高度.
		ll tmp = 0;
		for (int j = l; j <= r; j++)
			tmp = max(dp[j], tmp);
		dp[h[i]] = tmp + y[i];			// 到了 h[i] 这一个高度之后拿到的最大鱼数
		ans = max(ans, dp[h[i]]);
	}
	printf("%lld\n", ans);
	return 0;
}