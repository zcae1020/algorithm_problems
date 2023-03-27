#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, a, t[501], ans[501], outdegree[501];
vector<int> indegree[501];

void Solution() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        while (1) {
            cin >> a;
            if (a == -1) {
                break;
            }
            indegree[a].push_back(i);
            outdegree[i]++;
        }
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (outdegree[i] == 0) {
            q.push(i);
            ans[i] = t[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto next : indegree[cur]) {
            if (--outdegree[next] == 0) {
                q.push(next);
            }

            ans[next] = max(ans[next], t[next] + ans[cur]);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    FASTIO
    Solution();
}