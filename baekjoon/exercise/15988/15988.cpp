#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxn = 1e6 + 1;
const int mod = 1e9 + 9;

int t, n;
ll dp[maxn];

void fillDp() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < maxn; i++) {
        dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % mod;
    }
}

void Solution() {
    fillDp();
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
}

int main() {
    FASTIO
    Solution();
}