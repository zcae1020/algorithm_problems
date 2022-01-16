//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define pii pair<int, int>
//
//using namespace std;
//
//int invert[5] = { 0,0,2,3,1 };
//vector<pii> p;
//
//int main() {
//	int N;
//	cin >> N;
//	for (int i = 0;i < N / 2;i++) {
//		int a, b, c, d;
//		cin >> a >> b >> c >> d;
//		a = invert[a];
//		c = invert[c];
//		
//		int x = a * 51 + b, y = c * 51 + d;
//		if (a > 1) x += 51 - 2 * b;
//		if (c > 1) y += 51 - 2 * d;
//		p.emplace_back(min(x, y), max(x, y));
//	}
//
//	int res = 0, cross[51] = { 0 }, mx = 0, tmpmx;
//	for (int i = 0;i < N / 2;i++) {
//		for (int j = 0;j < N / 2;j++) {
//			int a, b, c, d;
//			a = p[i].first, b = p[i].second, c = p[j].first, d = p[j].second;
//			if ((a < c&&c < b&&b < d) || (c < a&&a < d&&d < b)) {
//				res++;
//				cross[i]++;
//				cross[j]++;
//				tmpmx = max(cross[i], cross[j]);
//				if (mx < tmpmx)
//					mx = tmpmx;
//			}
//		}
//	}
//	cout << res / 2 << endl << mx / 2;
//}