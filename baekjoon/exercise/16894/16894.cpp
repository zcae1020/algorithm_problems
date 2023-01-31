#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const ll maxn = 1e13 + 1;

ll n;
map<ll, int> dp;

void getPrime(ll cur) {
    if (dp[cur]) {
        return;
    }

    for (ll i = 2; i * i <= cur; i++) {
        if (cur % i == 0) {
            getPrime(i);
            getPrime(cur / i);
            dp[cur] = -1;
        }
    }

    if (dp[cur] == 0) {
        dp[cur] = 1;
    }
}

int makeDp(ll cur) {
    if (dp[cur] > 0) {
        return dp[cur];
    }

    for (ll i = 2; i * i <= cur; i++) {
        if (cur % i == 0) {
            if (makeDp(cur / i) == 2) {
                return dp[cur] = 1;
            }
        }
    }

    return dp[cur] = 2;
}

void Solution() {
    cin >> n;

    getPrime(n);
    makeDp(n);

    cout << (dp[n] == 1 ? "koosaga" : "cubelover");
}

int main() {
    FASTIO
    Solution();
}