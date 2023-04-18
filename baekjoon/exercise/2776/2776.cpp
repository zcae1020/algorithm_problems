#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int t, n, a;

void Solution() {
    cin >> t;
    while (t--) {
        unordered_map<int, int> m;
        cin >> n;
        while (n--) {
            cin >> a;
            m[a] = 1;
        }
        cin >> n;
        while (n--) {
            cin >> a;
            cout << m[a] << '\n';
        }
    }
}

int main() {
    FASTIO
    Solution();
}