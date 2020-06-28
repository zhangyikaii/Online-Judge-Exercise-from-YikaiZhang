// 记搜dalao:
// 注意注意vector存邻接表!
//using namespace std;
//int d[100001];
//vector<int> end[100001];
//int dp(int now) {
//	if (d[now] != -1)  return d[now];
//	d[now] = 1;
//	for (int i = 0; i<end[now].size(); i++)
//		d[now] = max(d[now], dp(end[now][i]) + 1);
//	return d[now];
//}


// 有向图 b -> a 就是  end[b].push_back(a);



//int main() {
//	int n, m;
//	memset(d, -1, sizeof(d));
//	cin >> n >> m;
//	int a, b;
//	for (int i = 1; i <= m; i++) {
//		cin >> a >> b;
//		end[b].push_back(a);
//	}
//	for (int i = 1; i <= n; i++)
//		printf("%d\n", dp(i));
//	return 0;
//}