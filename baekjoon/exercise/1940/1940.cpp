#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, m, ans;
map<int, bool> MAP;

void Solution() {
    cin >> n >> m;
    while (n--) {
        int a;
        cin >> a;
        if (MAP[a]) {
            ans++;
            MAP[a] = 0;
        } else {
            MAP[m - a] = 1;
        }
    }

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}