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
	int keyy;
	string next;
	bool flag;

	Data() { }
	Data(int k, string n, bool flag = false) : keyy(k), next(n) { }
};

struct Re {
	string ind;
	int keyy;
	string next;

	Re() { }
	Re(string indd, int k, string n) : ind(indd), keyy(k), next(n) { }
};

map<string, Data> ma;
map<int, bool> used;
vector<Re> remo;

string head;
int n;

int myabs(int a) {
	return a > 0 ? a : -a;
}

int main() {
	cin >> head >> n;
	For(i, 0, n) {
		string bef, nex;
		int ke;
		cin >> bef >> ke >> nex;
		ma[bef] = Data(ke, nex);
	}

	for (string i = head; i != "-1"; i = ma[i].next) {
		Data& cur = ma[i];
		if (used[myabs(cur.keyy)] == false) {
			used[myabs(cur.keyy)] = true;
			cur.flag = false;
		}
		else {
			remo.push_back(Re(i, cur.keyy, cur.next));
			cur.flag = true;
		}
	}

	bool isFir = true;
	for (string i = head; i != "-1"; i = ma[i].next) {
		while (ma[i].next != "-1" && ma[i].flag == true) {
			i = ma[i].next;
		}
		
		if (ma[i].flag == true)
			continue;

		if (isFir == true) {
			isFir = false;
		}
		else {
			cout << " " << i << endl;
		}
		
		
		cout << i << " " << ma[i].keyy;
	}

	cout << " -1" << endl;




	For(i, 0, remo.size()) {
		if (i == 0) {
			cout << remo[i].ind << " " << remo[i].keyy;
		}
		else {
			cout << " " << remo[i].ind << endl << remo[i].ind << " " << remo[i].keyy;
		}
	}

	cout << " -1" << endl;
	return 0;
}

/*

题目描述
Given a singly linked list L with integer keys, you are supposed to remove the nodes with duplicated absolute values of the keys.  That is, for each value K, only the first node of which the value or absolute value of its key equals K will be kept.  At the mean time, all the removed nodes must be kept in a separate list.  For example, given L being 21→-15→-15→-7→15, you must output 21→-15→-7, and the removed list -15→15.

输入描述:
Each input file contains one test case.  For each case, the first line contains the address of the first node, and a positive N (<= 105) which is the total number of nodes.  The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Key Next
where Address is the position of the node, Key is an integer of which absolute value is no more than 104, and Next is the position of the next node.


输出描述:
For each case, output the resulting linked list first, then the removed list.  Each node occupies a line, and is printed in the same format as in the input.

输入例子:
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854

输出例子:
00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1



*/