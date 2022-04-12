//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int person[9], visited[9];
//vector<int> ans;
//
//void dfs(int sum, int cnt, int idx) {
//	if (sum == 100 && cnt == 7) {
//		for (int i = 0; i < 9; i++) {
//			if (visited[i])
//				ans.push_back(person[i]);
//		}
//		sort(ans.begin(), ans.end());
//		for (auto i : ans)
//			cout << i << endl;
//		exit(0);
//	}
//
//	if (cnt == 7)
//		return;
//
//	for (int i = idx; i < 9; i++) {
//		if (visited[i]) continue;
//
//		if (sum + person[i] > 100) continue;
//
//		visited[i] = true;
//		dfs(sum + person[i], cnt + 1, i + 1);
//		visited[i] = false;
//	}
//}
//
//int main() {
//	for (int i = 0; i < 9; i++)
//		cin >> person[i];
//
//	dfs(0, 0, 0);
//}