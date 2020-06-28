#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
	// 传引用, 递归不好写
	/*int aMid = A.size() >> 1, bMid = B.size() >> 1;
	if (A[aMid] < B[bMid]) {
		vector<double> at(A.begin() + aMid, A.end()), bt(B.begin(), B.begin() + bMid);
		findMedianSortedArrays(at, bt);
	}*/

	int a1 = 0, a2 = 0, b1 = A.size() - 1, b2 = B.size() - 1;
	// 很简单取到中间数.
	int midPos1 = b1 >> 1;
	int midPos2 = (b2 >> 1) + 1;

	while ((A[midPos1] ^ B[midPos2]) && (a1 ^ b1 || a2 ^ b2)) {
		printf("%d, %d, %d\n%d, %d, %d\n", a1, midPos1, b1, a2, midPos2, b2);
		cout << "------\n";
		if (A[midPos1] < B[midPos2]) {
			// 个数是偶数
			if (((b1 - a1) & 1) == 1) {
				a1 = midPos1 + 1;				// 这里的 + 1 很精妙了.
			}
			else {
				a1 = midPos1;
			}
			b2 = midPos2;
		}

		else {
			// 个数是偶数
			if (((b1 - a1) & 1) == 1) {
				a2 = midPos2 + 1;
			}
			else {
				a2 = midPos2;
			}
			b1 = midPos1;
		}
		// Partition
		midPos1 = (a1 + b1) >> 1;
		midPos2 = (a2 + b2) >> 1;
	}

	cout << A[a1] << " " << B[a2] << endl;
	return ((double)(A[a1] + B[a2]) / 2);
}

int main() {
	vector<int> a = { 1, 2, 3, 4, 5, 6 }, b = { 2, 3, 4, 5 };
	cout << findMedianSortedArrays(a, b) << endl;
	
	return 0;
}


/*


*/