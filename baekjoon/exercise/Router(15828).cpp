//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//queue<int> q;
//int N, input;
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> N;
//	while (true) {
//		cin >> input;
//		if (input == -1) break;
//
//		if (input == 0) q.pop();
//		else if (q.size() < N) q.push(input);
//	}
//
//	if (q.empty()) {
//		cout << "empty";
//	}
//	else {
//		while (!q.empty()) {
//			cout << q.front() << ' ';
//			q.pop();
//		}
//	}
//}