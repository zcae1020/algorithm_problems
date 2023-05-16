#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
#define llu unsigned long long
#define fs first
#define sd second

using namespace std;

int t, n, arr[50];

void Solution() {
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Class " << i << '\n';
        cin >> n;
        int mx = 0, mn = 100, gap = 0;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
            mx = max(mx, arr[j]);
            mn = min(mn, arr[j]);
        }
        sort(arr, arr + n);
        for (int j = 0; j < n - 1; j++) {
            gap = max(gap, arr[j + 1] - arr[j]);
        }
        cout << "Max " << mx << ", Min " << mn << ", Largest gap " << gap
             << '\n';
    }
}

int main() {
    FASTIO
    Solution();
}