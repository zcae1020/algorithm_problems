#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

ll n, a[2], turn;

void Solution() {
    cin >> n;
    a[turn] = 1;
    while (n--) {
        a[!turn] += a[turn];
        turn = !turn;
    }

    cout << a[0] * 2 + a[1] * 2;
}

int main() {
    FASTIO
    Solution();
}