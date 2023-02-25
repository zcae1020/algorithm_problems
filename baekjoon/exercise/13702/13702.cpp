#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxn = 1e4;

int n, k, ju[maxn];

bool check(int val) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += ju[i] / val;
    }

    return cnt >= k;
}

void Solution() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> ju[i];
    }

    ll l = 0, r = INT_MAX, m, ans = 0;
    while (l <= r) {
        m = (l + r) / 2;
        if (check(m)) {
            l = m + 1;
            ans = max(ans, m);
        } else {
            r = m - 1;
        }
    }

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}