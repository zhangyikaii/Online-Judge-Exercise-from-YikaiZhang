#include<iostream>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#define N 50
#define M 2000
#define P 10000000//模数
#define bit 7 //待压位数
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FOS(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
struct HPN{
	long long v[M], l;
	void clear(){ FOR(i, 0, M - 1) v[i] = 0; l = 0; }
	void getstr(string s){
		clear(); string ts;
		l = (s.length() - 1) / bit + 1;
		FOR(i, 1, l){
			ts = s.length()<bit ? s : s.substr(s.length() - bit, bit);
			s.erase(s.length() - ts.length(), ts.length());
			FOR(j, 0, ts.length() - 1) v[i] = v[i] * 10 + ts[j] - '0';
		}
	}//string 转 HPN
	void read(){
		string s; cin >> s;
		getstr(s);
	}
	void print(){
		printf("%d", v[l]);
		FOS(i, l - 1, 1) printf("%07d", v[i]);
	}
	//HPN operator = (HPN x){
	//	clear(), l = x.l;
	//	FOR(i, 1, l) v[i] = x.v[i];
	//}
	//HPN operator = (int x){
	//	stringstream ss;
	//	ss << x;
	//	getstr(ss.str());
	//}//int 转 HPN
	bool operator > (HPN x){
		if (l != x.l) return l>x.l;
		FOS(i, l, 1)
		if (v[i] != x.v[i]) return v[i]>x.v[i];
		return 0;
	}
	HPN operator + (HPN x){
		HPN y; y.clear();
		y.l = max(x.l, l);
		FOR(i, 1, y.l){
			y.v[i] += x.v[i] + v[i];
			y.v[i + 1] += y.v[i] / P;
			y.v[i] %= P;
		}if (y.v[y.l + 1]) y.l++;
		return y;
	}
	HPN operator + (int x){
		HPN y = *this; y.v[1] += x;
		FOR(i, 1, y.l){
			if (!y.v[i] / P) break;
			y.v[i + 1] += y.v[i] / P;
		}return y;
	}//单精加
	HPN operator - (int x){
		HPN y = *this; y.v[1] -= x;
		FOR(i, 1, y.l){
			if (y.v[i]<0) y.v[i] += P, y.v[i + 1]--;
			else break;
		}
		return y;
	}//单精减 
	HPN operator * (HPN x){
		HPN y; y.clear();
		y.l = x.l + l - 1;
		FOR(i, 1, l)
			FOR(j, 1, x.l){
				y.v[i + j - 1] += x.v[j] * v[i];
				y.v[i + j] += y.v[i + j - 1] / P;
				y.v[i + j - 1] %= P;
			}
		if (y.v[y.l + 1]) y.l++;
		return y;
	}
	HPN operator * (int x){
		HPN y; y.clear();
		y.l = l + log10(x) / bit;
		FOR(i, 1, y.l){
			y.v[i] += x*v[i];
			y.v[i + 1] += y.v[i] / P;
			y.v[i] %= P;
		}if (y.v[y.l + 1]) y.l++;
		return y;
	}//单精乘
	HPN operator / (int x){
		int z = 0;
		HPN y; y.clear();//y为商，z为余数
		y.l = l;
		FOS(i, l, 1){
			y.v[i] = (z + v[i]) / x;
			z = (z + v[i]) % x*P;
		}while (y.l && y.v[y.l] == 0) y.l--;
		return y;
	}//单精除
};
int main() {
	HPN a, b;
	a.read();
	b.read();
	a = a * b;
	a.print();

	return 0;
}