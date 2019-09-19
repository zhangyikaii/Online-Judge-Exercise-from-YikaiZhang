//#include <bits/stdc++.h>
//using namespace std;
//
//typedef long long ll;
//
//#define in(x) x=read()
//#define For(i, a, b) for(int i = a; i < b; ++i)
//
//inline int read() {
//	int X = 0, w = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X * w;
//}
//
//struct Data {
//	int ach, bch;
//	Data() : ach(-1), bch(-1) { }
//	Data(int a, int b) : ach(a), bch(b) { }
//};
//int n, m;
//
//int main() {
//	// 想递归做.
//	in(n);
//	For(i, 0, n) {
//
//	}
//
//
//	return 0;
//}
//
///*
//
//给定两棵树T1和T2。如果T1可以通过若干次左右孩子互换就变成T2，则我们称两棵树是“同构”的。例如图1给出的两棵树就是同构的，因为我们把其中一棵树的结点A、B、G的左右孩子互换后，就得到另外一棵树。而图2就不是同构的。
//
//现给定两棵树，请你判断它们是否是同构的。
//输入格式:
//输入给出2棵二叉树树的信息。对于每棵树，首先在一行中给出一个非负整数N (≤10)，即该树的结点数（此时假设结点从0到N−1编号）；随后N行，第i行对应编号第i个结点，给出该结点中存储的1个英文大写字母、其左孩子结点的编号、右孩子结点的编号。如果孩子结点为空，则在相应位置上给出“-”。给出的数据间用一个空格分隔。注意：题目保证每个结点中存储的字母是不同的。
//
//输出格式:
//如果两棵树是同构的，输出“Yes”，否则输出“No”。
//
//输入样例1（对应图1）：
//8
//A 1 2
//B 3 4
//C 5 -
//D - -
//E 6 -
//G 7 -
//F - -
//H - -
//8
//G - 4
//B 7 6
//F - -
//A 5 1
//H - -
//C 0 -
//D - -
//E 2 -
//输出样例1:
//Yes
//输入样例2（对应图2）：
//8
//B 5 7
//F - -
//A 0 3
//C 6 -
//H - -
//D - -
//G 4 -
//E 1 -
//8
//D 6 -
//B 5 -
//E - -
//H - -
//C 0 2
//G - 3
//F - -
//A 1 4
//输出样例2:
//No
//
//
//
//
//*/


#include <bits/stdc++.h>
using namespace std;

typedef char ElementType;
typedef struct TNode BTree;
struct TNode {
	ElementType Data;
	int Left;
	int Right;
}T[101], t[101];

int vis[101];
int BuildTree(BTree t[]) {
	int n;
	cin >> n;
	int root;
	memset(vis, 0, sizeof(vis));
	if (!n)return -1;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		t[i].Data = a;
		if (b != '-') {
			t[i].Left = b - '0';
			vis[t[i].Left] = 1;
		}
		else t[i].Left = -1;
		if (c != '-') {
			t[i].Right = c - '0';
			vis[t[i].Right] = 1;
		}
		else t[i].Right = -1;
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i])root = i;
	}
	return root;
}
bool Judge(int a, int b) {
	if (a == -1 && b == -1)return true;
	else if ((a != -1 && b == -1) || (a == -1 && b != -1))return false;
	else if (T[a].Data != t[b].Data)return false;
	else if (T[a].Left == -1 && t[b].Left == -1)
		return Judge(T[a].Right, t[b].Right);
	else if (T[a].Left != -1 && t[b].Left != -1 && T[T[a].Left].Data == t[t[b].Left].Data)
		return Judge(T[a].Left, t[b].Left) && Judge(T[a].Right, t[b].Right);
	else return Judge(T[a].Left, t[b].Right) && Judge(T[a].Right, t[b].Left);
}
int main()
{
	int root1 = BuildTree(T);
	int root2 = BuildTree(t);
	if (Judge(root1, root2))cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
