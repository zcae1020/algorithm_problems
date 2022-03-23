//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#define MAX 1000006
//#define pii pair<int,int>
//
//using namespace std;
//
//int N, P, K, answer = -1;
//int cost[1001];
//vector<pii> map[1001];
//
//void Input() {
//	cin >> N >> P >> K;
//	for (int i = 0; i < P; i++) {
//		int a, b, c;
//		cin >> a >> b >> c;
//
//		map[a].push_back({ b,c });
//		map[b].push_back({ a,c });
//	}
//}
//
//int dijkstra(int m) {
//	for (int i = 1; i <= N; i++) cost[i] = MAX;
//
//	priority_queue<pii> pq;
//	pq.push({ 1,0 });
//	cost[1] = 0;
//
//	while (!pq.empty()) {
//		int curIdx = pq.top().first;
//		int curCost = -pq.top().second;
//		pq.pop();
//
//		if (cost[curIdx] < curCost) continue;
//
//		for (auto a : map[curIdx]) {
//			int nextIdx = a.first;
//			int nextCost = curCost + (a.second > m);
//
//			if (cost[nextIdx] > nextCost) {
//				cost[nextIdx] = nextCost;
//				pq.push({ nextIdx, -nextCost });
//			}
//		}
//	}
//
//	return cost[N] <= K;
//}
//
//void Solution() {
//	int l = 0, r = 1e7;
//	while (l <= r) {
//		int mid = l + r >> 1;
//		if (dijkstra(mid)) {
//			answer = mid;
//			r = mid - 1;
//		}
//		else {
//			l = mid + 1;
//		}
//	}
//	cout << answer;
//}
//
//int main() {
//	Input();
//	Solution();
//}