//#include <iostream>
//#include <vector>
//#include <queue>
//#define pii pair<int,int>
//
//using namespace std;
//
//int gear[4][8], K, G, T, visited[5], dx[2] = { -1,1 };
//queue<pii> q;
//
//void rotate(int g, int t) {
//	vector<int> v;
//	if (t == 1) {
//		v.emplace_back(gear[g - 1][7]);
//		for (int i = 0;i < 7;i++)
//			v.emplace_back(gear[g - 1][i]);
//	}
//	else {
//		for (int i = 1;i < 8;i++)
//			v.emplace_back(gear[g - 1][i]);
//		v.emplace_back(gear[g - 1][0]);
//	}
//	for (int i = 0;i < 8;i++)
//		gear[g - 1][i] = v[i];
//}
//
//void bfs(int g, int t) {
//	for (int i = 0;i < 5;i++)
//		visited[i] = 0;
//	q.push({ g,t });
//	while (!q.empty()) {
//		pii cur = q.front();
//		q.pop();
//		visited[cur.first] = 1;
//		for (int i = 0;i < 2;i++) {
//			pii next = { cur.first + dx[i],cur.second > 0 ? -1 : 1 };
//			if (next.first > 0 && next.first <= 4 && !visited[next.first]) {
//				if (i) {
//					if (gear[cur.first - 1][2] != gear[next.first - 1][6])
//						q.push(next);
//				}
//				else {
//					if (gear[cur.first - 1][6] != gear[next.first - 1][2])
//						q.push(next);
//				}
//			}
//		}
//		rotate(cur.first, cur.second);
//	}
//}
//
//int main() {
//	char input[4][10];
//
//	for (int i = 0;i < 4;i++)
//		cin >> input[i];
//
//	for (int i = 0;i < 4;i++)
//		for (int j = 0;j < 8;j++)
//			 gear[i][j] = input[i][j] - '0';
//
//	cin >> K;
//	while (K--) {
//		cin >> G >> T;
//		bfs(G, T);
//	}
//	int two = 1, ans = 0;
//	for (int i = 0;i < 4;i++) {
//		if (gear[i][0])
//			ans += two;
//		two *= 2;
//	}
//	cout << ans;
//}