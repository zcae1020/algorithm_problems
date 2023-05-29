#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, arr[10000], ans = 1e9;

int getIdx(int cur, int color, int lr) {
    int ret = cur;
    if (lr == 0) {
        for (; ret >= 0; ret--) {
            if (arr[ret] != color) {
                return ret;
            }
        }

        return ret;
    } else {
        for (; ret < n; ret++) {
            if (arr[ret] != color) {
                return ret;
            }
        }
        return ret;
    }
}

void Solution() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 3; j++) {
            if (arr[i] != j) {
                int l = getIdx(i - 1, j, 0), r = getIdx(i + 1, j, 1), lc = j,
                    rc = j, cnt = 0;

                while (lc == rc && r - l - 1 - cnt >= 4) {
                    cnt += r - l - 1 - cnt;
                    lc = l < 0 ? -1 : arr[l];
                    rc = r >= n ? -2 : arr[r];
                    if (l >= 0) {
                        l = getIdx(l, arr[l], 0);
                    }
                    if (r >= 0 && r < n) {
                        r = getIdx(r, arr[r], 1);
                    }
                }

                ans = min(ans, n - cnt);
            }
        }
    }

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}