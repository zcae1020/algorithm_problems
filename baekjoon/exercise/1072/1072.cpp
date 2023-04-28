#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

ll x, y, ans = 1e9;

void Solution() {
    cin >> x >> y;
    if (y * 100 / x >= 99) {
        cout << -1;
        return;
    }
    ll l = 0, r = 1e9, m;
    while (l <= r) {
        m = (l + r) / 2;
        if (((y + m) * 100) / (x + m) > (y * 100) / x) {
            ans = min(ans, m);
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans;
}

int main() {
    FASTIO
    Solution();
}