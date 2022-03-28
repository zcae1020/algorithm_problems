#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int N, input;

int main() {
	cin >> N;
	while (true) {
		cin >> input;
		if (input == -1) break;

		if (input == 0) q.pop();
		else if (q.size() < N) q.push(input);
	}

	if (q.empty()) {
		cout << "empty";
	}
	else {
		while (!q.empty()) {
			cout << q.front() << ' ';
			q.pop();
		}
	}
}