//#include <iostream>
//#include <algorithm>
//#include <vector>
//#define pii pair<int,int>
//
//using namespace std;
//
//int N, M, dp[50][50];
//bool visited[50][50];
//char board[51][51];
//
//int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
//
//int dfs(pii cur) {
//	if (dp[cur.second][cur.first] != -1)
//		return dp[cur.second][cur.first];
//
//	int ret = 0;
//	int speed = board[cur.second][cur.first] - '0';
//	pii next;
//
//	for (int i = 0; i < 4; i++) {
//		next.first = cur.first + dx[i] * speed, next.second = cur.second + dy[i] * speed;
//
//		if (next.first < 0 || next.second < 0 || next.first >= M || next.second >= N || board[next.second][next.first] == 'H')
//			continue;
//
//		if (visited[next.second][next.first]) {
//			cout << -1;
//			exit(0);
//		}
//
//		visited[cur.second][cur.first] = true;
//		ret = max(ret, dfs(next));
//		visited[cur.second][cur.first] = false;
//	}
//
//	ret++;
//	return dp[cur.second][cur.first] = ret;
//}
//
//int main() {
//	cin >> N >> M;
//	for (int i = 0; i < N; i++)
//		cin >> board[i];
//
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//			dp[i][j] = -1;
//
//	visited[0][0] = true;
//	cout << dfs(make_pair(0, 0));
//}