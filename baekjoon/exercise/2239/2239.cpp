#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

string MAP[9];

map<int, bool> getNum(int x, int y) {
    map<int, bool> m;
    for (int i = 0; i < 9; i++) {
        if (MAP[x][i] != '0') {
            m[MAP[x][i] - '0'] = true;
        }
        if (MAP[i][y] != '0') {
            m[MAP[i][y] - '0'] = true;
        }
    }

    for (int i = 3 * (x / 3); i < 3 * (x / 3 + 1); i++) {
        for (int j = 3 * (y / 3); j < 3 * (y / 3 + 1); j++) {
            if (MAP[i][j] != '0') {
                m[MAP[i][j] - '0'] = true;
            }
        }
    }

    return m;
}

bool dfs(int x, int y) {
    for (int i = y; i < 9; i++) {
        if (MAP[x][i] == '0') {
            map<int, bool> m = getNum(x, i);
            int mcnt = m.size();
            int cnt = 0;
            if (mcnt == 9)
                return false;
            for (int k = 1; k <= 9; k++) {
                if (!m[k]) {
                    cnt++;
                    MAP[x][i] = k + '0';
                    if (dfs(x, i + 1)) {
                        return true;
                    }
                    MAP[x][i] = '0';
                }
            }
            if (cnt == 9 - mcnt)
                return false;
        }
    }

    for (int i = x + 1; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (MAP[i][j] == '0') {
                map<int, bool> m = getNum(i, j);
                int mcnt = m.size();
                int cnt = 0;
                if (mcnt == 9)
                    return false;
                for (int k = 1; k <= 9; k++) {
                    if (!m[k]) {
                        cnt++;
                        MAP[i][j] = k + '0';
                        if (dfs(i, j + 1)) {
                            return true;
                        }
                        MAP[i][j] = '0';
                    }
                }
                if (cnt == 9 - mcnt)
                    return false;
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (MAP[i][j] == '0') {
                return false;
            }
        }
    }

    return true;
}

void Solution() {
    for (int i = 0; i < 9; i++) {
        cin >> MAP[i];
    }

    dfs(0, 0);

    for (int i = 0; i < 9; i++) {
        cout << MAP[i] << '\n';
    }
}

int main() {
    FASTIO
    Solution();
}