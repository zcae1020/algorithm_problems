#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

const int maxn = 1e5;
int n, arr[maxn], l, r, mn = INT_MAX;
pii ans;

void Solution() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    l = 0, r = n - 1;
    while (l < r) {
        if (mn > abs(arr[l] + arr[r])) {
            mn = abs(arr[l] + arr[r]);
            ans = {arr[l], arr[r]};
        }
        if (arr[l] + arr[r] >= 0) {
            r--;
        } else {
            l++;
        }
    }

    cout << ans.fs << ' ' << ans.sd;
}

int main() {
    FASTIO
    Solution();
}