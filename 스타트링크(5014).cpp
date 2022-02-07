//#include <iostream>
//#include <algorithm>
//#include <queue>
//#define pii pair<int,int>
//#define MAX 2000000009
//
//using namespace std;
//
//bool visited[1000006] = { 0 };
//int f, s, g, ud[2];
//
//int main() {
//	cin >> f >> s >> g >> ud[0] >> ud[1];
//	queue<pii> q;
//	q.push({ 0,s });
//	visited[s] = 1;
//	while (!q.empty()) {
//		pii cur = q.front();
//		q.pop();
//		if (cur.second == g) {
//			cout << cur.first;
//			return 0;
//		}
//		for (int i = 0;i < 2;i++) {
//			int next;
//			if (!i)
//				next = cur.second + ud[i];
//			else
//				next = cur.second - ud[i]; 
//			if (next<1 || next>f || visited[next])
//				continue;
//			q.push({ cur.first + 1,next });
//			visited[next] = 1;
//		}
//	}
//	cout << "use the stairs";
//}