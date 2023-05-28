#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, m;
string MAP[1003];

bool visited[1003][1003] = {0};
int turnMAP[1003][1003] = {0};

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

pii a, b;

pii next(pii cur) {
    if (cur.fs == 0) {
        if (cur.sd == m - 1) {
            return {cur.fs + 1, cur.sd};
        }
        return {cur.fs, cur.sd + 1};
    }
    if (cur.fs == n - 1) {
        if (cur.sd == 0) {
            return {cur.fs - 1, cur.sd};
        }
        return {cur.fs, cur.sd - 1};
    }
    if (cur.sd == 0) {
        if (cur.fs == 0) {
            return {cur.fs, cur.sd + 1};
        }
        return {cur.fs - 1, cur.sd};
    }
    if (cur.sd == m - 1) {
        if (cur.fs == n - 1) {
            return {cur.fs, cur.sd - 1};
        }
        return {cur.fs + 1, cur.sd};
    }
}

pii getTempb(int t) {
    pii ret = b;
    for (int i = 0; i < t; i++) {
        ret = next(ret);
    }
    return ret;
}

bool check(int t) {
    pii tmpb = getTempb(t);
    memset(turnMAP, 0, sizeof(turnMAP));
    int turnn = -1; //-1: 짝, 1: 홀
    int countt = -1;

    queue<pair<pii, int>> q;
    q.push({a, 0});
    while (!q.empty()) {
        pii cur = q.front().fs;
        int cnt = q.front().sd;
        q.pop();

        if (t == countt) {
            break;
        }

        if (countt != cnt) {
            turnn = turnn == -1 ? 1 : -1;
            countt = cnt;
        }

        for (int i = 0; i < 4; i++) {
            pii next = {cur.fs + dx[i], cur.sd + dy[i]};
            if (next.fs >= 0 && next.sd >= 0 && next.fs < n && next.sd < m &&
                !(turnMAP[next.fs][next.sd] == 2 ||
                  turnMAP[next.fs][next.sd] == turnn) &&
                MAP[next.fs][next.sd] != 'G') {
                q.push({next, cnt + 1});
                turnMAP[next.fs][next.sd] =
                    turnMAP[next.fs][next.sd] == 0
                        ? turnn
                        : (turnMAP[next.fs][next.sd] != turnn ? 2 : turnn);
            }
        }
    }

    return ((turnMAP[tmpb.fs][tmpb.sd] == -1 ||
             turnMAP[tmpb.fs][tmpb.sd] == 2) &&
            t % 2 == 0) ||
           ((turnMAP[tmpb.fs][tmpb.sd] == 1 ||
             turnMAP[tmpb.fs][tmpb.sd] == 2) &&
            t % 2 == 1);
}

void Solution() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> MAP[i];
        for (int j = 0; j < m; j++) {
            if (MAP[i][j] == 'A') {
                a = {i, j};
            }
            if (MAP[i][j] == 'B') {
                b = {i, j};
            }
        }
    }

    for (int i = 1; i < 5000; i++) {
        if (check(i)) {
            cout << i;
            return;
        }
    }

    cout << -1;
}

int main() {
    FASTIO
    Solution();
}