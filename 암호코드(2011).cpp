#include <iostream>
#include <string>
#define rest 1000000

using namespace std;

string input;
int dp[5001];

int main() {
	cin >> input;
	if (input[0] == '0') {
		cout << 0;
		exit(0);
	}
	dp[0] = 1;
	for (int i = 1;i < input.size();i++) {
		int num = (input[i - 1] - '0') * 10 + input[i] - '0';
		if (input[i] == '0') { // (0~9)0
			if (num > 20 || num == 0) {
				cout << 0;
				exit(0);
			}
			dp[i] = dp[i - 1];
		}
		else if (num > 10 && num <= 26) {
			if (i + 1 != input.size() && input[i + 1] == '0') // ex)110
				dp[i] = dp[i - 1];
			else if (i == 1)
				dp[i] = 2;
			else
				dp[i] = dp[i - 1] + dp[i - 2];
		}
		else
			dp[i] = dp[i - 1];
		dp[i] %= rest;
	}
	cout << dp[input.size() - 1];
}