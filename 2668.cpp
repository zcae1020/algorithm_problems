//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <cstring>
//#include <vector>
//
//using namespace std;
//
//int N, input[101], visited[101];
//vector<int> res;
//
//void dfs(int origin, int cur) {
//	if (!visited[cur]) {
//		visited[cur] = origin;
//		dfs(origin, input[cur]);
//	}
//	else if (origin == cur)
//		res.push_back(origin);
//}
//
//int main() {
//	scanf("%d", &N);
//	for (int i = 1;i <= N;i++)
//		scanf("%d", &input[i]);
//
//	for (int i = 1;i <= N;i++){
//		memset(visited, 0, sizeof(visited));
//		dfs(i, i);
//	}
//
//	int s = res.size();
//	printf("%d\n", s);
//	for (int i = 0;i < s;i++)
//		printf("%d\n", res[i]);
//}