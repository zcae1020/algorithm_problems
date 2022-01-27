//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//#include <cstring>
//#define pii pair<int,int>
//
//using namespace std;
//
//int N, M, map[8][8], visited[8][8];
//vector<pii> emp, virus, spreaded;
//int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
//
//void setting() {
//	for (int i = 0;i < N;i++)
//		memset(visited[i], 0, sizeof(visited[i]));
//	for (int i = 0;i < spreaded.size();i++) {
//		if (map[spreaded[i].second][spreaded[i].first] == 2)
//			map[spreaded[i].second][spreaded[i].first] = 0;
//	}
//	spreaded.clear();
//}
//
//void spread() {
//	queue<pii> q;
//	for (int i = 0;i < virus.size();i++) {
//		q.push(virus[i]);
//		visited[virus[i].second][virus[i].first] = 1;
//	}
//
//	while (!q.empty()) {
//		pii cur = q.front();
//		q.pop();
//		for (int i = 0;i < 4;i++) {
//			pii n = { cur.first + dx[i],cur.second + dy[i] };
//			if (!visited[n.second][n.first] && !map[n.second][n.first] && !(n.first < 0 || n.second < 0 || n.first >= M || n.second >= N)) {
//				q.push(n);
//				visited[n.second][n.first] = 1;
//				map[n.second][n.first] = 2;
//				spreaded.emplace_back(n);
//			}
//		}
//	}
//}
//
//int countEmp() {
//	int ret = 0;
//	for (int i = 0;i < N;i++) {
//		for (int j = 0;j < M;j++) {
//			if (!map[i][j])
//				ret++;
//		}
//	}
//	return ret;
//}
//
//int main() {
//	cin >> N >> M;
//	for (int i = 0;i < N;i++) {
//		for (int j = 0;j < M;j++) {
//			cin >> map[i][j];
//			pii tmp = { j,i };
//			if (map[i][j] == 0)
//				emp.emplace_back(tmp);
//			else if (map[i][j] == 2)
//				virus.emplace_back(tmp);
//
//		}
//	}
//
//	int mx = 0;
//	for (int i = 0;i < emp.size();i++) {
//		map[emp[i].second][emp[i].first] = 1;
//		for (int j = i + 1;j < emp.size();j++) {
//			map[emp[j].second][emp[j].first] = 1;
//			for (int k = j + 1;k < emp.size();k++) {
//				map[emp[k].second][emp[k].first] = 1;
//
//				setting();
//				spread();
//				mx = max(mx, countEmp());
//
//				map[emp[k].second][emp[k].first] = 0;
//			}
//			map[emp[j].second][emp[j].first] = 0;
//		}
//		map[emp[i].second][emp[i].first] = 0;
//	}
//	cout << mx;
//}