//#include <iostream>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//int N, res[50][10] = { 0 };
//
//int getScore(int order[10]) {
//	int out = 0, score = 0, cur = 1, base[3] = { 0 };
//	for (int i = 0;i < N;i++) {
//		out = 0;
//		for (int b = 0;b < 3;b++)
//			base[b] = 0;
//		while (out < 3) {
//			switch (res[i][order[cur]]) {
//			case 0:
//				out++;
//				break;
//			case 1:
//				if (base[2])
//					score++;
//				base[2] = base[1];
//				base[1] = base[0];
//				base[0] = 1;
//				break;
//			case 2:
//				for (int b = 1;b < 3;b++) {
//					if (base[b])
//						score++;
//				}
//				base[2] = base[0];
//				base[1] = 1;
//				base[0] = 0;
//				break;
//			case 3:
//				for (int b = 0;b < 3;b++) {
//					if (base[b])
//						score++;
//				}
//				base[2] = 1;
//				base[1] = 0;
//				base[0] = 0;
//				break;
//			case 4:
//				score++;
//				for (int b = 0;b < 3;b++) {
//					if (base[b])
//						score++;
//				}
//				base[2] = 0;
//				base[1] = 0;
//				base[0] = 0;
//				break;
//			}
//			cur++;
//			if (cur == 10)
//				cur = 1;
//		}
//	}
//	return score;
//}
//
//int dfs(int n, int order[10], int visited[10]) {
//	if (n == 10)
//		return getScore(order);
//	
//	int o[10], v[10];
//	for (int i = 0;i < 10;i++) {
//		o[i] = order[i], v[i] = visited[i];
//	}
//
//	int mx = 0;
//	for (int i = 2;i < 10;i++) {
//		if (!v[i]) {
//			v[i] = 1;
//			o[n] = i;
//			int nn = n + 1;
//			if (nn == 4)
//				nn = 5;
//			mx = max(mx, dfs(nn, o, v));
//			v[i] = 0;
//			o[n] = 0;
//		}
//	}
//	return mx;
//}
//
//int main() {
//	cin >> N;
//	for (int i = 0;i < N;i++) {
//		for (int j = 1;j < 10;j++) {
//			cin >> res[i][j];
//		}
//	}
//	int o[10] = { 0 }, v[10] = { 0 };
//	v[0] = 1, v[1] = 1;
//	o[4] = 1;
//	cout << dfs(1, o, v);
//}