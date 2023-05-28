#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int mod = 1e9 + 7;

int n, k, arr[3003][2];
ll dp[3003][3003], ans;

void Solution() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = arr[i][0]; j <= arr[i][1]; j++) {
            if (i == n - 1) {
                dp[i][j] = 1;
            } else {
                if (j == arr[i][0]) {
                    for (int l = max(j - k, 0); l <= j + k; l++) {
                        dp[i][j] = (dp[i][j] + dp[i + 1][l]) % mod;
                    }
                } else {
                    dp[i][j] = (dp[i][j - 1] -
                                ((j - k - 1 >= 0) ? dp[i + 1][j - k - 1] : 0) +
                                ((j + k <= 3000) ? dp[i + 1][j + k] : 0)) %
                               mod;
                }
            }
        }
    }

    for (int i = arr[0][0]; i <= arr[0][1]; i++) {
        ans = (ans + dp[0][i]) % mod;
    }

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}