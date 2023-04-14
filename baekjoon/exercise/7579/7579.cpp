#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int N, M, dp[100][10000], sum;
pii A[100];

void Solution() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> A[i].fs;
    }
    for (int i = 0; i < N; i++) {
        cin >> A[i].sd;
        sum += A[i].sd;
    }

    for (int i = A[0].sd; i <= sum; i++) {
        dp[0][i] = A[0].fs;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= A[i].sd) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - A[i].sd] + A[i].fs);
            }
        }
    }

    for (int i = 0; i <= sum; i++) {
        if (dp[N - 1][i] >= M) {
            cout << i;
            return;
        }
    }
}

int main() {
    FASTIO
    Solution();
}