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

/*

#include <iostream>
#include <vector>
#include<set>
using namespace std;
void readlnsets(vector<set<int>>*sets, int N)
{
  int M, integers,index;
  for (index = 0; index < N; index++)
  {
	scanf("%d", &M);
	while (M--)
	{
	  scanf("%d", &integers);
	  (*sets)[index].insert(integers);  // 当数已经在集合里面就不再放入了
	}
   }
}
int main()
{
	int N, K, a, b;
	double Nt, Nc;
	scanf("%d", &N);
	vector<set<int>>sets(N);
	readlnsets(&sets, N);
	scanf("%d", &K);
	while (K--)
	{
		scanf("%d%d", &a, &b);
		a--;
		b--;
		Nc = 0.0;
		for (set<int>::iterator iter = sets[a].begin(); iter != sets[a].end(); iter++)
			if (sets[b].find((*iter)) != sets[b].end())Nc++;
		Nt = sets[a].size() + sets[b].size() - Nc;
		printf("%.1lf%\n", Nc / Nt * 100.0);
	}
	system("pause");
	return 0;
}
*/

int n, m;

vector<set<int> > vs;

int main() {
	in(n);
	vs.resize(n + 10);
	For(i, 0, n) {
		int tmp;
		in(tmp);

		while (tmp--) {
			int subTmp;
			in(subTmp);
			vs[i].insert(subTmp);
		}
	}

	int q;
	in(q);
	while (q--) {
		int fir, sec;
		int uni = 0, inter = 0;
		in(fir), in(sec);

		--fir, --sec;
		for (set<int>::iterator iter = vs[fir].begin(); iter != vs[fir].end(); ++iter) {
			if (vs[sec].find(*iter) != vs[sec].end()) {
				++inter;
			}
		}
		uni = vs[fir].size() + vs[sec].size() - inter;
		double res = (double)inter / (double)uni * 100.0;
		printf("%.1f%%\n", res);
	}

	return 0;
}

/*




*/