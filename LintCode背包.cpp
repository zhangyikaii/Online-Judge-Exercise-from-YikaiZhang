#include <iostream>
#include <vector>
using namespace std;


int ans[105][1005];
void append(vector<vector<int> > & A, vector<vector<int> > &B, int C) {
	for (int i = 0; i < B.size(); i++) {
		A.push_back(B[i]);
		A[A.size() - 1].push_back(C);
	}
}
vector<vector<int> > anslist[105][1005];
vector<vector<int> > kSumII(vector<int> A, int k, int target) {
	ans[0][0] = 1;
	anslist[0][0].push_back(vector<int>());
	for (int i = 0; i < A.size(); ++i) {
		for (int j = k; j > 0; j--) {
			for (int l = target; l >= A[i]; l--) {
				ans[j][l] += ans[j - 1][l - A[i]];
				append(anslist[j][l], anslist[j - 1][l - A[i]], A[i]);
			}
		}
	}
	return anslist[k][target];
}