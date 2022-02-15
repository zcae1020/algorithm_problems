#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string a, b;
int dp[4003][4003] = { 0 }, mx = 0;

int main() {
	cin >> a >> b;
	for (int i = 1;i <= a.size();i++) {
		for (int j = 1;j <= b.size();j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				mx = max(mx, dp[i][j]);
			}
		}
	}
	cout << mx;
}