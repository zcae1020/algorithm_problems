#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxn = 1e6 + 5e3;

int n, ans = 1e9;
bool isPP[maxn];
vector<int> ansPool;

bool isPalin(int num) {
    string s = to_string(num);
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            return false;
        }
    }

    return true;
}

void Solution() {

    for (int i = 2; i < maxn; i++) {
        if (!isPP[i]) {
            for (int j = 2; i * j < maxn; j++) {
                isPP[i * j] = true;
            }

            if (isPalin(i)) {
                ansPool.push_back(i);
            }
        }
    }

    cin >> n;
    int l = 0, r = ansPool.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (ansPool[m] >= n) {
            ans = min(ans, ansPool[m]);
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << ans;
}

int main() {
    FASTIO
    Solution();
}