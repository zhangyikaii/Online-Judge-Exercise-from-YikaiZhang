#include <iostream>
#include <cstdlib>
#include <cstdio>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
typedef long long ll;
typedef pair<ll, ll> pii;
template<class T>ll chkmin(T &a, T b){ return a>b ? a = b, 1 : 0; }
template<class T>ll chkmax(T &a, T b){ return a<b ? a = b, 1 : 0; }
template<class T>T sqr(T a){ return a*a; }
template<class T>T mmin(T a, T b){ return a<b ? a : b; }
template<class T>T mmax(T a, T b){ return a>b ? a : b; }
template<class T>T aabs(T a){ return a<0 ? -a : a; }
#define min mmin
#define max mmax
#define abs aabs
ll read(){
	ll s = 0, base = 1;
	char c;
	while (!isdigit(c = getchar()))if (c == '-')base = -base;
	while (isdigit(c)){ s = s * 10 + (c ^ 48); c = getchar(); }
	return s*base;
}
char WritellBuffer[1024];
template<class T>void write(T a, char end){
	ll cnt = 0, fu = 1;
	if (a<0){ putchar('-'); fu = -1; }
	do{ WritellBuffer[++cnt] = fu*(a % 10) + '0'; a /= 10; } while (a);
	while (cnt){ putchar(WritellBuffer[cnt]); --cnt; }
	putchar(end);
}
const ll p[] = { 0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
ll sc[20], tc[20], tt[20], n, ansx, ansy;
void dfs(ll x){
	for (tt[x] = 1, sc[x] = sc[x - 1] * p[x], tc[x] = tc[x - 1] << 1; tt[x] <= tt[x - 1] && sc[x] <= n; ++tt[x], tc[x] += tc[x - 1], sc[x] *= p[x]){
		if (chkmax(ansx, tc[x]))ansy = sc[x];
		else if (ansx == tc[x])chkmin(ansy, sc[x]);
		dfs(x + 1);
	}

}
int main(){
#ifdef cnyali_lk
	freopen("1463_1.in", "r", stdin);
	freopen("1463_1.out", "w", stdout);
#endif
	n = read();
	sc[0] = 1;
	tc[0] = 1;
	tt[0] = 23333;
	ansx = 1; ansy = 1;
	dfs(1);
	printf("%lld\n", ansy);
	return 0;
}