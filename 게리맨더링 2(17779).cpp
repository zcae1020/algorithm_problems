//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#define MX 10000
//#define pii pair<int,int>
//
//using namespace std;
//
//int N, map[21][21], area[21][21], ans = MX, a[5];
//
//void Input() {
//	cin >> N;
//	for (int i = 1; i <= N; i++)
//		for (int j = 1; j <= N; j++)
//			cin >> map[i][j];
//}
//
//void divideArea(int x, int y, int d1, int d2) {
//	for (int i = x, j = y; i <= x + d1; i++, j--)
//		area[i][j] = 5;
//	for (int i = x, j = y; i <= x + d2; i++, j++)
//		area[i][j] = 5;
//	for (int i = x + d1, j = y - d1; i <= x + d1 + d2; i++, j++)
//		area[i][j] = 5;
//	for (int i = x + d2, j = y + d2; i <= x + d2 + d1; i++, j--)
//		area[i][j] = 5;
//
//	bool five;
//	for (int i = x + 1; i < x + d1 + d2; i++) {
//		five = false;
//		for (int j = 1; j <= N; j++) {
//			if (area[i][j] == 5) {
//				if (five) five = false;
//				else five = true;
//				continue;
//			}
//			if (five) area[i][j] = 5;
//		}
//	}
//}
//
//void getAreaNum(int x,int y,int d1,int d2) {
//	for (int i = 1; i < x + d1; i++)
//		for (int j = 1; j <= y; j++)
//			if (area[i][j] != 5) a[0] += map[i][j];
//	for (int i = 1; i <= x + d2; i++)
//		for (int j = y + 1; j <= N; j++)
//			if (area[i][j] != 5) a[1] += map[i][j];
//	for (int i = x + d1; i <= N; i++)
//		for (int j = 1; j < y - d1 + d2; j++)
//			if (area[i][j] != 5) a[2] += map[i][j];
//	for (int i = x + d2 + 1; i <= N; i++)
//		for (int j = y - d1 + d2; j <= N; j++)
//			if (area[i][j] != 5) a[3] += map[i][j];
//	for (int i = 1; i <= N; i++)
//		for (int j = 1; j <= N; j++)
//			if (area[i][j] == 5) a[4] += map[i][j];
//}
//
//void getAns() {
//	sort(a, a + 5);
//	ans = min(ans, a[4] - a[0]);
//}
//
//void Solution() {
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			for (int d1 = 1; d1 <= j - 1; d1++) {
//				for (int d2 = 1; d2 <= N - j; d2++) {
//					if (i + d1 + d2 > N) break;
//					divideArea(i, j, d1, d2);
//					getAreaNum(i, j, d1, d2);
//					getAns();
//					memset(area, 0, sizeof(area));
//					memset(a, 0, sizeof(a));
//				}
//			}
//		}
//	}
//	cout << ans;
//}
//
//int main() {
//	Input();
//	Solution();
//}