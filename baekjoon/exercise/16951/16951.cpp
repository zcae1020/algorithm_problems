#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxn = 1000;

int n, k, ans = maxn, arr[maxn];
bool visited[maxn];

void Solution() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] - i * k < 1 || visited[i]) {
            continue;
        }

        int cnt = 0;
        for (int j = 0; j < n; j++) {
            int mx = max(i, j), mn = min(i, j);
            if (arr[mx] - arr[mn] != k * (mx - mn)) {
                cnt++;
            } else {
                visited[j] = true;
            }
        }

        ans = min(ans, cnt);
    }

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}
