#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[201], dp[201];

int main() {
	arr[0] = 0, dp[0] = 0;
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> arr[i];

	for (int i = 1;i <= n;i++) {
		int mx = 0;
		for (int j = i - 1;j >= 0;j--) {
			if (arr[i] > arr[j])
				mx = max(mx, dp[j]);
		}
		dp[i] = mx + 1;
	}
	
	int mx = 0;
	for (int i = 1;i <= n;i++) {
		mx = max(mx, dp[i]);
	}
	cout << n - mx;
}