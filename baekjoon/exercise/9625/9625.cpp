#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, na, a, b;

void Solution() {
    cin >> n;
    a = 1;
    while (n--) {
        na = b;
        b = a + b;
        a = na;
    }

    cout << a << ' ' << b;
}

int main() {
    FASTIO
    Solution();
}