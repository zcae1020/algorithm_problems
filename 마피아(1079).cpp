//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//bool die[16];
//int N, guilt[16], R[16][16], ej;
//
//void Input() {
//	cin >> N;
//
//	for (int i = 0; i < N; i++)
//		cin >> guilt[i];
//
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			cin >> R[i][j];
//
//	cin >> ej;
//}
//
//void changeGuilt(int idx) {
//	for (int i = 0; i < N; i++)
//		guilt[i] += R[idx][i];
//}
//
//void initGuilt(int idx) {
//	for (int i = 0; i < N; i++)
//		guilt[i] -= R[idx][i];
//}
//
//int afternoon() {
//	int mx = 0;
//	for (int i = 0; i < N; i++) {
//		if (die[i])continue;
//		mx = max(mx, guilt[i]);
//	}
//	for (int i = 0; i < N; i++) {
//		if (die[i])continue;
//		if (mx == guilt[i])
//			return i;
//	}
//}
//
//int dfs(int day) {
//	int ret = day, a;
//	for (int i = 0; i < N; i++) {
//		if (i == ej || die[i])
//			continue;
//		die[i] = true;
//		changeGuilt(i);
//
//		a = afternoon();
//		if (a != ej) {
//			die[a] = true;
//			ret = max(ret, dfs(day + 1));
//			die[a] = false;
//		}
//
//		initGuilt(i);
//		die[i] = false;
//	}
//	return ret;
//}
//
//int main() {
//	Input();
//
//	if (N % 2) {
//		int a = afternoon();
//		if (a == ej) {
//			cout << 0;
//			return 0;
//		}
//		else
//			die[a] = true;
//	}
//
//	cout << dfs(1);
//}