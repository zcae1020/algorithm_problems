//#include <iostream>
//#include <algorithm>
//#include <cmath>
//#include <cstring>
//
//using namespace std;
//
//int N, K, na[10], ka[10], angle[360];
//
//int main() {
//	memset(angle, 0, sizeof(angle));
//	angle[0] = 1;
//	cin >> N >> K;
//	for (int i = 0;i < N;i++)
//		cin >> na[i];
//	for (int i = 0;i < K;i++)
//		cin >> ka[i];
//
//	for (int i = 0;i < N;i++) {
//		int idx = 1;
//		while (true) {
//			int cur = (na[i] * idx++) % 360;
//			if (cur == 0)
//				break;
//			for (int j = 0;j < 360;j++)
//				if (angle[j]) {
//					angle[(j + cur) % 360] = 1;
//					angle[abs(j - cur) % 360] = 1;
//				}
//		}
//	}
//
//	for (int i = 0;i < K;i++) {
//		if (angle[ka[i]])
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//	}
//}