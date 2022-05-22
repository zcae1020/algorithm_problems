//#include <iostream>
//#include <algorithm>
//#define ll long long
//
//using namespace std;
//
//ll N, M, C[100005], res;
//
//int main() {
//	cin >> N >> M;
//	ll mx = 0;
//	for (int i = 0;i < N;i++) {
//		cin >> C[i];
//		mx = max(mx, C[i]);
//	}
//	mx *= M;
//
//	ll l = 0, r = res = mx, m, p;
//	while (l <= r) {
//		m = (l + r) / 2;
//		p = 0;
//		for (int i = 0;i < N;i++)
//			p += m / C[i];
//		if (p < M)
//			l = m + 1;
//		else {
//			r = m - 1;
//			res = min(res, m);
//		}
//	}
//
//	cout << res;
//}