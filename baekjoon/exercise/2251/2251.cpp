#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int maxLiter[3], liter[3];
set<int> s;
map<vector<int>, bool> visited;

void dfs() {
    vector<int> origin;

    for (int i = 0; i < 3; i++) {
        origin.push_back(liter[i]);
    }

    visited[origin] = true;

    if (origin[0] == 0) {
        s.insert(origin[2]);
    }

    for (int i = 0; i < 3; i++) {
        if (origin[i] == 0)
            continue;
        for (int j = 0; j < 3; j++) {
            int remain = maxLiter[j] - origin[j];
            if (remain == 0 || i == j)
                continue;

            if (remain >= origin[i]) {
                liter[j] += origin[i];
                liter[i] = 0;
            } else {
                liter[j] = maxLiter[j];
                liter[i] -= remain;
            }

            vector<int> current;
            for (int k = 0; k < 3; k++) {
                current.push_back(liter[k]);
            }
            if (visited[current]) {
                for (int i = 0; i < 3; i++) {
                    liter[i] = origin[i];
                }
                continue;
            }

            dfs();

            for (int i = 0; i < 3; i++) {
                liter[i] = origin[i];
            }
        }
    }
}

void Solution() {
    for (int i = 0; i < 3; i++) {
        cin >> maxLiter[i];
    }
    liter[2] = maxLiter[2];

    dfs();

    for (auto a : s) {
        cout << a << ' ';
    }
}

int main() {
    FASTIO
    Solution();
}
