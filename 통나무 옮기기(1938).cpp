//#include <iostream>
//#include <queue>
//#define pii pair<int,int>
//
//using namespace std;
//
//struct tree {
//	pii t[3];
//	int d;
//	int cnt = 0;
//}b, e;
//
//int n, visited[2][50][50];
//char map[50][51];
//pii tb[3], te[3];
//int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,-1,1,-1,1 };
//
//void Input() {
//	int bn, en;
//	bn = en = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> map[i];
//		for (int j = 0; j < n; j++) {
//			if (map[i][j] == 'B') tb[bn++] = make_pair(j, i);
//			if (map[i][j] == 'E') te[en++] = make_pair(j, i);
//		}
//	}
//
//	for (int i = 0; i < 3; i++) {
//		b.t[i] = tb[i];
//		e.t[i] = te[i];
//	}
//
//	if (tb[1].first + 1 == tb[2].first)b.d = 0;
//	else b.d = 1;
//
//	if (te[1].first + 1 == te[2].first)e.d = 0;
//	else e.d = 1;
//}
//
//bool equallE(struct tree cur) {
//	for (int i = 0; i < 3; i++)
//		if (e.t[i] != cur.t[i]) return false;
//	if (e.d != cur.d) return false;
//	return true;
//}
//
//void BFS() {
//	int flag;
//	queue<struct tree> q;
//	q.push(b);
//	visited[b.d][b.t[1].second][b.t[1].first] = 1;
//	while (!q.empty()) {
//		struct tree cur = q.front();
//		q.pop();
//
//		if (equallE(cur)) {
//			cout << cur.cnt;
//			return;
//		}
//
//		for (int i = 0; i < 4; i++) {
//			flag = 1;
//			for (int j = 0; j < 3; j++) {
//				int nx = cur.t[j].first + dx[i], ny = cur.t[j].second + dy[i];
//				if (nx < 0 || ny < 0 || nx >= n || ny >= n || map[ny][nx] == '1' || (j == 1 && visited[cur.d][ny][nx])) {
//					flag = 0;
//					break;
//				}
//			}
//			if (flag) {
//				for (int j = 0; j < 3; j++)
//					cur.t[j].first += dx[i], cur.t[j].second += dy[i];
//				visited[cur.d][cur.t[1].second][cur.t[1].first] = 1;
//				cur.cnt++;
//				q.push(cur);
//				cur.cnt--;
//				for (int j = 0; j < 3; j++)
//					cur.t[j].first -= dx[i], cur.t[j].second -= dy[i];
//			}
//		}
//
//		flag = 1;
//		cur.d = cur.d == 0 ? 1 : 0;
//		if (visited[cur.d][cur.t[1].second][cur.t[1].first]) continue;
//
//		for (int i = 0; i < 8; i++) {
//			int nx = cur.t[1].first + dx[i], ny = cur.t[1].second + dy[i];
//			if (nx < 0 || ny < 0 || nx >= n || ny >= n || map[ny][nx] == '1') {
//				flag = 0;
//				break;
//			}
//		}
//		if (flag) {
//			if (cur.d) {
//				cur.t[0] = make_pair(cur.t[1].first, cur.t[1].second - 1);
//				cur.t[2] = make_pair(cur.t[1].first, cur.t[1].second + 1);
//			}
//			else {
//				cur.t[0] = make_pair(cur.t[1].first - 1, cur.t[1].second);
//				cur.t[2] = make_pair(cur.t[1].first + 1, cur.t[1].second);
//			}
//			cur.cnt++;
//			visited[cur.d][cur.t[1].second][cur.t[1].first] = 1;
//			q.push(cur);
//		}
//	}
//	cout << 0;
//}
//
//int main() {
//	Input();
//	BFS();
//}