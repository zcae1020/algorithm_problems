#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, m, h[500], lmx[500], rmx[500], ans;

void Solution() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> h[i];
    }

    lmx[0] = h[0];
    for (int i = 1; i < m; i++) {
        lmx[i] = max(lmx[i - 1], h[i]);
    }

    rmx[m - 1] = h[m - 1];
    for (int i = m - 2; i >= 0; i--) {
        rmx[i] = max(rmx[i + 1], h[i]);
    }

    for (int i = 1; i < m - 1; i++) {
        int val = min(lmx[i - 1], rmx[i + 1]) - h[i];
        if (val > 0) {
            ans += val;
        }
    }

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}