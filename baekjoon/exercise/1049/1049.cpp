#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, m, ans;
pii mn = {1e5, 1e5};

void Solution() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        mn.fs = min(mn.fs, a);
        mn.sd = min(mn.sd, b);
    }

    if (mn.fs >= mn.sd * 6) {
        ans = mn.sd * n;
    } else {
        ans = mn.fs * (n / 6);
        if (n % 6) {
            ans += min(mn.fs, mn.sd * (n % 6));
        }
    }

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}