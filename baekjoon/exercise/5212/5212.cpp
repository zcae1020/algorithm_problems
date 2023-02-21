#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int R, C;
string MAP[10], NMAP[10];

pii s = {10, 10}, e;

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void Solution() {
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        cin >> MAP[i];
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (MAP[i][j] == '.') {
                NMAP[i].push_back('.');
                continue;
            }

            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
                    cnt++;
                    continue;
                }

                if (MAP[nx][ny] == '.') {
                    cnt++;
                }
            }

            if (cnt > 2) {
                NMAP[i].push_back('.');
                continue;
            }

            NMAP[i].push_back('X');
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (NMAP[i][j] == 'X') {
                s.fs = min(s.fs, i);
                s.sd = min(s.sd, j);

                e.fs = max(e.fs, i);
                e.sd = max(e.sd, j);
            }
        }
    }

    for (int i = s.fs; i <= e.fs; i++) {
        for (int j = s.sd; j <= e.sd; j++) {
            cout << NMAP[i][j];
        }
        cout << '\n';
    }
}

int main() {
    FASTIO
    Solution();
}
