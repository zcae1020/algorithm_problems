//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int N;
//double ans, num[10000];
//
//int main() {
//	cin >> N;
//	for (int i = 0; i < N; i++) cin >> num[i];
//
//	ans = num[0];
//
//	for (int i = 1; i < N; i++) {
//		if (num[i] * num[i - 1] > num[i]) num[i] = num[i] * num[i - 1];
//
//		ans = max(ans, num[i]);
//	}
//
//	printf("%.3lf", ans);
//}