//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define pii pair<int,int>
//
//using namespace std;
//
//int N, M, map[8][8];
//vector<pair<int, pii>> cctv;
//int dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 };
//
//int cantSee(int m[][8]) {
//	int ret = 0;
//	for (int i = 0;i < N;i++)
//		for (int j = 0;j < M;j++)
//			if (!m[i][j])
//				ret++;
//	return ret;
//}
//
//void mcopy(int m1[][8], int m2[][8]) {
//	for (int i = 0;i < N;i++)
//		for (int j = 0;j < M;j++)
//			m1[i][j] = m2[i][j];
//}
//
//void draw(int m[][8], pair<int, pii> c, int type) {
//	//type 0:À§, 1:¿ì, 2:¾Æ·¡ 3:ÁÂ
//	pii cur;
//	switch (c.first) {
//	case 1:
//		cur = c.second;
//		cur.first += dx[type], cur.second += dy[type];
//		while (true) {
//			if (cur.first < 0 || cur.second < 0 || cur.first >= M || cur.second >= N || m[cur.second][cur.first] == 6)
//				break;
//			m[cur.second][cur.first] = 7;
//			cur.first += dx[type], cur.second += dy[type];
//		}
//		break;
//	case 2:
//		cur = c.second;
//		cur.first += dx[type], cur.second += dy[type];
//		while (true) {
//			if (cur.first < 0 || cur.second < 0 || cur.first >= M || cur.second >= N || m[cur.second][cur.first] == 6)
//				break;
//			m[cur.second][cur.first] = 7;
//			cur.first += dx[type], cur.second += dy[type];
//		}
//		cur = c.second;
//		cur.first += dx[type + 2], cur.second += dy[type + 2];
//		while (true) {
//			if (cur.first < 0 || cur.second < 0 || cur.first >= M || cur.second >= N || m[cur.second][cur.first] == 6)
//				break;
//			m[cur.second][cur.first] = 7;
//			cur.first += dx[type + 2], cur.second += dy[type + 2];
//		}
//		break;
//	case 3:
//		for (int i = 0;i < 2;i++) {
//			cur = c.second;
//			cur.first += dx[(type + i) % 4], cur.second += dy[(type + i) % 4];
//			while (true) {
//				if (cur.first < 0 || cur.second < 0 || cur.first >= M || cur.second >= N || m[cur.second][cur.first] == 6)
//					break;
//				m[cur.second][cur.first] = 7;
//				cur.first += dx[(type + i) % 4], cur.second += dy[(type + i) % 4];
//			}
//		}
//		break;
//	case 4:
//		for (int i = 0;i < 3;i++) {
//			cur = c.second;
//			cur.first += dx[(type + i) % 4], cur.second += dy[(type + i) % 4];
//			while (true) {
//				if (cur.first < 0 || cur.second < 0 || cur.first >= M || cur.second >= N || m[cur.second][cur.first] == 6)
//					break;
//				m[cur.second][cur.first] = 7;
//				cur.first += dx[(type + i) % 4], cur.second += dy[(type + i) % 4];
//			}
//		}
//		break;
//	case 5:
//		for (int i = 0;i < 4;i++) {
//			cur = c.second;
//			cur.first += dx[(type + i) % 4], cur.second += dy[(type + i) % 4];
//			while (true) {
//				if (cur.first < 0 || cur.second < 0 || cur.first >= M || cur.second >= N || m[cur.second][cur.first] == 6)
//					break;
//				m[cur.second][cur.first] = 7;
//				cur.first += dx[(type + i) % 4], cur.second += dy[(type + i) % 4];
//			}
//		}
//		break;
//	}
//}
//
//int dfs(int m[][8], int idx) {
//	if (idx == cctv.size())
//		return cantSee(m);
//
//	int cm[8][8];
//	pair<int, pii> cur = cctv[idx];
//	
//	int ret = 1000;
//	switch (cctv[idx].first) {
//	case 1:
//		for (int i = 0;i < 4;i++) {
//			mcopy(cm, m);
//			draw(cm, cctv[idx], i);
//			ret = min(ret, dfs(cm, idx + 1));
//		}
//		break;
//	case 2:
//		for (int i = 0;i < 2;i++) {
//			mcopy(cm, m);
//			draw(cm, cctv[idx], i);
//			ret = min(ret, dfs(cm, idx + 1));
//		}
//		break;
//	case 3:
//		for (int i = 0;i < 4;i++) {
//			mcopy(cm, m);
//			draw(cm, cctv[idx], i);
//			ret = min(ret, dfs(cm, idx + 1));
//		}
//		break;
//	case 4:
//		for (int i = 0;i < 4;i++) {
//			mcopy(cm, m);
//			draw(cm, cctv[idx], i);
//			ret = min(ret, dfs(cm, idx + 1));
//		}
//		break;
//	case 5:
//		mcopy(cm, m);
//		draw(cm, cctv[idx], 0);
//		ret = min(ret, dfs(cm, idx + 1));
//	}
//	return ret;
//}
//
//int main() {
//	cin >> N >> M;
//	for (int i = 0;i < N;i++) {
//		for (int j = 0;j < M;j++) {
//			cin >> map[i][j];
//			if (map[i][j] && map[i][j] != 6) {
//				pii p = { j,i };
//				cctv.emplace_back(map[i][j], p);
//			}
//		}
//	}
//
//	cout << dfs(map, 0);
//}