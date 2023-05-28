#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, k, ans;
string inst;
map<char, int> m;

bool check(int a, int b) {
    if (a - 1 <= m['R'] && b - 1 <= m['U']) {
        return true;
    }

    int cost = max(a - 1 - m['R'], b - 1 - m['U']);
    if (cost > a - 1 || cost > b - 1) {
        return false;
    }

    return cost <= m['X'];
}

void Solution() {
    cin >> n >> inst >> k;
    for (auto i : inst) {
        m[i]++;
    }

    while (k--) {
        int a, b;
        cin >> a >> b;
        ans += check(a, b);
    }

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}