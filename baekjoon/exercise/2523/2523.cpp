#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n;

void Solution() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cout << '*';
        }
        cout << '\n';
    }

    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << '*';
        }
        cout << '\n';
    }
}

int main() {
    FASTIO
    Solution();
}