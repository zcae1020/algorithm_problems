//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <queue>
//
//using namespace std;
//
//vector<int> v[51], res;
//int score[51], visited[51], N;
//
//bool isComplete() {
//	for (int i = 1;i <= N;i++)
//		if (!visited[i])
//			return false;
//	return true;
//}
//
//int bfs(int index) {
//	queue<int> q;
//	int myScore = 0, ci, ni;
//	q.push(index);
//	visited[index] = 1;
//	while (!q.empty()) {
//		ci = q.front();
//		q.pop();
//		for (int i = 0;i < v[ci].size();i++) {
//			ni = v[ci][i];
//			if (!visited[ni]) {
//				visited[ni] = visited[ci] + 1;
//				q.push(ni);
//			}
//		}
//		myScore = visited[ci];
//		if (isComplete())
//			break;
//	}
//	score[index] = myScore;
//	return myScore;
//}
//
//int main() {
//	int a, b, tmp, mn = 100;
//	cin >> N;
//	while (true) {
//		cin >> a >> b;
//		if (a == -1 && b == -1)
//			break;
//		v[a].push_back(b);
//		v[b].push_back(a);	
//	}
//	
//	for (int i = 1;i <= N;i++) {
//		memset(visited, 0, sizeof(visited));
//		tmp = bfs(i);
//		if (tmp < mn)
//			mn = tmp;
//	}
//	cout << mn << ' ';
//	for (int i = 1;i <= N;i++) {
//		if (score[i] == mn)
//			res.push_back(i);
//	}
//	cout << res.size() << '\n';
//	for (int i = 0;i < res.size();i++)
//		cout << res[i] << ' ';
//}