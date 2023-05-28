#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

ll q, a, d, x;

ll dp[5000] = {0}; // 0 1 3 6

void fillDp() {
    for (int i = 1; i < 5000; i++) {
        dp[i] = dp[i - 1] + i;
    }
}

int check(ll m) {
    if (x >= (1 + (m - 1) * a + (dp[m - 2]) * d) &&
        x < (1 + m * a + (dp[m - 1]) * d)) {
        return 0;
    }

    if (x < (1 + (m - 1) * a + (dp[m - 2]) * d))
        return -1;

    return 1;
}

void Solution() {
    fillDp();

    cin >> q;
    while (q--) {
        cin >> a >> d >> x;
        int l = 1;
        int r = 5000;
        while (l <= r) {
            ll m = (l + r) / 2;

            if (!check(m)) {
                cout << m << ' ';
                if (m == 1) {
                    cout << x;
                } else {
                    cout << x - (1 + (m - 1) * a + (dp[m - 2]) * d) + 1;
                }
                cout << '\n';
                break;
            } else if (check(m) < 0) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
    }
}

int main() {
    FASTIO
    Solution();
}