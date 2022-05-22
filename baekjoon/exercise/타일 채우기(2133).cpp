//#include <iostream>
//
//using namespace std;
//
//int N;
//long long DP[31];
//
//int main() {
//	DP[0] = 1;
//	DP[2] = 3;
//	cin >> N;
//	if (N % 2)
//		cout << 0;
//	else {
//		for (int i = 4;i <= N;i += 2) {
//			DP[i] = DP[i - 2] * 3;
//			for (int j = i - 4;j >= 0;j -= 2) {
//				DP[i] += 2 * DP[j];
//			}
//		}
//		cout << DP[N];
//	}
//}