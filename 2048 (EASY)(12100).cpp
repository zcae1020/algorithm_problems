//#include <iostream>
//#include <algorithm>
//#include <vector>
//#define pii pair<int,int>
//
//using namespace std;
//
//vector<int> makeV2(vector<int> v1) {
//	vector<int> ret;
//	vector<int> visited(20, 0);
//	if (v1.empty())
//		return ret;
//	for (int i = 0;i < v1.size() - 1;i++) {
//		if (visited[i])
//			continue;
//		if (v1[i] == v1[i + 1]) {
//			ret.emplace_back(2 * v1[i]);
//			visited[i] = visited[i + 1] = 1;
//		}
//		else {
//			ret.emplace_back(v1[i]);
//			visited[i] = 1;
//		}
//	}
//	if (!visited[v1.size() - 1])
//		ret.emplace_back(v1[v1.size() - 1]);
//	return ret;
//}
//
//int dfs(int N, int ori[][20], int type, int m) { //type 0:À§, 1:¿À, 2:¾Æ·¡, 3:¿Þ
//
//	vector<int> v1;
//	vector<int> visited(20, 0);
//	int map0[20][20], map1[20][20], map2[20][20], map3[20][20];
//	for (int i = 0;i < N;i++) {
//		for (int j = 0;j < N;j++) {
//			map0[i][j] = ori[i][j];
//			map1[i][j] = ori[i][j];
//			map2[i][j] = ori[i][j];
//			map3[i][j] = ori[i][j];
//		}
//	}
//	
//	switch (type) {
//	case 0:
//		for (int i = 0;i < N;i++) {
//			v1.clear();
//			for (int j = 0;j < N;j++) {
//				if (map0[j][i])
//					v1.emplace_back(map0[j][i]);
//			}
//			vector<int> v2 = makeV2(v1);
//			for (int j = 0;j < N;j++)
//				map0[j][i] = 0;
//			if (!v2.empty())
//				for (int j = 0;j < v2.size();j++)
//					map0[j][i] = v2[j];
//		}
//		break;
//
//	case 1:
//		for (int i = 0;i < N;i++) {
//			v1.clear();
//			for (int j = N - 1;j >= 0;j--) {
//				if (map1[i][j])
//					v1.emplace_back(map1[i][j]);
//			}
//			vector<int> v2 = makeV2(v1);
//			for (int j = 0;j < N;j++)
//				map1[i][j] = 0;
//			if (!v2.empty())
//				for (int j = 0;j < v2.size();j++)
//					map1[i][N - 1 - j] = v2[j];
//		}
//		break;
//
//	case 2:
//		for (int i = 0;i < N;i++) {
//			v1.clear();
//			for (int j = N - 1;j >= 0;j--) {
//				if (map2[j][i])
//					v1.emplace_back(map2[j][i]);
//			}
//			vector<int> v2 = makeV2(v1);
//			for (int j = 0;j < N;j++)
//				map2[j][i] = 0;
//			if (!v2.empty())
//				for (int j = 0;j < v2.size();j++)
//					map2[N - 1 - j][i] = v2[j];
//		}
//		break;
//
//	case 3:
//		for (int i = 0;i < N;i++) {
//			v1.clear();
//			for (int j = 0;j < N;j++) {
//				if (map3[i][j])
//					v1.emplace_back(map3[i][j]);
//			}
//			vector<int> v2 = makeV2(v1);
//			for (int j = 0;j < N;j++)
//				map3[i][j] = 0;
//			if (!v2.empty())
//				for (int j = 0;j < v2.size();j++)
//					map3[i][j] = v2[j];
//		}
//		break;
//	}
//
//	if (m == 4) {
//		int mx = 0;
//		for (int i = 0;i < N;i++) {
//			for (int j = 0;j < N;j++) {
//				switch (type) {
//				case 0:
//					mx = max(mx, map0[i][j]);
//					break;
//				case 1:
//					mx = max(mx, map1[i][j]);
//					break;
//				case 2:
//					mx = max(mx, map2[i][j]);
//					break;
//				case 3:
//					mx = max(mx, map3[i][j]);
//					break;
//				}
//			}
//		}
//		return mx;
//	}
//
//	int mx = 0;
//	for (int i = 0;i < 4;i++) {
//		switch (type) {
//		case 0:
//			mx = max(mx, dfs(N, map0, i, m + 1));
//			break;
//		case 1:
//			mx = max(mx, dfs(N, map1, i, m + 1));
//			break;
//		case 2:
//			mx = max(mx, dfs(N, map2, i, m + 1));
//			break;
//		case 3:
//			mx = max(mx, dfs(N, map3, i, m + 1));
//			break;
//		}
//	}
//	return mx;
//}
//
//int main() {
//	int N, map[20][20];
//	cin >> N;
//	for (int i = 0;i < N;i++)
//		for (int j = 0;j < N;j++)
//			cin >> map[i][j];
//
//	int mx = 0;
//	for (int i = 0;i < 4;i++) {
//		mx = max(mx, dfs(N, map, i, 0));
//	}
//	cout << mx;
//}