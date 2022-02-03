//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int T;
//int findPrime[2000006] = { 0 };
//long long A, B, sum;
//vector<int> prime;
//
//int main() {
//
//	for (int i = 2;i < 2000006;i++) {
//		if (!findPrime[i]) {
//			findPrime[i] = i;
//			prime.emplace_back(i);
//			for (int j = 2;j*i < 2000006;j++) {
//				findPrime[i*j] = i;
//			}
//		}
//	}
//
//	cin >> T;
//	while (T--) {
//		cin >> A >> B;
//		sum = A + B;
//		if (sum == 2 || sum == 3) {
//			cout << "NO" << endl;
//			continue;
//		}
//		else if (sum % 2 == 0) {
//			cout << "YES" << endl;;
//			continue;
//		}
//		else {
//			int flag = 1;
//			sum -= 2;
//			for (int i = 0;i < prime.size() && (long long)prime[i] * prime[i] <= sum;i++) {
//				if (sum%prime[i] == 0) {
//					cout << "NO" << endl;
//					flag = 0;
//					break;
//				}
//			}
//			if (flag)
//				cout << "YES" << endl;
//		}
//	}
//}