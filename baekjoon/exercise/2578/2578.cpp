#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int n = 5;

int board[n][n], a, ans, bingo, cnt;
bool visited[n][n];

pii findPos(int num) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == num) {
                return {i, j};
            }
        }
    }
}

void Solution() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    while (bingo < 3) {
        cin >> a;
        ans++;
        pii p = findPos(a);
        visited[p.fs][p.sd] = true;

        if (p.fs == 4 - p.sd) {
            cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += visited[i][4 - i];
            }
            bingo += cnt == 5;
        }
        if (p.fs == p.sd) {
            cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += visited[i][i];
            }
            bingo += cnt == 5;
        }

        cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += visited[p.fs][i];
        }
        bingo += cnt == 5;

        cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += visited[i][p.sd];
        }
        bingo += cnt == 5;
    }

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}
