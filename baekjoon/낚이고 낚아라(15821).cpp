//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<double> fishing;
//int K, N, P;
//
//int main() {
//	scanf("%d %d", &K, &N);
//	while (K--) {
//		double x, y, mx = 0;
//		scanf("%d", &P);
//		while (P--) {
//			scanf("%lf %lf", &x, &y);
//			mx = max(mx, x * x + y * y);
//		}
//		fishing.push_back(mx);
//	}
//
//	sort(fishing.begin(), fishing.end());
//
//	printf("%.2lf", fishing[N - 1]);
//}