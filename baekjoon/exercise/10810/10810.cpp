#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, m, a, b, c, ball[101];

void Solution() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        for (int j = a; j <= b; j++) {
            ball[j] = c;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ball[i] << ' ';
    }
}

int main() {
    FASTIO
    Solution();
}