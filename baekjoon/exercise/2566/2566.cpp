#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, mx = -1;
pii ans;

void Solution() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> n;
            if (mx < n) {
                mx = n;
                ans = {i, j};
            }
        }
    }

    cout << mx << '\n' << ans.fs << ' ' << ans.sd;
}

int main() {
    FASTIO
    Solution();
}