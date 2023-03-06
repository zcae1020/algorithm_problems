#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, m, arr[7];
vector<int> v;

void dfs(int cnt, int idx) {
    if (cnt == 0) {
        for (auto a : v) {
            cout << a << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = idx; i < n; i++) {
        v.push_back(arr[i]);
        dfs(cnt - 1, idx);
        v.pop_back();
    }
}

void Solution() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    dfs(m, 0);
}

int main() {
    FASTIO
    Solution();
}