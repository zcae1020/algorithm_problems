#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n;
string origin, s;

void Solution() {
    cin >> n >> origin;
    for (int i = 1; i < n; i++) {
        cin >> s;
        for (int j = 0; j < origin.size(); j++) {
            if (origin[j] != s[j]) {
                origin[j] = '?';
            }
        }
    }
    cout << origin;
}

int main() {
    FASTIO
    Solution();
}
