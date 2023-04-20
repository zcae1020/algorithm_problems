#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, arr[1001][3], dp[1001][3], ans = 1e9;

void Solution() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    for (int f = 0; f < 3; f++) {
        for (int i = 0; i < 3; i++) {
            dp[1][i] = f == i ? arr[1][i] : 1e9;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                int mn = 1e9;
                for (int k = 0; k < 3; k++) {
                    if (j != k)
                        mn = min(mn, dp[i - 1][k]);
                }
                dp[i][j] = mn + arr[i][j];
            }
        }

        for (int l = 0; l < 3; l++) {
            if (f != l) {
                ans = min(ans, dp[n][l]);
            }
        }
    }

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}