#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

// e

using namespace std;

const int maxn = 500;
int N, Q, M[maxn][maxn], parr2[maxn][maxn], dp[maxn][maxn][maxn];
// parr : 가로, parr: 세로, dp[L크기][x][y]

void getParr2() {
    for (int i = 0; i < N; i++) {
        int parr[maxn][maxn];
        for (int j = N - 1; j >= 0; j--) {
            if (j == N - 1) {
                parr[i][j] = M[i][j];
                continue;
            }
            parr[i][j] = M[i][j] + parr[i][j + 1];
        }
        for (int j = 0; j < N; j++) {
            if (i == 0) {
                parr2[i][j] = parr[i][j];
                continue;
            }
            parr2[i][j] = min(parr[i][j], parr2[i - 1][j]);
        }
    }
}

void Solution() {
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> M[i][j];
        }
    }

    for(int i=N-1;i>=0;i--) {
        dp[0][i][1] = i == N - 1 ? M[0][i] : dp[0][i + 1][1] + M[0][i];
    }

    for (int i = 0; i < N; i++) {          // x
        for (int j = N - 1; j >= 0; j--) { // y
            for (int l = i; l > 0; l--) {
                if (j == N - 1) {
                    dp[i][j][l] = min(dp[i - l][j][1], M[i][j]);
                } else {
                    dp[i][j][l] =
                        min(dp[i - l][j][1], dp[i][j + 1][l] + M[i][j]);
                }
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        int x, y, l;
        cin >> x >> y >> l;
        x--, y--;
        l=l?l:1;
        cout << dp[x][y][l] << '\n';
    }
}

int main() {
    FASTIO
    Solution();
}
