//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int D, N, oven[300000];
//
//int main() {
//	cin >> D >> N;
//
//	int mn = 2000000009;
//	for (int i = 0; i < D; i++) {
//		cin >> oven[i];
//		mn = min(mn, oven[i]);
//		oven[i] = mn;
//	}
//
//	int a, idx = D;
//	while (N--) {
//		idx--;
//		cin >> a;
//		while (oven[idx] < a) idx--;
//		if (idx < 0) {
//			cout << 0;
//			return 0;
//		}
//	}
//	cout << idx + 1;
//}