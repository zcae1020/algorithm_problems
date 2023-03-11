#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxn = 1e5 + 1;
int n, m[3], par[3][maxn];
map<vector<int>, vector<int>> MAP;

vector<vector<int>> ans;

int find(int idx, int u) {
    return (par[idx][u] == u ? u : par[idx][u] = find(idx, par[idx][u]));
}

void merge(int idx, int u, int v) {
    u = find(idx, u), v = find(idx, v);

    int mn = min(u, v);
    par[idx][u] = par[idx][v] = mn;
}

bool cmp(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

void Solution() {
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j < maxn; j++) {
            par[i][j] = j;
        }
    }

    cin >> n;
    for (int i = 0; i < 3; i++) {
        cin >> m[i];
    }


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < m[i]; j++) {
            int a, b;
            cin >> a >> b;
            merge(i, a, b);
        }

        for (int j = 0; j < maxn; j++) {
            find(i, j);
        }
    }

    for (int i = 1; i <= n; i++) {
        vector<int> tmp;
        for (int j = 0; j < 3; j++) {
            tmp.push_back(par[j][i]);
        }

        MAP[tmp].push_back(i);
    }

    for (auto p : MAP) {
        if (p.sd.size() > 1) {
            ans.push_back(p.sd);
        }
    }

    sort(ans.begin(), ans.end(), cmp);
    cout << ans.size() << '\n';
    for (auto v : ans) {
        sort(v.begin(), v.end());
        for (auto p : v) {
            cout << p << ' ';
        }
        cout << '\n';
    }
}

int main() {
    FASTIO
    Solution();
}
