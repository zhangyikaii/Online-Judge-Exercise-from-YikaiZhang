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


// 下面是答案:
// tql
#include <cstdio>  
#include <stack>  
#include <set>  
using namespace std;

const int debug = 1;
typedef int T;
class Find_Median {
private:
	multiset<T, greater<T> > maxheap;
	multiset<T, less<T> > minheap;
public:
	void Push(T data) {
		if (maxheap.size() < minheap.size())
			maxheap.insert(data);
		else
			minheap.insert(data);
	}
	bool Erase(T data) {
		multiset<T>::iterator it;
		if ((it = maxheap.find(data)) != maxheap.end())
			maxheap.erase(it);
		else if ((it = minheap.find(data)) != minheap.end())
			minheap.erase(it);
		else
			return false;
		return true;
	}
	T Query()
	{
		while (maxheap.size() < minheap.size())
		{
			maxheap.insert(*minheap.begin());
			minheap.erase(minheap.begin());
		}
		while (minheap.size() < maxheap.size())
		{
			minheap.insert(*maxheap.begin());
			maxheap.erase(maxheap.begin());
		}

		if (maxheap.size() == 0) return *minheap.begin();
		if (minheap.size() == 0) return *maxheap.begin();

		multiset<T>::iterator maxtop = maxheap.begin();
		multiset<T>::iterator mintop = minheap.begin();
		while (*maxtop > * mintop)
		{
			maxheap.insert(*mintop);
			minheap.insert(*maxtop);
			maxheap.erase(maxtop);
			minheap.erase(mintop);
			maxtop = maxheap.begin();
			mintop = minheap.begin();
		}
		return *(maxheap.size() >= minheap.size() ? maxtop : mintop);
	}
};
Find_Median FM;
int main()
{
	int n, tmp;
	scanf("%d", &n);
	stack<int> s;
	char str[10];
	while (n--)
	{
		scanf("%s", str);
		switch (str[1])
		{
		case 'e': {
			if (s.empty())  printf("Invalid\n");
			else
				printf("%d\n", FM.Query());
			break;
		}
		case 'o':
		{
			if (s.empty())  printf("Invalid\n");
			else
			{
				tmp = s.top(); s.pop();
				printf("%d\n", tmp);
				FM.Erase(tmp);
			}
			break;
		}
		case 'u':
		{
			scanf("%d", &tmp); s.push(tmp);
			FM.Push(tmp);
		}
		break;
		}
	}
	return 0;
}


//
//#define MAX 100010
//
//stack<int> sta;
//priority_queue<int> q;
//priority_queue<int, vector<int>, greater<int> > sq;
//
//int main() {
//	int n;
//	in(n);
//
//	string po = "Pop", pmm = "PeekMedian", pus = "Push";
//	string tmp;
//
//	for (int i = 0; i < n; ++i) {
//		getline(cin, tmp);
//		int pusPos = tmp.find(pus), popPos = tmp.find(po), pmmPos = tmp.find(pmm);
//		if (pusPos != string::npos) {
//			int puNum = atoi(tmp.substr(pusPos, tmp.size() - pusPos).c_str());
//			sta.push(puNum);
//		}
//		else if (popPos != )
//	}
//	
//	return 0;
//}

/*


*/