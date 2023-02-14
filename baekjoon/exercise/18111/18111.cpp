#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

ll sum, ans = LONG_LONG_MAX;
int N, M, B, mx, mn = 300, cnt[257], height;

void Solution() {
    cin >> N >> M >> B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            mx = max(mx, x);
            mn = min(mn, x);
            sum += x;

            cnt[x]++;
        }
    }

    for (int i = mn; i <= mx && i * N * M <= sum + B; i++) {
        int t = 0;
        for (int j = 0; j <= 256; j++) {
            if (i > j) {
                t += (i - j) * cnt[j];
            } else if (i < j) {
                t += 2 * (j - i) * cnt[j];
            }
        }

        if (ans > t) {
            ans = t;
            height = i;
        } else if (ans == t) {
            height = max(height, i);
        }
    }

    cout << ans << ' ' << height;
}

int main() {
    FASTIO
    Solution();
}