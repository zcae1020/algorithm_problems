#include <iostream>

using namespace std;

int N, K;

int main() {
	cin >> N >> K;
	int comp = K * (K + 1) / 2, sub = N - comp;
	if (sub < 0)
		cout << -1;
	else if (sub == 0 || !(sub%K))
		cout << K - 1;
	else
		cout << K;
}