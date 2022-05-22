//#include <iostream>
//#include <algorithm>
//#define N 10
//#define pii pair<int,int>
//
//using namespace std;
//
//int map[N][N];
//
//pii findP(int m[10][10]) {
//	for (int i = 0;i < N;i++) {
//		for (int j = 0;j < N;j++) {
//			if (m[i][j])
//				return { j,i };
//		}
//	}
//	return { -1,-1 };
//}
//
//int dfs(int m[10][10], int c[6]) {
//	pii p = findP(m);
//	if (p.first == -1 && p.second == -1) {
//		int ret = 0;
//		for (int i = 1;i < 6;i++)
//			ret += c[i];
//		return 25 - ret;
//	}
//
//	int M[10][10];
//	for (int i = 0;i < N;i++)
//		for (int j = 0;j < N;j++)
//			M[i][j] = m[i][j];
//
//	int s = 1, flag;
//	for (int i = 5;i > 0;i--) {
//		flag = 0;
//		for (int j = p.second;j < p.second + i;j++) {
//			for (int k = p.first;k < p.first + i;k++) {
//				if (!M[j][k] || j >= N || k >= N) {
//					flag = 1;
//					break;
//				}
//			}
//		}
//		if (!flag) {
//			s = i;
//			break;
//		}
//	}
//
//	int C[6], ret = 50;
//	for (int i = 0;i < 6;i++)
//		C[i] = c[i];
//	for (int i = s;i > 0;i--) {
//		if (p.first >= 10 || p.second >= 10 || !C[i])
//			continue;
//		for (int j = p.second;j < p.second + i;j++) {
//			for (int k = p.first;k < p.first + i;k++) {
//				M[j][k] = 0;
//			}
//		}
//		C[i]--;
//
//		int d = dfs(M, C);
//		ret = min(ret, d);
//
//		C[i]++;
//		for (int j = p.second;j < p.second + i;j++) {
//			for (int k = p.first;k < p.first + i;k++) {
//				M[j][k] = 1;
//			}
//		}
//	}
//	return ret;
//}
//
//int main() {
//	for (int i = 0;i < N;i++)
//		for (int j = 0;j < N;j++)
//			cin >> map[i][j];
//	int c[6] = { 0,5,5,5,5,5 };
//	int d = dfs(map, c);
//	if (d > 25)
//		cout << -1;
//	else
//		cout << d;
//}