#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int t, n;

bool check(vector<string> v) {
    if (v.size() <= 1) {
        return true;
    }

    bool ret = true;
    vector<string> next[10];

    for (auto a : v) {
        if (a == "") {
            return a.size() > 1;
        }
        next[a[0] - '0'].push_back(a.substr(1, a.size() - 1));
    }

    for (int i = 0; i < 10; i++) {
        ret &= check(next[i]);
    }
    return ret;
}

void Solution() {
    cin >> t;
    while (t--) {
        cin >> n;
        vector<string> input;
        for (int i = 0; i < n; i++) {
            string x;
            cin >> x;
            input.push_back(x);
        }

        cout << (check(input) ? "YES" : "NO") << '\n';
    }
}

int main() {
    FASTIO
    Solution();
}
