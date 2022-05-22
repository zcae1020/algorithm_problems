#include <iostream>
#include <climits>

using namespace std;

int n, k, arr[10000];

bool makeN(int m) {
	int line = 0;

	for (int i = 0; i < k; i++) line += arr[i] / m;

	if (line >= n) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin >> k >> n;
	for (int i = 0; i < k; i++) cin >> arr[i];

	long long l = 1, r = INT_MAX, m;
	while (l <= r) {
		m = (l + r) / 2;
		if (makeN(m)) l = m + 1;
		else r = m - 1;
	}
	cout << r;
}