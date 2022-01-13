//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <queue>
//
//using namespace std;
//
//struct cmp {
//	bool operator()(int a, int b) {
//		return a > b;
//	}
//};
//
//queue<int> qx;
//queue<int> qy;
//priority_queue<int, vector<int>, cmp> res;
//
//int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
//int N, map[27][27], visited[27][27];
//
//int bfs(int x, int y) {
//	int ret = 1, curx, cury, nx, ny;
//	qx.push(x);
//	qy.push(y);
//	while (!qx.empty()) {
//		curx = qx.front(), cury = qy.front();
//		qx.pop(), qy.pop();
//		for (int i = 0;i < 4;i++) {
//			nx = curx + dx[i], ny = cury + dy[i];
//			if (!visited[ny][nx] && map[ny][nx]) {
//				ret++;
//				qx.push(nx);
//				qy.push(ny);
//				visited[ny][nx] = 1;
//			}
//		}
//	}
//	return ret;
//}
//
//int main() {
//	scanf("%d", &N);
//	char str[30];
//	for (int i = 1;i <= N;i++) {
//		scanf("%s", str);
//		for (int j = 1;j <= N;j++) {
//			map[i][j] = str[j - 1] - '0';
//			visited[i][j] = 0;
//		}
//	}
//
//	for (int i = 0;i <= N + 1;i++) {
//		map[0][i] = 0;
//		map[i][0] = 0;
//		map[N + 1][i] = 0;
//		map[i][N + 1] = 0;
//		visited[i][0] = 1;
//		visited[0][i] = 1;
//		visited[N + 1][i] = 1;
//		visited[i][N + 1] = 1;
//	}
//	
//	for (int i = 1;i <= N;i++) {
//		for (int j = 1;j <= N;j++) {
//			if (visited[i][j])
//				continue;
//
//			visited[i][j] = 1;
//			if (map[i][j])
//				res.push(bfs(j, i));
//		}
//	}
//
//	printf("%d\n", res.size());
//	while (!res.empty()) {
//		printf("%d\n", res.top());
//		res.pop();
//	}
//}