#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxn = 1001;

int N, M, arr[maxn][maxn], dp[maxn][maxn];

void getAns() {
    for (int i = min(N, M); i >= 0; i--) {
        for (int j = 1; j + i - 1 <= N; j++) {
            for (int k = 1; k + i - 1 <= M; k++) {
                int x = j + i - 1, y = k + i - 1;
                if (i * i ==
                    dp[x][y] - dp[x][k - 1] - dp[j - 1][y] + dp[j - 1][k - 1]) {
                    cout << i << '\n';
                    return;
                }
            }
        }
    }
}

void Solution() {
    while (true) {
        cin >> N >> M;
        memset(dp, 0, sizeof(dp));
        if (N == 0 && M == 0) {
            break;
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> arr[i][j];
                dp[i][j] =
                    dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
            }
        }

        getAns();
    }
}

int main() {
    FASTIO
    Solution();
}