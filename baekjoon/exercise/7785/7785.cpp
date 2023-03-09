#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n;
map<string, bool> m;
vector<string> ans;

void Solution() {
    cin >> n;
    while (n--) {
        string a, b;
        cin >> a >> b;
        m[a] = b == "enter";
    }

    for (auto p : m) {
        if (p.sd) {
            ans.push_back(p.fs);
        }
    }

    sort(ans.begin(), ans.end());

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << '\n';
    }
}

int main() {
    FASTIO
    Solution();
}