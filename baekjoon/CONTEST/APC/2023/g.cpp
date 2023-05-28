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

ll fillDp(int cur, int cnt) {
    if (!(cnt >= arr[cur][0] && cnt <= arr[cur][1])) {
        return dp[cur][cnt] = 0;
    }

    if (cur == n - 1) {
        return dp[cur][cnt] = 1;
    }

    if (dp[cur][cnt]) {
        return dp[cur][cnt];
    }

    for (int i = cnt - k; i <= cnt + k; i++) {
        dp[cur][cnt] += fillDp(cur + 1, i);
        dp[cur][cnt] %= mod;
    }

    return dp[cur][cnt];
}

void Solution() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    for (int i = arr[0][0]; i <= arr[0][1]; i++) {
        ans += fillDp(0, i);
        ans %= mod;
    }

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}