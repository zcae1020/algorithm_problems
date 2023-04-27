#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, a;

void Solution() {
    cin >> n;
    for (int i = 0; i < 9; i++) {
        cin >> a;
        n -= a;
    }
    cout << n;
}

int main() {
    FASTIO
    Solution();
}