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

struct Data {
	int id;
	double pri;
	Data() { }
	Data(int i, double p) : id(i), pri(p) { }
};

int n;
double pri, rate, ans = 0;

vector<int> arrPri[100010];
map<int, int> mapp;
int main() {
	cin >> n >> pri >> rate;
	rate = 1 + rate / 100;
	For(i, 0, n) {
		int tmp, cur;
		in(tmp);
		if (tmp != 0) {
			while (tmp--) {
				in(cur);
				arrPri[i].push_back(cur);
			}
		}
		else {
			in(cur);
			mapp[i] = cur;
		}
	}

	queue<Data> q;
	q.push(Data(0, 1));
	while (!q.empty()) {
		Data tmp = q.front();
		q.pop();

		if (arrPri[tmp.id].size() != 0) {
			For(i, 0, arrPri[tmp.id].size()) {
				q.push(Data(arrPri[tmp.id][i], rate * tmp.pri));
			}
		}
		else {
			ans += mapp[tmp.id] * tmp.pri;
			// cout << mapp[tmp.id] << "  " << tmp.pri << endl;
			mapp[tmp.id] = 0;
		}
	}

	printf("%.1f\n", ans * pri);


	return 0;
}


/*


10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3



*/