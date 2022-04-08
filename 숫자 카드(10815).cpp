//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int N, M, arrn[500000], a;
//
//void Input() {
//	cin >> N;
//	for (int i = 0; i < N; i++) cin >> arrn[i];
//	cin >> M;
//
//	sort(arrn, arrn + N);
//}
//
//bool BS(int target) {
//	int l = 0, r = N - 1, m;
//	while (l <= r) {
//		m = (l + r) / 2;
//		if (arrn[m] == target) return true;
//		else if (arrn[m] < target) l = m + 1;
//		else r = m - 1;
//	}
//	return false;
//}
//
//void Solution() {
//	cin >> a;
//	if (BS(a)) cout << 1 << ' ';
//	else cout << 0 << ' ';
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);
//	Input();
//	while (M--)
//		Solution();
//}