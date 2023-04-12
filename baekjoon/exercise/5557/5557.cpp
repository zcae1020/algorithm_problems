#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, arr[101];
llu dp[101][21];

void Solution() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0][arr[0]] = 1;

    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (j - arr[i] >= 0) {
                dp[i][j - arr[i]] += dp[i - 1][j];
            }
            if (j + arr[i] <= 20) {
                dp[i][j + arr[i]] += dp[i - 1][j];
            }
        }
    }

    cout << dp[n - 2][arr[n - 1]];
}

int main() {
    FASTIO
    Solution();
}