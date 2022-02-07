//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//#define pii pair<int,int>
//
//using namespace std;
//
//int n, visited[102] = { 0 };
//pii h, f;
//vector<pii> c;
//
//bool dfs(pii cur) {
//	int dist = abs(cur.first - f.first) + abs(cur.second - f.second);
//	if (dist <= 1000)
//		return true;
//	for (int i = 0;i < n;i++) {
//		dist = abs(cur.first - c[i].first) + abs(cur.second - c[i].second);
//		if (visited[i] || dist > 1000)
//			continue;
//		visited[i] = 1;
//		bool tf = dfs(c[i]);
//		if (tf)
//			return true;
//	}
//	return false;
//}
//
//int main() {
//	int t, x, y;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		cin >> x >> y;
//		h.first = x, h.second = y;
//		for (int i = 0;i < n;i++) {
//			cin >> x >> y;
//			pii tmp = { x,y };
//			c.emplace_back(tmp);
//		}
//		cin >> x >> y;
//		f.first = x, f.second = y;
//		if (dfs(h))
//			cout << "happy" << endl;
//		else
//			cout << "sad" << endl;
//		c.clear();
//		memset(visited, 0, sizeof(visited));
//	}
//}