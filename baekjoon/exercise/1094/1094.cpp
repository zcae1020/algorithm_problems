#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int n, ans, cur = 1;

void Solution() {
    cin >> n;
    while (cur <= 64) {
        if (n & cur)
            ans++;
        cur <<= 1;
    }
    cout << ans;
}

int main() {
    FASTIO
    Solution();
}
