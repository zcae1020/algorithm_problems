#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, f;

void Solution() {
    cin >> n;
    f = n / 5;
    while (f) {
        if ((n - 5 * f) % 2 == 0) {
            break;
        }
        f--;
    }

    if ((n - 5 * f) % 2 == 0) {
        cout << f + (n - 5 * f) / 2;
    } else {
        cout << -1;
    }
}

int main() {
    FASTIO
    Solution();
}