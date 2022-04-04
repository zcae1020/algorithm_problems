#include <iostream>
#include <vector>

using namespace std;

int N, K, tk, T;
vector<int> A, R;

void Input() {
	cin >> N >> K;
	A.resize(2 * N), R.resize(2 * N);
	for (int i = 0; i < 2 * N; i++) cin >> A[i];
}

void moveBelt() {
	int tmp = A[2 * N - 1];

	for (int i = 2 * N - 1; i > 0; i--) {
		A[i] = A[i - 1];
		if (i < N) R[i] = R[i - 1];
	}

	A[0] = tmp;
	R[0] = 0;
}

void moveRobot() {
	R[N - 1] = 0;
	for (int i = N - 2; i > 0; i--) {
		if (R[i] == 1 && R[i + 1] == 0 && A[i + 1]) {

			R[i] = 0;
			R[i + 1] = 1;
			A[i + 1]--;

			if (A[i + 1] == 0) tk++;

		}
	}
}

void Solution() {
	while (tk < K) {
		T++;
		moveBelt();
		moveRobot();
		if (A[0]) {
			A[0]--;
			R[0] = 1;
			if (A[0] == 0) tk++;
		}
	}
	cout << T;
}

int main() {
	ios::sync_with_stdio(0);
	Input();
	Solution();
}