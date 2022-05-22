//#include <iostream>
//#define ll long long
//
//using namespace std;
//
//int m2m[1000006];
//ll mn, mx;
//
//void Solution() {
//	for (ll i = 2; i * i <= mx; i++) {
//		ll n = mn / (i * i);
//		if (mn % (i * i)) n++;
//		
//		while (n * i * i <= mx) {
//			m2m[n * i * i - mn] = 1;
//			n++;
//		}
//	}
//
//	int ans = 0;
//	for (ll i = 0; i <= mx - mn; i++)
//		if (m2m[i] == 0) ans++;
//
//	cout << ans;
//}
//
//int main() {
//	cin >> mn >> mx;
//	Solution();
//}